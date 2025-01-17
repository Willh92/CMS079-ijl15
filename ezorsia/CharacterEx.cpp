#include "stdafx.h"
#include "CharacterEx.h"
#include <string>
#include<iostream>
#include<fstream>
#include<sstream>

/*
	character data extension class. stores exp for now.
	will eventually store meso and maybe level if im feeling like i dont want a life for a month
*/
struct CharacterDataEx
{
private:
	static CharacterDataEx* m_pInstance;
public:
	LONGLONG m_liExp;
	LONGLONG m_liExpMsg;
	short m_liLevel;
	short m_liLevelCharInfo;
	tsl::robin_map<int, short> h_liLevel;

	CharacterDataEx()
	{
		/* setting default value as proof of concept. can be removed. */
		m_liExp = 0;
		m_liExpMsg = 0;
	}

	BYTE GetCharLevel();

	static CharacterDataEx* GetInstance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CharacterDataEx();
		}

		return m_pInstance;
	}
};


CharacterDataEx* CharacterDataEx::m_pInstance;
int CharacterEx::m_loginUserId = 0;
int CharacterEx::m_maxHp = 0;
int CharacterEx::m_maxMp = 0;
tsl::robin_map<int, int> CharacterEx::h_userSkin;

LONGLONG myArrayForCustomEXP[] = { 15, 15, 34, 57, 92, 135, 372, 560, 840, 1144, 1242, 1573, 2144, 2800, 3640, 4700, 5893, 7360, 9144, 11120, 13477, 16268, 19320, 22880, 27008, 31477, 36600, 42444, 48720, 55813, 63800, 86784, 98208, 110932, 124432, 139372, 155865, 173280, 192400, 213345, 235372, 259392, 285532, 312928, 342624, 374760, 408336, 445544, 483532, 524160, 567772, 598886, 631704, 666321, 702836, 741351, 781976, 824828, 870028, 917625, 967995, 1021041, 1076994, 1136013, 1198266, 1263930, 1333194, 1406252, 1483314, 1564600, 1650340, 1740778, 1836173, 1936794, 2042930, 2154882, 2272970, 2397528, 2528912, 2667496, 2813674, 2967863, 3130502, 3302053, 3483005, 3673873, 3875201, 4087562, 4311559, 4547832, 4797053, 5059931, 5337215, 5629694, 5938202, 6263614, 6606860, 6968915, 7350811, 7753635, 8178534, 8626718, 9099462, 9598112, 10124088, 10678888, 11264090, 11881362, 12532461, 13219239, 13943653, 14707765, 15513750, 16363902, 17260644, 18206527, 19204245, 20256637, 21366700, 22537594, 23772654, 25075395, 26449526, 27898960, 29427822, 31040466, 32741483, 34535716, 36428273, 38424542, 40530206, 42751262, 45094030, 47565183, 50171755, 52921167, 55821246, 58880250, 62106888, 65510344, 69100311, 72887008, 76881216, 81094306, 85594273, 90225770, 95170142, 100385466, 105886589, 111689174, 117809740, 124265714, 131075474, 138258410, 145834970, 153826726, 162256430, 171148082, 180526997, 190419876, 200854885, 211861732, 223471711, 223471711, 248635353, 262260570, 276632449, 291791906, 307782102, 324648562, 342439302, 361204976, 380999008, 401877754, 423900654, 447130410, 471633156, 497478653, 524740482, 553496261, 583827855, 615821622, 649568646, 685165008, 722712050, 762316670, 804091623, 848155844, 894634784, 943660770, 995373379, 1049919840, 1107455447, 1168144006, 1232158297, 1299680571, 1370903066, 1446028554, 1525246918, 1608855764, 1697021059, 2207026470L, 2471869646L, 2768494003L, 3100713283L, 3472798876L, 3889534741L,
			4356278909L, 4879032378L, 5464516263L, 6120258214L, 7956335678L, 8831532602L,
			9803001188L, 10881331318L, 12078277762L, 15701761090L, 17114919588L, 18655262350L,
			20334235961L, 22164317197L, 28813612356L, 30830565220L, 32988704785L, 35297914119L,
			37768768107L, 49099398539L, 52536356436L, 56213901386L, 60148874483L, 64359295696L,
			83667084404L, 86177096936L, 88762409844L, 91425282139L, 94168040603L, 122418452783L,
			126091006366L, 129873736556L, 133769948652L, 137783047111L, 179117961244L,
			184491500081L, 190026245083L, 195727032435L, 201598843408L, 262078496430L,
			269940851322L, 278039076861L, 286380249166L, 294971656640L, 442457484960L, 1042457484960L, 2042457484960L, 3042457484960L, 4042457484960L };

