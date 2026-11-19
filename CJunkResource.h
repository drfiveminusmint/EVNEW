// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CJunkResource.h

#ifndef CJUNKRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CJUNKRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CJunkResource;

////////////////////////////////////////////////////////////////
//////////////////////////	INCLUDES  //////////////////////////
////////////////////////////////////////////////////////////////

#include <windows.h>

#include <string>

#include "CControl.h"
#include "CBitFieldControl.h"
#include "CNovaResource.h"
#include "Utils.h"

////////////////////////////////////////////////////////////////
//////////////////////////  CONSTANTS  /////////////////////////
////////////////////////////////////////////////////////////////

const int NUM_JUNK_CONTROLS = 26;

const int NUM_JUNK_FIELDS = 23;

const std::string g_szJunkFields[NUM_JUNK_FIELDS] =
	{"Low Stel 1", "Low Stel 2", "Low Stel 3", "Low Stel 4", "Low Stel 5",
	 "Low Stel 6", "Low Stel 7", "Low Stel 8", "High Stel 1", "High Stel 2",
	 "High Stel 3", "High Stel 4", "High Stel 5", "High Stel 6",
	 "High Stel 7", "High Stel 8", "Base Price", "Flags", "Scan Mask",
	 "Lowercase Name", "Status Bar Abbreviation", "BuyOn", "SellOn"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CJunkResource : public CNovaResource
{
public:

	CJunkResource(void);
	~CJunkResource(void);

	int GetType(void);
	int GetSize(void);

	int GetDialogID(void);
	DLGPROCNOCALLBACK GetDialogProc(void);

	int GetNumFields(void);
	const std::string * GetFieldNames(void);

	int Initialize(HWND hwnd);

	int CloseAndSave(void);
	int CloseAndDontSave(void);

	int Save(char *pOutput);
	int Load(char *pInput, int iSize);

	int SaveToText(std::ostream & output, char delim);
	int LoadFromText(std::istream & input, char delim);

	static BOOL JunkDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iSoldAt[8];
	short m_iBoughtAt[8];

	short m_iBasePrice;

	USHORT m_iFlags;

	char  m_cScanMask[2];

	char  m_szLowerCaseName[64];
	char  m_szAbbreviation[64];

	char  m_szBuyOn[255];
	char  m_szSellOn[255];

	CControl m_controls[NUM_JUNK_CONTROLS];

	CBitFieldControl m_bitFieldControl;
};

#endif		// #ifndef CJUNKRESOURCE_H_INCLUDED
