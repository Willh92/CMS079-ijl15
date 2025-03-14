#pragma once
#include "stdafx.h"
#include "codecaves.h"

int nStatusBarY = 0;
__declspec(naked) void AdjustStatusBar() {
	__asm {
		push nStatusBarY
		push ebx // horizontal position; 0
		mov ecx, esi
		jmp dword ptr[dwStatusBarPosRetn]
	}
}

__declspec(naked) void AdjustStatusBarBG() {
	__asm {
		push nStatusBarY
		movsd
		push 0
		jmp dword ptr[dwStatusBarBackgroundPosRetn]
	}
}

__declspec(naked) void AdjustStatusBarInput() {
	__asm {
		push nStatusBarY
		xor edi, edi
		push edi
		lea ecx, ds: [esi + 0xC74]
		jmp dword ptr[dwStatusBarInputPosRetn]
	}
}

__declspec(naked) void PositionLoginDlg() {
	__asm {
		push 0x000000B4
		push 400
		push - 48	// y
		push - 185	// x
		jmp dword ptr[dwLoginCreateDlgRtn]
	}
}
__declspec(naked) void PositionLoginUsername() {
	__asm {
		push 0x0F
		push 0x00000084
		push 127	// y
		push 0		// x
		jmp dword ptr[dwLoginUsernameRtn]
	}
}
__declspec(naked) void PositionLoginPassword() {
	__asm {
		push 0x0F
		push 0x78
		push 127	// y
		push 272	// x
		jmp dword ptr[dwLoginPasswordRtn]
	}
}
__declspec(naked) void PositionBossBarY() {
	__asm {	//finally working!, originally posted by Angxl
		//push 22	//modification
		push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}
__declspec(naked) void PositionBossBarY1() {
	__asm {	//finally working!, originally posted by Angxl
		push 22	//modification
		//push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}

int serverMessageExists;
__declspec(naked) void PositionBossBarY2() {
	__asm {
		mov esi, eax
		and dword ptr ss : [ebp - 4] , 0
		mov serverMessageExists, esi
		jmp dword ptr[dwBossBarRetn2]
	}
}

int myHeight = -(Resolution::m_nGameHeight - 600) / 2;
int myWidth = -(Resolution::m_nGameWidth - 800) / 2;

__declspec(naked) void CashShopFix() {
	__asm {
		push    eax //vCanvas //originally posted by shavitash		//fixed
		push    ebx //nZ
		push    ebx //uHeight
		push    ebx //uWidth
		push	myHeight//84//myHeight //nTop - do the math yourself, this wont compile obviously
		push	myWidth//283//myWidth //nLeft - same as above
		jmp dword ptr[dwCashFixRtm]
	}
}

int nHeightOfsetted1 = 0; int nWidthOfsetted1 = 0; int nTopOfsetted1 = 0; int nLeftOfsetted1 = 0;
int nHeightOfsetted2 = 0; int nWidthOfsetted2 = 0; int nTopOfsetted2 = 0; int nLeftOfsetted2 = 0;
int nHeightOfsetted3 = 0; int nWidthOfsetted3 = 0; int nTopOfsetted3 = 0; int nLeftOfsetted3 = 0;
int nHeightOfsetted4 = 0; int nWidthOfsetted4 = 0; int nTopOfsetted4 = 0; int nLeftOfsetted4 = 0;
int nHeightOfsetted5 = 0; int nWidthOfsetted5 = 0; int nTopOfsetted5 = 0; int nLeftOfsetted5 = 0;
int nHeightOfsetted6 = 0; int nWidthOfsetted6 = 0; int nTopOfsetted6 = 0;
int nHeightOfsetted7 = 0; int nWidthOfsetted7 = 0; int nTopOfsetted7 = 0; int nLeftOfsetted7 = 0;
int nHeightOfsetted8 = 0; int nWidthOfsetted8 = 0; int nTopOfsetted8 = 0; int nLeftOfsetted8 = 0;

__declspec(naked) void CashShopFix1() {
	__asm {
		push	nHeightOfsetted1
		push	nWidthOfsetted1
		push	nTopOfsetted1
		push	nLeftOfsetted1
		jmp dword ptr[dwCashFix1Rtm]
	}
}

__declspec(naked) void CashShopFix2() {
	__asm {
		push	nHeightOfsetted2
		push	nWidthOfsetted2
		push	nTopOfsetted2
		push	nLeftOfsetted2
		jmp dword ptr[dwCashFix2Rtm]
	}
}

__declspec(naked) void CashShopFix3() {
	__asm {
		push	nHeightOfsetted3
		push	nWidthOfsetted3
		push	nTopOfsetted3
		push	nLeftOfsetted3
		jmp dword ptr[dwCashFix3Rtm]
	}
}

__declspec(naked) void CashShopFix4() {
	__asm {
		push	nHeightOfsetted4
		push	nWidthOfsetted4
		push	nTopOfsetted4
		push	nLeftOfsetted4
		jmp dword ptr[dwCashFix4Rtm]
	}
}

__declspec(naked) void CashShopFix5() {
	__asm {
		push	nHeightOfsetted5
		push	nWidthOfsetted5
		push	nTopOfsetted5
		push	nLeftOfsetted5
		jmp dword ptr[dwCashFix5Rtm]
	}
}

__declspec(naked) void CashShopFix6() {
	__asm {
		push	nHeightOfsetted6
		push	nWidthOfsetted6
		push	nTopOfsetted6
		jmp dword ptr[dwCashFix6Rtm]
	}
}

__declspec(naked) void CashShopFix7() {
	__asm {
		push	nHeightOfsetted7
		push	nWidthOfsetted7
		push	nTopOfsetted7
		push	nLeftOfsetted7
		jmp dword ptr[dwCashFix7Rtm]
	}
}

__declspec(naked) void CashShopFix8() {
	__asm {
		push	nHeightOfsetted8
		push	nWidthOfsetted8
		push	nTopOfsetted8
		push	nLeftOfsetted8
		jmp dword ptr[dwCashFix8Rtm]
	}
}

__declspec(naked) void CashShopFix9() {
	__asm {
		push	nHeightOfsetted5
		push	nWidthOfsetted5
		push	nTopOfsetted5
		push	nLeftOfsetted5
		jmp dword ptr[dwCashFix9Rtm]
	}
}

__declspec(naked) void CashShopFixOnOff() {	//could be improved upon because idk if it's the right way to do it or if it might cause issues
	__asm {
		pop	ebx
		push ecx
		mov ecx, dword ptr[dwCashFixOnOffCall]
		call ecx
		add esp, 4
		leave
		retn    4
	}
}

int nHeightOfsettedPrev = 0; int nWidthOfsettedPrev = 0; int nTopOfsettedPrev = 0; int nLeftOfsettedPrev = 0;

__declspec(naked) void CashShopFixPrev() {
	__asm {
		push	nHeightOfsettedPrev
		push	nWidthOfsettedPrev
		push	nTopOfsettedPrev
		push	nLeftOfsettedPrev
		jmp dword ptr[dwCashFixPrevRtm]
	}
}

int iHeightOfsetted1 = 0; int iWidthOfsetted1 = 0; int iTopOfsetted1 = 0; int iLeftOfsetted1 = 0;
int iHeightOfsetted2 = 0; int iWidthOfsetted2 = 0; int iTopOfsetted2 = 0; int iLeftOfsetted2 = 0;
int iHeightOfsetted3 = 0; int iWidthOfsetted3 = 0; int iTopOfsetted3 = 0; int iLeftOfsetted3 = 0;
int iHeightOfsetted4 = 0; int iWidthOfsetted4 = 0; int iTopOfsetted4 = 0; int iLeftOfsetted4 = 0;
int iHeightOfsetted5 = 0; int iWidthOfsetted5 = 0; int iTopOfsetted5 = 0; int iLeftOfsetted5 = 0;
int iHeightOfsetted6 = 0; int iWidthOfsetted6 = 0; int iTopOfsetted6 = 0; int iLeftOfsetted6 = 0;
int iHeightOfsetted7 = 0; int iWidthOfsetted7 = 0; int iTopOfsetted7 = 0; int iLeftOfsetted7 = 0;
int iHeightOfsetted8 = 0; int iWidthOfsetted8 = 0; int iTopOfsetted8 = 0; int iLeftOfsetted8 = 0;

__declspec(naked) void ITCFix1() {
	__asm {
		push	iHeightOfsetted1
		push	iWidthOfsetted1
		push	iTopOfsetted1
		push	iLeftOfsetted1
		jmp dword ptr[dwITCFix1Rtm]
	}
}

__declspec(naked) void ITCFix2() {
	__asm {
		push	iHeightOfsetted2
		push	iWidthOfsetted2
		push	iTopOfsetted2
		push	iLeftOfsetted2
		jmp dword ptr[dwITCFix2Rtm]
	}
}

__declspec(naked) void ITCFix3() {
	__asm {
		push	iHeightOfsetted3
		push	iWidthOfsetted3
		push	iTopOfsetted3
		push	iLeftOfsetted3
		jmp dword ptr[dwITCFix3Rtm]
	}
}

__declspec(naked) void ITCFix4() {
	__asm {
		push	iHeightOfsetted4
		push	iWidthOfsetted4
		push	iTopOfsetted4
		push	iLeftOfsetted4
		jmp dword ptr[dwITCFix4Rtm]
	}
}

__declspec(naked) void ITCFix5() {
	__asm {
		push    10
		push	iHeightOfsetted5
		push	iWidthOfsetted5
		push	iTopOfsetted5
		push	iLeftOfsetted5
		jmp dword ptr[dwITCFix5Rtm]
	}
}

__declspec(naked) void ITCFix6() {
	__asm {
		push	iHeightOfsetted6
		push	iWidthOfsetted6
		push	iTopOfsetted6
		push	iLeftOfsetted6
		jmp dword ptr[dwITCFix6Rtm]
	}
}

__declspec(naked) void ITCFix7() {
	__asm {
		push	iHeightOfsetted7
		push	iWidthOfsetted7
		push	iTopOfsetted7
		push	iLeftOfsetted7
		jmp dword ptr[dwITCFix7Rtm]
	}
}

__declspec(naked) void ITCFix8() {
	__asm {
		push	iHeightOfsetted8
		push	iWidthOfsetted8
		push	iTopOfsetted8
		push	iLeftOfsetted8
		jmp dword ptr[dwITCFix8Rtm]
	}
}

int nTopOfsettedVerFix = 2; int nLeftOfsettedVerFix = 0;

__declspec(naked) void VersionNumberFix() {
	__asm {
		mov    eax, nLeftOfsettedVerFix
		sub    eax, DWORD PTR[ebp - 0x1c]
		push	nTopOfsettedVerFix
		jmp dword ptr[dwVersionNumberFixRtm]
	}
}

int myAlwaysViewRestoreFixOffset = 0;

__declspec(naked) void AlwaysViewRestoreFix() {
	__asm {
		test	eax, eax
		jnz C_Dest
		mov ecx, myAlwaysViewRestoreFixOffset
		push myAlwaysViewRestoreFixOffset
		jmp dword ptr[dwAlwaysViewRestorerFixRtm]
		C_Dest:
		mov ecx, DWORD PTR[eax]
			push eax
			jmp dword ptr[dwAlwaysViewRestorerFixRtm]
	}
}

//int nHeightOfsettedloginFrameFix = 0; int nWidthOfsettedloginFrameFix = 0;
//int nTopOfsettedloginFrameFix = 0; int nLeftOfsettedloginFrameFix = 0;

//__declspec(naked) void loginFrameFix() {
//	__asm {
//		pop ebx
////		push 1
//		push 0
//		push 1
//		push	nHeightOfsettedloginFrameFix
//		push	nWidthOfsettedloginFrameFix
//		push	nTopOfsettedloginFrameFix
//		push	nLeftOfsettedloginFrameFix
//		push esi
//		call dword ptr[dwloginFrameFixCall]
//		add esp, 4
//		leave
//		retn 4
//	}
//}

int nHeightOfsettedLoginBackCanvasFix = 0; int nWidthOfsettedLoginBackCanvasFix = 0;
int nTopOfsettedLoginBackCanvasFix = 0; int nLeftOfsettedLoginBackCanvasFix = 0;

__declspec(naked) void ccLoginBackCanvasFix() {
	__asm {
		push	nHeightOfsettedLoginBackCanvasFix
		push	nWidthOfsettedLoginBackCanvasFix
		push	nTopOfsettedLoginBackCanvasFix
		push	nLeftOfsettedLoginBackCanvasFix
		jmp dword ptr[dwLoginBackCanvasFixRetn]
	}
}

int nHeightOfsettedLoginViewRecFix = 0; int nWidthOfsettedLoginViewRecFix = 0;
int nTopOfsettedLoginViewRecFix = 0; int nLeftOfsettedLoginViewRecFix = 0;

__declspec(naked) void ccLoginViewRecFix() {
	__asm {
		push	nHeightOfsettedLoginViewRecFix
		push	nWidthOfsettedLoginViewRecFix
		push	nTopOfsettedLoginViewRecFix
		push	nLeftOfsettedLoginViewRecFix
		jmp dword ptr[dwLoginViewRecFixRetn]
	}
}

int yOffsetOfLoginBackBtnFix = 0; int xOffsetOfLoginBackBtnFix = 0;

__declspec(naked) void ccLoginBackBtnFix() {	//un used
	__asm {
		mov    esi, yOffsetOfLoginBackBtnFix
		push	esi
		mov    edi, xOffsetOfLoginBackBtnFix
		push	edi
		push   0x3e8
		jmp dword ptr[dwLoginBackBtnFixRetn]
	}
}

int a1x = 0; int a2x = 0; int a2y = 0; int a3 = 0; int a1y = 0;

__declspec(naked) void ccLoginDescriptorFix() {
	__asm {
		and edx, 0x3f
		add    edx, 0x21
		add    edx, a2y
		cmp     ecx, edi
		setl   bl
		mov     ecx, esi
		mov    DWORD PTR[esi + 0x4], 0xaf7084
		mov    DWORD PTR[esi + 0x8], 0xaf7080
		neg     ebx
		sbb     ebx, ebx
		and ebx, a3	//and ebx, 0x64
		add     ebx, eax
		push    ebx
		push    edx
		xor eax, eax
		add eax, a1x //a1x
		push    eax
		push    edx
		push    eax
		push    edx
		mov    eax, a2x	//mov    eax, 0xffffff6b
		push    eax
		push	edi
		jmp dword ptr[dwLoginDescriptorFixRetn]
	}
}

int MoreGainMsgsOffset = 6;

__declspec(naked) void ccMoreGainMsgs() {
	__asm {
		mov    eax, DWORD PTR[edi + 0x10]
		cmp    eax, MoreGainMsgsOffset
		jmp dword ptr[dwMoreGainMsgsRetn]
	}
}

int MoreGainMsgsFadeOffset = 0;

__declspec(naked) void ccMoreGainMsgsFade() {
	__asm {
		add eax, MoreGainMsgsFadeOffset
		push 3
		jmp dword ptr[dwMoreGainMsgsFadeRetn]
	}
}

int MoreGainMsgsFade1Offset = 0;

__declspec(naked) void ccMoreGainMsgsFade1() {
	__asm {
		push MoreGainMsgsFade1Offset
		jmp dword ptr[dwMoreGainMsgsFade1Retn]
	}
}

int yOffsetOfMuruengraidPlayer = 50; int xOffsetOfMuruengraidPlayer = 169;

__declspec(naked) void ccMuruengraidPlayer() {
	__asm {
		push yOffsetOfMuruengraidPlayer
		push xOffsetOfMuruengraidPlayer
		push ecx
		jmp dword ptr[dwMuruengraidPlayerRetn]
	}
}

int yOffsetOfMuruengraidClock = 26; int xOffsetOfMuruengraidClock = 400;

__declspec(naked) void ccMuruengraidClock() {
	__asm {
		push yOffsetOfMuruengraidClock
		push xOffsetOfMuruengraidClock
		push ecx
		jmp dword ptr[dwMuruengraidClockRetn]
	}
}

int yOffsetOfMuruengraidMonster = 50; int xOffsetOfMuruengraidMonster = 631;

__declspec(naked) void ccMuruengraidMonster() {
	__asm {
		push yOffsetOfMuruengraidMonster
		push xOffsetOfMuruengraidMonster
		push ecx
		jmp dword ptr[dwMuruengraidMonsterRetn]
	}
}

int yOffsetOfMuruengraidMonster1 = 32; int xOffsetOfMuruengraidMonster1 = 317;

__declspec(naked) void ccMuruengraidMonster1() {
	__asm {
		push yOffsetOfMuruengraidMonster1
		push xOffsetOfMuruengraidMonster1
		jmp dword ptr[dwMuruengraidMonster1Retn]
	}
}

int yOffsetOfMuruengraidMonster2 = 32; int xOffsetOfMuruengraidMonster2 = 482;

__declspec(naked) void ccMuruengraidMonster2() {
	__asm {
		push yOffsetOfMuruengraidMonster2
		push xOffsetOfMuruengraidMonster2
		jmp dword ptr[dwMuruengraidMonster2Retn]
	}
}

int yOffsetOfMuruengraidEngBar = 86; int xOffsetOfMuruengraidEngBar = 17;

__declspec(naked) void ccMuruengraidEngBar() {
	__asm {
		push yOffsetOfMuruengraidEngBar
		push xOffsetOfMuruengraidEngBar
		push ecx
		jmp dword ptr[dwMuruengraidEngBarRetn]
	}
}

int yOffsetOfMuruengraidEngBar1 = 130; int xOffsetOfMuruengraidEngBar1 = 20;

__declspec(naked) void ccMuruengraidEngBar1() {
	__asm {
		push yOffsetOfMuruengraidEngBar1
		push xOffsetOfMuruengraidEngBar1
		push ecx
		jmp dword ptr[dwMuruengraidEngBar1Retn]
	}
}

int yOffsetOfMuruengraidEngBar2 = 80; int xOffsetOfMuruengraidEngBar2 = 9;

__declspec(naked) void ccMuruengraidEngBar2() {
	__asm {
		push yOffsetOfMuruengraidEngBar2
		push xOffsetOfMuruengraidEngBar2
		push ecx
		jmp dword ptr[dwMuruengraidEngBar2Retn]
	}
}

int yOffsetOfMuruengraidClearRoundUI = 260; int xOffsetOfMuruengraidClearRoundUI = 400;

__declspec(naked) void ccMuruengraidClearRoundUI() {
	__asm {
		mov ecx, esi
		push yOffsetOfMuruengraidClearRoundUI
		push xOffsetOfMuruengraidClearRoundUI
		jmp dword ptr[dwMuruengraidClearRoundUIRetn]
	}
}

int yOffsetOfMuruengraidTimerCanvas = 28; int xOffsetOfMuruengraidTimerCanvas = 112;

__declspec(naked) void ccMuruengraidTimerCanvas() {
	__asm {
		push yOffsetOfMuruengraidTimerCanvas
		movsd
		push xOffsetOfMuruengraidTimerCanvas
		jmp dword ptr[dwMuruengraidTimerCanvasRetn]
	}
}

int yOffsetOfMuruengraidTimerMinutes = 0; int xOffsetOfMuruengraidTimerMinutes = 0;

__declspec(naked) void ccMuruengraidTimerMinutes() {
	__asm {
		mov    DWORD PTR[esi + 7C8h], edi
		push eax
		push yOffsetOfMuruengraidTimerMinutes
		push xOffsetOfMuruengraidTimerMinutes
		jmp dword ptr[dwMuruengraidTimerMinutesRetn]
	}
}

int yOffsetOfMuruengraidTimerSeconds = 0; int xOffsetOfMuruengraidTimerSeconds = 68;

__declspec(naked) void ccMuruengraidTimerSeconds() {
	__asm {
		mov ecx, esi
		push edx
		push yOffsetOfMuruengraidTimerSeconds
		push xOffsetOfMuruengraidTimerSeconds
		jmp dword ptr[dwMuruengraidTimerSecondsRetn]
	}
}

int yOffsetOfMuruengraidTimerBar = 16; int xOffsetOfMuruengraidTimerBar = 345;

__declspec(naked) void ccMuruengraidTimerBar() {
	__asm {
		push yOffsetOfMuruengraidTimerBar
		push xOffsetOfMuruengraidTimerBar
		jmp dword ptr[dwMuruengraidTimerBarRetn]
	}
}

int xOffsetOfMuruengraidMonster1_2 = 318;

__declspec(naked) void ccMuruengraidMonster1_2() {
	__asm {
		mov    edx, xOffsetOfMuruengraidMonster1_2
		jmp dword ptr[dwMuruengraidMonster1_2Retn]
	}
}

__declspec(naked) void ccStatsSubMov() {
	__asm {
		mov     ecx, esi
		add   DWORD PTR[ebp + 0x8], 84 //260-176
		push   DWORD PTR[ebp + 0x8]
		jmp dword ptr[dwStatsSubMovRetn]
	}
}
//beginning of packed client run caves

__declspec(naked) void ccCLoginSendCheckPasswordPacket() {
	__asm {
		jmp dword ptr[dwCLoginSendCheckPasswordPacketRetn]
	}
}

__declspec(naked) void cc0x0044E550() {
	__asm {
		jmp dword ptr[dw0x0044E550Retn]
	}
}

__declspec(naked) void cc0x0044E5BE() {
	__asm {
		jmp dword ptr[dw0x0044E5BERetn]
	}
}

__declspec(naked) void cc0x0044E5DB() {
	__asm {
		jmp dword ptr[dw0x0044E5DBRetn]
	}
}

__declspec(naked) void cc0x0044E6AC() {
	__asm {
		jmp dword ptr[dw0x0044E6ACRetn]
	}
}

__declspec(naked) void cc0x0044E71D() {
	__asm {
		jmp dword ptr[dw0x0044E71DRetn]
	}
}

__declspec(naked) void cc0x0044E80C() {
	__asm {
		jmp dword ptr[dw0x0044E80CRetn]
	}
}

__declspec(naked) void cc0x0044E8B4() {
	__asm {
		jmp dword ptr[dw0x0044E8B4Retn]
	}
}

__declspec(naked) void cc0x0044EA22() {
	__asm {
		jmp dword ptr[dw0x0044EA22Retn]
	}
}

__declspec(naked) void cc0x0044EA6F() {
	__asm {
		jmp dword ptr[dw0x0044EA6FRetn]
	}
}

__declspec(naked) void cc0x0044EBD6() {
	__asm {
		jmp dword ptr[dw0x0044EBD6Retn]
	}
}

__declspec(naked) void cc0x0044ECA1() {
	__asm {
		jmp dword ptr[dw0x0044ECA1Retn]
	}
}

__declspec(naked) void cc0x0044ED32() {
	__asm {
		jmp dword ptr[dw0x0044ED32Retn]
	}
}

__declspec(naked) void cc0x0044ED52() {
	__asm {
		jmp dword ptr[dw0x0044ED52Retn]
	}
}

__declspec(naked) void cc0x0044EED3() {
	__asm {
		jmp dword ptr[dw0x0044EED3Retn]
	}
}

__declspec(naked) void cc0x00494943() {
	__asm {
		jmp dword ptr[dw0x00494943Retn]
	}
}

__declspec(naked) void cc0x00494BB6() {
	__asm {
		jmp dword ptr[dw0x00494BB6Retn]
	}
}

__declspec(naked) void cc0x00494CA9() {
	__asm {
		jmp dword ptr[dw0x00494CA9Retn]
	}
}

__declspec(naked) void cc0x00494CF0() {
	__asm {
		jmp dword ptr[dw0x00494CF0Retn]
	}
}

__declspec(naked) void cc0x00494D3B() {
	__asm {
		jmp dword ptr[dw0x00494D3BRetn]
	}
}

__declspec(naked) void cc0x00494EAF() {
	__asm {
		jmp dword ptr[dw0x00494EAFRetn]
	}
}

__declspec(naked) void cc0x00494EEC() {
	__asm {
		jmp dword ptr[dw0x00494EECRetn]
	}
}

__declspec(naked) void cc0x00494F87() {
	__asm {
		jmp dword ptr[dw0x00494F87Retn]
	}
}

__declspec(naked) void cc0x009F4E84() {
	__asm {
		jmp dword ptr[dw0x009F4E84Retn]
	}
}

__declspec(naked) void cc0x009F4EC3() {
	__asm {
		jmp dword ptr[dw0x009F4EC3Retn]
	}
}

__declspec(naked) void cc0x009F4F12() {
	__asm {
		jmp dword ptr[dw0x009F4F12Retn]
	}
}

__declspec(naked) void cc0x009F4FC6() {
	__asm {
		jmp dword ptr[dw0x009F4FC6Retn]
	}
}

__declspec(naked) void cc0x009F503C() {
	__asm {
		jmp dword ptr[dw0x009F503CRetn]
	}
}

__declspec(naked) void cc0x009F51A7() {
	__asm {
		jmp dword ptr[dw0x009F51A7Retn]
	}
}

__declspec(naked) void cc0x009F526F() {
	__asm {
		jmp dword ptr[dw0x009F526FRetn]
	}
}

__declspec(naked) void cc0x009F5653() {
	__asm {
		jmp dword ptr[dw0x009F5653Retn]
	}
}

__declspec(naked) void cc0x009F5833() {
	__asm {
		jmp dword ptr[dw0x009F5833Retn]
	}
}

__declspec(naked) void cc0x009F5C2C() {
	__asm {
		jmp dword ptr[dw0x009F5C2CRetn]
	}
}

__declspec(naked) void cc0x009F5CA3() {
	__asm {
		jmp dword ptr[dw0x009F5CA3Retn]
	}
}

__declspec(naked) void cc0x009F5FBD() {
	__asm {
		jmp dword ptr[dw0x009F5FBDRetn]
	}
}

__declspec(naked) void cc0x009F631C() {
	__asm {
		jmp dword ptr[dw0x009F631CRetn]
	}
}

__declspec(naked) void cc0x009F691F() {
	__asm {
		jmp dword ptr[dw0x009F691FRetn]
	}
}

__declspec(naked) void cc0x009F6F36() {
	__asm {
		jmp dword ptr[dw0x009F6F36Retn]
	}
}

__declspec(naked) void cc0x009F6F5C() {
	__asm {
		jmp dword ptr[dw0x009F6F5CRetn]
	}
}

__declspec(naked) void cc0x009F7CFA() {
	__asm {
		jmp dword ptr[dw0x009F7CFARetn]
	}
}

__declspec(naked) void cc0x009F7D83() {
	__asm {
		jmp dword ptr[dw0x009F7D83Retn]
	}
}

__declspec(naked) void cc0x009F81FB() {
	__asm {
		jmp dword ptr[dw0x009F81FBRetn]
	}
}

__declspec(naked) void cc0x009F84E9() {
	__asm {
		jmp dword ptr[dw0x009F84E9Retn]
	}
}

__declspec(naked) void cc0x009F8AD4() {
	__asm {
		jmp dword ptr[dw0x009F8AD4Retn]
	}
}

__declspec(naked) void cc0x00A4BB39() {
	__asm {
		jmp dword ptr[dw0x00A4BB39Retn]
	}
}

__declspec(naked) void cc0x00A4BC79() {
	__asm {
		jmp dword ptr[dw0x00A4BC79Retn]
	}
}

__declspec(naked) void cc0x00A4BD05() {
	__asm {
		jmp dword ptr[dw0x00A4BD05Retn]
	}
}

__declspec(naked) void cc0x00A4BD4E() {
	__asm {
		jmp dword ptr[dw0x00A4BD4ERetn]
	}
}

__declspec(naked) void cc0x00A4BD99() {
	__asm {
		jmp dword ptr[dw0x00A4BD99Retn]
	}
}

__declspec(naked) void cc0x00A4BDE3() {
	__asm {
		jmp dword ptr[dw0x00A4BDE3Retn]
	}
}

__declspec(naked) void cc0x00A4BDFE() {
	__asm {
		jmp dword ptr[dw0x00A4BDFERetn]
	}
}

__declspec(naked) void cc0x00A4BE47() {
	__asm {
		jmp dword ptr[dw0x00A4BE47Retn]
	}
}


const char myWzFile[] = "TamingMob";
const char* ptrmyWzFile = myWzFile;

int MINT = 51 + 1;
const DWORD dwTesting = 0x009F74D2;
const DWORD dwTestingRetn = 0x009F74EA;
const int TestingNOPs = 24;
__declspec(naked) void testingCodeCave() {
	__asm {
		mov    DWORD PTR[ebp - 0x78], 0xb3f434
		mov    DWORD PTR[ebp - 0x74], 0xb3f42c
		mov    DWORD PTR[ebp - 0x70], 0xb3f428
		mov    DWORD PTR[ebp - 0x6C], 0xb3f428
		mov    DWORD PTR[ebp - 0x18], edi
		jmp dword ptr[dwTestingRetn]
	}
}

const DWORD dwTesting2 = 0x005549F8;
const DWORD dwTesting2Retn = 0x005549FD;
const int Testing2NOPs = 5;
__declspec(naked) void testingCodeCave2() {
	__asm {
		//call dword ptr[custom_sub_4289B7]
		jmp dword ptr[dwTesting2Retn]
	}
}

const DWORD dwTesting3 = 0x005556CC;
const DWORD dwTesting3Retn = 0x005556D5;
const int Testing3NOPs = 9;
__declspec(naked) void testingCodeCave3() {
	__asm {
		mov    DWORD PTR[esi + 0x848], edi
		push eax
		push 80//0
		push 250//0
		jmp dword ptr[dwTesting3Retn]
	}
}

const DWORD dwTesting4 = 0x005556E6;
const DWORD dwTesting4Retn = 0x005556EC;
const int Testing4NOPs = 6;
__declspec(naked) void testingCodeCave4() {
	__asm {
		mov ecx, esi
		push edx
		push 80//0
		push 318//68
		jmp dword ptr[dwTesting4Retn]
	}
}


DWORD fixMouseWheelAddr = 0x009F1AD5;
DWORD fixMouseWheelRetJmpAddr = 0x009F1AE4;
DWORD fixMouseWheelCallSetCursorPosAddr = 0x005CA91A;
__declspec(naked) void fixMouseWheelHook() {
	__asm {
		// is mouse wheel
		cmp eax, 522
		je next
		mov eax, dword ptr ds : [edi]
		shr eax, 0x10
		push eax
		movzx eax, word ptr ds : [edi]
		push eax
		call fixMouseWheelCallSetCursorPosAddr
		next :
		jmp[fixMouseWheelRetJmpAddr]
	}
}

// ARRAYS ---- 长键盘开始
unsigned char Array_aDefaultQKM[] = {
	42, 0, 0, 0,
	82, 0, 0, 0,
	71, 0, 0, 0,
	73, 0, 0, 0,
	2, 0, 0, 0,
	3, 0, 0, 0,
	4, 0, 0, 0,
	5, 0, 0, 0,
	6, 0, 0, 0,
	30, 0, 0, 0,
	31, 0, 0, 0,
	32, 0, 0, 0,
	33, 0, 0, 0,  // 13
	29, 0, 0, 0,
	83, 0, 0, 0,
	79, 0, 0, 0,
	81, 0, 0, 0,
	16, 0, 0, 0,
	17, 0, 0, 0,
	18, 0, 0, 0,
	19, 0, 0, 0,
	20, 0, 0, 0,
	44, 0, 0, 0,
	45, 0, 0, 0,
	46, 0, 0, 0,
	47, 0, 0, 0,
	52, 0, 0, 0
};

// 0x00BE2DB0 confirmed, s_ptShortKeyPos
unsigned char Array_ptShortKeyPos[] = {
	82, 0, 0, 0,           //7+75
	8, 0, 0, 0,
	117, 0, 0, 0,
	8, 0, 0, 0,
	152, 0, 0, 0,
	8, 0, 0, 0,
	187, 0, 0, 0,
	8, 0, 0, 0,
	222, 0, 0, 0,
	8, 0, 0, 0,
	1, 1, 0, 0,
	8, 0, 0, 0,
	36, 1, 0, 0,
	8, 0, 0, 0,
	71, 1, 0, 0,
	8, 0, 0, 0,
	106, 1, 0, 0,
	8, 0, 0, 0,
	141, 1, 0, 0,
	8, 0, 0, 0,
	176, 1, 0, 0,
	8, 0, 0, 0,
	211, 1, 0, 0,
	8, 0, 0, 0,
	246, 1, 0, 0,
	8, 0, 0, 0,
	82, 0, 0, 0,    //第二行
	41, 0, 0, 0,
	117, 0, 0, 0,
	41, 0, 0, 0,
	152, 0, 0, 0,
	41, 0, 0, 0,
	187, 0, 0, 0,
	41, 0, 0, 0,
	222, 0, 0, 0,
	41, 0, 0, 0,
	1, 1, 0, 0,
	41, 0, 0, 0,
	36, 1, 0, 0,
	41, 0, 0, 0,
	71, 1, 0, 0,
	41, 0, 0, 0,
	106, 1, 0, 0,
	41, 0, 0, 0,
	141, 1, 0, 0,
	41, 0, 0, 0,
	176, 1, 0, 0,
	41, 0, 0, 0,
	211, 1, 0, 0,
	41, 0, 0, 0,
	246, 1, 0, 0,
	41, 0, 0, 0
};
//Variant of Array_ptShortKeyPos
unsigned char Array_ptShortKeyPos_Fixed_Tooltips[] = {
	82, 0, 0, 0,           //7+75
	8, 0, 0, 0,
	117, 0, 0, 0,
	8, 0, 0, 0,
	152, 0, 0, 0,
	8, 0, 0, 0,
	187, 0, 0, 0,
	8, 0, 0, 0,
	222, 0, 0, 0,
	8, 0, 0, 0,
	1, 1, 0, 0,
	8, 0, 0, 0,
	36, 1, 0, 0,
	8, 0, 0, 0,
	71, 1, 0, 0,
	8, 0, 0, 0,
	106, 1, 0, 0,
	8, 0, 0, 0,
	141, 1, 0, 0,
	8, 0, 0, 0,
	176, 1, 0, 0,
	8, 0, 0, 0,
	211, 1, 0, 0,
	8, 0, 0, 0,
	246, 1, 0, 0,
	8, 0, 0, 0,
	82, 0, 0, 0,    //第二行
	41, 0, 0, 0,
	117, 0, 0, 0,
	41, 0, 0, 0,
	152, 0, 0, 0,
	41, 0, 0, 0,
	187, 0, 0, 0,
	41, 0, 0, 0,
	222, 0, 0, 0,
	41, 0, 0, 0,
	1, 1, 0, 0,
	41, 0, 0, 0,
	36, 1, 0, 0,
	41, 0, 0, 0,
	71, 1, 0, 0,
	41, 0, 0, 0,
	106, 1, 0, 0,
	41, 0, 0, 0,
	141, 1, 0, 0,
	41, 0, 0, 0,
	176, 1, 0, 0,
	41, 0, 0, 0,
	211, 1, 0, 0,
	41, 0, 0, 0,
	246, 1, 0, 0,
	41, 0, 0, 0
};// This array will fix the janky offset of the tooltips
// s_aDefaultQKM_0
unsigned char Array_aDefaultQKM_0[] = {
	42, 0, 0, 0,
	82, 0, 0, 0,
	71, 0, 0, 0,
	73, 0, 0, 0, //4
	29, 0, 0, 0,
	83, 0, 0, 0,
	79, 0, 0, 0,
	81, 0, 0, 0, //8
	42, 0, 0, 0,
	82, 0, 0, 0,
	71, 0, 0, 0,
	73, 0, 0, 0, //12
	29, 0, 0, 0,
	83, 0, 0, 0,
	79, 0, 0, 0,
	81, 0, 0, 0, //16
	84, 0, 0, 0,
	85, 0, 0, 0,
	86, 0, 0, 0,
	87, 0, 0, 0, //20 
	88, 0, 0, 0,
	89, 0, 0, 0,
	29, 0, 0, 0,
	29, 0, 0, 0, //24
	29, 0, 0, 0,
	29, 0, 0, 0,
	29, 0, 0, 0,
};

unsigned char Array_Expanded[312] = {
	4, 4, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 2, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 3, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 5, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 6, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 7, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 8, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 10, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 11, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 12, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 13, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 14, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 15, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 16, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 17, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 23, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 24, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 25, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 26, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	4, 27, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	5, 50, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	5, 51, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	5, 52, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	5, 53, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0 };

unsigned char Array_Expanded_Testing_Cooldown_fix[312] = { 0 };

unsigned char cooldown_Array[124] = { 255, 255, 255, 255, 255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255,255, 255, 255, 255 };


// CODECAVES --- 
DWORD Array_aDefaultQKM_Address = (DWORD)&Array_aDefaultQKM;
DWORD Array_mystery_Address = (DWORD)&Array_Expanded;
DWORD Array_mystery_Address_plus = (DWORD)&Array_Expanded + 1;
DWORD cooldown_Array_Address = (DWORD)&cooldown_Array;
DWORD Array_Expanded_Testing_Cooldown_fix_Address = (DWORD)&Array_Expanded_Testing_Cooldown_fix;

DWORD CompareValidate_Retn = 0x8E244D;
_declspec(naked) void CompareValidateFuncKeyMappedInfo_cave()
{
	_asm
	{
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		jmp CompareValidate_Retn
			//push 0x8DD8BD;
			//ret;
	}
}

DWORD sub_9FA0CB_cave_retn_1 = 0x9FA0E1;
_declspec(naked) void sub_9FA0CB_cave()
{
	_asm {
		test eax, eax;
		jne label;
		push 0xD4;
		pushad;
		popad;
		// -> ZAllocEx<ZAllocAnonSelector>::Alloc(ZAllocEx<ZAllocAnonSelector>::_s_alloc, 0x44u);
		//push 0x9FA0E1;
		//ret;
		jmp sub_9FA0CB_cave_retn_1
			label :
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		// -> memset(this + 0xD20, 0, 0x60u);
		//push 0x8DD8BD;
		//ret;
		jmp CompareValidate_Retn
	}
}
//DWORD sDefaultQuickslotKeyMap_cave_retn = 0x72B7C2;
_declspec(naked) void sDefaultQuickslotKeyMap_cave()
{
	_asm {
		push ebx;
		push esi;
		push edi;
		xor edx, edx;
		mov ebx, ecx;
		call label;
		nop;
		lea edi, dword ptr ds : [ebx + 0x4] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		lea edi, dword ptr ds : [ebx + 0x6C] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		pop edi;
		pop esi;
		pop ebx;
		ret;
		// 0xBF8EE8
	label:
		push esi;
		mov esi, ecx;
		lea eax, dword ptr ds : [esi + 0x4] ;
		// -> _DWORD *__fastcall sub_72B7BC(_DWORD *a1)
		push 0x72B7C2;
		ret;
		//jmp sDefaultQuickslotKeyMap_cave_retn
	}
}
_declspec(naked) void DefaultQuickslotKeyMap_cave()
{
	_asm {
		push esi;
		push edi;
		lea eax, dword ptr ds : [ecx + 0x4] ;
		mov esi, Array_aDefaultQKM_Address;
		mov ecx, 0x1A;
		mov edi, eax;
		rep movsd;
		pop edi;
		pop esi;
		ret;
	}
}

_declspec(naked) void Restore_Array_Expanded() //Thank you Max  0x006282FC
{
	_asm {
		lea eax, [esi + 0344h]
		push esi
		push edi
		push ecx
		mov esi, [Array_Expanded_Testing_Cooldown_fix_Address]
		mov edi, Array_mystery_Address
		mov ecx, 78
		rep movsd
		pop ecx
		pop edi
		pop esi
		push 0x00628302;
		ret;
	}
}

DWORD keyMapDefaultRtn = 0x005BA216;   //start 0x005BA1C6
DWORD keyMap79Rtn = 0x005BA219;
unsigned int Array_keyMap_offset[] = {
	0xD6,
	0x19E,
	0x167,
	0x171, //4
	0xE,
	0x13,
	0x18,
	0x1D,//8
	0x22,
	0x27,
	0x2c,
	0x31, //12
	0x36,
	0x95, //----------------
	0x1A3,
	0x18F, //16
	0x199,
	0x54,
	0x59,
	0x5E, //20 
	0x63,
	0x68,
	0x6D,
	0x72, //24
	0x77,
	0x7C
};
unsigned int Array_keyMap_offset2[] = {
	0xD6,
	0x19E,
	0x167,
	0x171, //4
	0x54,
	0x59,
	0x5E,
	0x63, //8
	0x68,
	0x6D,
	0x72,
	0x77, //12
	0x7C,
	0x95, //----------------
	0x1A3,
	0x18F, //16
	0x199,
	0x9A,
	0x9F,
	0xA4, //20 
	0xA9,
	0xAE,
	0xB3,
	0xB8, //24
	0xBD,
	0xC2
};
unsigned int Array_keyMap_offset3[] = {
	0xD6,
	0x19E,
	0x167,
	0x171, //4
	0xE,
	0x13,
	0x18,
	0x1D,//8
	0x22,
	0x27,
	0x2c,
	0x31, //12
	0x36,
	0x95, //----------------
	0x1A3,
	0x18F, //16
	0x199,
	0x9A,
	0x9F,
	0xA4, //20 
	0xA9,
	0xAE,
	0xB3,
	0xB8, //24
	0xBD,
	0xC2
};
DWORD slotKeyMap = (DWORD)Array_keyMap_offset;
__declspec(naked) void DefaultQuickslotKeyMap79_cave()
{
	__asm {
		mov eax, [esp + 04]
		cmp eax, 25
		ja label_default
		push ebx
		mov ebx, slotKeyMap
		mov eax, [eax * 4 + ebx]
		lea eax, [ecx + eax]
		label_return :
		pop ebx
			jmp keyMap79Rtn
			label_default :
		jmp keyMapDefaultRtn
	}
}

__declspec(naked) void removeKeyToolTips()
{
	__asm {
		pushad
		pushfd
		mov eax, esp
		add eax, 0x24
		mov ebx, 0x008DCA25
		cmp[eax], ebx
		jne label_ret
		cmp[eax + 4], 0x5
		jne label_ret
		mov dword ptr[eax], 0x008DCB9A
		label_ret:
		popfd
			popad
			mov eax, 0x00AA203C
			push 0x005CAF37
			ret
	}
}
// 长键盘结束


DWORD fixDateFormatRtnAddr = 0x008EBF65;
__declspec(naked) void fixDateFormat() {
	__asm {
		movzx   ecx, word ptr[ebp - 16h]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ah]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ch]
		jmp fixDateFormatRtnAddr
	}
}
DWORD fixDateFormat2RtnAddr = 0x008EBFAF;
__declspec(naked) void fixDateFormat2() {
	__asm {
		movzx   ecx, word ptr[ebp - 16h]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ah]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ch]
		jmp fixDateFormat2RtnAddr
	}
}
DWORD fixDateFormat3RtnAddr = 0x008EC328;
__declspec(naked) void fixDateFormat3() {
	__asm {
		movzx   ecx, word ptr[ebp - 1Eh]
		push    ecx
		movzx   ecx, word ptr[ebp - 22h]
		push    ecx
		movzx   ecx, word ptr[ebp - 24h]
		jmp fixDateFormat3RtnAddr
	}
}
DWORD fixDateFormat4RtnAddr = 0x008EBF13;
__declspec(naked) void fixDateFormat4() {
	__asm {
		movzx   ecx, word ptr[ebp - 16h]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ah]
		push    ecx
		movzx   ecx, word ptr[ebp - 1Ch]
		jmp fixDateFormat4RtnAddr
	}
}

