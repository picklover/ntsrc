/****************************************************************************
	HAUTO.CPP

	Owner: cslim
	Copyright (c) 1997-1999 Microsoft Corporation

	Hangul composition state machine class
	
	History:
	14-JUL-1999 cslim       Copied from IME98 source tree
*****************************************************************************/

#if !defined (__HAUTOMATA_H__)
#define __HAUTOMATA_H__

#include "debug.h"

// Number of each component
#define NUM_OF_CHOSUNG  19
#define NUM_OF_JUNGSUNG 21
#define NUM_OF_JONGSUNG 28

#define NUM_OF_DOUBLE_CHOSUNG   5
#define NUM_OF_DOUBLE_JUNGSUNG  7
#define NUM_OF_DOUBLE_JONGSUNG_2BEOL 11
#define NUM_OF_DOUBLE_JONGSUNG_3BEOL 13

#define UNICODE_HANGUL_BASE					0xAC00
#define UNICODE_HANGUL_END					0xD7A3
#define UNICODE_HANGUL_COMP_JAMO_START		0x3131
#define UNICODE_HANGUL_COMP_JAMO_VOWEL_START		0x314F
#define UNICODE_HANGUL_COMP_JAMO_END		0x3163
#define UNICODE_HANGUL_COMP_JAMO_START_FILL	0x3130
#define UNICODE_HANGUL_COMP_JAMO_SIOT		0x3145

///////////////////////////////////////////
// HANGUL Jaso inernal difinitions
// ChoSung
#define _KIYEOK_			1		// 'ぁ'	
#define _SSANGKIYEOK_		2		// 'あ'
#define _NIEUN_				3		// 'い'
#define _TIKEUT_			4		// 'ぇ'
#define _SSANGTIKEUT_		5		// 'え'
#define _RIEUL_				6		// 'ぉ'
#define _MIEUM_				7		// 'け'
#define _PIEUP_				8		// 'げ'
#define _SSANGPIEUP_		9		// 'こ'
#define _SIOS_				10		// 'さ'
#define _SSANGSIOS_			11		// 'ざ'
#define _IEUNG_				12		// 'し'
#define _CIEUC_				13		// 'じ'
#define _SSANGCIEUC_		14		// 'す'
#define _CHIEUCH_			15		// 'ず'
#define _KHIEUKH_			16		// 'せ'
#define _THIEUTH_			17		// 'ぜ'
#define _PHIEUPH_			18		// 'そ'
#define _HIEUH_				19		// 'ぞ'

// JungSung
#define _A_					1		// 'た'
#define _AE_				2		// 'だ'
#define _YA_				3		// 'ち'
#define _YAE_				4		// 'ぢ'
#define _EO_				5		// 'っ'
#define _E_					6		// 'つ'
#define _YEO_				7		// 'づ'
#define _YE_				8		// 'て'
#define _O_					9		// 'で'
#define _WA_				10		// 'と'
#define _WAE_				11		// 'ど'
#define _OE_				12		// 'な'
#define _YO_				13		// 'に'
#define _U_					14		// 'ぬ'
#define _WEO_				15		// 'ね'
#define _WE_				16		// 'の'
#define _WI_				17		// 'は'
#define _YU_				18		// 'ば'
#define _EU_				19		// 'ぱ'
#define _YI_				20		// 'ひ'
#define _I_					21		// 'び'
////////////////////////////////////////

