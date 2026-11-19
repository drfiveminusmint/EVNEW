// EVNEW - Escape Velocity: Nova Editor for Windows
// By Adam Rosenfield
// (c) 2003 All Rights Reserved

// File CIntfResource.cpp

////////////////////////////////////////////////////////////////
//////////////////////////	INCLUDES  //////////////////////////
////////////////////////////////////////////////////////////////

#include <windows.h>
#include <windowsx.h>

#include "CWindow.h"

#include "EVNEW.h"
#include "CNovaResource.h"
#include "CIntfResource.h"

#include "resource.h"

////////////////////////////////////////////////////////////////
///////////////////  CLASS MEMBER FUNCTIONS  ///////////////////
////////////////////////////////////////////////////////////////

CIntfResource::CIntfResource(void)
{
	m_iBrightText = 0x00000000;
	m_iDimText    = 0x00000000;

	m_iRadarT = 0;
	m_iRadarL = 0;
	m_iRadarB = 0;
	m_iRadarR = 0;

	m_iBrightRadar = 0x00000000;
	m_iDimRadar    = 0x00000000;

	m_iShieldT = 0;
	m_iShieldL = 0;
	m_iShieldB = 0;
	m_iShieldR = 0;

	m_iShieldColor = 0x00000000;

	m_iArmorT = 0;
	m_iArmorL = 0;
	m_iArmorB = 0;
	m_iArmorR = 0;

	m_iArmorColor = 0x00000000;

	m_iFuelT = 0;
	m_iFuelL = 0;
	m_iFuelB = 0;
	m_iFuelR = 0;

	m_iFuelFull    = 0x00000000;
	m_iFuelPartial = 0x00000000;

	m_iNavigationT = 0;
	m_iNavigationL = 0;
	m_iNavigationB = 0;
	m_iNavigationR = 0;

	m_iWeaponT = 0;
	m_iWeaponL = 0;
	m_iWeaponB = 0;
	m_iWeaponR = 0;

	m_iTargetT = 0;
	m_iTargetL = 0;
	m_iTargetB = 0;
	m_iTargetR = 0;

	m_iCargoT = 0;
	m_iCargoL = 0;
	m_iCargoB = 0;
	m_iCargoR = 0;

	memset(m_szStatusFont, 0, 64 * sizeof(char));

	m_iStatusFontSize   = 0;
	m_iSubtitleFontSize = 0;

	m_iBackground = 128;
}

CIntfResource::~CIntfResource(void)
{

}

int CIntfResource::GetType(void)
{
	return CNR_TYPE_INTF;
}

int CIntfResource::GetSize(void)
{
	return 166;
}

int CIntfResource::GetDialogID(void)
{
	return IDD_EDIT_INTF;
}

DLGPROCNOCALLBACK CIntfResource::GetDialogProc(void)
{
	return IntfDlgProc;
}

int CIntfResource::GetNumFields(void)
{
	return NUM_INTF_FIELDS;
}

const std::string * CIntfResource::GetFieldNames(void)
{
	return g_szIntfFields;
}

