// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CShipResource.h

#ifndef CSHIPRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CSHIPRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CShipResource;

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

const int NUM_SHIP_CONTROLS = 127;

const int NUM_SHIP_ESCORTTYPE_CHOICES = 5;

const std::string g_szShipEscortTypeChoices[NUM_SHIP_ESCORTTYPE_CHOICES] =
	{"Let Nova figure it out", "Fighter", "Medium ship", "Warship", "Freighter"};

const int NUM_SHIP_FIELDS = 91;

const std::string g_szShipFields[NUM_SHIP_FIELDS] =
	{"Cargo Capacity", "Shields", "Acceleration", "Speed", "Turn Rate", "Fuel", "Free Space", "Armor", "Shield Recharge",
	 "Weapon 1", "Weap 2", "Weapon 3", "Weapon 4",
	 "Weap 1 Count", "Weap 2 Count", "Weap 3 Count", "Weap 4 Count",
	 "Weap 1 Ammo", "Weap 2 Ammo", "Weap 3 Ammo", "Weap 4 Ammo",
	 "Max Guns", "Max Turrets", "Tech Level", "Cost", "Death Delay", "Armor Recharge", "Explode 1", "Explode 2",
	 "Display Weight", "Mass", "Length", "AI Type", "Crew", "Strength", "Govt", "Flags", "Pod Count",
	 "Outfit 1", "Outfit 2", "Outfit 3", "Outfit 4",
	 "Outf 1 Count", "Outf 2 Count", "Outf 3 Count", "Outf 4 Count",
	 "Fuel Regen", "Skill Variance", "Flags 2", "Contribute", "Availability",
	 "AppearOn", "OnPurchase", "Deionize", "Max Ionize", "Key Carried",
	 "Outfit 5", "Outfit 6", "Outfit 7", "Outfit 8",
	 "Outf 5 Count", "Outf 6 Count", "Outf 7 Count", "Outf 8 Count",
	 "Require", "Buy Random", "Hire Random", "OnCapture", "OnRetire",
	 "Shipyard Name", "Comm Name", "Long Name", "Movie File",
	 "Weapon 5", "Weapon 6", "Weapon 7", "Weapon 8",
	 "Weap 5 Count", "Weap 6 Count", "Weap 7 Count", "Weap 8 Count",
	 "Weap 5 Ammo", "Weap 6 Ammo", "Weap 7 Ammo", "Weap 8 Ammo",
	 "Subtitle", "Flags 3", "Escort Upgrade", "Upgrade Cost", "Sell Value", "Escort Type"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CShipResource : public CNovaResource
{
public:

	CShipResource(void);
	~CShipResource(void);

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

	static BOOL ShipDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iCargo;

	short m_iShields;
	short m_iShieldRecharge;
	short m_iArmor;
	short m_iArmorRecharge;

	short m_iAcceleration;
	short m_iMaxSpeed;
	short m_iTurning;

	short m_iFuel;

	short m_iFreeMass;

	short m_iMaxGuns;
	short m_iMaxTurrets;

	short m_iTechLevel;

	int   m_iCost;

	short m_iDeathDelay;
	short m_iExplosion1;
	short m_iExplosion2;

	short m_iDisplayWeight;

	short m_iMass;
	short m_iLength;
	short m_iCrew;
	short m_iStrength;

	short m_iGovernment;

	short m_iEscapePodCount;

	short m_iFuelRegeneration;

	short m_iSkillVariation;

	char  m_szAvailability[255];
	char  m_szAppearOn[255];
	char  m_szOnPurchase[256];

	short m_iDeionize;
	short m_iMaxIonization;

	short m_iKeyCarried;

	char  m_cContribute[8];
	char  m_cRequire[8];

	short m_iBuyRandom;
	short m_iHireRandom;

	char  m_szOnCapture[255];
	char  m_szOnRetire[255];

	char  m_szSubtitle[64];
	char  m_szShortName[64];
	char  m_szCommName[32];
	char  m_szLongName[128];

	char  m_szMovieFile[32];

	short m_iEscortAI;
	short m_iEscortUpgradeTo;
	int   m_iEscortUpgradeCost;
	int   m_iEscortSellValue;
	short m_iEscortType;

	short m_iWeapons[8];
	short m_iWeaponCounts[8];
	short m_iWeaponAmmos[8];

	short m_iOutfits[8];
	short m_iOutfitCounts[8];

	USHORT m_iFlags1;
	USHORT m_iFlags2;
	USHORT m_iFlags3;

	CControl m_controls[NUM_SHIP_CONTROLS];

	CBitFieldControl m_bitFieldControl;
};

#endif		// #ifndef CSHIPRESOURCE_H_INCLUDED