DWORD getItemType2Addr = 0x005CFAC2;
__declspec(naked) void getItemType1() {
	__asm {
		jmp getItemType2Addr
	}
}

DWORD getItemType2ErrRtnAddr = 0x005CFAA8;
DWORD getItemType2RtnAddr = 0x005CFADD;
__declspec(naked) void getItemType2() {
	__asm {
		dec eax
		jz label_eqp
		dec eax
		jz label_use
		dec eax
		jz label_ins
		dec eax
		jz label_etc
		dec eax
		jz label_cash
		jmp getItemType2ErrRtnAddr
		label_cash :
		push 0x159C
			jmp getItemType2RtnAddr
			label_etc :
		push 0x6DD
			jmp getItemType2RtnAddr
			label_ins :
		push 0x0B
			jmp getItemType2RtnAddr
			label_use :
		push 0x6E3
			jmp getItemType2RtnAddr
			label_eqp :
		push 0x6D9
			jmp getItemType2RtnAddr
	}
}

const DWORD back1 = 0x007888EC;
__declspec(naked) void customJumpCapHook1()
{
	__asm {
		cmp eax, Client::jumpCap
		jl label
		push Client::jumpCap
		pop eax
		label :
		mov edx, edi
			jmp[back1]
	}
}


const DWORD back2 = 0x008C9B41;
const DWORD back3 = 0x008C9B43;
__declspec(naked) void customJumpCapHook2()
{
	__asm {
		cmp eax, Client::jumpCap
		jle label
		push Client::jumpCap
		pop edi
		jmp[back3]
		label:
		jmp[back2]
	}
}