int CIntfResource::Save(char *pOutput)
{
	SwapEndians();

	*(UINT  *)pOutput = m_iBrightText;       pOutput += sizeof(UINT);
	*(UINT  *)pOutput = m_iDimText;          pOutput += sizeof(UINT);
	*(short *)pOutput = m_iRadarL;          pOutput += sizeof(short);
	*(short *)pOutput = m_iRadarT;          pOutput += sizeof(short);
	*(short *)pOutput = m_iRadarR;          pOutput += sizeof(short);
	*(short *)pOutput = m_iRadarB;          pOutput += sizeof(short);
	*(UINT  *)pOutput = m_iBrightRadar;      pOutput += sizeof(UINT);
	*(UINT  *)pOutput = m_iDimRadar;         pOutput += sizeof(UINT);
	*(short *)pOutput = m_iShieldL;         pOutput += sizeof(short);
	*(short *)pOutput = m_iShieldT;         pOutput += sizeof(short);
	*(short *)pOutput = m_iShieldR;         pOutput += sizeof(short);
	*(short *)pOutput = m_iShieldB;         pOutput += sizeof(short);
	*(UINT  *)pOutput = m_iShieldColor;      pOutput += sizeof(UINT);
	*(short *)pOutput = m_iArmorL;          pOutput += sizeof(short);
	*(short *)pOutput = m_iArmorT;          pOutput += sizeof(short);
	*(short *)pOutput = m_iArmorR;          pOutput += sizeof(short);
	*(short *)pOutput = m_iArmorB;          pOutput += sizeof(short);
	*(UINT  *)pOutput = m_iArmorColor;       pOutput += sizeof(UINT);
	*(short *)pOutput = m_iFuelL;           pOutput += sizeof(short);
	*(short *)pOutput = m_iFuelT;           pOutput += sizeof(short);
	*(short *)pOutput = m_iFuelR;           pOutput += sizeof(short);
	*(short *)pOutput = m_iFuelB;           pOutput += sizeof(short);
	*(UINT  *)pOutput = m_iFuelFull;         pOutput += sizeof(UINT);
	*(UINT  *)pOutput = m_iFuelPartial;      pOutput += sizeof(UINT);
	*(short *)pOutput = m_iNavigationL;     pOutput += sizeof(short);
	*(short *)pOutput = m_iNavigationT;     pOutput += sizeof(short);
	*(short *)pOutput = m_iNavigationR;     pOutput += sizeof(short);
	*(short *)pOutput = m_iNavigationB;     pOutput += sizeof(short);
	*(short *)pOutput = m_iWeaponL;         pOutput += sizeof(short);
	*(short *)pOutput = m_iWeaponT;         pOutput += sizeof(short);
	*(short *)pOutput = m_iWeaponR;         pOutput += sizeof(short);
	*(short *)pOutput = m_iWeaponB;         pOutput += sizeof(short);
	*(short *)pOutput = m_iTargetL;         pOutput += sizeof(short);
	*(short *)pOutput = m_iTargetT;         pOutput += sizeof(short);
	*(short *)pOutput = m_iTargetR;         pOutput += sizeof(short);
	*(short *)pOutput = m_iTargetB;         pOutput += sizeof(short);
	*(short *)pOutput = m_iCargoL;          pOutput += sizeof(short);
	*(short *)pOutput = m_iCargoT;          pOutput += sizeof(short);
	*(short *)pOutput = m_iCargoR;          pOutput += sizeof(short);
	*(short *)pOutput = m_iCargoB;          pOutput += sizeof(short);

	memcpy(pOutput, m_szStatusFont, 64 * sizeof(char)); pOutput += 64 * sizeof(char);

	*(short *)pOutput = m_iStatusFontSize;   pOutput += sizeof(short);
	*(short *)pOutput = m_iSubtitleFontSize; pOutput += sizeof(short);
	*(short *)pOutput = m_iBackground;       pOutput += sizeof(short);

	SwapEndians();

	return 1;
}

