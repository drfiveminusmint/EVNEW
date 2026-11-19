// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CSystResource.h

#ifndef CSYSTRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CSYSTRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CSystResource;

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

const int NUM_SYST_CONTROLS = 95;

const int NUM_SYST_FIELDS = 78;

const std::string g_szSystFields[NUM_SYST_FIELDS] =
	{"Position X", "Position Y", "Hyperlink 1", "Hyperlink 2", "Hyperlink 3",
	 "Hyperlink 4", "Hyperlink 5", "Hyperlink 6", "Hyperlink 7", "Hyperlink 8",
	 "Hyperlink 9", "Hyperlink 10", "Hyperlink 11", "Hyperlink 12", "Hyperlink 13",
	 "Hyperlink 14", "Hyperlink 15", "Hyperlink 16", "Nav Def 1", "Nav Def 2",
	 "Nav Def 3", "Nav Def 4", "Nav Def 5", "Nav Def 6", "Nav Def 7", "Nav Def 8",
	 "Nav Def 9", "Nav Def 10", "Nav Def 11", "Nav Def 12", "Nav Def 13", "Nav Def 14",
	 "Nav Def 15", "Nav Def 16", "Dude 1", "Dude 2", "Dude 3", "Dude 4", "Dude 5",
	 "Dude 6", "Dude 7", "Dude 8", "Dude 1 %", "Dude 2 %",
	 "Dude 3 %", "Dude 4 %", "Dude 5 %",
	 "Dude 6 %", "Dude 7 %", "Dude 8 %", "Avg Ships",
	 "Govt", "Message Buoy", "Asteroids", "Interference", "Pers 1",
	 "Pers 2", "Pers 3", "Pers 4", "Pers 5", "Pers 6", "Pers 7",
	 "Pers 8", "Pers 1 %", "Pers 2 %",
	 "Pers 3 %", "Pers 4 %", "Pers 5 %",
	 "Pers 6 %", "Pers 7 %", "Pers 8 %",
	 "Background", "Murk", "Roid Types", "Visibility", "Reinf Fleet",
	 "Reinf Delay", "Reinf Interval"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CSystResource : public CNovaResource
{
public:

	CSystResource(void);
	~CSystResource(void);

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

	static BOOL SystDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iXPosition;
	short m_iYPosition;

	short m_iHyperlinks[16];

	short m_iStellars[16];

	short m_iDudeTypes[8];
	short m_iDudeProbabilities[8];

	short m_iNumShips;

	short m_iGovernment;

	short m_iMessageBuoy;

	short m_iNumAsteroids;
	short m_iInterference;

	short m_iPersons[8];
	short m_iPersonProbabilities[8];

	char  m_szVisibility[256];

	UINT  m_iBackgroundColor;

	short m_iMurkiness;

	short m_iReinforcementFleet;
	short m_iReinforcementTime;
	short m_iReinforcementInterval;

	USHORT m_iAsteroidTypes;

	CControl m_controls[NUM_SYST_CONTROLS];
};

#endif		// #ifndef CSYSTRESOURCE_H_INCLUDED