const LONGLONG maxLevelForCustomEXP = sizeof(myArrayForCustomEXP);

LONGLONG get_next_level_exp()
{
	BYTE lvl = CharacterDataEx::GetInstance()->GetCharLevel();

	if (lvl >= sizeof(myArrayForCustomEXP) / sizeof(myArrayForCustomEXP[0])) return 0;

	return myArrayForCustomEXP[lvl];
}

BYTE CharacterDataEx::GetCharLevel()
{

	auto CUserLocal__GetCharacterLevel = (BYTE(__fastcall*)(PVOID pThis, PVOID edx))0x00950DE3;

	PVOID CUserLocal__ms_pInstance = *reinterpret_cast<void**>(0x00BD9028);

	return CUserLocal__GetCharacterLevel(CUserLocal__ms_pInstance, NULL);
}

char* __cdecl itoa_ExpSwap(int value, PCHAR buffer, int radix)
{
	_i64toa_s(CharacterDataEx::GetInstance()->m_liExp, buffer, 64, radix);
	// TODO abbreviate large numbers to something like 14.123B or something -- maybe make toggleable through some UI setting??
	return buffer;
}

LPWSTR __cdecl _itoa_LevelSwap(int value, LPWSTR lpWideCharStr, int radix)
{
	CHAR MultiByteStr[64];
	_itoa_s(CharacterDataEx::GetInstance()->m_liLevel, MultiByteStr, strlen(MultiByteStr), radix);
	MultiByteToWideChar(0, 1u, MultiByteStr, -1, lpWideCharStr, 20);
	return lpWideCharStr;
}

int level = 1;
void getlevel() {
	level = CharacterDataEx::GetInstance()->m_liLevel;
}

void getlevel2(void* esi) {
	int userId = reinterpret_cast<int>(esi);
	CharacterEx::m_loginUserId = userId;
	CharacterDataEx::GetInstance()->m_liLevel = CharacterDataEx::GetInstance()->h_liLevel[userId];
}

const DWORD itoa_LevelSwapRetn = 0x0063458C;
__declspec(naked) void itoa_LevelSwap() {
	__asm {
		pushad
		pushfd
		push[esi]
		call getlevel2
		pop esi
		popfd
		popad
		call _itoa_LevelSwap
		jmp dword ptr[itoa_LevelSwapRetn]
	}
}

/* all arguments passed on the stack despite being a member function */
void __cdecl FormatExpString_Hook(ZXString<char>* pThis, const char* originalstring, int curexp, int nextlevelexp)
{
	std::string s = std::to_string(CharacterDataEx::GetInstance()->m_liExp);
	s.append(" / ");
	s.append(std::to_string(get_next_level_exp()));

	pThis->Assign(s.c_str(), s.length());
}

void __cdecl FormatExpMsgString_Hook(ZXString<char>* pThis, const char* originalstring, int expmsg)
{
	std::stringstream ss;
	ss << "得到经验值(+";
	ss << CharacterDataEx::GetInstance()->m_liExpMsg;
	ss << ")";
	std::string s = ss.str();

	pThis->Assign(s.c_str(), s.length());
}

typedef void* (__cdecl* _lpfn_NextLevel_t)(int[]);
static auto _lpfn_NextLevel = reinterpret_cast<_lpfn_NextLevel_t>(0x00793711);