const DWORD back4 = 0x0095455D;
__declspec(naked) void customJumpCapHook3()
{
	__asm {
		push Client::jumpCap
		pop ecx
		cmp eax, ecx
		jmp[back4]
	}
}

const DWORD chatTextPosRtn = 0x008DD075;
__declspec(naked) void chatTextPos()
{
	__asm {
		add eax, [edi + 0CFCh]
		cmp[edi + 0D00h], 3
		jz label_type3
		cmp[edi + 0D00h], 2
		jz label_type2

		label_type1 :        // 状态1 收缩
		sub eax, 1
			jmp label_rtn

			label_type2 :        // 状态2 收缩 + 输入
		jmp label_rtn

			label_type3 :        // 状态3 展开
		sub eax, 2

			label_rtn :
			jmp chatTextPosRtn
	}
}

int curSpeed = 100;
double climbSpeedSave = 0;
void calcClimbSpeed() {
	int speed = curSpeed;
	//speed = speed < 80 ? 80 : speed;
	//speed = speed > Client::speedMovementCap ? Client::speedMovementCap : speed;

	double climbingSpeed = Client::climbSpeed;
	climbingSpeed = climbingSpeed <= 1.0 ? 1.0 : climbingSpeed;
	double curClimbSpeed = 3.0 * speed * climbingSpeed / 100;
	Memory::WriteDouble((DWORD)&climbSpeedSave, curClimbSpeed);
	//std::cout << "curClimbSpeed = " << speed << " " << curClimbSpeed << std::endl;
}

