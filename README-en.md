<p align="center">
	<a href="./README-en.md">
	English
	</a>
	/
  <a href="./README.md">
	简体中文
	</a>
</p>


ijl15 for CMS-079
====

## Usage
Tested development tools: VS 2022, SDK 10, Toolset VS2022 (v144).

When opening with VS, ensure to build the solution in Release x86 MT/MD mode:

- MT: No need for C++ runtime library, does not support forwarding load.
- MD: Requires C++ runtime library, supports forwarding load.

After building, you can find ijl15.dll in the corresponding out/Release-mt or out/Release-md directory.

Two loading methods are supported:

### Overwrite Method：
Overwrite the original client’s ijl15.dll and set ijl15hook to false in the configuration file.

### Forwarding Method (only supports MD mode compiled files):
Rename the original client’s ijl15.dll to 2ijl15.dll, copy the generated ijl15.dll to the client directory, and set ijl15hook to true.

For both methods, copy the config.ini from the project’s root directory to the client’s root directory and modify the corresponding configurations.

`Note: The new version has removed the ijl15hook configuration item and now auto-detects.`

## Main Additional Features

- Supports WZ and IMG modes.
- Supports dynamic resolution (switchable in system settings).
- Supports damage skins (loads external files from [Effect/DamageSkin.img](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/DamageSkin.img) or [Custom.wz](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/Custom.wz)
- Supports Longslot (loads external files from [UI/QuickSlot.img](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/QuickSlot.img) or [Custom.wz](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/Custom.wz)， supports multiple key configurations)
- Supports TamingMob starting with 198.
- Supports new hairstyles and faces.
- Supports effects in ItemEff.img (activatable via 0xAA packet header or ItemEffect).
- Supports memory anti-crash.
- Supports quick double jump (double-tap jump key).
- Suppresses chatroom button pop-up, only sends data packet (can be used for unblocking).
- Character level exceeds Short type, character experience exceeds Long type.
- Character panel width adapts (follows background image width).
- Removes mount model restrictions: can climb ropes, double jump, and move quickly.
- Fixes original SetEff.img effect confusion under specific conditions.


`For more features, please refer to the config.ini configuration file.`

### Damage Skin Instructions:

`In WZ mode,`place [Custom.wz](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/Custom.wz) in the game’s root directory.

`In IMG mode` place the [DamageSkin.img](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/DamageSkin.img) file under UI/Effect.

The format is：{SkinID}/NoRed0   SkinID=0 is the default skin. Refer to the downloaded file for details.

#### Local Version：

Set DamageSkin={SkinID} to enable; visible only to yourself.

#### Remote Version:

Set RemoteDamageSkin=true. The server needs corresponding handling, mainly hooking the guild name packet for loading.

Assuming the GuildName is `BestGuildEver` and the SkinID is 2, the corresponding packet sent would be GuildName changed to `BestGuildEver$$2`.

If GuildName doesn’t exist, replace it with `#`, becoming `#$$2`.

1.  Add `DAMAGESKIN(4194304)` enum type to `client.MapleStat`
2.  In `tools.MaplePacketCreator.MaplePacketCreator.updatePlayerStats` add `DAMAGESKIN` handling to `writeInt`.

#### Reference code for updating the skin:

```Java
//handling.channel.handler.InterServerHandler
public static void LoggedIn(int playerid, MapleClient c) {
     //……omitted
     player.sendDamageSkin();  // Send damage skin packet
     player.sendMacros();
      //……omitted
}

//client.MapleCharacter
public void sendDamageSkin() {
    updateSingleStat(MapleStat.DAMAGESKIN, this.damageSkin);
}

//tools.MaplePacketCreator
public static byte[] updatePlayerStats(Map<MapleStat, Number> mystats, boolean itemReaction, MapleCharacter chr) {
    //……omitted
                case DAMAGESKIN:
                    mplew.writeInt(statupdate2.getValue().intValue());
                    continue;
    //……omitted
}

//tools.MaplePacketCreator
public void updateDamageSkin(int damageSkin) {
        this.damageSkin = damageSkin;
        MapleMap map = getMap();
        if (map != null) {
            String guildName = null;
            MapleGuild gs = World.Guild.getGuild(getGuildId());
            if (gs != null) {
                guildName = gs.getName();
            }
            if (guildName == null || guildName.length() == 0) {
                guildName = "#";
            }
            getMap().broadcastMessage(this, MaplePacketCreator.guildNameChanged(getId()
                    , guildName + "$$" + damageSkin), false);
        }
        updateSingleStat(MapleStat.DAMAGESKIN, damageSkin);
    }

public static byte[] spawnPlayerMapobject(MapleCharacter chr) {
        //……omitted
        //Locate the corresponding code block and modify
        if (chr.getGuildId() <= 0) {
            mplew.writeMapleAsciiString("#$$" + chr.getDamageSkin());
            mplew.writeZeroBytes(6);
        } else {
            MapleGuild gs = World.Guild.getGuild(chr.getGuildId());
            if (gs != null) {
                mplew.writeMapleAsciiString(gs.getName() + "$$" + chr.getDamageSkin());
                mplew.writeShort(gs.getLogoBG());
                mplew.write(gs.getLogoBGColor());
                mplew.writeShort(gs.getLogo());
                mplew.write(gs.getLogoColor());
            } else {
                mplew.writeMapleAsciiString("#$$" + chr.getDamageSkin());
                mplew.writeZeroBytes(6);
            }
        }
        //……omitted
```
#### Add Character Judgement for Hypnotize Effect

```Java
//……omitted
} else if (buff.getSkill() > 0) {
//Added part
if (buff.getStatus() == MonsterStatus.HYPNOTIZE) {
                        mplew.writeInt(-1);  //Used to distinguish whether it is enabled
                        MapleCharacter hypnotizeChr = buff.getHypnotizeChr();
                        mplew.writeInt(hypnotizeChr == null ? 0 : hypnotizeChr.getId());
                    }
                    //End of added part
                    mplew.writeInt((buff.getSkill() > 0) ? buff.getSkill() : 0);
}
//……omitted
```

## Reference Open Source Libraries

https://github.com/BeiDouMS/BeiDou-ijl15

https://github.com/Chronicle20/gms-83-dll

https://github.com/v3921358/MapleRoot

## Friendly Links

UU Downloader：https://github.com/uuuu233/downloader

# For Educational and Research Purposes Only!!!