int CIntfResource::Load(char *pInput, int iSize)
{
	m_iBrightText       = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iDimText          = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iRadarL          = *(short *)pInput; pInput += sizeof(short);
	m_iRadarT          = *(short *)pInput; pInput += sizeof(short);
	m_iRadarR          = *(short *)pInput; pInput += sizeof(short);
	m_iRadarB          = *(short *)pInput; pInput += sizeof(short);
	m_iBrightRadar      = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iDimRadar         = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iShieldL         = *(short *)pInput; pInput += sizeof(short);
	m_iShieldT         = *(short *)pInput; pInput += sizeof(short);
	m_iShieldR         = *(short *)pInput; pInput += sizeof(short);
	m_iShieldB         = *(short *)pInput; pInput += sizeof(short);
	m_iShieldColor      = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iArmorL          = *(short *)pInput; pInput += sizeof(short);
	m_iArmorT          = *(short *)pInput; pInput += sizeof(short);
	m_iArmorR          = *(short *)pInput; pInput += sizeof(short);
	m_iArmorB          = *(short *)pInput; pInput += sizeof(short);
	m_iArmorColor       = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iFuelL           = *(short *)pInput; pInput += sizeof(short);
	m_iFuelT           = *(short *)pInput; pInput += sizeof(short);
	m_iFuelR           = *(short *)pInput; pInput += sizeof(short);
	m_iFuelB           = *(short *)pInput; pInput += sizeof(short);
	m_iFuelFull         = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iFuelPartial      = *(UINT  *)pInput; pInput += sizeof(UINT);
	m_iNavigationL     = *(short *)pInput; pInput += sizeof(short);
	m_iNavigationT     = *(short *)pInput; pInput += sizeof(short);
	m_iNavigationR     = *(short *)pInput; pInput += sizeof(short);
	m_iNavigationB     = *(short *)pInput; pInput += sizeof(short);
	m_iWeaponL         = *(short *)pInput; pInput += sizeof(short);
	m_iWeaponT         = *(short *)pInput; pInput += sizeof(short);
	m_iWeaponR         = *(short *)pInput; pInput += sizeof(short);
	m_iWeaponB         = *(short *)pInput; pInput += sizeof(short);
	m_iTargetL         = *(short *)pInput; pInput += sizeof(short);
	m_iTargetT         = *(short *)pInput; pInput += sizeof(short);
	m_iTargetR         = *(short *)pInput; pInput += sizeof(short);
	m_iTargetB         = *(short *)pInput; pInput += sizeof(short);
	m_iCargoL          = *(short *)pInput; pInput += sizeof(short);
	m_iCargoT          = *(short *)pInput; pInput += sizeof(short);
	m_iCargoR          = *(short *)pInput; pInput += sizeof(short);
	m_iCargoB          = *(short *)pInput; pInput += sizeof(short);

	memcpy(m_szStatusFont, pInput, 64 * sizeof(char)); pInput += 64 * sizeof(char);

	m_iStatusFontSize   = *(short *)pInput; pInput += sizeof(short);
	m_iSubtitleFontSize = *(short *)pInput; pInput += sizeof(short);
	m_iBackground       = *(short *)pInput; pInput += sizeof(short);

	SwapEndians();

	return 1;
}

int CIntfResource::SwapEndians(void)
{
	m_iBrightText       = SwapEndianInt(m_iBrightText);
	m_iDimText          = SwapEndianInt(m_iDimText);
	m_iRadarL          = SwapEndianShort(m_iRadarL);
	m_iRadarT          = SwapEndianShort(m_iRadarT);
	m_iRadarR          = SwapEndianShort(m_iRadarR);
	m_iRadarB          = SwapEndianShort(m_iRadarB);
	m_iBrightRadar      = SwapEndianInt(m_iBrightRadar);
	m_iDimRadar         = SwapEndianInt(m_iDimRadar);
	m_iShieldL         = SwapEndianShort(m_iShieldL);
	m_iShieldT         = SwapEndianShort(m_iShieldT);
	m_iShieldR         = SwapEndianShort(m_iShieldR);
	m_iShieldB         = SwapEndianShort(m_iShieldB);
	m_iShieldColor      = SwapEndianInt(m_iShieldColor);
	m_iArmorL          = SwapEndianShort(m_iArmorL);
	m_iArmorT          = SwapEndianShort(m_iArmorT);
	m_iArmorR          = SwapEndianShort(m_iArmorR);
	m_iArmorB          = SwapEndianShort(m_iArmorB);
	m_iArmorColor       = SwapEndianInt(m_iArmorColor);
	m_iFuelL           = SwapEndianShort(m_iFuelL);
	m_iFuelT           = SwapEndianShort(m_iFuelT);
	m_iFuelR           = SwapEndianShort(m_iFuelR);
	m_iFuelB           = SwapEndianShort(m_iFuelB);
	m_iFuelFull         = SwapEndianInt(m_iFuelFull);
	m_iFuelPartial      = SwapEndianInt(m_iFuelPartial);
	m_iNavigationL     = SwapEndianShort(m_iNavigationL);
	m_iNavigationT     = SwapEndianShort(m_iNavigationT);
	m_iNavigationR     = SwapEndianShort(m_iNavigationR);
	m_iNavigationB     = SwapEndianShort(m_iNavigationB);
	m_iWeaponL         = SwapEndianShort(m_iWeaponL);
	m_iWeaponT         = SwapEndianShort(m_iWeaponT);
	m_iWeaponR         = SwapEndianShort(m_iWeaponR);
	m_iWeaponB         = SwapEndianShort(m_iWeaponB);
	m_iTargetL         = SwapEndianShort(m_iTargetL);
	m_iTargetT         = SwapEndianShort(m_iTargetT);
	m_iTargetR         = SwapEndianShort(m_iTargetR);
	m_iTargetB         = SwapEndianShort(m_iTargetB);
	m_iCargoL          = SwapEndianShort(m_iCargoL);
	m_iCargoT          = SwapEndianShort(m_iCargoT);
	m_iCargoR          = SwapEndianShort(m_iCargoR);
	m_iCargoB          = SwapEndianShort(m_iCargoB);
	m_iStatusFontSize   = SwapEndianShort(m_iStatusFontSize);
	m_iSubtitleFontSize = SwapEndianShort(m_iSubtitleFontSize);
	m_iBackground       = SwapEndianShort(m_iBackground);

	return 1;
}