DWORD calcSpeedHookRtn = 0x00954558;
__declspec(naked) void calcSpeedHook()
{
	__asm {
		push eax
		mov eax, [ebp - 10h]
		mov curSpeed, eax
		call calcClimbSpeed
		pop eax
		cmp     eax, edi
		jg label_return
		mov     eax, edi

		label_return :
		jmp calcSpeedHookRtn
	}
}

DWORD calcSpeedHookRtn2 = 0x0095441C;
__declspec(naked) void calcSpeedHook2()
{
	__asm {
		push eax
		push ecx
		mov curSpeed, ebx
		call calcClimbSpeed
		pop ecx
		pop eax
		cmp     eax, edi
		jg label_return
		mov     eax, edi

		label_return :
		jmp calcSpeedHookRtn2
	}
}

DWORD faceRtn = 0x005FCF6C;
DWORD hairRtn = 0x005FCF3F;
DWORD faceHairCaveRtn = 0x005FCF09;
DWORD faceHairNpcRtn = 0x009B7EAB;
__declspec(naked) void faceHairCave()
{
	__asm {
		cmp  eax, 2
		jz label_face
		cmp  eax, 3
		jz label_hair
		cmp  eax, 4
		jz label_hair
		cmp  eax, 5
		jz label_face
		cmp  eax, 6
		jz label_hair

		jmp faceHairCaveRtn

		label_face :
		jmp faceRtn

			label_hair :
		jmp hairRtn
	}
}