auto CUIStatusBar__SetNumberValue_t = (void(__thiscall*)(void*, int, int, int, int, int, int, int))0x008DD003;
void __fastcall CUIStatusBar__SetNumberValue_Hook(void* pThis, void* edx, int hp, int hpMax, int mp, int mpMax, int exp, int expMax, int tempExp)
{
	LONGLONG liExp = CharacterDataEx::GetInstance()->m_liExp;
	LONGLONG liExpMax = get_next_level_exp();

	/* this adjusts the exp bar gauge -- idk how else to do this lmao, we're essentially scaling the exp down until itll fit in the data type */
	while (liExpMax > INT_MAX || liExp > INT_MAX)
	{
		liExp >>= 2;
		liExpMax >>= 2;
	}

	exp = liExp;
	expMax = liExpMax;
	CharacterEx::m_maxHp = hpMax;
	CharacterEx::m_maxMp = mpMax;

	if (hp > hpMax) {
		hpMax = hp;
	}

	if (mp > mpMax) {
		mpMax = mp;
	}

	CUIStatusBar__SetNumberValue_t(pThis, hp, hpMax, mp, mpMax, exp, expMax, tempExp);
}

void* __fastcall _lpfn_NextLevel_Hook(LONGLONG expTable[maxLevelForCustomEXP])	 //your max level is the size of your array 
{
	memcpy(expTable, myArrayForCustomEXP, maxLevelForCustomEXP);	//ty to creator of github.com/PurpleMadness/CustomExpTable
	expTable[maxLevelForCustomEXP] = 0;	//insert your own formula or predefined array into this part. MUST MATCH server numbers
	return expTable;					//currently using predefined array	
}

int __fastcall ExpSwap__Decode4To8msg(CInPacket* pThis, void* edx)
{
	LONGLONG liExpMsg;

	pThis->DecodeBuffer(&liExpMsg, sizeof(liExpMsg));

	CharacterDataEx::GetInstance()->m_liExpMsg = liExpMsg;

	return liExpMsg < INT_MAX ? (INT)liExpMsg : INT_MAX;
}

int __fastcall ExpSwap__Decode4To8(CInPacket* pThis, void* edx)
{
	LONGLONG liExp;

	pThis->DecodeBuffer(&liExp, sizeof(liExp));

	CharacterDataEx::GetInstance()->m_liExp = liExp;

	return liExp < INT_MAX ? (INT)liExp : INT_MAX;
}

char __fastcall LevelSwap__Decode1To2(CInPacket* pThis, void* edx)
{
	short level = pThis->Decode2();

	CharacterDataEx::GetInstance()->m_liLevel = level;

	return level < UCHAR_MAX ? (char)level : UCHAR_MAX;
}

char __fastcall LevelSwapOnCharacterInfo__Decode1To2(CInPacket* pThis, void* edx)
{
	short level = pThis->Decode2();

	CharacterDataEx::GetInstance()->m_liLevelCharInfo = level;

	return level < UCHAR_MAX ? (char)level : UCHAR_MAX;
}

const char* __fastcall LevelOnCharacterInfoStr(ZXString<char>* pThis, PVOID edx)
{
	std::string s = std::to_string(CharacterDataEx::GetInstance()->m_liLevelCharInfo);

	pThis->Assign(s.c_str(), s.length());
}

const char* __fastcall ZXString__GetConstCharString(ZXString<char>* pThis, PVOID edx)
{
	std::ostringstream oss;

	oss << CharacterDataEx::GetInstance()->m_liExp;

	char pencent[64];
	float value = std::floor((double)CharacterDataEx::GetInstance()->m_liExp / get_next_level_exp() * 10000) / 100;
	sprintf_s(pencent, " (%.2f%%)", min(value, 100.0f));

	oss << pencent;

	std::string s = oss.str();

	pThis->Assign(s.c_str(), s.length());

	return static_cast<const char*>(*pThis);
}

const char* __fastcall ZXString_LevelString(ZXString<char>* pThis, PVOID edx)
{
	std::string s = std::to_string(CharacterDataEx::GetInstance()->m_liLevel);

	pThis->Assign(s.c_str(), s.length());

	return static_cast<const char*>(*pThis);
}

void putLevel(void* esi) {
	int addr = reinterpret_cast<int>(esi);
	CharacterDataEx::GetInstance()->h_liLevel[addr] = CharacterDataEx::GetInstance()->m_liLevel;
}