int CIntfResource::SaveToText(std::ostream & output, char delim)
{
	PrintHex32Field(output, (char *)&m_iBrightText, delim);
	PrintHex32Field(output, (char *)&m_iDimText,    delim);

	output << m_iRadarT          << delim
		   << m_iRadarL          << delim
		   << m_iRadarB          << delim
		   << m_iRadarR          << delim;

	PrintHex32Field(output, (char *)&m_iBrightRadar, delim);
	PrintHex32Field(output, (char *)&m_iDimRadar,    delim);

	output << m_iShieldT         << delim
		   << m_iShieldL         << delim
		   << m_iShieldB         << delim
		   << m_iShieldR         << delim;

	PrintHex32Field(output, (char *)&m_iShieldColor, delim);

	output << m_iArmorT          << delim
		   << m_iArmorL          << delim
		   << m_iArmorB          << delim
		   << m_iArmorR          << delim;

	PrintHex32Field(output, (char *)&m_iArmorColor, delim);

	output << m_iFuelT           << delim
		   << m_iFuelL           << delim
		   << m_iFuelB           << delim
		   << m_iFuelR           << delim;

	PrintHex32Field(output, (char *)&m_iFuelFull,    delim);
	PrintHex32Field(output, (char *)&m_iFuelPartial, delim);

	output << m_iNavigationT     << delim
		   << m_iNavigationL     << delim
		   << m_iNavigationB     << delim
		   << m_iNavigationR     << delim
		   << m_iWeaponT         << delim
		   << m_iWeaponL         << delim
		   << m_iWeaponB         << delim
		   << m_iWeaponR         << delim
		   << m_iTargetT         << delim
		   << m_iTargetL         << delim
		   << m_iTargetB         << delim
		   << m_iTargetR         << delim
		   << m_iCargoT          << delim
		   << m_iCargoL          << delim
		   << m_iCargoB          << delim
		   << m_iCargoR          << delim;

	PrintTextField(output, m_szStatusFont, delim);

	output << m_iStatusFontSize   << delim
		   << m_iSubtitleFontSize << delim
		   << m_iBackground;

	return 1;
}

int CIntfResource::LoadFromText(std::istream & input, char delim)
{
	ReadHex32Field(input, (char *)&m_iBrightText);
	ReadHex32Field(input, (char *)&m_iDimText);

	m_iRadarT = ReadIntField(input, delim);
	m_iRadarL = ReadIntField(input, delim);
	m_iRadarB = ReadIntField(input, delim);
	m_iRadarR = ReadIntField(input, delim);

	ReadHex32Field(input, (char *)&m_iBrightRadar);
	ReadHex32Field(input, (char *)&m_iDimRadar);

	m_iShieldT = ReadIntField(input, delim);
	m_iShieldL = ReadIntField(input, delim);
	m_iShieldB = ReadIntField(input, delim);
	m_iShieldR = ReadIntField(input, delim);

	ReadHex32Field(input, (char *)&m_iShieldColor);

	m_iArmorT = ReadIntField(input, delim);
	m_iArmorL = ReadIntField(input, delim);
	m_iArmorB = ReadIntField(input, delim);
	m_iArmorR = ReadIntField(input, delim);

	ReadHex32Field(input, (char *)&m_iArmorColor);

	m_iFuelT = ReadIntField(input, delim);
	m_iFuelL = ReadIntField(input, delim);
	m_iFuelB = ReadIntField(input, delim);
	m_iFuelR = ReadIntField(input, delim);

	ReadHex32Field(input, (char *)&m_iFuelFull);
	ReadHex32Field(input, (char *)&m_iFuelPartial);

	m_iNavigationT = ReadIntField(input, delim);
	m_iNavigationL = ReadIntField(input, delim);
	m_iNavigationB = ReadIntField(input, delim);
	m_iNavigationR = ReadIntField(input, delim);
	m_iWeaponT = ReadIntField(input, delim);
	m_iWeaponL = ReadIntField(input, delim);
	m_iWeaponB = ReadIntField(input, delim);
	m_iWeaponR = ReadIntField(input, delim);
	m_iTargetT = ReadIntField(input, delim);
	m_iTargetL = ReadIntField(input, delim);
	m_iTargetB = ReadIntField(input, delim);
	m_iTargetR = ReadIntField(input, delim);
	m_iCargoT = ReadIntField(input, delim);
	m_iCargoL = ReadIntField(input, delim);
	m_iCargoB = ReadIntField(input, delim);
	m_iCargoR = ReadIntField(input, delim);

	ReadTextField(input, m_szStatusFont, 64);

	m_iStatusFontSize = ReadIntField(input, delim);
	m_iSubtitleFontSize = ReadIntField(input, delim);
	m_iBackground = ReadIntField(input, '\n');

	return 1;
}