// JongSung
#define _JONG_KIYEOK_			1		// 'ぁ'	
#define _JONG_SSANGKIYEOK_		2		// 'あ'
#define _JONG_KIYEOK_SIOS		3
#define _JONG_NIEUN_			4		// 'い'
#define _JONG_NIEUN_CHIEUCH_	5		// 'い'
#define _JONG_NIEUN_HIEUH_		6		// 'い'
#define _JONG_TIKEUT_			7		// 'ぇ'
#define _JONG_RIEUL_			8		// 'ぉ'
#define _JONG_RIEUL_KIYEOK_		9		// 'ぉ'
#define _JONG_RIEUL_MIUM_		10		// 'ぉ'
#define _JONG_RIEUL_PIEUP_		11		// 'ぉ'
#define _JONG_RIEUL_SIOS_		12		// 'ぉ'
#define _JONG_RIEUL_THIEUTH_	13		// 'ぉ'
#define _JONG_RIEUL_PHIEUPH_	14		// 'ぉ'
#define _JONG_RIEUL_HIEUH_		15		// 'ぉ'
#define _JONG_MIEUM_			16		// 'け'
#define _JONG_PIEUP_			17		// 'げ'
#define _JONG_PIEUP_SIOS		18		// 'げ'
#define _JONG_SIOS_				19		// 'さ'
#define _JONG_SSANGSIOS_		20		// 'ざ'
#define _JONG_IEUNG_			21		// 'し'
#define _JONG_CIEUC_			22		// 'じ'
#define _JONG_CHIEUCH_			23		// 'ず'
#define _JONG_KHIEUKH_			24		// 'せ'
#define _JONG_THIEUTH_			25		// 'ぜ'
#define _JONG_PHIEUPH_			26		// 'そ'
#define _JONG_HIEUH_			27		// 'ぞ'
//
const int MaxInterimStackSize = 6;		// Maximum stack size is 6.
										// At most 6 key input
										// to complete one Hangul Char.
										// ex) ��(3 beolsik)
enum HAutomataReturnState 
	{ 
	  HAUTO_NONHANGULKEY,
	  HAUTO_COMPOSITION,	// Hagul still in interim state.
	  HAUTO_COMPLETE,		// One hangul char completed and have chars 
							// will takeover as next input.
	  HAUTO_IMPOSSIBLE
	};

const WORD H_HANGUL = 0x8000;

/////////////////////////////////////////////////////////////////////////////
// CHangulAutomata Abstract Class
//
class CHangulAutomata
	{
public:
	CHangulAutomata() {	InitState(); }

// Attributes
public:

// Operations
public:
	void InitState() 
		{ 
		m_CurState = m_NextState = 0;
		m_wInternalCode = 0;
		m_Chosung = m_Jungsung = m_Jongsung = 0;
		m_wcComposition = m_wcComplete = L'\0';
		InterimStack.Init();
		}
	virtual HAutomataReturnState Machine(UINT KeyCode, int iShift) = 0;
	virtual BOOL IsInputKey(UINT KeyCode, int iShift) = 0;
	virtual BOOL IsHangulKey(UINT KeyCode, int iShift) = 0;
	virtual WORD GetKeyMap(UINT KeyCode, int iShift) = 0;
	virtual BOOL SetCompositionChar(WCHAR wcComp) = 0;
	
	static WORD GetEnglishKeyMap(UINT KeyCode, int iShift) { return bETable[KeyCode][iShift]; }
	BOOL BackSpace();
	BOOL MakeComplete();
	WCHAR GetCompositionChar() { return m_wcComposition; }
	WCHAR GetCompleteChar() { return m_wcComplete; }

// Implementation
public:
	virtual ~CHangulAutomata() {}

protected:
	void MakeComposition();
	BOOL MakeComplete(WORD wcComplete);
	WORD FindChosungComb(WORD wPrevCode);
	WORD FindJunsungComb(WORD wPrevCode);
	virtual WORD FindJonsungComb(WORD wPrevCode) = 0;
	void SeparateDJung(LPWORD pJungSung);
	void SeparateDJong(LPWORD pJongSung);

	virtual HAutomataReturnState Input(WORD InternalCode) = 0;
	//
	struct InterimStackEntry 
		{
		WORD	m_wInternalCode;
		WORD	m_CurState;
		WORD	m_Chosung, m_Jungsung, m_Jongsung;
		WCHAR	m_wcCode;
		};

	///////////////////////////////////////////////////////////////////////////
	//
	class CInterimStack 
		{
	protected:
		InterimStackEntry	m_StackBuffer[MaxInterimStackSize];	
		int	m_sp;		// Stack pointer

	public:
		CInterimStack() { m_sp = 0; }
		~CInterimStack() {}
		void Init() { m_sp = 0; }
		void Push(InterimStackEntry& InterimEntry);
		void Push(WORD wInternalCode, WORD CurState, 
				  WORD Chosung, WORD Jungsung, WORD Jongsung, WCHAR wcCode);

		InterimStackEntry* CInterimStack::Pop() 
			{
			DbgAssert(m_sp > 0);
			return &m_StackBuffer[--m_sp];
			}

		InterimStackEntry* CInterimStack::GetTop() 
			{
			DbgAssert(m_sp > 0);
			return &m_StackBuffer[m_sp-1];
			}

		BOOL IsEmpty() { return m_sp == 0; }
		};
	///////////////////////////////////////////////////////////////////////////
	CInterimStack InterimStack;

protected:
	WORD	m_CurState, m_NextState;
	WORD	m_wInternalCode, m_Chosung, m_Jungsung, m_Jongsung;
	WCHAR	m_wcComposition;
	WCHAR	m_wcComplete;
	//
	const static BYTE  bETable[256][2];
	const static BYTE  Cho2Jong[NUM_OF_CHOSUNG+1];
	const static BYTE  Jong2Cho[NUM_OF_JONGSUNG];
	};

