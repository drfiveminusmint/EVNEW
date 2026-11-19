// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CFletResource.h

#ifndef CFLETRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CFLETRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CFletResource;

////////////////////////////////////////////////////////////////
//////////////////////////	INCLUDES  //////////////////////////
////////////////////////////////////////////////////////////////

#include <windows.h>

#include <string>

#include "CControl.h"
#include "CNovaResource.h"
#include "Utils.h"

////////////////////////////////////////////////////////////////
//////////////////////////  CONSTANTS  /////////////////////////
////////////////////////////////////////////////////////////////

const int NUM_FLET_CONTROLS = 20;

const int NUM_FLET_FIELDS = 18;

const std::string g_szFletFields[NUM_FLET_FIELDS] =
	{"Lead Ship", "Ship 1", "Ship 2", "Ship 3",
	 "Ship 4", "Min 1", "Min 2", "Min 3",
	 "Min 4", "Max 1", "Max 2", "Max 3",
	 "Max 4", "Govt", "Link System", "AppearOn", "Hail Quote",
	 "Flags"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CFletResource : public CNovaResource
{
public:

	CFletResource(void);
	~CFletResource(void);

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

	static BOOL FletDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iLeadShipType;

	short m_iEscortTypes[4];
	short m_iMinEscorts[4];
	short m_iMaxEscorts[4];

	short m_iGovernment;

	short m_iSystem;

	char m_szAppearOn[256];

	short m_iQuote;

	USHORT m_iFlags;

	CControl m_controls[NUM_FLET_CONTROLS];
};

#endif		// #ifndef CFLETRESOURCE_H_INCLUDED