// Face and Hair NPC Extension
__declspec(naked) void faceHairNpcCave() {
	__asm {
		cmp eax, 0x2
		je face_check
		cmp eax, 0x5
		je face_check
		cmp eax, 0x3
		je hair_check
		cmp eax, 0x4
		je hair_check
		cmp eax, 0x6
		je hair_check

		jmp skin_check

		face_check :
		mov eax, 0x0
			mov ecx, 0x0
			jmp return_point

			hair_check :
		mov eax, 0x1
			mov ecx, 0x1
			jmp return_point

			skin_check :
		mov eax, 0x2
			mov ecx, 0x2

			return_point :
			jmp DWORD PTR[faceHairNpcRtn]
	}
}

//WORLD MAP CENTER ON OPEN CODECAVE
const DWORD CodeCave_CWorldMapDlg__OnCreate_Return = 0x009F51FA;
__declspec(naked) void CodeCave_CWorldMapDlg__OnCreate()
{
	__asm {
		push    524; dialogue height
		push    666; dialogue width

		// push -> (screenHeight / 2) - 262
		mov        eax, [Resolution::m_nGameHeight]
		shr        eax, 1
		sub        eax, 262
		push    eax

		// push -> (screenWidth / 2) - 333
		mov        eax, [Resolution::m_nGameWidth]
		shr        eax, 1
		sub        eax, 333
		push    eax

		jmp        dword ptr[CodeCave_CWorldMapDlg__OnCreate_Return]
	}
}