/////////////////////////////////////////////////////////////////////////////
// CHangulAutomata2 Keyboard layout #1 (2 beolsik)
//
class CHangulAutomata2 : public CHangulAutomata
{
public:
	CHangulAutomata2() { }

// Attributes
public:

// Operations
public:
	HAutomataReturnState Machine(UINT KeyCode, int iShift);
	BOOL IsInputKey(UINT KeyCode, int iShift);
	BOOL IsHangulKey(UINT KeyCode, int iShift);
	WORD GetKeyMap(UINT KeyCode, int iShift);
	BOOL SetCompositionChar(WCHAR wcComp);
	
// Implementation
public:
	~CHangulAutomata2() { }

protected:
	WORD FindJonsungComb(WORD wPrevCode);
	HAutomataReturnState Input(WORD InternalCode);
		
protected:
	// This enum should be matched with m_NextState
	// DO NOT change without changing _Transistion_state !
	enum _Transistion_state { FINAL=8, TAKEOVER=9, FIND=10 };
	static const WORD m_NextStateTbl[8][5];
	static const WORD H_CONSONANT, H_VOWEL, H_DOUBLE, H_ONLYCHO;
	static WORD wHTable[256][2];
	static BYTE  rgbDJongTbl[NUM_OF_DOUBLE_JONGSUNG_2BEOL+1][3];
};


/////////////////////////////////////////////////////////////////////////////
// CHangulAutomata3 Keyboard layout #2 (3 beolsik)
class CHangulAutomata3 : public CHangulAutomata
{
public:
	CHangulAutomata3() {}

// Attributes
public:

// Operations
public:
	HAutomataReturnState Machine(UINT KeyCode, int iShift);
	BOOL IsInputKey(UINT KeyCode, int iShift);
	BOOL IsHangulKey(UINT KeyCode, int iShift);
	WORD GetKeyMap(UINT KeyCode, int iShift);
	BOOL SetCompositionChar(WCHAR wcComp);

// Implementation
public:
	~CHangulAutomata3() { }

protected:
	WORD FindJonsungComb(WORD wPrevCode);
	HAutomataReturnState Input(WORD InternalCode);
	
protected:
	enum _Transistion_state { FINAL=11, FIND=12 };
	static const WORD m_NextStateTbl[11][6];
	static const WORD H_CHOSUNG, H_JUNGSUNG, H_JONGSUNG, H_DOUBLE;
	static WORD wHTable[256][2];
	static BYTE  rgbDJongTbl[NUM_OF_DOUBLE_JONGSUNG_3BEOL+1][3];
};