const DWORD sub_429411 = 0x00429411;
const DWORD drawLevelStringRetn = 0x008DCE4B;
__declspec(naked) void drawLevelString() {
	__asm {
		call sub_429411
		call getlevel
		push level
		jmp dword ptr[drawLevelStringRetn]
	}
}

const DWORD characterLevelStatDecodeRetn = 0x004F2269;
__declspec(naked) void characterLevelStatDecode() {
	__asm {
		call LevelSwap__Decode1To2
		pushad
		pushfd
		push[esi]
		call putLevel
		pop esi
		popfd
		popad
		jmp dword ptr[characterLevelStatDecodeRetn]
	}
}

typedef std::vector<std::string>  StringList;
StringList splitstr(const std::string& str, const std::string& pattern)
{
	StringList  li;
	std::string subStr;
	std::string tPattern;
	size_t      patternLen = pattern.length();
	size_t      strLen = str.length();

	for (size_t i = 0; i < str.length(); i++)
	{
		if (pattern[0] == str[i] && ((strLen - i) >= patternLen))
		{
			if (memcmp(&pattern[0], &str[i], patternLen) == 0)
			{
				i += patternLen - 1;
				if (!subStr.empty())
				{
					li.push_back(subStr);
					subStr.clear();
				}
			}
			else
			{
				subStr.push_back(str[i]);
			}
		}
		else
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty())
	{
		li.push_back(subStr);
	}

	return li;
}

unsigned char* __fastcall _userName_Decode(CInPacket* pThis, void* edx, void* esi, ZXString<char>* p)
{
	int userId = reinterpret_cast<int>(esi);
	unsigned char* result = pThis->DecodeStr(p);

	const char* name = static_cast<const char*>(*p);

	std::string s = name;

	StringList res = splitstr(s, "$$");
	if (res.size() == 2) {
		if (res[0] == "#") {
			p->Empty();
		}
		else {
			p->Assign(res[0].c_str(), res[0].length());
		}
		int skin = std::stoi(res[1]);
		//std::cout << pThis << " " << res.size() << " user:" << userId << " skin:" << skin << std::endl;
		CharacterEx::h_userSkin[userId] = skin;
	}
	return result;
}

const DWORD GuildNameDecodeRet = 0x0098CE63;
__declspec(naked) void GuildNameDecode() {
	__asm {
		push[eax + 1Ch]
		call _userName_Decode
		jmp dword ptr[GuildNameDecodeRet]
	}
}

int __UserRemoteID = 0;
int __fastcall CUserPoolOnUserRemotePacket_DecodeID(CInPacket* pThis, void* edx)
{

	__UserRemoteID = pThis->Decode4();

	return __UserRemoteID;
}

int __fastcall OnUserLeave_DecodeID(CInPacket* pThis, void* edx)
{

	int userId = pThis->Decode4();

	CharacterEx::h_userSkin.erase(userId);

	return userId;
}

const DWORD GuildNameDecodeRet2 = 0x009912EC;
__declspec(naked) void GuildNameDecode2() {
	__asm {
		push[__UserRemoteID]
		call _userName_Decode
		jmp dword ptr[GuildNameDecodeRet2]
	}
}

void __fastcall _CharacterStatSkin(CInPacket* pThis, void* edx, int userId)
{
	CharacterEx::h_userSkin[userId] = pThis->Decode4();
}

const DWORD CharacterStatSkinRet = 0x004F28BB;
__declspec(naked) void CharacterStatSkin() {
	__asm {
		test byte ptr[ebp + 0x0A], 0x40
		je label_ret
		mov ecx, edi
		push[esi]
		call _CharacterStatSkin
		label_ret :
		mov eax, [ebp + 0x08]
			pop edi
			pop esi
			pop ebx
			pop ebp
			jmp dword ptr[CharacterStatSkinRet]
	}
}

void __fastcall _exitcleart() {
	CharacterEx::h_userSkin.clear();
	CharacterDataEx::GetInstance()->h_liLevel.clear();
}

_declspec(naked) void exitCleart()
{
	_asm {
		lea eax, [esi + 358h]
		pushad
		pushfd
		call _exitcleart
		popfd
		popad
		push 0x00628318
		ret
	}
}