int CIntfResource::Initialize(HWND hwnd)
{
	std::string szTitle;

	szTitle = "intf ";
	szTitle += ToString(m_iID);
	szTitle += " (";
	szTitle += m_szName;
	szTitle += ") in ";
	szTitle += CEditor::GetCurrentEditor()->GetCurFilenameNoPath();

	m_pWindow->SetTitle(szTitle.c_str());

	m_controls[0].Create(hwnd, IDC_EDIT_INTF_EDIT1, CCONTROL_TYPE_INT, IDS_STRING336);
	m_controls[0].SetInt(m_iID);
	m_controls[1].Create(hwnd, IDC_EDIT_INTF_BUTTON2, CCONTROL_TYPE_COLOR, IDS_STRING337);
	m_controls[1].SetInt(m_iBrightText);
	m_controls[2].Create(hwnd, IDC_EDIT_INTF_BUTTON3, CCONTROL_TYPE_COLOR, IDS_STRING338);
	m_controls[2].SetInt(m_iDimText);
	m_controls[3].Create(hwnd, IDC_EDIT_INTF_EDIT4, CCONTROL_TYPE_INT, IDS_STRING339);
	m_controls[3].SetInt(m_iRadarT);
	m_controls[4].Create(hwnd, IDC_EDIT_INTF_EDIT5, CCONTROL_TYPE_INT, IDS_STRING340);
	m_controls[4].SetInt(m_iRadarL);
	m_controls[5].Create(hwnd, IDC_EDIT_INTF_EDIT6, CCONTROL_TYPE_INT, IDS_STRING341);
	m_controls[5].SetInt(m_iRadarB);
	m_controls[6].Create(hwnd, IDC_EDIT_INTF_EDIT7, CCONTROL_TYPE_INT, IDS_STRING342);
	m_controls[6].SetInt(m_iRadarR);
	m_controls[7].Create(hwnd, IDC_EDIT_INTF_BUTTON8, CCONTROL_TYPE_COLOR, IDS_STRING343);
	m_controls[7].SetInt(m_iBrightRadar);
	m_controls[8].Create(hwnd, IDC_EDIT_INTF_BUTTON9, CCONTROL_TYPE_COLOR, IDS_STRING344);
	m_controls[8].SetInt(m_iDimRadar);
	m_controls[9].Create(hwnd, IDC_EDIT_INTF_EDIT10, CCONTROL_TYPE_INT, IDS_STRING345);
	m_controls[9].SetInt(m_iShieldT);
	m_controls[10].Create(hwnd, IDC_EDIT_INTF_EDIT11, CCONTROL_TYPE_INT, IDS_STRING346);
	m_controls[10].SetInt(m_iShieldL);
	m_controls[11].Create(hwnd, IDC_EDIT_INTF_EDIT12, CCONTROL_TYPE_INT, IDS_STRING347);
	m_controls[11].SetInt(m_iShieldB);
	m_controls[12].Create(hwnd, IDC_EDIT_INTF_EDIT13, CCONTROL_TYPE_INT, IDS_STRING348);
	m_controls[12].SetInt(m_iShieldR);
	m_controls[13].Create(hwnd, IDC_EDIT_INTF_BUTTON14, CCONTROL_TYPE_COLOR, IDS_STRING349);
	m_controls[13].SetInt(m_iShieldColor);
	m_controls[14].Create(hwnd, IDC_EDIT_INTF_EDIT15, CCONTROL_TYPE_INT, IDS_STRING350);
	m_controls[14].SetInt(m_iArmorT);
	m_controls[15].Create(hwnd, IDC_EDIT_INTF_EDIT16, CCONTROL_TYPE_INT, IDS_STRING351);
	m_controls[15].SetInt(m_iArmorL);
	m_controls[16].Create(hwnd, IDC_EDIT_INTF_EDIT17, CCONTROL_TYPE_INT, IDS_STRING352);
	m_controls[16].SetInt(m_iArmorB);
	m_controls[17].Create(hwnd, IDC_EDIT_INTF_EDIT18, CCONTROL_TYPE_INT, IDS_STRING353);
	m_controls[17].SetInt(m_iArmorR);
	m_controls[18].Create(hwnd, IDC_EDIT_INTF_BUTTON19, CCONTROL_TYPE_COLOR, IDS_STRING354);
	m_controls[18].SetInt(m_iArmorColor);
	m_controls[19].Create(hwnd, IDC_EDIT_INTF_EDIT20, CCONTROL_TYPE_INT, IDS_STRING355);
	m_controls[19].SetInt(m_iFuelT);
	m_controls[20].Create(hwnd, IDC_EDIT_INTF_EDIT21, CCONTROL_TYPE_INT, IDS_STRING356);
	m_controls[20].SetInt(m_iFuelL);
	m_controls[21].Create(hwnd, IDC_EDIT_INTF_EDIT22, CCONTROL_TYPE_INT, IDS_STRING357);
	m_controls[21].SetInt(m_iFuelB);
	m_controls[22].Create(hwnd, IDC_EDIT_INTF_EDIT23, CCONTROL_TYPE_INT, IDS_STRING358);
	m_controls[22].SetInt(m_iFuelR);
	m_controls[23].Create(hwnd, IDC_EDIT_INTF_BUTTON24, CCONTROL_TYPE_COLOR, IDS_STRING359);
	m_controls[23].SetInt(m_iFuelFull);
	m_controls[24].Create(hwnd, IDC_EDIT_INTF_BUTTON25, CCONTROL_TYPE_COLOR, IDS_STRING360);
	m_controls[24].SetInt(m_iFuelPartial);
	m_controls[25].Create(hwnd, IDC_EDIT_INTF_EDIT26, CCONTROL_TYPE_INT, IDS_STRING361);
	m_controls[25].SetInt(m_iNavigationT);
	m_controls[26].Create(hwnd, IDC_EDIT_INTF_EDIT27, CCONTROL_TYPE_INT, IDS_STRING362);
	m_controls[26].SetInt(m_iNavigationL);
	m_controls[27].Create(hwnd, IDC_EDIT_INTF_EDIT28, CCONTROL_TYPE_INT, IDS_STRING363);
	m_controls[27].SetInt(m_iNavigationB);
	m_controls[28].Create(hwnd, IDC_EDIT_INTF_EDIT29, CCONTROL_TYPE_INT, IDS_STRING364);
	m_controls[28].SetInt(m_iNavigationR);
	m_controls[29].Create(hwnd, IDC_EDIT_INTF_EDIT30, CCONTROL_TYPE_INT, IDS_STRING365);
	m_controls[29].SetInt(m_iWeaponT);
	m_controls[30].Create(hwnd, IDC_EDIT_INTF_EDIT31, CCONTROL_TYPE_INT, IDS_STRING366);
	m_controls[30].SetInt(m_iWeaponL);
	m_controls[31].Create(hwnd, IDC_EDIT_INTF_EDIT32, CCONTROL_TYPE_INT, IDS_STRING367);
	m_controls[31].SetInt(m_iWeaponB);
	m_controls[32].Create(hwnd, IDC_EDIT_INTF_EDIT33, CCONTROL_TYPE_INT, IDS_STRING368);
	m_controls[32].SetInt(m_iWeaponR);
	m_controls[33].Create(hwnd, IDC_EDIT_INTF_EDIT34, CCONTROL_TYPE_INT, IDS_STRING369);
	m_controls[33].SetInt(m_iTargetT);
	m_controls[34].Create(hwnd, IDC_EDIT_INTF_EDIT35, CCONTROL_TYPE_INT, IDS_STRING370);
	m_controls[34].SetInt(m_iTargetL);
	m_controls[35].Create(hwnd, IDC_EDIT_INTF_EDIT36, CCONTROL_TYPE_INT, IDS_STRING371);
	m_controls[35].SetInt(m_iTargetB);
	m_controls[36].Create(hwnd, IDC_EDIT_INTF_EDIT37, CCONTROL_TYPE_INT, IDS_STRING372);
	m_controls[36].SetInt(m_iTargetR);
	m_controls[37].Create(hwnd, IDC_EDIT_INTF_EDIT38, CCONTROL_TYPE_INT, IDS_STRING373);
	m_controls[37].SetInt(m_iCargoT);
	m_controls[38].Create(hwnd, IDC_EDIT_INTF_EDIT39, CCONTROL_TYPE_INT, IDS_STRING374);
	m_controls[38].SetInt(m_iCargoL);
	m_controls[39].Create(hwnd, IDC_EDIT_INTF_EDIT40, CCONTROL_TYPE_INT, IDS_STRING375);
	m_controls[39].SetInt(m_iCargoB);
	m_controls[40].Create(hwnd, IDC_EDIT_INTF_EDIT41, CCONTROL_TYPE_INT, IDS_STRING376);
	m_controls[40].SetInt(m_iCargoR);
	m_controls[41].Create(hwnd, IDC_EDIT_INTF_EDIT42, CCONTROL_TYPE_STR64, IDS_STRING377);
	m_controls[41].SetString(m_szStatusFont);
	m_controls[42].Create(hwnd, IDC_EDIT_INTF_EDIT43, CCONTROL_TYPE_INT, IDS_STRING378);
	m_controls[42].SetInt(m_iStatusFontSize);
	m_controls[43].Create(hwnd, IDC_EDIT_INTF_EDIT44, CCONTROL_TYPE_INT, IDS_STRING379);
	m_controls[43].SetInt(m_iSubtitleFontSize);
	m_controls[44].Create(hwnd, IDC_EDIT_INTF_EDIT45, CCONTROL_TYPE_INT, IDS_STRING380);
	m_controls[44].SetInt(m_iBackground);
	m_controls[45].Create(hwnd, IDC_EDIT_INTF_EDIT2, CCONTROL_TYPE_STR256, IDS_STRING381);
	m_controls[45].SetString(m_szName);

	return 1;
}

