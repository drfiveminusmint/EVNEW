// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CSpobResource.h

#ifndef CSPOBRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CSPOBRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CSpobResource;

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

const int NUM_SPOB_CONTROLS = 69;

const int NUM_SPOB_COMMODITYPRICE_CHOICES = 4;

const std::string g_szSpobCommodityPriceChoices[NUM_SPOB_COMMODITYPRICE_CHOICES] =
	{"Unavailable", "High", "Medium", "Low"};

const int NUM_SPOB_FIELDS = 42;

const std::string g_szSpobFields[NUM_SPOB_FIELDS] =
	{"Position X", "Position Y", "Graphic Type", "Flags", "Tribute", "Tech Level",
	 "Tech 1", "Tech 2", "Tech 3",
	 "Govt", "Min Status", "Custom Pict", "Custom Sound",
	 "Defense Dude", "Defense Count", "Flags 2", "Anim Delay", "Frame-0 Bias",
	 "Hyperlink 1", "Hyperlink 2", "Hyperlink 3", "Hyperlink 4",
	 "Hyperlink 5", "Hyperlink 6", "Hyperlink 7", "Hyperlink 8",
	 "OnDominate", "OnRelease", "Landing Fee", "Gravity", "Weapon",
	 "Strength", "Dead Type", "Dead Time", "Explode Type", "OnDestroy", "OnRegen",
	 "Tech 4", "Tech 5", "Tech 6", "Tech 7", "Tech 8"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CSpobResource : public CNovaResource
{
public:

	CSpobResource(void);
	~CSpobResource(void);

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

	static BOOL SpobDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iXPosition;
	short m_iYPosition;

	short m_iGraphics;

	short m_iTribute;

	short m_iTechLevel;
	short m_iSpecialTechs[8];

	short m_iGovernment;
	short m_iMinStatus;

	short m_iCustomPicture;
	short m_iCustomSound;

	short m_iDefenseDude;
	short m_iDefenseCount;

	short m_iAnimationDelay;
	short m_iFrame0Bias;

	short m_iHyperlinks[8];

	char  m_szOnDominate[255];
	char  m_szOnRelease[255];

	int   m_iLandingFee;

	short m_iGravity;
	short m_iWeapon;
	int   m_iStrength;

	short m_iDeadType;
	short m_iDeadTime;

	short m_iExplosionType;

	char  m_szOnDestroy[255];
	char  m_szOnRegenerate[255];

	UINT  m_iFlags1;
	USHORT m_iFlags2;

	CControl m_controls[NUM_SPOB_CONTROLS];
};

#endif		// #ifndef CSPOBRESOURCE_H_INCLUDED