void __fastcall _changerMapCleart() {
	int skin = -1;
	if (CharacterEx::h_userSkin.find(CharacterEx::m_loginUserId) != CharacterEx::h_userSkin.end())
		skin = CharacterEx::h_userSkin[CharacterEx::m_loginUserId];
	int level = -1;
	if (CharacterDataEx::GetInstance()->h_liLevel.find(CharacterEx::m_loginUserId) != CharacterDataEx::GetInstance()->h_liLevel.end())
		level = CharacterDataEx::GetInstance()->h_liLevel[CharacterEx::m_loginUserId];
	_exitcleart();
	if (skin > 0) {
		CharacterEx::h_userSkin[CharacterEx::m_loginUserId] = skin;
	}
	if (level > 0) {
		CharacterDataEx::GetInstance()->h_liLevel[CharacterEx::m_loginUserId] = level;
	}
}

const DWORD changerMapCleartOrginCall = 0x00666186;
_declspec(naked) void changerMapCleart()
{
	_asm {
		pushad
		pushfd
		call _changerMapCleart
		popfd
		popad
		call changerMapCleartOrginCall
		push 0x005348FF
		ret
	}
}

int hypontizeId = 0;
const DWORD hypontizeCInpacket__Decode4 = 0x004066FF;
const DWORD hypontize_INT128__operator_bool = 0x00884E00;
_declspec(naked) void hookHypontizePacket()
{
	_asm {
		mov hypontizeId, 0x0
		call hypontizeCInpacket__Decode4
		cmp eax, -1
		jnz label_ret
		call hypontizeCInpacket__Decode4
		mov hypontizeId, eax
		call hypontizeCInpacket__Decode4
		label_ret :
		ret
	}
}

_declspec(naked) void hookHypontizeSet()
{
	_asm {
		call hypontize_INT128__operator_bool
		test al, al
		push ebx
		jz label_ret
		mov ebx, [hypontizeId]
		cmp ebx, 0x0
		je label_ret
		mov ebx, 0x00BE4F14
		mov ebx, [ebx]
		cmp ebx, [hypontizeId]
		je label_ret
		mov eax, 0x0
		label_ret :
		pop ebx
			ret
	}
}

_declspec(naked) void hookHypontizeCancel()
{
	_asm {
		call hypontize_INT128__operator_bool
		test al, al
		push ebx
		jz label_ret
		mov ebx, 0x00BDD49C
		mov ebx, [ebx]
		cmp ebx, 0x0
		je label_ret
		add ebx, 0x68
		mov ebx, [ebx]
		cmp ebx, esi
		je label_ret
		mov eax, 0x0
		label_ret :
		pop ebx
			ret
	}
}

__declspec(naked) void fixMaxHP() {
	__asm {
		push 0x0A
		push eax
		push CharacterEx::m_maxHp
		push 0x008DF657
		ret
	}
}

__declspec(naked) void fixMaxMp() {
	__asm {
		push 0x0A
		push eax
		push CharacterEx::m_maxMp
		push 0x008DF982
		ret
	}
}