DWORD canSendPkgTimeCaveRtn = 0x00485173;
__declspec(naked) void canSendPkgTimeCave()
{
	__asm {
		sub eax, [esi + 208Ch]
		cmp eax, 200
		jmp canSendPkgTimeCaveRtn
	}
}

DWORD apDetailBtnRtn = 0x008CA490;
int statDetailBtnX = 124;
__declspec(naked) void apDetailBtn()
{
	__asm {
		push 13Ah
		push statDetailBtnX
		jmp apDetailBtnRtn

	}
}

DWORD apAutoBtnRtn = 0x008CD3E3;
int statAutoBtnX = 97;
__declspec(naked) void apAutoBtn()
{
	__asm {
		push statAutoBtnX
		push 7D7h
		jmp apAutoBtnRtn

	}
}

int darkCircleX;
int darkCircleY;
constexpr DWORD darkMap1ccRtn = 0x0057645F;
__declspec(naked) void darkMap1cc() {
	__asm {
		add edx, darkCircleX
		add ecx, darkCircleY
		jmp darkMap1ccRtn
	}
}
constexpr DWORD darkMap2ccRtn = 0x005765FB;
__declspec(naked) void darkMap2cc() {
	__asm {
		add eax, darkCircleY
		push eax
		mov eax, [ebp - 3Ch]
		add eax, darkCircleX
		jmp darkMap2ccRtn
	}
}
constexpr DWORD darkMap3ccRtn = 0x00576742;
__declspec(naked) void darkMap3cc() {
	__asm {
		add eax, darkCircleY
		push edi
		push eax
		mov eax, [ebp - 3Ch]
		add eax, darkCircleX
		jmp darkMap3ccRtn
	}
}

int nSkillGuildX = 0;
int nSkillGuildY = 0;
__declspec(naked) void skillGuild() {
	__asm {
		push 600
		push 800
		push nSkillGuildY
		push nSkillGuildX
		push 0x008BB42D
		ret
	}
}

int nDiedDialogX = 252;
int nDiedDialogY = 97;
__declspec(naked) void diedDialog() {
	__asm {
		push nDiedDialogY
		push nDiedDialogX
		push 0x008A8FAE
		ret
	}
}

int nDoudouDialogX = 12;
int nDoudouDialogY = 100;
__declspec(naked) void doudouDialog() {
	__asm {
		push nDoudouDialogY
		push nDoudouDialogX
		mov ecx, esi
		push 0x006DED7B
		ret
	}
}

int nCollegeDialogX = 107;
int nCollegeDialogY = 111;
__declspec(naked) void collegeDialog() {
	__asm {
		push 0x242
		push nCollegeDialogY
		push nCollegeDialogX
		push 0x008210D7
		ret
	}
}

int nBarBackgrndWidth = 1008;
int nBarBackgrndOpenWidth = 1008;
int isInit = 1;
DWORD updateBarBackgrndWidthRet = 0x008E354F;
DWORD updateBarBackgrndWidthRet2 = 0x008E357D;  //未更新地址

__declspec(naked) void _updateBarBackgrndWidth()
{
	__asm {
		cmp[esi + 0xCBC], 0x1    //开关
		mov ebx, nBarBackgrndOpenWidth;
		jz label_jz
			mov ebx, nBarBackgrndWidth
			label_jz :
		mov eax, [0x00BDD6F0]
			mov eax, [eax]
			mov eax, [eax + 0xC70]
			mov eax, [eax + 0x40]
			mov eax, [eax + 0x24]
			mov[eax + 0x20], ebx
			ret
	}
}

__declspec(naked) void gameRect()
{
	__asm {
		push 0x0
		push 0x1
		push 0x80000000
		push 0x009FFF01
		ret
	}
}


int Resolution::D3Dptr = 0;

