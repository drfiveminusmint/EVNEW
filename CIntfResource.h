// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CIntfResource.h

#ifndef CINTFRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CINTFRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CIntfResource;

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

const int NUM_INTF_CONTROLS = 46;

const int NUM_INTF_FIELDS = 44;

const std::string g_szIntfFields[NUM_INTF_FIELDS] =
	{"Bright Text", "Dim Text", "Radar T", "Radar L", "Radar B",
	 "Radar R", "Bright Radar", "Dim Radar", "Shield T", "Shield L",
	 "Shield B", "Shield R", "Shield Color", "Armor T", "Armor L",
	 "Armor B", "Armor R", "Armor Color", "Fuel T", "Fuel L",
	 "Fuel B", "Fuel R", "Fuel Full", "Fuel Partial", "Nav T",
	 "Nav L", "Nav B", "Nav R", "Weapon T",
	 "Weapon L", "Weapon B", "Weapon R", "Target T", "Target L",
	 "Target B", "Target R", "Cargo T", "Cargo L", "Cargo B",
	 "Cargo R", "Status Font", "Font Size", "Subtitle Size",
	 "Background"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CIntfResource : public CNovaResource
{
public:

	CIntfResource(void);
	~CIntfResource(void);

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

	static BOOL IntfDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	UINT  m_iBrightText;
	UINT  m_iDimText;

	short m_iRadarT;
	short m_iRadarL;
	short m_iRadarB;
	short m_iRadarR;

	UINT  m_iBrightRadar;
	UINT  m_iDimRadar;

	short m_iShieldT;
	short m_iShieldL;
	short m_iShieldB;
	short m_iShieldR;

	UINT  m_iShieldColor;

	short m_iArmorT;
	short m_iArmorL;
	short m_iArmorB;
	short m_iArmorR;

	UINT  m_iArmorColor;

	short m_iFuelT;
	short m_iFuelL;
	short m_iFuelB;
	short m_iFuelR;

	UINT  m_iFuelFull;
	UINT  m_iFuelPartial;

	short m_iNavigationT;
	short m_iNavigationL;
	short m_iNavigationB;
	short m_iNavigationR;

	short m_iWeaponT;
	short m_iWeaponL;
	short m_iWeaponB;
	short m_iWeaponR;

	short m_iTargetT;
	short m_iTargetL;
	short m_iTargetB;
	short m_iTargetR;

	short m_iCargoT;
	short m_iCargoL;
	short m_iCargoB;
	short m_iCargoR;

	char  m_szStatusFont[64];
	short m_iStatusFontSize;
	short m_iSubtitleFontSize;

	short m_iBackground;

	CControl m_controls[NUM_INTF_CONTROLS];
};

#endif		// #ifndef CINTFRESOURCE_H_INCLUDED
