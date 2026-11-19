// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CShanResource.h

#ifndef CSHANRESOURCE_H_INCLUDED		// Prevent multiple inclusions
#define CSHANRESOURCE_H_INCLUDED

////////////////////////////////////////////////////////////////
///////////////////////  CLASS FORWARDS  ///////////////////////
////////////////////////////////////////////////////////////////

class CShanResource;

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

const int NUM_SHAN_CONTROLS = 95;

const int NUM_SHAN_EXTRAFRAMES_CHOICES = 6;

const std::string g_szShanExtraFramesChoices[NUM_SHAN_EXTRAFRAMES_CHOICES] =
	{"No extra frames", "Banking", "Banking with Glow", "Animated ship parts",
	 "When carrying Key Carried ships", "Shown in sequence"};

const int NUM_SHAN_BLINKMODE_CHOICES = 4;

const std::string g_szShanBlinkModeChoices[NUM_SHAN_BLINKMODE_CHOICES] =
	{"None", "Square", "Triangle", "Random"};

const int NUM_SHAN_FIELDS = 88;

const std::string g_szShanFields[NUM_SHAN_FIELDS] =
	{"Base Sprite", "Base Mask", "Set Count", "Base X", "Base Y", "Transparency",
	 "Alt Sprite", "Alt Mask", "Alt Count", "Alt X", "Alt Y",
	 "Glow Sprite", "Glow Mask", "Glow X", "Glow Y",
	 "Light Sprite", "Light Mask", "Light X", "Light Y",
	 "Weap Sprite", "Weap Mask", "Weap X", "Weap Y",
	 "Flags", "Anim Delay", "Weap Decay", "Frames Per", "Blink Mode",
	 "Blink Val A", "Blink Val B", "Blink Val C", "Blink Val D",
	 "Shield Sprite", "Shield Mask", "Shield X", "Shield Y",
	 "Gun 1 X", "Gun 2 X", "Gun 3 X", "Gun 4 X",
	 "Gun 1 Y", "Gun 2 Y", "Gun 3 Y", "Gun 4 Y",
	 "Turret 1 X", "Turret 2 X", "Turret 3 X", "Turret 4 X",
	 "Turret 1 Y", "Turret 2 Y", "Turret 3 Y", "Turret 4 Y",
	 "Guided 1 X", "Guided 2 X", "Guided 3 X", "Guided 4 X",
	 "Guided 1 Y", "Guided 2 Y", "Guided 3 Y", "Guided 4 Y",
	 "Beam 1 X", "Beam 2 X", "Beam 3 X", "Beam 4 X",
	 "Beam 1 Y", "Beam 2 Y", "Beam 3 Y", "Beam 4 Y",
	 "Up Comp X", "Up Comp Y", "Dn Comp X", "Dn Comp Y",
	 "Gun 1 Z", "Gun 2 Z", "Gun 3 Z", "Gun 4 Z",
	 "Turret 1 Z", "Turret 2 Z", "Turret 3 Z", "Turret 4 Z",
	 "Guided 1 Z", "Guided 2 Z", "Guided 3 Z", "Guided 4 Z",
	 "Beam 1 Z", "Beam 2 Z", "Beam 3 Z", "Beam 4 Z"};

////////////////////////////////////////////////////////////////
///////////////////////////  CLASSES  //////////////////////////
////////////////////////////////////////////////////////////////

class CShanResource : public CNovaResource
{
public:

	CShanResource(void);
	~CShanResource(void);

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

	static BOOL ShanDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:

	int SwapEndians(void);

	short m_iBaseImage;
	short m_iBaseMask;
	short m_iBaseSetCount;
	short m_iBaseXSize;
	short m_iBaseYSize;
	short m_iBaseTransparency;

	short m_iAltImage;
	short m_iAltMask;
	short m_iAltSetCount;
	short m_iAltXSize;
	short m_iAltYSize;

	short m_iGlowImage;
	short m_iGlowMask;
	short m_iGlowXSize;
	short m_iGlowYSize;

	short m_iLightsImage;
	short m_iLightsMask;
	short m_iLightsXSize;
	short m_iLightsYSize;

	short m_iWeaponImage;
	short m_iWeaponMask;
	short m_iWeaponXSize;
	short m_iWeaponYSize;

	short m_iShieldImage;
	short m_iShieldMask;
	short m_iShieldXSize;
	short m_iShieldYSize;

	USHORT m_iFlags;

	short m_iAnimationDelay;
	short m_iWeaponDecay;

	short m_iRotationFrames;

	short m_iBlinkMode;
	short m_iBlinkValueA;
	short m_iBlinkValueB;
	short m_iBlinkValueC;
	short m_iBlinkValueD;

	short m_iGunPosX[4];
	short m_iGunPosY[4];
	short m_iTurretPosX[4];
	short m_iTurretPosY[4];
	short m_iGuidedPosX[4];
	short m_iGuidedPosY[4];
	short m_iBeamPosX[4];
	short m_iBeamPosY[4];

	short m_iUpCompressX;
	short m_iUpCompressY;
	short m_iDownCompressX;
	short m_iDownCompressY;

	short m_iGunPosZ[4];
	short m_iTurretPosZ[4];
	short m_iGuidedPosZ[4];
	short m_iBeamPosZ[4];

	CControl m_controls[NUM_SHAN_CONTROLS];
};

#endif		// #ifndef CSHANRESOURCE_H_INCLUDED