__declspec(naked) void SaveD3D()
{
	__asm {
		mov Resolution::D3Dptr, esi
		lea esi, [ebp - 0x40]
		pushad
		pushfd
		call Resolution::InitResolution
		mov eax, 0x009FFF02
		mov word ptr[eax], 0x00000438
		mov eax, 0x009FFF07
		mov word ptr[eax], 0x00000780
		mov eax, [0x00BE2788]
		mov eax, [eax]
		add eax, 0x20
		mov  word ptr[eax], 0x00000780
		add eax, 0x4
		mov  word ptr[eax], 0x00000438
		//mov eax, 0x007F7AD6
		//mov  word ptr[eax], 0x00000320
		popfd
		popad
		movsd
		movsd
		push 0x009EC60C
		ret
	}
}

__declspec(naked) void forcedWindowMode() {
	__asm {
		mov eax, 0x1
		neg eax
		sbb eax, eax
		inc eax
		push 0x009ED7E1
		ret
	}
}

__declspec(naked) void onWorldSelect() {
	__asm {
		mov eax, 0x005CAB91
		call eax
		pushad
		pushfd
		call Resolution::ResetResolution
		popfd
		popad
		cmp Client::SkipWorldSelect, 0x0
		je label_ret
		mov ecx, [0x00BDD8A0]
		mov ecx, [ecx]
		mov eax, [ecx]
		mov edx, 0x005BCDF4
		push 0x000007D3  //0x000007D0线路1
		call edx
		label_ret :
		mov edx, 0x005BB9C6
			jmp edx
	}
}

void _skipWorldSConnectError() {
	int x = 0;
	int y = 0;
	HWND hWnd = getMapleStoryHWND();
	if (hWnd) {
		RECT rect;
		GetWindowRect(hWnd, &rect);
		x = rect.left + Resolution::m_nGameWidth / 2;
		y = rect.top + Resolution::m_nGameHeight / 2;
		CloseHandle(hWnd);
	}
	MessageBoxPos(NULL, L"连接服务器失败", StringToWString(Client::ServerName).c_str(), MB_ICONERROR | MB_TOPMOST, x, y);
	std::abort();
}

DWORD sub_495C4A = 0x00495C4A;
__declspec(naked) void skipWorldSConnectError() {
	__asm {
		call sub_495C4A
		cmp eax, 0x0
		jne label_ret
		//call _skipWorldSConnectError
		mov dword ptr[ebp + 0x28], 0x12
		push eax
		mov eax, 0x00BDD6F4
		mov eax, [eax]
		cmp eax, ebx
		pop eax
		je label_dailog
		push 0x004948D5
		ret
		label_dailog :
		push 0x004948C6
			ret
			label_ret :
		push 0x004948C1
			ret
	}
}

__declspec(naked) void updateBarBackgrndWidth()
{
	__asm {
		cmp[esi + 0xD98], ebx
		je label_unUpdate
		pushfd
		call _updateBarBackgrndWidth
		popfd
		jmp updateBarBackgrndWidthRet
		label_unUpdate :
		mov eax, isInit
			cmp eax, 0x1
			jnz label_ret1
			call _updateBarBackgrndWidth
			mov isInit, 0x0
			label_ret1 :
			jmp updateBarBackgrndWidthRet2
	}
}

DWORD updateBarBackgrndaAnimationTimeRet = 0x008E3564;
__declspec(naked) void updateBarBackgrndaAnimationTime() {
	__asm {
		cmp[esi + 0xCBC], 0x1   //开关
		jz label_ret1
		cmp eax, 0x0
		jmp updateBarBackgrndaAnimationTimeRet
		label_ret1 :
		cmp eax, 0x190
			jmp updateBarBackgrndaAnimationTimeRet
	}
}

DWORD updateBarBackgrndaInitCall = 0x00A6FC7C;
DWORD updateBarBackgrndaInitRet = 0x008D50D2;
__declspec(naked) void updateBarBackgrndaInit() {
	__asm {
		mov isInit, 0x1
		call updateBarBackgrndaInitCall
		jmp updateBarBackgrndaInitRet
	}
}

VOID __fastcall sentOutPacket(COutPacket* c) {
	try {
		CClientSocket::GetInstance()->SendPacket(c);
	}
	catch (...) {
	}
}

VOID __fastcall  sentUnlockPacket() {
	auto cOutPacket = COutPacket(0x104);
	sentOutPacket(&cOutPacket);
}

__declspec(naked) void unlockPacket() {
	__asm {
		call sentUnlockPacket
		ret
	}
}

DWORD doubleJumpRtn = 0x00955F56;
DWORD keyJump = 0x00952F1F;
DWORD skill = 0x00974307;
__declspec(naked) void doubleJump()
{
	__asm {
		call keyJump
		push 0
		push edi
		push 0x003EBA9E  //4111006
		mov  ecx, ebx
		call skill
		jmp doubleJumpRtn

	}
}

DWORD upDoubleJumpRet = 0x00979911;
__declspec(naked) void upDoubleJump()
{
	__asm {
		push eax
		mov ecx, 0x00BDD838
		mov ecx, [ecx]
		push 38
		mov eax, 0x005CAAA9
		call eax
		test eax, 0x1
		pop eax
		jne label_up
		mov ecx, 0xFFFFFF06
		sub ecx, eax
		jmp label_ret
		label_up :
		mov eax, 0
			mov[ebp + 0x0C], eax
			mov ecx, 0xFFFFFC00
			label_ret :
			jmp upDoubleJumpRet
	}
}

int currentSkillId = 0;

DWORD sub_A70F94 = 0x00A70F94;
__declspec(naked) void skill2221006()
{
	__asm {
	lablel_loop:
		fild dword ptr[esi]
			fmul st(0), st(1)
			call sub_A70F94
			cmp currentSkillId, 0x21E3CE
			je label_je
			mov[esi], eax
			label_je :
		add esi, 0x4
			dec edi
			jne lablel_loop
			push 0x00769408
			ret
	}
}

__declspec(naked) void skill2221006_2()  //save skill id
{
	__asm {
		mov currentSkillId, eax
		cmp eax, 0x0021E3CE
		push 0x0076937B
		ret
	}
}

__declspec(naked) void skill2100NoMove()
{
	__asm {
		push ebx
		mov ebx, [edi + 0x2908]
		cmp ebx, 0x1406F40    //21000000
		jl label_ret
		cmp ebx, 0x141F5E2    //21100002 ignore
		je label_ret
		cmp ebx, 0x14247F0    //21121008
		jg label_ret
		pop ebx
		push 0x00955592
		ret
		label_ret :
		pop ebx
			cmp[edi + 0x290C], ebx
			push 0x009553F6
			ret
	}
}

//DWORD skill4221001Rtn = 0x00975478;
//__declspec(naked) void skill4221001()   //0x00975369
//{
//	__asm {
//		pushfd
//		cmp eax, 0x1
//		jne label_ret
//		push eax
//		mov eax, 0x0097642E
//		mov byte ptr[eax], 0xEB
//		pop eax
//		label_ret :
//		popfd
//			jmp skill4221001Rtn
//
//	}
//}

DWORD _tamingMob198 = 0x00407A53;
DWORD _tamingMob198_Rtn = 0x00407A51;
__declspec(naked) void tamingMob198()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn
		label_j :
		jmp _tamingMob198
	}
}

DWORD _tamingMob198_1 = 0x004140DD;
DWORD _tamingMob198_Rtn1 = 0x00413FB1;
__declspec(naked) void tamingMob198_1()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn1
		label_j :
		jmp _tamingMob198_1
	}
}

DWORD _tamingMob198_2 = 0x0041439C;
DWORD _tamingMob198_Rtn2 = 0x00414381;
__declspec(naked) void tamingMob198_2()
{
	__asm {
		cmp dword ptr[ebp - 0x48], 0xC1
		jz label_j
		cmp dword ptr[ebp - 0x48], 0xC6
		jmp _tamingMob198_Rtn2
		label_j :
		jmp _tamingMob198_2
	}
}

DWORD _tamingMob198_3 = 0x0045193F;
DWORD _tamingMob198_Rtn3 = 0x0045193A;
__declspec(naked) void tamingMob198_3()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn3
		label_j :
		jmp _tamingMob198_3
	}
}

DWORD _tamingMob198_4 = 0x004527A6;
DWORD _tamingMob198_Rtn4 = 0x004527A4;
__declspec(naked) void tamingMob198_4()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn4
		label_j :
		jmp _tamingMob198_4
	}
}

DWORD _tamingMob198_5 = 0x0045281B;
DWORD _tamingMob198_Rtn5 = 0x00452815;
__declspec(naked) void tamingMob198_5()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn5
		label_j :
		jmp _tamingMob198_5
	}
}

DWORD _tamingMob198_6 = 0x00452C63;
DWORD _tamingMob198_Rtn6 = 0x00452C61;
__declspec(naked) void tamingMob198_6()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn6
		label_j :
		jmp _tamingMob198_6
	}
}

DWORD _tamingMob198_7 = 0x00454522;
DWORD _tamingMob198_Rtn7 = 0x00454520;
__declspec(naked) void tamingMob198_7()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jz label_j
		cmp eax, 0x12D
		jmp _tamingMob198_Rtn7
		label_j :
		jmp _tamingMob198_7
	}
}