int CIntfResource::CloseAndSave(void)
{
	std::string szError;

	if(CEditor::GetCurrentEditor()->IsUniqueResourceID(this, m_controls[0].GetInt()) == 0)
	{
		szError = ToString(m_controls[0].GetInt());
		szError += " is not a unique ";
		szError += g_szResourceTypes[GetType()];
		szError += " ID.  Please enter a unique ID.";

		MessageBox(m_pWindow->GetHWND(), szError.c_str(), "Error", MB_OK | MB_ICONEXCLAMATION);

		return 0;
	}
	else if((m_controls[0].GetInt() < 128) || (m_controls[0].GetInt() > 32767))
	{
		szError = ToString(m_controls[0].GetInt());
		szError += " is not a valid ID.  Please enter an ID between 128 and 32767 inclusive.";

		MessageBox(m_pWindow->GetHWND(), szError.c_str(), "Error", MB_OK | MB_ICONEXCLAMATION);

		return 0;
	}

	int iIDOrNameChanged = 0;

	if((m_iID != m_controls[0].GetInt()) || (strcmp(m_szName, m_controls[45].GetString()) != 0))
		iIDOrNameChanged = 1;

	m_iID         = m_controls[0].GetInt();

	m_iBrightText = m_controls[1].GetInt();
	m_iDimText    = m_controls[2].GetInt();

	m_iRadarT = m_controls[3].GetInt();
	m_iRadarL = m_controls[4].GetInt();
	m_iRadarB = m_controls[5].GetInt();
	m_iRadarR = m_controls[6].GetInt();

	m_iBrightRadar = m_controls[7].GetInt();
	m_iDimRadar    = m_controls[8].GetInt();

	m_iShieldT = m_controls[9].GetInt();
	m_iShieldL = m_controls[10].GetInt();
	m_iShieldB = m_controls[11].GetInt();
	m_iShieldR = m_controls[12].GetInt();

	m_iShieldColor = m_controls[13].GetInt();

	m_iArmorT = m_controls[14].GetInt();
	m_iArmorL = m_controls[15].GetInt();
	m_iArmorB = m_controls[16].GetInt();
	m_iArmorR = m_controls[17].GetInt();

	m_iArmorColor = m_controls[18].GetInt();

	m_iFuelT = m_controls[19].GetInt();
	m_iFuelL = m_controls[20].GetInt();
	m_iFuelB = m_controls[21].GetInt();
	m_iFuelR = m_controls[22].GetInt();

	m_iFuelFull    = m_controls[23].GetInt();
	m_iFuelPartial = m_controls[24].GetInt();

	m_iNavigationT = m_controls[25].GetInt();
	m_iNavigationL = m_controls[26].GetInt();
	m_iNavigationB = m_controls[27].GetInt();
	m_iNavigationR = m_controls[28].GetInt();

	m_iWeaponT = m_controls[29].GetInt();
	m_iWeaponL = m_controls[30].GetInt();
	m_iWeaponB = m_controls[31].GetInt();
	m_iWeaponR = m_controls[32].GetInt();

	m_iTargetT = m_controls[33].GetInt();
	m_iTargetL = m_controls[34].GetInt();
	m_iTargetB = m_controls[35].GetInt();
	m_iTargetR = m_controls[36].GetInt();

	m_iCargoT = m_controls[37].GetInt();
	m_iCargoL = m_controls[38].GetInt();
	m_iCargoB = m_controls[39].GetInt();
	m_iCargoR = m_controls[40].GetInt();

	strcpy(m_szStatusFont, m_controls[41].GetString());

	m_iStatusFontSize   = m_controls[42].GetInt();
	m_iSubtitleFontSize = m_controls[43].GetInt();

	m_iBackground = m_controls[44].GetInt();

	strcpy(m_szName, m_controls[45].GetString());

	int i;

	for(i = 0; i < NUM_INTF_CONTROLS; i++)
		m_controls[i].Destroy();

	m_iIsNew = 0;

	CEditor::GetCurrentEditor()->SetDirty();

	CEditor::GetCurrentEditor()->RemoveEditDialog(m_pWindow, iIDOrNameChanged);

	return 1;
}