/////////////////////////////////////////////////////////////////////////////
// CHangulAutomata3 Keyboard layout #3 (3 beolsik final)
class CHangulAutomata3Final : public CHangulAutomata3
{
public:
	CHangulAutomata3Final() {}

// Attributes
public:

// Operations
public:
	HAutomataReturnState Machine(UINT KeyCode, int iShift) ;
	BOOL IsInputKey(UINT KeyCode, int iShift);
	BOOL IsHangulKey(UINT KeyCode, int iShift); 
	WORD GetKeyMap(UINT KeyCode, int iShift);

// Implementation
public:
	~CHangulAutomata3Final() { }

protected:
	static WORD wHTable[256][2];
};

///////////////////////////////////////////////////////////////////////////////
// Inline functions

inline
void CHangulAutomata::CInterimStack::Push(InterimStackEntry& InterimEntry) 
	{
	DbgAssert(m_sp<MaxInterimStackSize);
	m_StackBuffer[m_sp++] =  InterimEntry;
	}

inline
void CHangulAutomata::CInterimStack::Push(WORD wInternalCode, WORD CurState, 
				  WORD Chosung, WORD Jungsung, WORD Jongsung, WCHAR wcCode) 
	{
	DbgAssert(m_sp<=5);
	m_StackBuffer[m_sp].m_wInternalCode =  wInternalCode;
	m_StackBuffer[m_sp].m_CurState =  CurState;
	m_StackBuffer[m_sp].m_Chosung =  Chosung;
	m_StackBuffer[m_sp].m_Jungsung =  Jungsung;
	m_StackBuffer[m_sp].m_Jongsung =  Jongsung;
	m_StackBuffer[m_sp++].m_wcCode =  wcCode;
	}

// CHangulAutomata2
inline
HAutomataReturnState CHangulAutomata2::Machine(UINT KeyCode, int iShift) 
	{
	return (Input(wHTable[KeyCode][iShift]));
	}

inline
BOOL CHangulAutomata2::IsInputKey(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return fFalse;
	}

inline
BOOL CHangulAutomata2::IsHangulKey(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]) & H_HANGUL;
	else
		return fFalse;
	}

inline
WORD CHangulAutomata2::GetKeyMap(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return fFalse;
	}


// CHangulAutomata3
inline
HAutomataReturnState CHangulAutomata3::Machine(UINT KeyCode, int iShift) 
	{
	DbgAssert(KeyCode<256);
	return (Input(wHTable[KeyCode][iShift]));
	}

inline
BOOL CHangulAutomata3::IsInputKey(UINT KeyCode, int iShift)
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return fFalse;
	}

inline
BOOL CHangulAutomata3::IsHangulKey(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]) & H_HANGUL;
	else
		return fFalse;
	}

inline
WORD CHangulAutomata3::GetKeyMap(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return 0;
	}

// CHangulAutomata3Final
inline 
HAutomataReturnState CHangulAutomata3Final::Machine(UINT KeyCode, int iShift) 
	{
	DbgAssert(KeyCode<256);
	return (Input(wHTable[KeyCode][iShift]));
	}

inline 
BOOL CHangulAutomata3Final::IsInputKey(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return fFalse;
	}

inline
BOOL CHangulAutomata3Final::IsHangulKey(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]) & H_HANGUL;
	else
		return fFalse;
	}

inline
WORD CHangulAutomata3Final::GetKeyMap(UINT KeyCode, int iShift) 
	{
	if (KeyCode<256)
		return (wHTable[KeyCode][iShift]);
	else
		return 0;
	}

#endif // !defined (__HAUTOMATA_H__)