void CharacterEx::InitExpOverride(BOOL bEnable)
{
	Memory::SetHook(true, reinterpret_cast<void**>(&CUIStatusBar__SetNumberValue_t), CUIStatusBar__SetNumberValue_Hook);
	Memory::CodeCave(fixMaxHP, 0x008DF651, 6);
	Memory::CodeCave(fixMaxMp, 0x008DF97C, 6);
	if (!bEnable)
		return;
	Memory::CodeCave(changerMapCleart, 0x005348FA, 5);
	Memory::CodeCave(exitCleart, 0x00628312, 6);
	//Memory::SetHook(true, reinterpret_cast<void**>(&_lpfn_NextLevel), _lpfn_NextLevel_Hook);
	/* GW_CharacterStat::DecodeChangeStat -> hijack decode4 call and switch to decode8, then return int value */
	Memory::PatchCall(0x004F283C, ExpSwap__Decode4To8);

	/* GW_CharacterStat::Decode -> hijack decode4 call and switch to decode8, then return int value */
	Memory::PatchCall(0x004F2360, ExpSwap__Decode4To8);

	// GainExpShow
	Memory::PatchCall(0x00A2B20D, ExpSwap__Decode4To8msg);
	Memory::PatchCall(0x00A2B337, FormatExpMsgString_Hook);

	///* CWvsContext::OnStatChanged -> jmping over a segment that looks at exp and then makes pet talk if at a certain % -> cbf fixing this */
	Memory::WriteByte(0x00A297A3, 0xEB);

	///* CUIStat::OnMouseMove -> hijack displayed exp in tooltip when hovering in stat window */
	Memory::PatchCall(0x008CAA15, FormatExpString_Hook);

	///* CUIStat::Draw -> hijack displayed exp in stat window 0x008C602E*/
	Memory::PatchCall(0x008CB685, ZXString__GetConstCharString);

	///* CUIStatusBar::ProcessToolTip -> hijack displayed exp in tooltip when hovering exp gauge in stat bar */
	Memory::PatchCall(0x008DC3ED, FormatExpString_Hook);
	Memory::PatchCall(0x008DC3A9, FormatExpString_Hook);

	///* CUIStatusBar::SetNumberValue -> hijack displayed exp above exp gauge */
	Memory::WriteByte(0x008DEEFE + 1, 64); // increase string size allocation -- v207 = alloca(32)
	Memory::PatchCall(0x008DEF10, itoa_ExpSwap);
}

void CharacterEx::InitLevelOverride(BOOL bEnable)
{
	if (!bEnable)
		return;
	Memory::CodeCave(changerMapCleart, 0x005348FA, 5);
	Memory::CodeCave(exitCleart, 0x00628312, 6);
	/* GW_CharacterStat::DecodeChangeStat */
	Memory::PatchCall(0x004F26F8, LevelSwap__Decode1To2);

	/* GW_CharacterStat::Decode */
	Memory::CodeCave(characterLevelStatDecode, 0x004F2264, 5);
	//Memory::PatchCall(0x004F2264, LevelSwap__Decode1To2);

	///* CUIStat::Draw */
	Memory::PatchCall(0x008CB2AF, ZXString_LevelString);

	Memory::WriteByte(0x00634565 + 1, 64);
	//Memory::PatchCall(0x00634587, _itoa_LevelSwap);
	Memory::CodeCave(itoa_LevelSwap, 0x00634587, 5);

	Memory::CodeCave(drawLevelString, 0x008DCE43, 5);

	//CWvsContext::OnCharacterInfo
	Memory::PatchCall(0x00A2CE3A, LevelSwapOnCharacterInfo__Decode1To2);   //0x0090740B pic init
	Memory::PatchCall(0x00908929, LevelOnCharacterInfoStr);

}

void CharacterEx::InitDamageSkinOverride(BOOL bEnable)
{
	if (!bEnable)
		return;
	Memory::CodeCave(changerMapCleart, 0x005348FA, 5);
	Memory::CodeCave(exitCleart, 0x00628312, 6);
	Memory::PatchCall(0x0097FAD3, CUserPoolOnUserRemotePacket_DecodeID);
	Memory::PatchCall(0x0097F8CD, OnUserLeave_DecodeID);
	Memory::CodeCave(GuildNameDecode, 0x0098CE5E, 5);
	Memory::CodeCave(GuildNameDecode2, 0x009912E7, 5);
	Memory::CodeCave(CharacterStatSkin, 0x004F28B4, 7);
	Memory::WriteByte(0x00437D44 + 1, 0x60);  // 0x39->0x60  57 -> 96  expand display range
	Memory::WriteByte(0x0043803A + 1, 0x60);
	Memory::WriteByte(0x006978DD + 2, 0xCA);  //0xF1
	Memory::WriteByte(0x006978E8 + 1, 0xCA);
	Memory::WriteByte(0x00437F04 + 1, 0x27);  //0x00
}

void CharacterEx::InitHypontizeFix(BOOL bEnable)
{
	if (!bEnable)
		return;
	Memory::PatchCall(0x007927DE, hookHypontizePacket);
	Memory::PatchCall(0x0069AA65, hookHypontizeSet);
	Memory::PatchCall(0x0069AF76, hookHypontizeCancel);
}