int CIntfResource::CloseAndDontSave(void)
{
	int i;

	for(i = 0; i < NUM_INTF_CONTROLS; i++)
		m_controls[i].Destroy();

	CEditor::GetCurrentEditor()->RemoveEditDialog(m_pWindow, 0);

	return 1;
}

BOOL CIntfResource::IntfDlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	CWindow *pWindow;
	CIntfResource *pResource;

	pWindow = CWindow::GetWindow(hwnd, 1);

	if(pWindow != NULL)
		pResource = (CIntfResource *)pWindow->GetExtraData(2);

	int i;

	switch(msg)
	{
		case WM_INITDIALOG:
		{
			pResource->Initialize(hwnd);

			return TRUE;

			break;
		}

		case WM_SYSCOMMAND:
		{
			if(wparam == SC_CLOSE)
			{
				pResource->CloseAndDontSave();

				return TRUE;
			}

			break;
		}

		case WM_COMMAND:
		{
			int iNotifyCode = HIWORD(wparam);
			int iControlID  = LOWORD(wparam);

			if(iControlID == IDC_EDIT_INTF_CANCEL)
			{
				pResource->CloseAndDontSave();
			}
			else if(iControlID == IDC_EDIT_INTF_OK)
			{
				pResource->CloseAndSave();
			}
			else
			{
				for(i = 0; i < NUM_INTF_CONTROLS; i++)
				{
					if(iControlID == pResource->m_controls[i].GetControlID())
					{
						pResource->m_controls[i].ProcessMessage(iNotifyCode);

						break;
					}
				}
			}

			return TRUE;

			break;
		}

		default:
		{
			break;
		}
	}

	return FALSE;
}
