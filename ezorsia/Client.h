#pragma once
class Client
{
public:
	static void UpdateGameStartup();
	static void EnableNewIGCipher();
	static void UpdateLogin();
	static void FixMouseWheel();
	static void LongQuickSlot();
	static void JumpCap();
	static void CRCBypass();
	static void NoPassword();
	static void MoreHook();
	static void Skill();
	static bool EmptyMemory();
	static const int m_nIGCipherHash = 0xC65053F2;
	static int DefaultResolution;
	static int MsgAmount;
	static bool WindowedMode;
	static bool RemoveLogos;
	static bool SkipWorldSelect;
	static bool RemoveSystemMsg;
	static bool RemoveLoginNxIdDialog;
	static int ScreenShotPath;
	static int ResCheckTime;
	static int ResFlushTimeInterval;
	static int ResManFlushCached;
	static int SetWorkingSetSize;
	//static int setDamageCap;
	//static int setMAtkCap;
	static int setAccCap;
	static int setAvdCap;
	static double setAtkOutCap;
	static bool longEXP;
	static std::string levelExpOverride;
	static int levelType;
	static bool useTubi;
	static bool debug;
	static bool crashAutoDump;
	static bool noPassword;
	static bool forceExit;
	static bool linkNodeNew;
	static bool climbSpeedAuto;
	static float climbSpeed;
	static int speedMovementCap;
	static DWORD jumpCap;
	static std::string ServerName;
	static std::string ServerNameTips;
	static std::string WelcomeMessage;
	static std::string ServerIP_AddressFromINI;
	static bool ServerIP_Address_hook;
	static bool canInjected;
	static bool isInjected;
	static std::mutex injected;
	static std::condition_variable injectedCondition;
	static bool exit;
	static int serverIP_Port;
	static bool talkRepeat;
	static int talkTime;
	static bool longSlots;
	static int longSlotsKey;
	static bool showItemID;
	static bool showWeaponSpeed;
	static bool minimizeMaptitleColor;
	static bool meleePunching;
	static bool holdAttack;
	static bool spLimit;
	static int StatDetailBackgrndWidthEx;
	static int DamageSkin;
	static bool RemoteDamageSkin;
	static bool tamingMobUnlock;
	static bool tamingMob198Effect;
	static bool replacePetEquipCheck;
	static int downJumpLimitHeight;
	static bool unlockPanelLimit;
	static bool unlockPaneMaplLimit;
	static bool s2221006;
	static bool s4221001;
	static bool s4221007;
	static bool s14101004;
	static bool s14101004up;
	static bool s5221009;
	static bool s2100NoMove;
};