DWORD _tamingMob198_8 = 0x004545E1;
DWORD _tamingMob198_Rtn8 = 0x00454548;
__declspec(naked) void tamingMob198_8()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn8
		label_j :
		jmp _tamingMob198_8
	}
}

DWORD _tamingMob198_9 = 0x00454606;
DWORD _tamingMob198_Rtn9 = 0x00454604;
__declspec(naked) void tamingMob198_9()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn9
		label_j :
		jmp _tamingMob198_9
	}
}

DWORD _tamingMob198_10 = 0x0045463C;
DWORD _tamingMob198_Rtn10 = 0x00454636;
__declspec(naked) void tamingMob198_10()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn10
		label_j :
		jmp _tamingMob198_10
	}
}

DWORD _tamingMob198_11 = 0x004546D7;
DWORD _tamingMob198_Rtn11 = 0x004546D5;
__declspec(naked) void tamingMob198_11()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn11
		label_j :
		jmp _tamingMob198_11
	}
}

DWORD _tamingMob198_12 = 0x00454762;
DWORD _tamingMob198_Rtn12 = 0x00454760;
__declspec(naked) void tamingMob198_12()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn12
		label_j :
		jmp _tamingMob198_12
	}
}

DWORD _tamingMob198_13 = 0x004549A7;
DWORD _tamingMob198_Rtn13 = 0x004549A1;
__declspec(naked) void tamingMob198_13()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn13
		label_j :
		jmp _tamingMob198_13
	}
}

DWORD _tamingMob198_14 = 0x00456567;
DWORD _tamingMob198_Rtn14 = 0x00456540;
__declspec(naked) void tamingMob198_14()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn14
		label_j :
		jmp _tamingMob198_14
	}
}

DWORD _tamingMob198_15 = 0x004B1BEA;
DWORD _tamingMob198_Rtn15 = 0x004B1B91;
__declspec(naked) void tamingMob198_15()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn15
		label_j :
		jmp _tamingMob198_15
	}
}

DWORD _tamingMob198_16 = 0x0066FB25;
DWORD _tamingMob198_Rtn16 = 0x0066FB23;
__declspec(naked) void tamingMob198_16()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn16
		label_j :
		jmp _tamingMob198_16
	}
}

DWORD _tamingMob198_17 = 0x0066FCB1;
DWORD _tamingMob198_Rtn17 = 0x0066FCAB;
__declspec(naked) void tamingMob198_17()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn17
		label_j :
		jmp _tamingMob198_17
	}
}

DWORD _tamingMob198_18 = 0x007AAA5E;
DWORD _tamingMob198_Rtn18 = 0x007AAA55;
__declspec(naked) void tamingMob198_18()
{
	__asm {
		inc     eax
		test    eax, eax
		jnz label_j
		mov     eax, [ebp - 0E6Ch]
		cdq
		mov     ecx, 0x2710
		idiv    ecx
		sub     eax, 0xC6
		neg     eax
		sbb     eax, eax
		inc     eax
		test    eax, eax
		jnz label_j
		jmp _tamingMob198_Rtn18
		label_j :
		jmp _tamingMob198_18
	}
}

DWORD _tamingMob198_19 = 0x008C9EF8;
DWORD _tamingMob198_Rtn19 = 0x008C9EF6;
__declspec(naked) void tamingMob198_19()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn19
		label_j :
		jmp _tamingMob198_19
	}
}

DWORD _tamingMob198_20 = 0x008C9F62;
DWORD _tamingMob198_Rtn20 = 0x008C9F60;
__declspec(naked) void tamingMob198_20()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn20
		label_j :
		jmp _tamingMob198_20
	}
}

DWORD _tamingMob198_21 = 0x0093A8EE;
DWORD _tamingMob198_Rtn21 = 0x0093A8E8;
__declspec(naked) void tamingMob198_21()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn21
		label_j :
		jmp _tamingMob198_21
	}
}

DWORD _tamingMob198_22 = 0x0093CEE4;
DWORD _tamingMob198_Rtn22 = 0x0093CEDE;
__declspec(naked) void tamingMob198_22()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn22
		label_j :
		jmp _tamingMob198_22
	}
}

DWORD _tamingMob198_23 = 0x0094231F;
DWORD _tamingMob198_Rtn23 = 0x00942214;
__declspec(naked) void tamingMob198_23()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn23
		label_j :
		jmp _tamingMob198_23
	}
}

DWORD _tamingMob198_24 = 0x00964959;
DWORD _tamingMob198_Rtn24 = 0x00964953;
__declspec(naked) void tamingMob198_24()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn24
		label_j :
		jmp _tamingMob198_24
	}
}

DWORD _tamingMob198_25 = 0x0096CA59;
DWORD _tamingMob198_25_2 = 0x0096CA57;
DWORD _tamingMob198_Rtn25 = 0x0096CA55;
__declspec(naked) void tamingMob198_25()
{
	__asm {
		cmp eax, ebx
		jz label_j
		cmp eax, 0xC6
		jz label_j
		xor eax, eax
		jmp _tamingMob198_25_2
		label_j :
		jmp _tamingMob198_25
	}
}

DWORD _tamingMob198_26 = 0x00974539;
DWORD _tamingMob198_Rtn26 = 0x009746D2;
__declspec(naked) void tamingMob198_26()
{
	__asm {
		cmp eax, 0xC1
		jz label_j2
		cmp eax, 0xC6
		jz label_j2
		jmp label_allow
		label_j2 :
		mov eax, 0x003EBA9E    //允许二段跳
			cmp eax, esi
			jz label_allow
			mov eax, 0x00200F0A    //允许瞬移
			cmp eax, esi
			jz label_allow
			mov eax, 0x002195AA
			cmp eax, esi
			jz label_allow
			mov eax, 0x00231C49
			cmp eax, esi
			jz label_allow
			mov eax, 0x00B8A58B
			cmp eax, esi
			jz label_allow
			jmp label_reject
			label_allow :
		jmp _tamingMob198_Rtn26
			label_reject :
		jmp _tamingMob198_26
	}
}

DWORD _tamingMob198_27 = 0x00A12B39;
DWORD _tamingMob198_Rtn27 = 0x00A129F3;
__declspec(naked) void tamingMob198_27()
{
	__asm {
		cmp dword ptr[ebp - 0x10], 0xC1
		jz label_j
		cmp dword ptr[ebp - 0x10], 0xC6
		jmp _tamingMob198_Rtn27
		label_j :
		jmp _tamingMob198_27
	}
}

DWORD _tamingMob198_28 = 0x0096CA98;
DWORD _tamingMob198_Rtn28 = 0x0096CAC3;
__declspec(naked) void tamingMob198_28()
{
	__asm {
		cmp eax, ebx
		jz label_j
		cmp eax, 0xC6
		jnz label_j2
		label_j :
		lea eax, [ebp - 0x14]
			jmp _tamingMob198_28
			label_j2 :
		jmp _tamingMob198_Rtn28
	}
}

DWORD _tamingMob198_29 = 0x00413E43;
DWORD _tamingMob198_Rtn29 = 0x00413E41;
__declspec(naked) void tamingMob198_29()
{
	__asm {
		cmp eax, 0xC1
		jz label_j
		cmp eax, 0xC6
		jmp _tamingMob198_Rtn29
		label_j :
		jmp _tamingMob198_29
	}
}

DWORD _tamingMob198_30 = 0x005FD208;
DWORD _tamingMob198_Rtn30 = 0x005FD1C0;
__declspec(naked) void tamingMob198_30()
{
	__asm {
		jz label_j
		dec ecx
		dec ecx
		jz label_j
		dec ecx
		dec ecx
		dec ecx
		dec ecx
		dec ecx
		jz label_j
		jmp _tamingMob198_Rtn30
		label_j :
		jmp _tamingMob198_30
	}
}

__declspec(naked) void screenShotPath()
{
	__asm {
		mov eax, Client::ScreenShotPath
		sub eax, edi
		push 0x00751ADE
		ret
	}
}

__declspec(naked) void fixSomeEuipmentNotCanvasCrash()
{
	__asm {
		cmp edi, 0
		je label_exit
		mov ax, [edi]
		test ax, ax
		label_exit :
		push 0x00401D58
			ret
	}
}

__declspec(naked) void fExit()
{
	__asm {
		mov fs : [00000000] , ecx
		pop ebx
		leave
		call std::abort
		retn 0x10
	}
}

DWORD sub_A73600 = 0x00A73600;
__declspec(naked) void onExit()
{
	__asm {
		mov Client::exit, 0x1
		call sub_A73600
		push 0x00A73561
		ret
	}
}

DWORD sub_49470D = 0x0049470D;
__declspec(naked) void changerPort()
{
	__asm {
		mov ebp, Client::serverIP_Port
		mov[esp + 0x4], ebp
		call sub_49470D
		push 0x0075F18B;
		ret
	}
}

__declspec(naked) void setAtkOutCapPannelMax()
{
	__asm {
		cmp ebx, 0x0
		jge label_ret
		push 0x7FFFFFFF
		pop ebx
		label_ret :
		cmp ebx, eax
			push 0x008C8BCA;
		ret
	}
}
