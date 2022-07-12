
// FCU_SWDlg.cpp : 구현 파일

#include "stdafx.h"
#include "FCU_SW.h"
#include "FCU_SWDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// UINT16 Byte2WORD(UINT8* byte) { return (byte[0] << 8 | byte[1]); }
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFCU_SWDlg 대화 상자


IMPLEMENT_DYNAMIC(CFCU_SWDlg, CDialogEx);

CFCU_SWDlg::CFCU_SWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFCU_SWDlg::IDD, pParent)
	, bPaintOnce(TRUE)
	, m_bLaunch(TRUE)
	, u16LED_Cnt(0)
	, m_u8Mode(CASE_INITIAL_MODE)
	, m_u8LaunchStat(CASE_BEFORE_FIRE)
	, m_bAtkModeCmdDlg(FALSE)
	, m_wEXTPOW(DISABLE)
	, m_bMSL_BIT_CHK(FALSE)
	, m_bRecvView(FALSE)
	, bLED_State(FALSE)
	, bDISC_TEST_MODE_SET(FALSE)
	, m_bSKR_CAGE_CMD(FALSE)
	, m_bMSL_ID_CHK(FALSE)
	, m_bSKR_RDY_CHK(FALSE)
	, m_bSKR_PLC_CHK(FALSE)
	, m_bLOCK_ON_CMD(FALSE)
	, m_bSKR_TRK_STATUS(FALSE)
	, m_bATK_MODE_CMD(FALSE)
	, m_bMSL_STS_CHK(FALSE)
	, s16AimRT_X(275)
	, s16AimRT_Y(236)
	, s16AimLB_X(236)
	, s16AimLB_Y(275)
	, m_sclAim(255, 255, 255)
	, m_sclAimResult(255, 255, 255)
	, m_s16SX_CAM(0)
	, m_s16SY_CAM(0)
	, m_s16EX_CAM(0)
	, m_s16EY_CAM(0)
	, m_s16YAW_CAM(0)
	, m_s16PITCH_CAM(0)
	, m_bRE_ROCK_ON_Flag(FALSE)
	, m_bModifyAxis(FALSE)
	, m_pThread(NULL)
	, m_strPLC_VALUE(_T(""))
	, m_strAimSize_X(_T(""))
	, m_strAimSize_Y(_T(""))
	, m_bSKR_IMG_CTRL(FALSE)
	, m_wMBATABAT(DISABLE)
	, m_s16LB_X(0)
	, m_s16LB_Y(0)
	, m_s16RT_X(0)
	, m_s16RT_Y(0)
	, m_bBAT_STAT(FALSE)
	, m_u16AtkMode(ATK_MODE_UPPER)
	, m_bConnectionStateHILS(FALSE)
	, optval(TRUE)
	, m_u8FCU_BIT_CNT(0)
	, m_wMBATPOW(DISABLE)
	, m_matMain(512, 512, CV_8UC3, Scalar(0, 0, 0))
	, m_bSetGasOnce(FALSE)
	, m_bSkrRecvFlag(FALSE)
	, m_bDisplayMSL_BIT(FALSE)
	, m_bDisplaySKR_CAGE(FALSE)
	, m_bDisplayMSL_ID(FALSE)
	, m_bDisplaySKR_RDY(FALSE)
	, m_bDisplaySKR_PLC(FALSE)
	, m_bDisplaySKR_TRK(FALSE)
	, m_bDisplayMSL_STS(FALSE)
	, m_u8LampStat(BLACK)
	, m_u8GasCnt(15)
	, m_strRUX(_T(""))
	, m_strRUY(_T(""))
	, m_strLLX(_T(""))
	, m_strLLY(_T(""))
	, m_bWantExitHILS(FALSE)
	, m_bThreadCamDataRecv(FALSE)
	, m_u8ClientCnt(0)
	, m_u8MaxSkrRdyTime(0)
	, m_u16currentCMD(NULL)
	, m_bAimT(FALSE)
	, m_bAimTracking(FALSE)
	, m_bAimSight(TRUE)
	, m_u8MslTestFlag(FALSE)
	, m_bLOCK_ON_RSLT_FAULT(FALSE)
	, m_bRE_ROCK_ON_LED_Flag(FALSE)
	, m_bShowWarning(FALSE)

{
#ifndef DEBUG
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
#endif
	m_pAutoProxy = NULL;
}

CFCU_SWDlg::~CFCU_SWDlg()
{
	// 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
	//  후방 포인터를 NULL로 설정하여
	//  대화 상자가 삭제되었음을 알 수 있게 합니다.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CFCU_SWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_imgTitle, m_staticTitle);
	DDX_Control(pDX, IDC_imgMode, m_staticMode);
	DDX_Control(pDX, IDC_imgMslStat, m_staticMslStat);
	DDX_Control(pDX, IDC_imgLnchStat, m_staticLnchStat);
	DDX_Control(pDX, IDC_CAM, m_imgCam);
	DDX_Control(pDX, IDC_imgBright, m_staticBright);
	DDX_Control(pDX, IDC_imgContrast, m_staticContrast);
	DDX_Control(pDX, IDC_imgGas, m_staticGas);
	DDX_Control(pDX, IDC_imgWarn, m_staticWarn);

	DDX_Control(pDX, IDC_BTN_MSL_BIT_CHK_TEST, m_btnMslBitChkTest);
	DDX_Control(pDX, IDC_BTN_MSL_ID_CHK, m_btnMslIdChk);
	DDX_Control(pDX, IDC_BTN_SKR_RDY_CHK, m_btnSkrRdyChk);
	DDX_Control(pDX, IDC_BTN_LOCK_ON_CMD, m_btnLockOnCmd);
	DDX_Control(pDX, IDC_BTN_RE_LOCK_ON_CMD, m_btnReLockOnCmd);

	DDX_Control(pDX, IDC_ATK_MODE_CMD, m_btnAtkModeCmd);
	DDX_Control(pDX, IDC_BTN_CUSQ_TEST, m_btnCUSQTest);
	DDX_Control(pDX, IDC_BTN_MSL_STS_CHK_TEST, m_btnMslStsChk);
	DDX_Control(pDX, IDC_BTN_LIFTOFF_RDY_CMD_TEST, m_btnLiftoffRdyCmd);
	DDX_Control(pDX, IDC_BTN_LAUNCH, m_btnLaunch);
	DDX_Control(pDX, IDC_BTN_UP, m_btnUp);
	DDX_Control(pDX, IDC_BTN_LEFT, m_btnLeft);
	DDX_Control(pDX, IDC_BTN_RIGHT, m_btnRight);
	DDX_Control(pDX, IDC_BTN_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BTN_MODE_DRYRUN, m_btnModeDryrun);
	DDX_Control(pDX, IDC_BTN_MODE_LAUNCH, m_btnModeLaunch);
	DDX_Control(pDX, IDC_BTN_EMSQ, m_btnEMSQ);
	DDX_Control(pDX, IDC_BTN_POWER, m_btnPower);
	DDX_Control(pDX, IDC_BTN_CANCEL_DLG, m_btnCancelDlg);
	DDX_Control(pDX, IDC_BTN_CHANGE_MODE, m_btnChangeMode);
	DDX_Control(pDX, IDC_BTN_SKR_CAGE_CMD_TEST, m_btnSkrCageCmdTest);
	DDX_Control(pDX, IDC_BTN_SKR_PLC_CHK_TEST, m_btnSkrPlcChkTest);
	DDX_Control(pDX, IDC_BTN_SKR_TRK_STATUS_TEST, m_btnSkrTrkStatusTest);
	DDX_Control(pDX, IDC_BTN_BATSQ_TEST, m_btnBATSQTest);
	DDX_Control(pDX, IDC_BTN_PINSQ_TEST, m_btnPINSQTest);
	DDX_Control(pDX, IDC_BTN_MODE_TEST, m_btnModeTest);
	DDX_Control(pDX, IDC_BTN_TRY_CONNECT, m_btnTryConnect);
	DDX_Control(pDX, IDC_LED_TCP_STAT, m_ledTCP);
	DDX_Control(pDX, IDC_LED_UDP_STAT, m_ledUDP);
	DDX_Control(pDX, IDC_LED_MSL_BIT_CHK_TEST, m_ledMSL_BIT_CHK_TEST);
	DDX_Control(pDX, IDC_LED_CUSQ, m_ledCUSQ);
	DDX_Control(pDX, IDC_LED_CUSQ_TEST, m_ledCUSQ_TEST);
	DDX_Control(pDX, IDC_LED_SKR_CAGE_CMD, m_ledSKR_CAGE_CMD);
	DDX_Control(pDX, IDC_LED_MSL_ID_CHK_TEST, m_ledMSL_ID_CHK_TEST);
	DDX_Control(pDX, IDC_LED_SKR_RDY_CHK_TEST, m_ledSKR_RDY_CHK_TEST);
	DDX_Control(pDX, IDC_LED_SKR_PLC_CHK_TEST, m_ledSKR_PLC_CHK_TEST);
	DDX_Control(pDX, IDC_LED_SKR_PLC_CHK, m_ledSKR_PLC_CHK);
	DDX_Control(pDX, IDC_LED_SKR_TRK_STATUS_TEST, m_ledSKR_TRK_STATUS_TEST);
	DDX_Control(pDX, IDC_LED_SKR_TRK_STATUS, m_ledSKR_TRK_STATUS);
	DDX_Control(pDX, IDC_LED_BATSQ_TEST, m_ledBATSQ_TEST);
	DDX_Control(pDX, IDC_LED_MSL_STS_CHK_TEST, m_ledMSL_STS_CHK_TEST);
	DDX_Control(pDX, IDC_LED_BATSQ, m_ledBATSQ);
	DDX_Control(pDX, IDC_LED_MSL_STS_CHK, m_ledMSL_STS_CHK);
	DDX_Control(pDX, IDC_LED_LIFTOFF_RDY_CMD_TEST, m_ledLIFTOFF_RDY_CMD_TEST);
	DDX_Control(pDX, IDC_LED_LIFTOFF_RDY_CMD, m_ledLIFTOFF_RDY_CMD);
	DDX_Control(pDX, IDC_LED_PINSQ, m_ledPINSQ);
	DDX_Control(pDX, IDC_LED_PINSQ_TEST, m_ledPINSQ_TEST);
	DDX_Control(pDX, IDC_LED_EMSQ_TEST, m_ledEMSQ_TEST);
	DDX_Control(pDX, IDC_BTN_HIDDEN, m_btnHidden);
	DDX_Control(pDX, IDC_STATIC_VAL_V1, m_txtVAL_V1);
	DDX_Control(pDX, IDC_STATIC_VAL_A1, m_txtVAL_A1);
	DDX_Control(pDX, IDC_STATIC_VAL_V2, m_txtVAL_V2);
	DDX_Control(pDX, IDC_STATIC_VAL_V3, m_txtVAL_V3);
	DDX_Control(pDX, IDC_STATIC_VAL_A2, m_txtVAL_A2);
	DDX_Control(pDX, IDC_STATIC_VAL_A3, m_txtVAL_A3);
	DDX_Control(pDX, IDC_BTN_DISC_TEST_MODE_SET, m_btnDISC_TEST_MODE_SET);
	DDX_Control(pDX, IDC_LED_MSLCON, m_ledMSLCON);
	DDX_Control(pDX, IDC_LED_PINCHK, m_ledPINCHK);
	DDX_Control(pDX, IDC_BTN_GSTREAMER, m_btnGstreamer);
	DDX_Control(pDX, IDC_LED_MSL_BIT_CHK, m_ledMSL_BIT_CHK);
	DDX_Control(pDX, IDC_LED_SKR_RDY_CHK, m_ledSKR_RDY_CHK);
	DDX_Control(pDX, IDC_LED_SKR_CAGE_CMD_TEST, m_ledSKR_CAGE_CMD_TEST);
	DDX_Control(pDX, IDC_LED_EMSQ, m_ledEMSQ);
	DDX_Control(pDX, IDC_LED_MSL_ID_CHK, m_ledMSL_ID_CHK);
	DDX_Text(pDX, IDC_STATIC_PLC_VALUE, m_strPLC_VALUE);
	DDX_Text(pDX, IDC_STATIC2, m_strAimSize_X);
	DDX_Text(pDX, IDC_STATIC4, m_strAimSize_Y);
	DDX_Text(pDX, IDC_EDIT_IMG_VAL, m_strImgVal);
	DDX_Control(pDX, IDC_BTN_PUSHING_L, m_LED_L1);
	DDX_Control(pDX, IDC_BTN_PUSHING_L2, m_LED_L2);
	DDX_Control(pDX, IDC_BTN_PUSHING_L3, m_LED_L3);
	DDX_Control(pDX, IDC_BTN_PUSHING_L4, m_LED_L4);
	DDX_Control(pDX, IDC_BTN_PUSHING_L5, m_LED_L5);
	DDX_Control(pDX, IDC_BTN_PUSHING_L6, m_LED_L6);
	DDX_Control(pDX, IDC_BTN_PUSHING_L7, m_LED_L7);
	DDX_Control(pDX, IDC_BTN_CENTER, m_btnCenter);
	DDX_Control(pDX, IDC_imgSkrStat, m_staticSkrStat);
	DDX_Control(pDX, IDC_LAMP_SKR_RDY, m_LampSkrRdy);
	DDX_Control(pDX, IDC_BTN_POWER_MBAT, m_btnMbatOn);
	DDX_Text(pDX, IDC_STATIC14, m_strRUX);
	DDX_Text(pDX, IDC_STATIC13, m_strRUY);
	DDX_Text(pDX, IDC_STATIC8, m_strLLX);
	DDX_Text(pDX, IDC_STATIC6, m_strLLY);
}

BEGIN_MESSAGE_MAP(CFCU_SWDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_MODE_DRYRUN, &CFCU_SWDlg::OnBnClickedBtnModeDryrun)
	ON_BN_CLICKED(IDC_BTN_MODE_LAUNCH, &CFCU_SWDlg::OnBnClickedBtnModeLaunch)
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CFCU_SWDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ATK_MODE_CMD, &CFCU_SWDlg::OnBnClickedAtkModeCmd)
	ON_COMMAND(ID_MENU_DRYRUN, &CFCU_SWDlg::OnMenuDryrun)
	ON_COMMAND(ID_MENU_LAUNCH, &CFCU_SWDlg::OnMenuLaunch)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTN_CANCEL_DLG, &CFCU_SWDlg::OnBnClickedCancelDlg)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ACCELERATOR_F1, &CFCU_SWDlg::OnAcceleratorF1)
	ON_WM_KEYUP()
	ON_BN_CLICKED(IDC_BTN_CHANGE_MODE, &CFCU_SWDlg::OnBnClickedChangeMode)
	ON_BN_CLICKED(IDC_BTN_LAUNCH, &CFCU_SWDlg::OnBnClickedBtnLaunch)
	ON_COMMAND(ID_ACCELERATOR_F2, &CFCU_SWDlg::OnAcceleratorF2)
	ON_COMMAND(ID_ACCELERATOR_F3, &CFCU_SWDlg::OnAcceleratorF3)
	ON_STN_CLICKED(IDC_LED_MSL_BIT_CHK_TEST, &CFCU_SWDlg::OnStnClickedLedMslBitChkTest)
	ON_STN_CLICKED(IDC_LED_CUSQ_TEST, &CFCU_SWDlg::OnStnClickedLedCusqTest)
	ON_STN_CLICKED(IDC_LED_SKR_CAGE_CMD_TEST, &CFCU_SWDlg::OnStnClickedLedSkrCageCmdTest)
	ON_STN_CLICKED(IDC_LED_SKR_CAGE_CMD, &CFCU_SWDlg::OnStnClickedLedSkrCageCmd)
	ON_STN_CLICKED(IDC_LED_MSL_ID_CHK_TEST, &CFCU_SWDlg::OnStnClickedLedMslIdChkTest)
	ON_STN_CLICKED(IDC_LED_SKR_RDY_CHK_TEST, &CFCU_SWDlg::OnStnClickedLedSkrRdyChkTest)
	ON_STN_CLICKED(IDC_LED_SKR_PLC_CHK_TEST, &CFCU_SWDlg::OnStnClickedLedSkrPlcChkTest)
	ON_STN_CLICKED(IDC_LED_SKR_PLC_CHK, &CFCU_SWDlg::OnStnClickedLedSkrPlcChk)
	ON_STN_CLICKED(IDC_LED_SKR_TRK_STATUS_TEST, &CFCU_SWDlg::OnStnClickedLedSkrTrkStatusTest)
	ON_STN_CLICKED(IDC_LED_SKR_TRK_STATUS, &CFCU_SWDlg::OnStnClickedLedSkrTrkStatus)
	ON_STN_CLICKED(IDC_LED_MSL_STS_CHK_TEST, &CFCU_SWDlg::OnStnClickedLedMslStsChkTest)
	ON_STN_CLICKED(IDC_LED_LIFTOFF_RDY_CMD, &CFCU_SWDlg::OnStnClickedLedLiftoffRdyCmd)
	ON_STN_CLICKED(IDC_LED_PINSQ, &CFCU_SWDlg::OnStnClickedLedPinsq)
	ON_STN_CLICKED(IDC_LED_PINSQ_TEST, &CFCU_SWDlg::OnStnClickedLedPinsqTest)
	ON_STN_CLICKED(IDC_LED_EMSQ_TEST, &CFCU_SWDlg::OnStnClickedLedEmsqTest)
	ON_BN_CLICKED(IDC_BTN_POWER, &CFCU_SWDlg::OnBnClickedBtnPower)
	ON_BN_CLICKED(IDC_BTN_LOCK_ON_CMD, &CFCU_SWDlg::OnBnClickedLockOnCmd)
	ON_BN_CLICKED(IDC_BTN_RE_LOCK_ON_CMD, &CFCU_SWDlg::OnBnClickedReLockOnCmd)
	ON_MESSAGE(WM_CONNECT_EVENT, &CFCU_SWDlg::OnConnectEvent)
	ON_MESSAGE(WM_RECEIVE_EVENT, &CFCU_SWDlg::OnReceiveEvent)
	ON_MESSAGE(WM_CLOSE_EVENT, &CFCU_SWDlg::OnCloseEvent)
	ON_BN_CLICKED(IDC_BTN_MODE_TEST, &CFCU_SWDlg::OnBnClickedBtnModeTest)
	ON_BN_CLICKED(IDC_BTN_TRY_CONNECT, &CFCU_SWDlg::OnBnClickedBtnTryConnect)
	ON_BN_CLICKED(IDC_BTN_UP, &CFCU_SWDlg::OnBnClickedBtnUp)
	ON_BN_CLICKED(IDC_BTN_LEFT, &CFCU_SWDlg::OnBnClickedBtnLeft)
	ON_BN_CLICKED(IDC_BTN_RIGHT, &CFCU_SWDlg::OnBnClickedBtnRight)
	ON_BN_CLICKED(IDC_BTN_DOWN, &CFCU_SWDlg::OnBnClickedBtnDown)
	ON_BN_CLICKED(IDC_BTN_MSL_BIT_CHK_TEST, &CFCU_SWDlg::OnBnClickedBtnMslBitChk)
	ON_BN_CLICKED(IDC_BTN_CUSQ_TEST, &CFCU_SWDlg::OnBnClickedBtnCusq)
	ON_BN_CLICKED(IDC_BTN_SKR_CAGE_CMD_TEST, &CFCU_SWDlg::OnBnClickedBtnSkrCageCmd)
	ON_BN_CLICKED(IDC_BTN_MSL_ID_CHK, &CFCU_SWDlg::OnBnClickedBtnMslIdChk)
	ON_BN_CLICKED(IDC_BTN_SKR_RDY_CHK, &CFCU_SWDlg::OnBnClickedBtnSkrRdyChk)
	ON_BN_CLICKED(IDC_BTN_SKR_PLC_CHK_TEST, &CFCU_SWDlg::OnBnClickedBtnSkrPlcChk)
	ON_BN_CLICKED(IDC_BTN_MSL_STS_CHK_TEST, &CFCU_SWDlg::OnBnClickedBtnMslStsChk)
	ON_BN_CLICKED(IDC_BTN_LIFTOFF_RDY_CMD_TEST, &CFCU_SWDlg::OnBnClickedBtnLiftoffRdyCmd)
	ON_BN_CLICKED(IDC_BTN_PINSQ_TEST, &CFCU_SWDlg::OnBnClickedBtnPinsq)
	ON_BN_CLICKED(IDC_BTN_EMSQ, &CFCU_SWDlg::OnBnClickedBtnEmsq)
	ON_BN_CLICKED(IDC_BTN_BATSQ_TEST, &CFCU_SWDlg::OnBnClickedBtnBatsq)
	ON_BN_CLICKED(IDCANCEL, &CFCU_SWDlg::OnBnClickedCancel)
	ON_WM_MOVE()
	ON_WM_MOVING()
	ON_STN_CLICKED(IDC_BTN_HIDDEN, &CFCU_SWDlg::OnStnClickedBtnHidden)
	ON_STN_CLICKED(IDC_imgLnchStat, &CFCU_SWDlg::OnStnClickedimglnchstat)
	ON_BN_CLICKED(IDC_BTN_DISC_TEST_MODE_SET, &CFCU_SWDlg::OnBnClickedBtnDiscBit)
	ON_STN_CLICKED(IDC_LED_CUSQ, &CFCU_SWDlg::OnStnClickedLedCusq)
	ON_STN_CLICKED(IDC_LED_MSL_ID_CHK, &CFCU_SWDlg::OnStnClickedLedMslIdChk)
	ON_STN_CLICKED(IDC_LED_BATSQ_TEST, &CFCU_SWDlg::OnStnClickedLedBatsqTest)
	ON_STN_CLICKED(IDC_LED_BATSQ, &CFCU_SWDlg::OnStnClickedLedBatsq)
	ON_STN_CLICKED(IDC_LED_MSL_STS_CHK, &CFCU_SWDlg::OnStnClickedLedMslStsChk)
	ON_STN_CLICKED(IDC_LED_LIFTOFF_RDY_CMD_TEST, &CFCU_SWDlg::OnStnClickedLedLiftoffRdyCmdTest)
	ON_STN_CLICKED(IDC_LED_EMSQ, &CFCU_SWDlg::OnStnClickedLedEmsq)
	ON_STN_CLICKED(IDC_LED_MSL_BIT_CHK, &CFCU_SWDlg::OnStnClickedLedMslBitChk)
	ON_STN_CLICKED(IDC_LED_SKR_RDY_CHK, &CFCU_SWDlg::OnStnClickedLedSkrRdyChk)
	ON_BN_CLICKED(IDC_BTN_SKR_TRK_STATUS_TEST, &CFCU_SWDlg::OnBnClickedBtnSkrTrkStatus)
	ON_BN_CLICKED(IDC_BTN_GSTREAMER, &CFCU_SWDlg::OnBnClickedBtnGstreamer)
	ON_BN_CLICKED(IDC_BTN_SEND_IMG_VAL, &CFCU_SWDlg::OnBnClickedBtnSendImgVal)
	ON_COMMAND(ID_ACCELERATOR_ALT_P, &CFCU_SWDlg::OnAcceleratorAltP)
	ON_COMMAND(ID_ACCELERATOR_ALT_A, &CFCU_SWDlg::OnAcceleratorAltA)
	ON_BN_CLICKED(IDC_BTN_FOLD, &CFCU_SWDlg::OnBnClickedBtnFold)
	ON_COMMAND(ID_ACCELERATOR_FOLD, &CFCU_SWDlg::OnAcceleratorFold)
	ON_BN_CLICKED(IDC_BTN_CENTER, &CFCU_SWDlg::OnBnClickedBtnCenter)
	ON_COMMAND(ID_ACCELERATOR_SPACE, &CFCU_SWDlg::OnAcceleratorSpace)
	ON_COMMAND(ID_ACCELERATOR_ALT_L, &CFCU_SWDlg::OnAcceleratorAltL)
	ON_STN_CLICKED(IDC_imgMode, &CFCU_SWDlg::OnStnClickedimgmode)
	ON_COMMAND(ID_ACCELERATOR_F6, &CFCU_SWDlg::OnAcceleratorF6)
	ON_COMMAND(ID_ACCELERATOR_ALT_F, &CFCU_SWDlg::OnAcceleratorAltF)
	ON_MESSAGE(WM_SELECT_MODE, &CFCU_SWDlg::OnSelectMode)
	ON_MESSAGE(WM_SET_LAUNCH_MODE, &CFCU_SWDlg::OnSetLaunchMode)
	ON_MESSAGE(WM_SET_DRYRUN_MODE, &CFCU_SWDlg::OnSetDryrunMode)
	ON_COMMAND(ID_ACCELERATOR_F10, &CFCU_SWDlg::OnAcceleratorF10)
	ON_WM_DESTROY()
	ON_STN_CLICKED(IDC_imgTitle, &CFCU_SWDlg::OnStnClickedimgtitle)
	ON_MESSAGE(WM_RECEIVE_EVENT_HILS, &CFCU_SWDlg::OnReceiveEventHils)
	ON_MESSAGE(WM_CLIENT_DISCONNECT, &CFCU_SWDlg::OnClientDisconnect)
	ON_COMMAND(ID_ACCELERATOR_F4, &CFCU_SWDlg::OnAcceleratorF4)
	ON_COMMAND(ID_ACCELERATOR_ALT_C, &CFCU_SWDlg::OnAcceleratorAltC)
	ON_BN_CLICKED(IDC_BTN_POWER_MBAT, &CFCU_SWDlg::OnBnClickedBtnPowerMbat)
END_MESSAGE_MAP()


// CFCU_SWDlg 메시지 처리기

BOOL CFCU_SWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	S32BIT m_s32SysCx, m_s32SysCy;

	m_s32SysCx = (int)GetSystemMetrics(SM_CXSCREEN);
	m_s32SysCy = (int)GetSystemMetrics(SM_CYSCREEN);
	// ScreenToClient(&m_rectWindow);

	// MainDlg 크기 세팅
	this->MoveWindow(0, 80, 960, 720);
	m_imgCam.MoveWindow(223, 130, 512, 512);
	// 배경색 지정
	SetBackgroundColor(RGB(0, 0, 0));

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	/* 폰트 속성 */
	SetWindowTheme(GetDlgItem(IDC_STATIC9)->m_hWnd, _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_STATIC10)->m_hWnd, _T(""), _T(""));

	m_btnPower.LoadBitmaps(IDB_BTN_POWER_02, IDB_BTN_POWER_02, NULL, NULL);
	m_btnPower.SizeToContent();

	m_btnCancelDlg.LoadBitmaps(IDB_BTN_CANCEL_DLG_02, IDB_BTN_CANCEL_DLG_03, NULL, NULL);
	m_btnCancelDlg.SizeToContent();

	m_btnMslBitChkTest.LoadBitmaps(IDB_BTN_MSL_BIT_01, IDB_BTN_MSL_BIT_02, NULL, NULL);
	m_btnMslBitChkTest.SizeToContent();
	m_btnSkrCageCmdTest.LoadBitmaps(IDB_BTN_SKR_CAGE_CMD_01, IDB_BTN_SKR_CAGE_CMD_02, NULL, NULL);
	m_btnSkrCageCmdTest.SizeToContent();
	m_btnMslIdChk.LoadBitmaps(IDB_BTN_CHK_ID_01, IDB_BTN_CHK_ID_02, NULL, NULL);
	m_btnMslIdChk.SizeToContent();
	m_btnSkrRdyChk.LoadBitmaps(IDB_BTN_SKR_RDY_CHK_01, IDB_BTN_SKR_RDY_CHK_02, NULL, NULL);
	m_btnSkrRdyChk.SizeToContent();
	m_btnLockOnCmd.LoadBitmaps(IDB_DESIGN_TGT_01, IDB_DESIGN_TGT_02, NULL, NULL);
	m_btnLockOnCmd.SizeToContent();
	m_btnSkrPlcChkTest.LoadBitmaps(IDB_BTN_SKR_PLC_CHK_01, IDB_BTN_SKR_PLC_CHK_02, NULL, NULL);
	m_btnSkrPlcChkTest.SizeToContent();
	m_btnReLockOnCmd.LoadBitmaps(IDB_BTN_RE_LOCK_ON_CMD_01, IDB_BTN_RE_LOCK_ON_CMD_02, NULL, NULL);
	m_btnReLockOnCmd.SizeToContent();
	m_btnSkrTrkStatusTest.LoadBitmaps(IDB_BTN_SKR_TRK_STATUS_01, IDB_BTN_SKR_TRK_STATUS_02, NULL, NULL);
	m_btnSkrTrkStatusTest.SizeToContent();

	m_btnAtkModeCmd.LoadBitmaps(IDB_DESIGN_MODE_01, IDB_DESIGN_MODE_02, NULL, NULL);
	m_btnAtkModeCmd.SizeToContent();
	m_btnCUSQTest.LoadBitmaps(IDB_BTN_CUSQ_01, IDB_BTN_CUSQ_02, NULL, NULL);
	m_btnCUSQTest.SizeToContent();
	m_btnMslStsChk.LoadBitmaps(IDB_BTN_MSL_STS_CHK_TEST_01, IDB_BTN_MSL_STS_CHK_TEST_02, NULL, NULL);
	m_btnMslStsChk.SizeToContent();
	m_btnLiftoffRdyCmd.LoadBitmaps(IDB_SET_MSL_01, IDB_SET_MSL_02, NULL, NULL);
	m_btnLiftoffRdyCmd.SizeToContent();
	m_btnLaunch.LoadBitmaps(IDB_LAUNCH_01, IDB_LAUNCH_02, NULL, NULL);
	m_btnLaunch.SizeToContent();
	GetDlgItem(IDC_BTN_LAUNCH)->EnableWindow(FALSE);

	m_btnBATSQTest.LoadBitmaps(IDB_BTN_BATSQ_11, IDB_BTN_BATSQ_12, NULL, NULL);
	m_btnBATSQTest.SizeToContent();
	m_btnPINSQTest.LoadBitmaps(IDB_BTN_PINSQ_11, IDB_BTN_PINSQ_12, NULL, NULL);
	m_btnPINSQTest.SizeToContent();
	m_btnEMSQ.LoadBitmaps(IDB_BTN_EMSQ_11, IDB_BTN_EMSQ_12, NULL, NULL);
	m_btnEMSQ.SizeToContent();

	m_btnUp.LoadBitmaps(IDB_BTN_UP, IDB_BTN_UP_02, NULL, NULL);
	m_btnUp.SizeToContent();
	m_btnDown.LoadBitmaps(IDB_BTN_DOWN, IDB_BTN_DOWN_02, NULL, NULL);
	m_btnDown.SizeToContent();
	m_btnLeft.LoadBitmaps(IDB_BTN_LEFT, IDB_BTN_LEFT_02, NULL, NULL);
	m_btnLeft.SizeToContent();
	m_btnRight.LoadBitmaps(IDB_BTN_RIGHT, IDB_BTN_RIGHT_02, NULL, NULL);
	m_btnRight.SizeToContent();
	m_btnCenter.LoadBitmaps(IDB_BTN_CENTER, IDB_BTN_CENTER_02, NULL, NULL);
	m_btnCenter.SizeToContent();

	m_btnModeDryrun.LoadBitmaps(IDB_BTN_DRYRUN_01, IDB_BTN_DRYRUN_03, NULL, NULL);
	m_btnModeDryrun.SizeToContent();
	m_btnModeLaunch.LoadBitmaps(IDB_BTN_LAUNCH_01, IDB_BTN_LAUNCH_03, NULL, NULL);
	m_btnModeLaunch.SizeToContent();

	m_btnChangeMode.LoadBitmaps(IDB_BTN_CHANGE_MODE_01, IDB_BTN_CHANGE_MODE_02, NULL, NULL);
	m_btnChangeMode.SizeToContent();

	m_btnTryConnect.LoadBitmaps(IDB_BTN_CONNECT_TCP_01, IDB_BTN_CONNECT_TCP_01_2, NULL, NULL);
	m_btnTryConnect.SizeToContent();

	m_btnDISC_TEST_MODE_SET.LoadBitmaps(IDB_BTN_TMSL_FALSE_01, IDB_BTN_TMSL_FALSE_02, NULL, NULL);
	m_btnDISC_TEST_MODE_SET.SizeToContent();

	m_btnGstreamer.LoadBitmaps(IDB_BTN_SKR_IMG_CTRL_01, IDB_BTN_SKR_IMG_CTRL_02, NULL, NULL);
	m_btnGstreamer.SizeToContent();

	m_btnMbatOn.LoadBitmaps(IDB_BTN_POWER_MBAT_02, IDB_BTN_POWER_MBAT_02, NULL, NULL);
	m_btnMbatOn.SizeToContent();

	s8ConnectStat = -1;


	setEnableBTN(FALSE);
	GetDlgItem(IDC_BTN_BATSQ_TEST)->EnableWindow(TRUE);

	m_wEXTPOW = DISABLE;


	// SetTimer(FCU_SWDLG_INIT, 10, NULL);


	this->GetWindowRect(m_rectMainDlg);
	CRect rectModeIO;

	// RecvView 생성
	if (m_pRecvView == NULL)
	{
		m_pRecvView = new CRecvView(this);

		m_pRecvView->Create(IDD_RECVVIEW);
		m_pRecvView->SetWindowPos(NULL, m_rectMainDlg.right, m_rectMainDlg.top, 0, 0, SWP_NOSIZE);

		m_bRecvView = TRUE;

		m_pRecvView->ShowWindow(SW_HIDE);
	}

	// 무인차량통제기 진입/해제 대화상자 생성
	if (m_pModeIO.DoModal() == IDOK)
	{
		// 진입 시도 결과가 0xFF일 시 프로그램 종료
		if (m_pModeIO.m_u8CNNCT_RSLT == 0x0F)
		{
			m_ClientSocket.End();
			m_SocketServer.Close();
			::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);

			return FALSE;
		}
		// 모드 선택 대화상자 생성
		if (m_ptCModeSelect == NULL)
		{
			m_ptCModeSelect = new CFCU_MODE_SELECT(this);

			m_ptCModeSelect->Create(IDD_FCU_MODE_SELECT);
			// m_ptCModeSelect->GetClientRect(rectFCU_STS_Dlg);
			m_ptCModeSelect->SetWindowPos(NULL, m_rectMainDlg.left, m_rectMainDlg.bottom, 0, 0, SWP_NOSIZE);

			m_bCModeSelect = TRUE;

			m_ptCModeSelect->ShowWindow(SW_SHOW);

			// SetTimer(FCU_SWDLG_INIT, 10, NULL);
		}
	}
	// 
	////  For DEBUG
	//m_ptCModeSelect = new CFCU_MODE_SELECT(this);

	//m_ptCModeSelect->Create(IDD_FCU_MODE_SELECT);
	//// m_ptCModeSelect->GetClientRect(rectFCU_STS_Dlg);
	//m_ptCModeSelect->SetWindowPos(NULL, m_rectMainDlg.left, m_rectMainDlg.bottom, 0, 0, SWP_NOSIZE);

	//m_bCModeSelect = TRUE;

	//m_ptCModeSelect->ShowWindow(SW_SHOW);

	memset(&m_uFCU_BIT_CHK, 0, sizeof(m_uFCU_BIT_CHK));
	memset(&m_uEXT_POW_ON, 0, sizeof(m_uEXT_POW_ON));
	memset(&m_uSKR_CAGE_CMD, 0, sizeof(m_uSKR_CAGE_CMD));
	memset(&m_uMSL_ID_CHK, 0, sizeof(m_uMSL_ID_CHK));
	memset(&m_uSKR_RDY_CHK, 0, sizeof(m_uSKR_RDY_CHK));
	memset(&m_uSKR_PLC_CHK, 0, sizeof(m_uSKR_PLC_CHK));
	memset(&m_uLOCK_ON_CMD, 0, sizeof(m_uLOCK_ON_CMD));
	memset(&m_uRE_LOCK_ON_CMD, 0, sizeof(m_uRE_LOCK_ON_CMD));
	memset(&m_uSKR_TRK_STATUS, 0, sizeof(m_uSKR_TRK_STATUS));
	memset(&m_uATK_MODE_CMD, 0, sizeof(m_uATK_MODE_CMD));
	memset(&m_uBATSQ, 0, sizeof(m_uBATSQ));
	memset(&m_uMBAT_ON, 0, sizeof(m_uMBAT_ON));
	memset(&m_uABAT_ON, 0, sizeof(m_uABAT_ON));
	memset(&m_uMSL_STS_CHK, 0, sizeof(m_uMSL_STS_CHK));
	memset(&m_uLIFTOFF_RDY_CMD, 0, sizeof(m_uLIFTOFF_RDY_CMD));
	memset(&m_uPINSQ, 0, sizeof(m_uPINSQ));
	memset(&m_uEMSQ, 0, sizeof(m_uEMSQ));
	memset(&m_uCUSQ, 0, sizeof(m_uCUSQ));
	memset(&m_uMSL_BIT_CHK, 0, sizeof(m_uMSL_BIT_CHK));
	memset(&m_uEXT_POW_CHK, 0, sizeof(m_uEXT_POW_CHK));
	memset(&m_uABAT_POW_CHK, 0, sizeof(m_uABAT_POW_CHK));
	memset(&m_uMBAT_POW_CHK, 0, sizeof(m_uMBAT_POW_CHK));
	memset(&m_uMSLCON_CHK, 0, sizeof(m_uMSLCON_CHK));
	memset(&m_uPINCHK_CHK, 0, sizeof(m_uPINCHK_CHK));
	memset(&m_uDISC_TEST_MODE_SET, 0, sizeof(m_uDISC_TEST_MODE_SET));
	memset(&m_uPINCHK_MSLCON, 0, sizeof(m_uPINCHK_MSLCON));

	m_pRecvView->AddEventString(_T(""));

	CRect rectFCU_STS_Dlg;

	// 상태 전시 대화상자 생성
	if (m_pFCU_STS_Dlg == NULL)
	{
		m_pFCU_STS_Dlg = new CFCU_STS_Dlg(this);

		m_pFCU_STS_Dlg->Create(IDD_FCU_STS_Dlg);
		m_pFCU_STS_Dlg->SetWindowPos(NULL, m_rectMainDlg.left, m_rectMainDlg.bottom, 0, 0, SWP_NOSIZE);

		m_bFCU_STS_Dlg = TRUE;

		m_pFCU_STS_Dlg->ShowWindow(SW_HIDE);
	}

	if (m_bShowWarning == FALSE)
	{
		m_pShowWarning = new CShowWarning;
		m_bShowWarning = m_pShowWarning->Create(IDD_ShowWarning);
		m_pShowWarning->ShowWindow(SW_HIDE);
	}

	// 최초 조준창 전시
	m_s16RT_X = convertCV2MSL(s16AimRT_X, AXIS_X);
	m_s16LB_X = convertCV2MSL(s16AimLB_X, AXIS_X);
	m_s16RT_Y = convertCV2MSL(s16AimRT_Y, AXIS_Y);
	m_s16LB_Y = convertCV2MSL(s16AimLB_Y, AXIS_Y);
	SetTimer(FCU_SWDLG_INIT, 10, NULL);

	// 발사통제기와 통신을 위한 서버 생성
	// 포트 번호 50999
	if (m_SocketServer.Create(LOCAL_PORT, SOCK_STREAM))
	{
		if (!m_SocketServer.Listen())
		{
			m_pRecvView->AddEventString(_T("ERROR : Listen() return FALSE"));
		}
		else
		{
			m_SocketServer.SetKeepalive();
		}

	}
	else
	{
		CString str;
		str.Format(_T("%d"), m_SocketServer.GetLastError());
		AfxMessageBox(_T("ERROR : Failed to create server socket"));
	}
	// 최초 생성 조준창 크기 전시(20x20)
	m_strAimSize_X.Format(_T("%d"), (s16AimRT_X - s16AimLB_X + 1) / 2);
	m_strAimSize_Y.Format(_T("%d"), (s16AimLB_Y - s16AimRT_Y + 1) / 2);
	m_strLLX.Format(_T("-"));
	m_strLLY.Format(_T("-"));
	m_strRUX.Format(_T("-"));
	m_strRUY.Format(_T("-"));

	UpdateData(FALSE);

	SetTimer(5000, 500, NULL);
	// LoadnDraw();

	m_pThread = ::AfxBeginThread(CamDataRecv, this);

	this->SetFocus();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFCU_SWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();

	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFCU_SWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFCU_SWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
//  사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다. 이들
//  메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
//  UI가 표시되지 않아도 대화 상자는
//  남겨 둡니다.

void CFCU_SWDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CFCU_SWDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CFCU_SWDlg::OnCancel()
{
	if (m_ClientSocket_HILS.bSocketOpen == TRUE)
	{
		closesocket(m_ClientSocket_HILS.m_hSocket);
		m_ClientSocket_HILS.m_hSocket = INVALID_SOCKET;
	}

	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CFCU_SWDlg::CanExit()
{
	// 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
	//  이 응용 프로그램을 계속 사용합니다. 대화 상자는 남겨 두지만
	//  해당 UI는 숨깁니다.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CFCU_SWDlg::TransparentPNG(CImage* png)
{
	for (int i = 0; i < png->GetWidth(); i++)
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			byte* pucColor = (byte*)(png->GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}


BOOL CFCU_SWDlg::MyLoadFromResource(CImage& img, LPCTSTR pName, LPCTSTR pType, HMODULE hInst)
{
	IStream* pStream = NULL;
	HRSRC hResource = ::FindResource(hInst, pName, pType); if (!hResource) return FALSE;
	DWORD nImageSize = ::SizeofResource(hInst, hResource); if (!nImageSize) return FALSE;

	HGLOBAL m_hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, nImageSize);
	BYTE* pBytes = (BYTE*)::LoadResource(hInst, hResource);

	if (m_hBuffer)
	{
		void* pSource = ::LockResource(::LoadResource(hInst, hResource));

		if (!pSource)
			return FALSE;

		void* pDest = ::GlobalLock(m_hBuffer);
		if (pDest)
		{
			CopyMemory(pDest, pSource, nImageSize);
			if (::CreateStreamOnHGlobal(m_hBuffer, FALSE, &pStream) == S_OK)
			{
				img.Load(pStream); // 여기만 수정 하면
				pStream->Release();
			}
			::GlobalUnlock(m_hBuffer);
		}
		::GlobalFree(m_hBuffer);
		m_hBuffer = NULL;
	}
	if (img.IsNull()) return FALSE;

	return TRUE;
}


BOOL CFCU_SWDlg::SetTitle(UINT16 state)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBitmap bmp;

	if (state == CASE_DRYRUN_MODE)
		bmp.LoadBitmap(IDB_TITLE_DRYRUN);
	else if (state == CASE_LAUNCH_MODE)
		bmp.LoadBitmap(IDB_TITLE_LAUNCH);
	else if (state == CASE_TEST_MODE)
		bmp.LoadBitmap(IDB_TITLE_TEST);

	HBITMAP oldBitmap = m_staticTitle.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	//m_staticTitle.GetClientRect(&m_rect);
	//CDC *dc1 = m_staticTitle.GetDC();
	//int height, width;

	//if(!m_imgTitle.IsNull())
	//    m_imgTitle.Destroy();

	//// 리소스 ID를 참조하여 PNG 로드
	//if(state == 1)
	//    MyLoadFromResource(m_imgTitle, (LPCTSTR)MAKEINTRESOURCE(IDB_TITLE_DRYRUN), _T("PNG"), 0);
	//else
	//    MyLoadFromResource(m_imgTitle, (LPCTSTR)MAKEINTRESOURCE(IDB_TITLE_BATTLE), _T("PNG"), 0);

	//height = m_imgTitle.GetHeight();
	//width = m_imgTitle.GetWidth();

	//if(!m_imgTitle.IsNull())
	//{
	//    m_imgTitle.Draw(dc1->m_hDC, CRect(-30, -10, width-30, height-10));
	//}

	//TransparentPNG(&m_imgTitle);

	return TRUE;
}


BOOL CFCU_SWDlg::SetMode(UINT16 state)
{
	CBitmap bmp;


	bmp.LoadBitmap(state);

	HBITMAP oldBitmap = m_staticMode.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


void CFCU_SWDlg::OnStnClickedimgmode()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ChangeLED(&m_LED_L6, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_ATK_MODE, 1000, NULL);

	if (m_u16AtkMode == ATK_MODE_UPPER)
	{
		m_u16AtkMode = ATK_MODE_DIRECT;
		SetMode(IDB_STAT_FRONT);
	}
	else
	{
		m_u16AtkMode = ATK_MODE_UPPER;
		SetMode(IDB_STAT_UPPER);
	}
}


BOOL CFCU_SWDlg::SetMslStat(UINT16 state)
{
	CBitmap bmp;

	switch (state)
	{
	case GREEN:
		m_u8MslStat = GREEN;
		bmp.LoadBitmap(IDB_STAT_MSL_G);
		break;
	case RED:
		m_wEXTPOW = ENABLE;
		OnBnClickedBtnPower();
		m_u8MslStat = RED;
		bmp.LoadBitmap(IDB_STAT_MSL_R);
		break;
	case WHITE:
		m_u8MslStat = WHITE;
		bmp.LoadBitmap(IDB_STAT_MSL_MONO);
		break;
	case BLACK:
		m_u8MslStat = BLACK;
		bmp.LoadBitmap(IDB_STAT_MSL_BK);
		break;
	case YELLOW:
		m_u8MslStat = YELLOW;
		bmp.LoadBitmap(IDB_STAT_MSL_Y);
		break;
	}

	HBITMAP oldBitmap = m_staticMslStat.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


BOOL CFCU_SWDlg::SetSkrLamp(UINT16 state)
{
	CBitmap bmp;

	switch (state)
	{
	case RED:
		m_u8LampStat = RED;
		bmp.LoadBitmap(IDB_LAMP_SKR_RDY_02);
		break;
	case BLACK:
		m_u8LampStat = BLACK;
		bmp.LoadBitmap(IDB_LAMP_SKR_RDY_01);
		break;
	}

	HBITMAP oldBitmap = m_LampSkrRdy.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


BOOL CFCU_SWDlg::SetSkrStat(UINT16 state)
{
	CBitmap bmp;

	switch (state)
	{
	case GREEN:
		bmp.LoadBitmap(IDB_SKR_G);
		break;
	case RED:
		bmp.LoadBitmap(IDB_SKR_R);
		break;
	case WHITE:
		bmp.LoadBitmap(IDB_SKR_MONO);
		break;
	case BLACK:
		bmp.LoadBitmap(IDB_SKR_BLACK);
		break;
	case YELLOW:
		bmp.LoadBitmap(IDB_SKR_Y);
		break;
	}

	HBITMAP oldBitmap = m_staticSkrStat.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}



BOOL CFCU_SWDlg::SetLnchStat(UINT16 state)
{
	CBitmap bmp;

	if (state == GREEN)
	{
		bmp.LoadBitmap(IDB_STAT_EQ_G);
	}
	else if (state == RED)
	{
		bmp.LoadBitmap(IDB_STAT_EQ_R);
	}
	else if (state == MONO)
	{
		bmp.LoadBitmap(IDB_STAT_EQ_MONO);
	}

	HBITMAP oldBitmap = m_staticLnchStat.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


HBRUSH CFCU_SWDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT nID = pWnd->GetDlgCtrlID();

	switch (nID)
	{
		//case IDC_STATIC1:
		//case IDC_STATIC2:
		//case IDC_STATIC3:
		//case IDC_STATIC4:
		//case IDC_STATIC9:
		//	pDC->SetTextColor(RGB(130, 130, 130));
		//	//pDC -> SetBkColor( RGB(70, 70, 250) );
		//	//hbr = ::CreateSolidBrush( RGB(70, 70, 250) );
		//	break;
	case IDC_STATIC1:
	case IDC_STATIC2:
	case IDC_STATIC3:
	case IDC_STATIC4:
	case IDC_STATIC9:
	case IDC_STATIC5:
	case IDC_STATIC6:
	case IDC_STATIC7:
	case IDC_STATIC8:
	case IDC_STATIC10:
	case IDC_STATIC11:
	case IDC_STATIC12:
	case IDC_STATIC13:
	case IDC_STATIC14:
	case IDC_STATIC_MPOW:
	case IDC_STATIC_APOW:
		pDC->SetTextColor(RGB(200, 200, 200));
		break;
	case IDC_STATIC_PLC_SPACE:
	case IDC_STATIC_PLC_VALUE:
	case IDC_STATIC_TRGT_RNG:
	case IDC_STATIC_V1:
	case IDC_STATIC_V2:
	case IDC_STATIC_V3:
	case IDC_STATIC_A1:
	case IDC_STATIC_A2:
	case IDC_STATIC_A3:
	case IDC_STATIC_STS_CHK:
	case IDC_STATIC_RDY_CMD:
	case IDC_STATIC_CUSQ:
	case IDC_STATIC_VAL_V1:
	case IDC_STATIC_VAL_V2:
	case IDC_STATIC_VAL_V3:
	case IDC_STATIC_VAL_A1:
	case IDC_STATIC_VAL_A2:
	case IDC_STATIC_VAL_A3:
	case IDC_STATIC_MSL_BIT_CHK:
	case IDC_STATIC_SKR_CAGE_CMD:
	case IDC_STATIC_MSL_ID_CHK:
	case IDC_STATIC_SKR_RDY_CHK:
	case IDC_STATIC_SKR_PLC_CHK:
	case IDC_STATIC_SKR_TRK_STATUS:
	case IDC_STATIC_BATSQ:
	case IDC_STATIC_PINSQ:
	case IDC_STATIC_EMSQ:
	case IDC_STATIC_BATSQ_L:
	case IDC_STATIC_SKR_RDY:
	case IDC_STATIC_SKR_TEMP:
	case IDC_STATIC_FPA_TEMP:
	case IDC_STATIC_EXT_POW:
	case IDC_STATIC_MBAT_POW:
		pDC->SetTextColor(RGB(200, 200, 200));
		break;
	}

	return hbr;
}


BOOL CFCU_SWDlg::SetBrightness(UINT16 state)
{
	m_staticBright.GetClientRect(&m_rect);
	CDC* dc1 = m_staticBright.GetDC();
	int height, width;

	if (!m_imgBright.IsNull())
		m_imgBright.Destroy();

	// 리소스 ID를 참조하여 PNG 로드
	MyLoadFromResource(m_imgBright, (LPCTSTR)MAKEINTRESOURCE(IDB_BRIGHTNESS_15), _T("PNG"), 0);
	height = m_imgBright.GetHeight();
	width = m_imgBright.GetWidth();

	if (!m_imgBright.IsNull())
	{
		m_imgBright.Draw(dc1->m_hDC, CRect(-10, -10, width - 10, height - 10));
	}

	TransparentPNG(&m_imgBright);

	return TRUE;
}


BOOL CFCU_SWDlg::SetContrast(UINT16 state)
{
	m_staticContrast.GetClientRect(&m_rect);
	CDC* dc1 = m_staticContrast.GetDC();
	int height, width;

	if (!m_imgContrast.IsNull())
		m_imgContrast.Destroy();

	// 리소스 ID를 참조하여 PNG 로드
	MyLoadFromResource(m_imgContrast, (LPCTSTR)MAKEINTRESOURCE(IDB_CONTRAST_15), _T("PNG"), 0);
	height = m_imgContrast.GetHeight();
	width = m_imgContrast.GetWidth();

	if (!m_imgContrast.IsNull())
	{
		m_imgContrast.Draw(dc1->m_hDC, CRect(-10, -10, width - 10, height - 10));
	}

	TransparentPNG(&m_imgContrast);

	return TRUE;
}


BOOL CFCU_SWDlg::SetGas(UINT16 state)
{
	CBitmap bmp;

	if (state == 15)
		bmp.LoadBitmap(IDB_GAS_15);
	else if (state == 14)
		bmp.LoadBitmap(IDB_GAS_14);
	else if (state == 13)
		bmp.LoadBitmap(IDB_GAS_13);
	else if (state == 12)
		bmp.LoadBitmap(IDB_GAS_12);
	else if (state == 11)
		bmp.LoadBitmap(IDB_GAS_11);
	else if (state == 10)
		bmp.LoadBitmap(IDB_GAS_10);
	else if (state == 9)
		bmp.LoadBitmap(IDB_GAS_09);
	else if (state == 8)
		bmp.LoadBitmap(IDB_GAS_08);
	else if (state == 7)
		bmp.LoadBitmap(IDB_GAS_07);
	else if (state == 6)
		bmp.LoadBitmap(IDB_GAS_06);
	else if (state == 5)
		bmp.LoadBitmap(IDB_GAS_05);
	else if (state == 4)
		bmp.LoadBitmap(IDB_GAS_04);
	else if (state == 3)
		bmp.LoadBitmap(IDB_GAS_03);
	else if (state == 2)
		bmp.LoadBitmap(IDB_GAS_02);
	else if (state == 1)
		bmp.LoadBitmap(IDB_GAS_01);
	else if (state == 0)
		bmp.LoadBitmap(IDB_GAS_0);


	HBITMAP oldBitmap = m_staticGas.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


BOOL CFCU_SWDlg::SetWarn(UINT16 state)
{
	CBitmap bmp;

	bmp.LoadBitmap(IDB_WARN_CHANGE_GAS);

	HBITMAP oldBitmap = m_staticWarn.SetBitmap((HBITMAP)bmp.Detach());

	if (oldBitmap != NULL) ::DeleteObject(oldBitmap);

	return TRUE;
}


void CFCU_SWDlg::OnBnClickedBtnModeDryrun()
{
	SetTitle(CASE_DRYRUN_MODE);
	(GetDlgItem(IDC_imgTitle))->ShowWindow(TRUE);

	this->MoveWindow(0, 80, 960, 720);
	m_pFCU_STS_Dlg->ShowWindow(SW_SHOW);
	m_pFCU_STS_Dlg->PostMessageW(WM_SET_DRYRUN_MODE, NULL, NULL);

	(GetDlgItem(IDC_STATIC_VAL_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A3))->ShowWindow(TRUE);

	m_u8Mode = CASE_DRYRUN_MODE;
}


void CFCU_SWDlg::OnBnClickedBtnModeLaunch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTitle(CASE_LAUNCH_MODE);
	(GetDlgItem(IDC_imgTitle))->ShowWindow(TRUE);

	this->MoveWindow(0, 80, 960, 720);
	m_pFCU_STS_Dlg->ShowWindow(SW_SHOW);
	m_pFCU_STS_Dlg->PostMessageW(WM_SET_LAUNCH_MODE, NULL, NULL);


	(GetDlgItem(IDC_STATIC_VAL_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A3))->ShowWindow(TRUE);

	m_u8Mode = CASE_LAUNCH_MODE;
}


void CFCU_SWDlg::OnBnClickedBtnModeTest()
{
	SetTitle(CASE_TEST_MODE);
	(GetDlgItem(IDC_imgTitle))->ShowWindow(TRUE);
	m_pFCU_STS_Dlg->ShowWindow(SW_HIDE);
	m_ptCModeSelect->ShowWindow(SW_HIDE);
	this->MoveWindow(0, 80, 960, 960);

	(GetDlgItem(IDC_LED_MSL_BIT_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_SKR_RDY_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_CUSQ_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_CUSQ_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_SKR_CAGE_CMD_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_SKR_PLC_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_SKR_PLC_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_SKR_TRK_STATUS_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_SKR_TRK_STATUS_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_MSL_ID_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_BATSQ_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_BATSQ_TEST))->ShowWindow(TRUE);

	(GetDlgItem(IDC_BTN_MSL_STS_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_MSL_STS_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_LIFTOFF_RDY_CMD_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_LIFTOFF_RDY_CMD_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_PINSQ_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_PINSQ_TEST))->ShowWindow(TRUE);

	(GetDlgItem(IDC_BTN_DISC_TEST_MODE_SET))->ShowWindow(TRUE);

	//(GetDlgItem(IDC_TXT_MBAT))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A2))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A2))->ShowWindow(TRUE);
	//(GetDlgItem(IDC_TXT_ABAT))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_V3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_VAL_A3))->ShowWindow(TRUE);
	(GetDlgItem(IDC_STATIC_A3))->ShowWindow(TRUE);

	(GetDlgItem(IDC_BTN_MSL_BIT_CHK_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_MSL_ID_CHK))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_SKR_RDY_CHK))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_SKR_CAGE_CMD_TEST))->ShowWindow(TRUE);
	(GetDlgItem(IDC_BTN_EMSQ))->ShowWindow(TRUE);
	(GetDlgItem(IDC_LED_EMSQ_TEST))->ShowWindow(TRUE);

	m_u8Mode = CASE_TEST_MODE;
}


void CFCU_SWDlg::OnAcceleratorF1()
{
	if (m_u8Mode == CASE_INITIAL_MODE)
	{
		OnBnClickedBtnModeLaunch();
	}
	else
	{
		m_pRecvView->AddEventString(_T("운용 모드를 변경할 수 없습니다!"));
	}
	this->SetFocus();
}


void CFCU_SWDlg::OnAcceleratorF2()
{
	if (m_u8Mode == CASE_INITIAL_MODE)
	{

		OnBnClickedBtnModeDryrun();

	}
	else
	{
		m_pRecvView->AddEventString(_T("운용 모드를 변경할 수 없습니다!"));
	}
	this->SetFocus();
}


void CFCU_SWDlg::OnAcceleratorF3()
{
	m_pFCU_STS_Dlg->OnBnClickedBtnLnchModeStop();
	this->SetFocus();
}


void CFCU_SWDlg::OnAcceleratorF4()
{
	m_pFCU_STS_Dlg->OnBnClickedBtnMainScreen();
	this->SetFocus();
}


BOOL CFCU_SWDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}


void CFCU_SWDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CWnd* pWnd;
	CString strTmp;
	static int a = 0;
	static UINT8 u8MslStat = 0;
	static UINT8 u8SkrStat = 0;
	static UINT8 u8MaxMslBitTime = 0;
	static UINT16 u16CurSkrRdyTime = 0;
	static UINT16 u16CurMslBitTime = 0;
	static UINT16 u16CurSkrPlcTime = 0;
	static UINT16 u16CurSkrTrkTime = 0;
	static UINT16 u16CurSkrCageTime = 0;
	CFCU_SWDlg* pDlg = (CFCU_SWDlg*)AfxGetApp()->m_pMainWnd;

	switch (nIDEvent)
	{
	case 5000:
		KillTimer(5000);
		LoadnDraw();
		break;

	case CASE_EXT_POW_OFF:
		KillTimer(CASE_EXT_POW_OFF);

		m_txtVAL_V1.SetWindowTextW(_T("0"));
		m_txtVAL_A1.SetWindowTextW(_T("0"));
		break;

	case CASE_GSTREAMER:
		KillTimer(CASE_GSTREAMER);
		m_bSKR_IMG_CTRL = TRUE;
		m_SocketServer.SendData(HEADER_SKR_IMG_CTRL);
		break;

	case CASE_SET_MAX_SKR_CAGE_TIME:
		KillTimer(CASE_SET_MAX_SKR_CAGE_TIME);
		KillTimer(HEADER_SKR_CAGE_CMD);

		u16CurSkrCageTime = 0;

		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, RED, NULL);

		SetSkrStat(RED);
		SetMslStat(RED);

		break;
	case CASE_SET_MAX_ATK_MOD_TIME:
		KillTimer(CASE_SET_MAX_ATK_MOD_TIME);
		m_pFCU_STS_Dlg->PostMessageW(WM_ATK_MOD, RED, NULL);
		break;

	case CASE_SET_MAX_MSL_BIT_TIME:
		u8MaxMslBitTime = 0;
		bLED_State = FALSE;
		u16LED_Cnt = 0;
		m_u8MslTestFlag = 0;

		KillTimer(CASE_SET_MAX_MSL_BIT_TIME);
		KillTimer(CASE_MSL_STAT_CHANGE);
		KillTimer(CASE_SKR_STAT_CHANGE);
		KillTimer(HEADER_MSL_BIT_CHK);

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledMSL_BIT_CHK_TEST, IDI_LED_RED);
		}
		else
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_MSL_BIT_CHK, RED, NULL);
		}

		SetSkrStat(RED);
		SetMslStat(RED);

		break;

	case CASE_SET_MAX_SKR_RDY_TIME:
		m_u8MaxSkrRdyTime++;

		if (m_u8MaxSkrRdyTime >= 15)
		{
			KillTimer(CASE_SET_MAX_SKR_RDY_TIME);
			m_u8MaxSkrRdyTime = 0;

			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, RED, NULL);
			KillTimer(HEADER_SKR_RDY_CHK);
			KillTimer(CASE_SKR_STAT_CHANGE);

			SetSkrStat(RED);
			SetMslStat(RED);

			this->SetFocus();
		}

		break;

	case CASE_SET_MAX_LIFTOFF_RDY_TIME:
		KillTimer(CASE_SET_MAX_LIFTOFF_RDY_TIME);
		m_pFCU_STS_Dlg->PostMessageW(WM_LIFTOFF_RDY, RED, NULL);
		SetMslStat(RED);

		m_pShowWarning->ShowWindow(SW_SHOW);

		break;

	case CASE_SET_MAX_PINSQB_TIME:
		KillTimer(CASE_SET_MAX_PINSQB_TIME);
		KillTimer(HEADER_PINSQ);
		// m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, RED, NULL);
		SetMslStat(RED);

		m_pShowWarning->ShowWindow(SW_SHOW);

		break;

	case CASE_SET_MAX_EMSQUIB_TIME:
		KillTimer(CASE_SET_MAX_EMSQUIB_TIME);
		KillTimer(HEADER_EMSQ);
		SetMslStat(RED);

		m_pShowWarning->ShowWindow(SW_SHOW);

		break;

	case CASE_MSL_STAT_CHANGE:
		if (m_u8MslTestFlag % 2)
		{
			SetMslStat(BLACK);
		}
		else
		{
			SetMslStat(YELLOW);
		}
		m_u8MslTestFlag++;
		break;

	case CASE_SKR_STAT_CHANGE:
		if (u8SkrStat % 2)
		{
			SetSkrStat(BLACK);
		}
		else
		{
			SetSkrStat(YELLOW);
		}
		u8SkrStat++;
		break;
	case HEADER_FCU_BIT_CHK:
		if (m_u8FCU_BIT_CNT > 4)
		{
			m_u8FCU_BIT_CNT = 0;
			SetMslStat(BLACK);
			SetLnchStat(MONO);
			KillTimer(HEADER_FCU_BIT_CHK);
			(GetDlgItem(IDC_LAMP_SKR_RDY))->ShowWindow(FALSE);

			// KillTimer(CASE_RECV_CAM);
			break;
		}

		m_SocketServer.SendData(HEADER_FCU_BIT_CHK);
		m_u8FCU_BIT_CNT++;
		break;
	case HEADER_EXIT:
		m_ClientSocket.End();
		m_SocketServer.Close();
		::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
		break;

	case CASE_RECV_CAM:
		HDC dc;
		int bpp;
		int padding;
		int border;
		RECT rect;
		cv::Size* winSize;
		BITMAPINFO* bmp_info;



		////카메라에서 프레임 1장 캡쳐
		//if (m_pVC_Cam->read(m_matMain))
		//{
		//	m_pVC_Cam->release();
		//	m_pVC_Cam = new cv::VideoCapture("udpsrc port=52999 caps=\"application/x-rtp,encoding-name=H264,payload=96\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
		//	
		//	break;
		//}


		resize(m_matMain, m_matMain, Size(512, 512), 0, 0, 1);

		//화면 회전
		//rotate(m_matMain, m_matMain, cv::ROTATE_180);
		//화면 좌우 반전
		// flip(m_matMain, m_matMain, 1);
		//화면 상하 반전
		//flip(m_matMain, m_matMain, 0);

		if (m_bAimT == TRUE)
		{
			// T자선 X축
			cv::line(m_matMain, cv::Point(m_s16YAW_CAM - 35, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM - 5, m_s16PITCH_CAM), m_sclAim, 2, 1, 0);
			cv::line(m_matMain, cv::Point(m_s16YAW_CAM + 5, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM + 35, m_s16PITCH_CAM), m_sclAim, 2, 1, 0);
			cv::line(m_matMain, cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM), m_sclAim, 2, 1, 0);

			// T자선 Y축
			cv::line(m_matMain, cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM + 5), cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM + 35), m_sclAim, 2, 1, 0);
		}

		if (m_bAimTracking == TRUE)
		{
			// 위 가로
			cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16SY_CAM), cv::Point(m_s16SX_CAM, m_s16SY_CAM), m_sclAim, 2, 1, 0);

			// 밑 가로
			cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16EY_CAM), cv::Point(m_s16SX_CAM, m_s16EY_CAM), m_sclAim, 2, 1, 0);

			// 위 세로
			cv::line(m_matMain, cv::Point(m_s16SX_CAM, m_s16SY_CAM), cv::Point(m_s16SX_CAM, m_s16EY_CAM), m_sclAim, 2, 1, 0);

			// 밑 세로
			cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16SY_CAM), cv::Point(m_s16EX_CAM, m_s16EY_CAM), m_sclAim, 2, 1, 0);
		}

		if (m_bAimSight == TRUE)
		{
			if (m_u16currentCMD == HEADER_SKR_TRK_STATUS)
			{
				m_sclAimResult = SCL_GREEN;
			}

			// 위 가로
			cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimRT_Y), cv::Point(s16AimLB_X + 5, s16AimRT_Y), m_sclAimResult, 2, 1, 0);
			cv::line(m_matMain, cv::Point(s16AimRT_X - 5, s16AimRT_Y), cv::Point(s16AimRT_X, s16AimRT_Y), m_sclAimResult, 2, 1, 0);

			// 밑 가로
			cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimLB_Y), cv::Point(s16AimLB_X + 5, s16AimLB_Y), m_sclAimResult, 2, 1, 0);
			cv::line(m_matMain, cv::Point(s16AimRT_X - 5, s16AimLB_Y), cv::Point(s16AimRT_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);

			// 위 세로
			cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimRT_Y), cv::Point(s16AimLB_X, s16AimRT_Y + 5), m_sclAimResult, 2, 1, 0);
			cv::line(m_matMain, cv::Point(s16AimRT_X, s16AimRT_Y), cv::Point(s16AimRT_X, s16AimRT_Y + 5), m_sclAimResult, 2, 1, 0);

			// 밑 세로
			cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimLB_Y - 5), cv::Point(s16AimLB_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);
			cv::line(m_matMain, cv::Point(s16AimRT_X, s16AimLB_Y - 5), cv::Point(s16AimRT_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);

		}

		//화면 상하 반전
		flip(m_matMain, m_matMain, 0);

		// 화면에 보여주기 위한 처리
		bpp = 8 * (int)m_matMain.elemSize();
		assert((bpp == 8 || bpp == 24 || bpp == 32));

		padding = 0;
		if (bpp < 32) {
			padding = 4 - (m_matMain.cols % 4);
		}
		if (padding == 4) {
			padding = 0;
		}

		border = 0;
		if (bpp < 32) {
			border = 4 - (m_matMain.cols % 4);
		}

		m_matTmp = m_matMain;

		//picture_control UI 크기 가져오기
		m_imgCam.GetClientRect(&rect);

		//picture_control UI 크기정보를 cv::Size에 저장
		winSize = new cv::Size(rect.right, rect.bottom);

		//CImage 생성
		m_cimgCam.Create(winSize->width, winSize->height, 24);

		//bitmap 헤더정보
		bmp_info = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
		bmp_info->bmiHeader.biBitCount = bpp;
		bmp_info->bmiHeader.biWidth = m_matTmp.cols;
		bmp_info->bmiHeader.biHeight = m_matTmp.rows;
		bmp_info->bmiHeader.biPlanes = 1;
		bmp_info->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmp_info->bmiHeader.biCompression = BI_RGB;
		bmp_info->bmiHeader.biClrImportant = 0;
		bmp_info->bmiHeader.biClrUsed = 0;
		bmp_info->bmiHeader.biSizeImage = 0;
		bmp_info->bmiHeader.biXPelsPerMeter = 0;
		bmp_info->bmiHeader.biYPelsPerMeter = 0;

		if (bpp == 8) {
			RGBQUAD* palette = bmp_info->bmiColors;
			for (int i = 0; i < 256; i++) {
				palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
				palette[i].rgbReserved = 0;
			}
		}

		//CImage buffer에 frame update
		if (m_matTmp.cols == winSize->width && m_matTmp.rows == winSize->height) {
			SetDIBitsToDevice(m_cimgCam.GetDC(),
				0, 0, winSize->width, winSize->height,
				0, 0, 0, m_matTmp.rows,
				m_matTmp.data, bmp_info, DIB_RGB_COLORS);
		}
		else {
			int destx = 0;
			int desty = 0;
			int destw = winSize->width;
			int desth = winSize->height;
			int imgx = 0;
			int imgy = 0;
			int imgWidth = m_matTmp.cols - border;
			int imgHeight = m_matTmp.rows;

			StretchDIBits(m_cimgCam.GetDC(),
				destx, desty, destw, desth,
				imgx, imgy, imgWidth, imgHeight,
				m_matTmp.data, bmp_info, DIB_RGB_COLORS, SRCCOPY);
		}

		//picture control에 CImage buffer update
		dc = ::GetDC(m_imgCam.m_hWnd);
		m_cimgCam.BitBlt(dc, 0, 0);

		::ReleaseDC(m_imgCam.m_hWnd, dc);
		m_cimgCam.ReleaseDC();
		m_cimgCam.Destroy();

		break;

	case FCU_SWDLG_INIT:
		KillTimer(FCU_SWDLG_INIT);

		// SetTitle(1);

		SetMode(IDB_STAT_UPPER);
		SetMslStat(BLACK);
		SetSkrStat(BLACK);
		SetLnchStat(MONO);

		SetGas(15);

		LoadnDraw();

		this->SetFocus();

		break;

	case FCU_AUTO_START:
		KillTimer(FCU_AUTO_START);

		OnBnClickedBtnMslBitChk();

		break;
	case HEADER_MSL_BIT_CHK:
		pWnd = (CWnd*)GetDlgItem(IDC_BTN_MSL_BIT_CHK_TEST);
		pWnd->EnableWindow(FALSE);

		m_SocketServer.SendData(HEADER_MSL_BIT_CHK);
		u16CurMslBitTime++;

		if ((u16CurMslBitTime % 7) == 0)
		{
			if (bLED_State == FALSE)
			{

				bLED_State = TRUE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnMslBitChkTest.LoadBitmaps(IDB_BTN_MSL_BIT_03, IDB_BTN_MSL_BIT_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_MSL_BIT_CHK, WHITE, NULL);
				}
			}
			else
			{
				bLED_State = FALSE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnMslBitChkTest.LoadBitmaps(IDB_BTN_MSL_BIT_01, IDB_BTN_MSL_BIT_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_MSL_BIT_CHK, YELLOW, NULL);
				}
			}
		}
		pWnd->EnableWindow(TRUE);

		break;

	case HEADER_SKR_CAGE_CMD:
		pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_CAGE_CMD_TEST);
		pWnd->EnableWindow(FALSE);

		m_SocketServer.SendData(HEADER_SKR_CAGE_CMD);
		u16CurSkrCageTime++;

		if ((u16CurSkrCageTime % 7) == 0)
		{

			if (bLED_State == FALSE)
			{
				bLED_State = TRUE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrCageCmdTest.LoadBitmaps(IDB_BTN_SKR_CAGE_CMD_03, IDB_BTN_SKR_CAGE_CMD_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, WHITE, NULL);
				}

			}
			else
			{
				bLED_State = FALSE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrCageCmdTest.LoadBitmaps(IDB_BTN_SKR_CAGE_CMD_01, IDB_BTN_SKR_CAGE_CMD_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, YELLOW, NULL);
				}
			}
		}

		pWnd->EnableWindow(TRUE);
		break;

	case HEADER_SKR_RDY_CHK:

		// m_pRecvView->AddEventString(15 - u16LED_Cnt, TYPE_WORD);
		m_SocketServer.SendData(HEADER_SKR_RDY_CHK);
		u16CurSkrRdyTime++;

		if ((u16CurSkrRdyTime % 7) == 0)
		{
			pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_RDY_CHK);
			pWnd->EnableWindow(FALSE);
			if (bLED_State == FALSE)
			{
				bLED_State = TRUE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrRdyChk.LoadBitmaps(IDB_BTN_SKR_RDY_CHK_03, IDB_BTN_SKR_RDY_CHK_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, WHITE, NULL);
				}
			}
			else
			{
				bLED_State = FALSE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrRdyChk.LoadBitmaps(IDB_BTN_SKR_RDY_CHK_01, IDB_BTN_SKR_RDY_CHK_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, YELLOW, NULL);
				}
			}
			pWnd->EnableWindow(TRUE);
		}

		break;

	case HEADER_SKR_PLC_CHK:
		m_SocketServer.SendData(HEADER_SKR_PLC_CHK);
		u16CurSkrPlcTime++;

		if ((u16CurSkrPlcTime % 7) == 0)
		{
			pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_PLC_CHK_TEST);
			pWnd->EnableWindow(FALSE);

			if (bLED_State == FALSE)
			{
				bLED_State = TRUE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrPlcChkTest.LoadBitmaps(IDB_BTN_SKR_PLC_CHK_03, IDB_BTN_SKR_PLC_CHK_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					// m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, WHITE, NULL);
				}
			}
			else
			{
				bLED_State = FALSE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrPlcChkTest.LoadBitmaps(IDB_BTN_SKR_PLC_CHK_01, IDB_BTN_SKR_PLC_CHK_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					// m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, YELLOW, NULL);
				}
			}
			pWnd->EnableWindow(TRUE);
		}

		break;

	case HEADER_SKR_TRK_STATUS:

		m_SocketServer.SendData(HEADER_SKR_TRK_STATUS);
		u16CurSkrTrkTime++;

		if ((u16CurSkrTrkTime % 7) == 0)
		{
			pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_TRK_STATUS_TEST);
			pWnd->EnableWindow(FALSE);

			if (bLED_State == FALSE)
			{
				bLED_State = TRUE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrTrkStatusTest.LoadBitmaps(IDB_BTN_SKR_TRK_STATUS_03, IDB_BTN_SKR_TRK_STATUS_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_TRK_STATUS, WHITE, NULL);
				}
			}
			else
			{
				bLED_State = FALSE;

				if (m_u8Mode == CASE_TEST_MODE)
				{
					m_btnSkrTrkStatusTest.LoadBitmaps(IDB_BTN_SKR_TRK_STATUS_01, IDB_BTN_SKR_TRK_STATUS_02, NULL, NULL);
				}
				else if ((m_u8Mode == CASE_LAUNCH_MODE) || (m_u8Mode == CASE_DRYRUN_MODE))
				{
					m_pFCU_STS_Dlg->PostMessageW(WM_SKR_TRK_STATUS, YELLOW, NULL);
				}
			}

			pWnd->EnableWindow(TRUE);
		}

		break;

	case HEADER_MSL_STS_CHK:
		m_SocketServer.SendData(HEADER_MSL_STS_CHK);

		break;

	case CASE_SET_MAX_MSL_STS_TIME:
		KillTimer(HEADER_MSL_STS_CHK);
		KillTimer(CASE_SET_MAX_MSL_STS_TIME);

		// 220627 수정
		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_STS_CHK, RED, NULL);
		SetMslStat(RED);

		// OnBnClickedBtnLiftoffRdyCmd();
		// ~220627 수정

		break;

	case HEADER_LIFTOFF_RDY_CMD:
		KillTimer(HEADER_LIFTOFF_RDY_CMD);
		OnBnClickedBtnLiftoffRdyCmd();

		break;

	case HEADER_BATSQ:
		KillTimer(HEADER_BATSQ);
		m_wEXTPOW = DISABLE;
		// 전원 제어 커맨드 Send
		m_SocketServer.SendData(HEADER_EXT_POW_ON);
		SetTimer(CASE_EXT_POW_OFF, 300, 0);
		KillTimer(HEADER_EXT_POW_CHK);

		pWnd = (CWnd*)GetDlgItem(IDC_BTN_POWER);
		pWnd->EnableWindow(FALSE);
		m_btnPower.LoadBitmaps(IDB_BTN_POWER_02, IDB_BTN_POWER_02, NULL, NULL);
		pWnd->EnableWindow(TRUE);

		OnBnClickedBtnMslStsChk();

		break;

	case HEADER_EXT_POW_ON:
		ChangeLED(&m_LED_L7, IDI_BTN_GREEN_UP);
		KillTimer(HEADER_EXT_POW_ON);

		break;

	case HEADER_EXT_POW_CHK:
		m_SocketServer.SendData(HEADER_EXT_POW_CHK);

		break;

	case HEADER_MBAT_ON:
		KillTimer(HEADER_MBAT_ON);
		m_SocketServer.SendData(HEADER_ABAT_ON);
		// KillTimer(HEADER_MBAT_ON);

		//m_SocketServer.SendData(HEADER_MBAT_POW_CHK);
		//m_SocketServer.SendData(HEADER_ABAT_POW_CHK);
		//SetTimer(HEADER_MBAT_POW_CHK, 1000, NULL);
		//SetTimer(HEADER_ABAT_POW_CHK, 1000, NULL);

		break;

	case HEADER_OFF_ABAT:
		m_SocketServer.SendData(HEADER_OFF_MBAT);
		KillTimer(HEADER_OFF_ABAT);
		//KillTimer(HEADER_MBAT_POW_CHK);
		//KillTimer(HEADER_ABAT_POW_CHK);

		m_txtVAL_V2.SetWindowTextW(_T("0"));
		m_txtVAL_V3.SetWindowTextW(_T("0"));

		m_txtVAL_A2.SetWindowTextW(_T("0"));
		m_txtVAL_A3.SetWindowTextW(_T("0"));
		break;

	case HEADER_MBAT_POW_CHK:
		m_SocketServer.SendData(HEADER_MBAT_POW_CHK);

		break;

	case HEADER_ABAT_POW_CHK:
		m_SocketServer.SendData(HEADER_ABAT_POW_CHK);

		break;

	case HEADER_CUSQ:

		m_u8GasCnt = m_u8GasCnt - 1;

		if ((0 <= m_u8GasCnt) && (m_u8GasCnt <= 15))
		{
			SetGas(m_u8GasCnt);
		}
		else
		{
			KillTimer(HEADER_CUSQ);
			// m_u8GasCnt = 15;

			break;
		}

		break;

	case HEADER_PINSQ:
		if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[3] == 0x0001)
		{
			KillTimer(HEADER_PINSQ);
			KillTimer(CASE_SET_MAX_PINSQB_TIME);
			// m_pFCU_STS_Dlg->PostMessageW(WM_SQB_PIN, GREEN, NULL);
			OnBnClickedBtnEmsq();
		}

		break;

	case HEADER_EMSQ:
		if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[4] == 0x0001)
		{
			KillTimer(HEADER_EMSQ);
			KillTimer(CASE_SET_MAX_EMSQUIB_TIME);
			OnBnClickedBtnFold();
		}

		break;

	case CASE_KEY_UPPER:
		ChangeLED(&m_LED_L1, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_UPPER);
		break;

	case CASE_KEY_LEFT:
		ChangeLED(&m_LED_L2, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_LEFT);
		break;

	case CASE_KEY_RIGHT:
		ChangeLED(&m_LED_L4, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_RIGHT);
		break;

	case CASE_KEY_BOTTOM:
		ChangeLED(&m_LED_L5, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_BOTTOM);
		break;
	case CASE_KEY_CENTER:
		ChangeLED(&m_LED_L3, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_CENTER);
		break;
	case CASE_KEY_ATK_MODE:
		ChangeLED(&m_LED_L6, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_ATK_MODE);
		break;
	case CASE_KEY_MSL_POW:
		ChangeLED(&m_LED_L7, IDI_BTN_GREEN_UP);
		KillTimer(CASE_KEY_MSL_POW);
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CFCU_SWDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTitle(2);
}


BOOL CFCU_SWDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (::TranslateAccelerator(this->m_hWnd, m_hAccel, pMsg))
		return TRUE;

	if (pMsg->message == WM_KEYDOWN)
	{
		m_pShowWarning->ShowWindow(SW_HIDE);

		if (pMsg->wParam == VK_ESCAPE)
		{
			// ESC 키 이벤트에 대한 처리 추가
			return TRUE;
		}
		else if (pMsg->wParam == VK_RETURN)
		{
			// Enter 키 이벤트에 대한 처리 추가
			return TRUE;
		}
		else if ((VK_LEFT <= pMsg->wParam) && (pMsg->wParam <= VK_DOWN))
		{
			switch (pMsg->wParam)
			{
			case VK_LEFT:
				OnBnClickedBtnLeft();
				break;
			case VK_RIGHT:
				OnBnClickedBtnRight();
				break;
			case VK_UP:
				OnBnClickedBtnUp();
				break;
			case VK_DOWN:
				OnBnClickedBtnDown();
				break;
			}
		}
		//else if (pMsg->wParam == VK_SPACE)
		//{
		//	AfxMessageBox(_T("!"));
		//	OnBnClickedReLockOnCmd();
		//}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CFCU_SWDlg::OnBnClickedAtkModeCmd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBitmap bmp;

	if (m_CAtkModeCmd.DoModal() == IDOK)
	{
		if (m_bSKR_TRK_STATUS == TRUE)
		{
			updateSKR_TRK_STATUS();
		}
		m_SocketServer.SendData(HEADER_ATK_MODE_CMD);
		ChangeLED(&m_LED_L6, IDI_BTN_GREEN_DOWN);
		SetTimer(CASE_KEY_ATK_MODE, 1000, NULL);

		KillSKR_TRK_STATUS();

		if (m_ClientSocket.m_u16AtkMode == ATK_MODE_DIRECT)
			bmp.LoadBitmap(IDB_STAT_FRONT);
		else if (m_ClientSocket.m_u16AtkMode == ATK_MODE_UPPER)
			bmp.LoadBitmap(IDB_STAT_UPPER);
		else
			m_pRecvView->AddEventString(_T("ERROR : ATK_MODE"));

		HBITMAP oldBitmap = m_staticMode.SetBitmap((HBITMAP)bmp.Detach());

		if (oldBitmap != NULL) ::DeleteObject(oldBitmap);
	}
}


void CFCU_SWDlg::OnMenuDryrun()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedBtnModeDryrun();
}


void CFCU_SWDlg::OnMenuLaunch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedBtnModeLaunch();
}


BOOL CFCU_SWDlg::SetFixResource(UINT16 state)
{
	m_staticMSLCON.GetClientRect(&m_rect);
	CDC* dc1 = m_staticMSLCON.GetDC();
	int height, width;

	if (!m_imgMSLCON.IsNull())
		m_imgMSLCON.Destroy();

	// 리소스 ID를 참조하여 PNG 로드
	MyLoadFromResource(m_imgMSLCON, (LPCTSTR)MAKEINTRESOURCE(IDB_TXT_MSLCON), _T("PNG"), 0);
	height = m_imgMSLCON.GetHeight();
	width = m_imgMSLCON.GetWidth();

	if (!m_imgMSLCON.IsNull())
	{
		m_imgMSLCON.Draw(dc1->m_hDC, CRect(-10, 0, width - 10, height));
	}

	TransparentPNG(&m_imgMSLCON);

	m_staticPINCHK.GetClientRect(&m_rect);
	CDC* dc2 = m_staticPINCHK.GetDC();

	if (!m_imgPINCHK.IsNull())
		m_imgPINCHK.Destroy();

	// 리소스 ID를 참조하여 PNG 로드
	MyLoadFromResource(m_imgPINCHK, (LPCTSTR)MAKEINTRESOURCE(IDB_TXT_PINCHK), _T("PNG"), 0);
	height = m_imgPINCHK.GetHeight();
	width = m_imgPINCHK.GetWidth();

	if (!m_imgPINCHK.IsNull())
	{
		m_imgPINCHK.Draw(dc2->m_hDC, CRect(-10, 0, width - 10, height));
	}

	TransparentPNG(&m_imgPINCHK);

	return TRUE;
}


void CFCU_SWDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	m_pShowWarning->ShowWindow(SW_HIDE);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CFCU_SWDlg::OnBnClickedCancelDlg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bWantExitHILS = TRUE;
	m_ptCModeSelect->ShowWindow(SW_HIDE);

	//if (m_ClientSocket_HILS.m_hSocket == INVALID_SOCKET)
	//{
	//	m_ClientSocket_HILS.Init(CONNECTION_IP, CONNECTION_PORT);
	//}

	if (m_pModeIO.DoModal() == IDOK)
	{
		if (m_pModeIO.m_u8DSCNNCT_RSLT == 0xF0)
		{
			// UDP 영상 송출 종료
			KillTimer(CASE_RECV_CAM);
			m_bSKR_IMG_CTRL = FALSE;
			m_SocketServer.SendData(HEADER_SKR_IMG_CTRL);

			m_ClientSocket.End();
			m_SocketServer.Close();
			::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
			return;
		}
		else if (m_pModeIO.m_u8DSCNNCT_RSLT == 0x00)
		{
			SetInitialDlg();
			this->SetFocus();
			return;
		}
	}
}


void CFCU_SWDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CFCU_SWDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//switch (nChar)
	//{
	//case VK_LEFT:
	//	OnBnClickedBtnLeft();
	//	break;
	//case VK_RIGHT:
	//	OnBnClickedBtnRight();
	//	break;
	//case VK_UP:
	//	OnBnClickedBtnUp();
	//	break;
	//case VK_DOWN:
	//	OnBnClickedBtnDown();
	//	break;
	//}
	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CFCU_SWDlg::OnBnClickedChangeMode()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	if (m_u8Mode == CASE_DRYRUN_MODE)
	{
		OnAcceleratorF2();
	}
	else if (m_u8Mode == CASE_LAUNCH_MODE)
	{
		OnAcceleratorF1();
	}
	else if (m_u8Mode = CASE_TEST_MODE)
	{
		OnAcceleratorF1();
	}

	m_pFCU_STS_Dlg->PostMessageW(WM_RESET_STAT, NULL, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnLaunch()
{
	u16LED_Cnt = 0;
	bLED_State = FALSE;
	KillTimer(HEADER_SKR_TRK_STATUS);

	m_SocketServer.SendData(HEADER_ATK_MODE_CMD);

	ChangeLED(&m_LED_L6, IDI_BTN_GREEN_UP);
	SetTimer(CASE_KEY_ATK_MODE, 1000, NULL);

	//if(bSKR_TRK_STATUS == TRUE)
	//{
	//    updateSKR_PLC_CHK();
	//}
}


/* 점검 모드 LED 클릭 이벤트 처리 */
void CFCU_SWDlg::OnStnClickedLedMslBitChkTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 BIT < 점검"));

	if (m_bMSL_BIT_CHK == FALSE)
	{
		m_ptMSL_BIT_CHK = new CMSL_BIT_CHK;
		m_bMSL_BIT_CHK = m_ptMSL_BIT_CHK->Create(IDD_MSL_BIT_CHK);
		m_ptMSL_BIT_CHK->PostMessageW(WM_MSL_BIT_CHK, NULL, NULL);
		m_ptMSL_BIT_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_BIT_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedCusqTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("냉각 가스통 조립체 점화 < 점검"));
}


void CFCU_SWDlg::OnStnClickedLedSkrCageCmdTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탐색기 구속 명령 < 점검"));

	if (m_bSKR_CAGE_CMD == FALSE)
	{
		m_ptSKR_CAGE_CMD = new CSKR_CAGE_CMD;
		m_bSKR_CAGE_CMD = m_ptSKR_CAGE_CMD->Create(IDD_SKR_CAGE_CMD);
		m_ptSKR_CAGE_CMD->PostMessageW(WM_SKR_CAGE_CMD, NULL, NULL);
		m_ptSKR_CAGE_CMD->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_CAGE_CMD->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedMslIdChkTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 ID 확인 < 점검"));

	if (m_bMSL_ID_CHK == FALSE)
	{
		m_ptMSL_ID_CHK = new CMSL_ID_CHK;
		m_bMSL_ID_CHK = m_ptMSL_ID_CHK->Create(IDD_MSL_ID_CHK);
		m_ptMSL_ID_CHK->PostMessageW(WM_MSL_ID_CHK, NULL, NULL);
		m_ptMSL_ID_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_ID_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrRdyChkTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탐색기 준비 상태 확인 < 점검"));

	if (m_bSKR_RDY_CHK == FALSE)
	{
		m_ptSKR_RDY_CHK = new CSKR_RDY_CHK;
		m_bSKR_RDY_CHK = m_ptSKR_RDY_CHK->Create(IDD_SKR_RDY_CHK);
		m_ptSKR_RDY_CHK->PostMessageW(WM_SKR_RDY_CHK, NULL, NULL);
		m_ptSKR_RDY_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_RDY_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrPlcChkTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("PLC 산출 < 점검"));

	if (m_bSKR_PLC_CHK == FALSE)
	{
		m_ptSKR_PLC_CHK = new CSKR_PLC_CHK;
		m_bSKR_PLC_CHK = m_ptSKR_PLC_CHK->Create(IDD_SKR_PLC_CHK);
		m_ptSKR_PLC_CHK->PostMessageW(WM_SKR_PLC_CHK, NULL, NULL);
		m_ptSKR_PLC_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_PLC_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrTrkStatusTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("표적 추적 상태 < 점검"));

	if (m_bSKR_TRK_STATUS == FALSE)
	{
		m_ptSKR_TRK_STATUS = new CSKR_TRK_STATUS;
		m_bSKR_TRK_STATUS = m_ptSKR_TRK_STATUS->Create(IDD_SKR_TRK_STATUS);
		m_ptSKR_TRK_STATUS->PostMessageW(WM_SKR_TRK_STATUS, NULL, NULL);
		m_ptSKR_TRK_STATUS->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_TRK_STATUS->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedBatsqTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("열전지 점화 < 점검"));
}


void CFCU_SWDlg::OnStnClickedLedMslStsChkTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 상태 확인 < 점검"));

	if (m_bMSL_STS_CHK == FALSE)
	{
		m_ptMSL_STS_CHK = new CMSL_STS_CHK;
		m_bMSL_STS_CHK = m_ptMSL_STS_CHK->Create(IDD_MSL_STS_CHK);
		m_ptMSL_STS_CHK->PostMessageW(WM_MSL_STS_CHK, NULL, NULL);
		m_ptMSL_STS_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_STS_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedLiftoffRdyCmdTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 사출 준비 명령 < 점검"));
}


void CFCU_SWDlg::OnStnClickedLedPinsqTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탄 구속 해제 < 점검"));
}
/* ~점검 모드 LED 클릭 이벤트 처리 */



/* ~드라이런/발사 모드 LED 클릭 이벤트 처리 */
void CFCU_SWDlg::OnStnClickedLedMslBitChk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 BIT"));

	if (m_bMSL_BIT_CHK == FALSE)
	{
		m_ptMSL_BIT_CHK = new CMSL_BIT_CHK;
		m_bMSL_BIT_CHK = m_ptMSL_BIT_CHK->Create(IDD_MSL_BIT_CHK);
		m_ptMSL_BIT_CHK->PostMessageW(WM_MSL_BIT_CHK, NULL, NULL);
		m_ptMSL_BIT_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_BIT_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedCusq()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("냉각 가스통 조립체 점화"));

}


void CFCU_SWDlg::OnStnClickedLedSkrCageCmd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탐색기 구속 확인"));

	if (m_bSKR_CAGE_CMD == FALSE)
	{
		m_ptSKR_CAGE_CMD = new CSKR_CAGE_CMD;
		m_bSKR_CAGE_CMD = m_ptSKR_CAGE_CMD->Create(IDD_SKR_CAGE_CMD);
		m_ptSKR_CAGE_CMD->PostMessageW(WM_SKR_CAGE_CMD, NULL, NULL);
		m_ptSKR_CAGE_CMD->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_CAGE_CMD->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedMslIdChk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 ID 확인"));

	if (m_bMSL_ID_CHK == FALSE)
	{
		m_ptMSL_ID_CHK = new CMSL_ID_CHK;
		m_bMSL_ID_CHK = m_ptMSL_ID_CHK->Create(IDD_MSL_ID_CHK);
		m_ptMSL_ID_CHK->PostMessageW(WM_MSL_ID_CHK, NULL, NULL);
		m_ptMSL_ID_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_ID_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrRdyChk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탐색기 준비 상태 확인"));

	if (m_bSKR_RDY_CHK == FALSE)
	{
		m_ptSKR_RDY_CHK = new CSKR_RDY_CHK;
		m_bSKR_RDY_CHK = m_ptSKR_RDY_CHK->Create(IDD_SKR_RDY_CHK);
		m_ptSKR_RDY_CHK->PostMessageW(WM_SKR_RDY_CHK, NULL, NULL);
		m_ptSKR_RDY_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_RDY_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrPlcChk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("PLC 확인"));

	if (m_bSKR_PLC_CHK == FALSE)
	{
		m_ptSKR_PLC_CHK = new CSKR_PLC_CHK;
		m_bSKR_PLC_CHK = m_ptSKR_PLC_CHK->Create(IDD_SKR_PLC_CHK);
		m_ptSKR_PLC_CHK->PostMessageW(WM_SKR_PLC_CHK, NULL, NULL);
		m_ptSKR_PLC_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_PLC_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedSkrTrkStatus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("표적 추적 상태 확인"));

	if (m_bSKR_TRK_STATUS == FALSE)
	{
		m_ptSKR_TRK_STATUS = new CSKR_TRK_STATUS;
		m_bSKR_TRK_STATUS = m_ptSKR_TRK_STATUS->Create(IDD_SKR_TRK_STATUS);
		m_ptSKR_TRK_STATUS->PostMessageW(WM_SKR_TRK_STATUS, NULL, NULL);
		m_ptSKR_TRK_STATUS->CenterWindow(CWnd::GetDesktopWindow());
		m_ptSKR_TRK_STATUS->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedBatsq()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 점화 상태"));
}


void CFCU_SWDlg::OnStnClickedLedMslStsChk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 상태 점검"));

	if (m_bMSL_STS_CHK == FALSE)
	{
		m_ptMSL_STS_CHK = new CMSL_STS_CHK;
		m_bMSL_STS_CHK = m_ptMSL_STS_CHK->Create(IDD_MSL_STS_CHK);
		m_ptMSL_STS_CHK->PostMessageW(WM_MSL_STS_CHK, NULL, NULL);
		m_ptMSL_STS_CHK->CenterWindow(CWnd::GetDesktopWindow());
		m_ptMSL_STS_CHK->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedLedLiftoffRdyCmd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("유도탄 사출 준비 명령"));
}


void CFCU_SWDlg::OnStnClickedLedPinsq()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("탄 구속 상태 확인"));
}


void CFCU_SWDlg::OnStnClickedLedEmsqTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("사출 모터 점화 상태 확인"));
}
/* ~드라이런/발사 모드 LED 클릭 이벤트 처리 */

void CFCU_SWDlg::OnBnClickedBtnPower()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ChangeLED(&m_LED_L7, IDI_BTN_GREEN_DOWN);
	SetTimer(HEADER_EXT_POW_ON, 1000, NULL);

	if (m_u8Mode != CASE_INITIAL_MODE)
	{
		//if (m_wMBATABAT = ENABLE)
		//{
		//	m_wEXTPOW = DISABLE;

		//	// 전원 제어 커맨드 Send
		//	m_SocketServer.SendData(HEADER_EXT_POW_ON);
		//	SetTimer(CASE_EXT_POW_OFF, 300, 0);

		//	return;
		//}

		CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_POWER);

		if (m_wEXTPOW == ENABLE)
		{
			m_wEXTPOW = DISABLE;
			m_bRE_ROCK_ON_Flag = FALSE;
			m_bRE_ROCK_ON_LED_Flag = FALSE;
			m_bLOCK_ON_RSLT_FAULT = FALSE;
			m_u16currentCMD = NULL;
			m_u8MslStat = BLACK;
			killAllTimer();
			ResetAim();

			// 전원 제어 커맨드 Send
			m_SocketServer.SendData(HEADER_EXT_POW_ON);
			SetTimer(CASE_EXT_POW_OFF, 300, 0);

			pWnd->EnableWindow(FALSE);
			m_btnPower.LoadBitmaps(IDB_BTN_POWER_02, IDB_BTN_POWER_02, NULL, NULL);
			pWnd->EnableWindow(TRUE);
		}
		else if (m_wEXTPOW == DISABLE)
		{
			m_wEXTPOW = ENABLE;
			// 전원 제어 커맨드 Send
			m_SocketServer.SendData(HEADER_EXT_POW_ON);

			// 전원 체크 타이머 On
			SetTimer(CASE_MSL_STAT_CHANGE, 500, NULL);
			// 버튼 활성화
			setEnableBTN(TRUE);

			// 전원 버튼 상태 변경
			pWnd->EnableWindow(FALSE);
			m_btnPower.LoadBitmaps(IDB_BTN_POWER_01, IDB_BTN_POWER_01, NULL, NULL);
			pWnd->EnableWindow(TRUE);

			// 전원 상승 및 유도탄 자체점검 시간 8초 타이머 Set
			if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
			{
				SetTimer(CASE_SET_MAX_SKR_RDY_TIME, 1000, NULL);

				OnBnClickedBtnCusq();
				SetTimer(FCU_AUTO_START, 8000, NULL);
			}
		}
	}
}


void CFCU_SWDlg::OnBnClickedLockOnCmd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_u16currentCMD = HEADER_LOCK_ON_CMD;

	u16LED_Cnt = 0;
	bLED_State = FALSE;

	KillTimer(HEADER_SKR_PLC_CHK);
	m_SocketServer.SendData(HEADER_LOCK_ON_CMD);
}


void CFCU_SWDlg::OnBnClickedReLockOnCmd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_u16currentCMD = HEADER_RE_LOCK_ON_CMD;

	u16LED_Cnt = 0;
	bLED_State = FALSE;

	KillTimer(HEADER_SKR_TRK_STATUS);
	m_SocketServer.SendData(HEADER_RE_LOCK_ON_CMD);
	ChangeLED(&m_LED_L3, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_CENTER, 500, NULL);
}


afx_msg LRESULT CFCU_SWDlg::OnConnectEvent(WPARAM wParam, LPARAM lParam)
{
	// m_u8FCU_BIT_CNT = 0;
	// SetTimer(HEADER_FCU_BIT_CHK, 1000, NULL);
	(GetDlgItem(IDC_LAMP_SKR_RDY))->ShowWindow(TRUE);
	m_u8ClientCnt = 1;

	// m_u8ClientCnt++;

	return 0;

}


// lParam->Receive 리턴값(길이)
afx_msg LRESULT CFCU_SWDlg::OnReceiveEvent(WPARAM wParam, LPARAM lParam)
{
	CString str, strTmp;
	UINT32 idx = 0;
	WORD wRecvedCRC = 0, wTmpCRC = 0;
	UINT32 u32Length = 0;
	BYTE m_bBufferTMP[1024];
	BYTE m_bBufferTMP2[1024];
	UINT16 Temp_Len = 0;
	UINT16 u16LengthNextTMP = 0;

	// m_pRecvView->AddEventString((WORD)lParam, TYPE_DEC);
	u32Length = (m_bBuffer[1] + 2) * 2;

	if (lParam > 0)
	{
		// 운용전시기 ↔ 발사통제기
		if (lParam > 5)
		{
			wRecvedCRC = MAKEWORD(m_bBuffer[u32Length - 1], m_bBuffer[u32Length - 2]);
			wTmpCRC = m_SocketServer.Calc_CRC(m_bBuffer, (UINT32)u32Length - 2);
		}
		else
		{
			m_pRecvView->AddEventString(_T("ERROR : Incomplete Data"));
		}

		if (wRecvedCRC != wTmpCRC)
		{
			m_pRecvView->AddEventString(_T("ERROR : CRC 불일치"));
		}
		else
		{
			// 뭉쳐서 들어오는 경우 예외 처리
			memcpy(m_bBufferTMP, m_bBuffer, (U16BIT)lParam);
			do
			{
				Temp_Len = (Byte2WORD(&m_bBufferTMP[u16LengthNextTMP]) * 2) + 4;

				if (Temp_Len < 200)
				{
					memcpy(m_bBufferTMP2, &m_bBufferTMP[u16LengthNextTMP], Temp_Len);
					ParseData(m_bBufferTMP2, m_bBufferTMP2[1] + 1, (U16BIT)lParam);

					if (Temp_Len != (U16BIT)lParam)
					{
						u16LengthNextTMP = u16LengthNextTMP + (Byte2WORD(&m_bBufferTMP2[0]) * 2) + 4;
					}
					else
					{ 
						u16LengthNextTMP = (U16BIT)lParam;
					}

				}
				else
				{
					u16LengthNextTMP = (U16BIT)lParam;
				}
			} while ((U16BIT)lParam > u16LengthNextTMP);

		}

		// 데이터 로그
		//for (idx = 0; idx < lParam; idx++)
		//{
		//	strTmp.Format(_T("%02X "), m_bBuffer[idx]);
		//	str += strTmp;
		//}

		//m_pRecvView->AddEventString(str);
	}
	else
	{
		m_pRecvView->AddEventString(_T("ERROR : recv()"));
	}

	return 0;
}


int CFCU_SWDlg::ParseData(BYTE* buf, U16BIT len, U16BIT recvLen)
{
	WORD tmpBuf[MESSAGE_SIZE_MAX] = { 0, };
	double dTmp = 0;
	int tmpIdx = 0;
	int bufIdx = 0;
	U8BIT u8CtrlID = buf[2];
	CString str, strTmp;

	for (; tmpIdx < (len); bufIdx += 2)
	{
		tmpBuf[tmpIdx] = MAKEWORD(buf[bufIdx + 1], buf[bufIdx]);
		// m_pRecvView->AddEventString(tmpBuf[tmpIdx ], TYPE_WORD);
		tmpIdx++;
	}

	for (int idx = 0; idx < (len * 2); idx++)
	{
		strTmp.Format(_T("%02X "), m_bBuffer[idx]);
		str += strTmp;
	}
	m_pRecvView->AddEventString(str);

	switch (tmpBuf[1])
	{
	case CASE_FCU_BIT_CHK:
		m_pRecvView->AddEventString(_T("R] FCU_BIT_CHK"));
		m_u8FCU_BIT_CNT = 0;
		memcpy(m_uFCU_BIT_CHK.wFCU_BIT_CHK, tmpBuf, len * 2);
		updateFCU_BIT_CHK();
		break;

		// EXT_POW_ON 응답 Receive
	case CASE_EXT_POW_ON:
		m_pRecvView->AddEventString(_T("R] EXT_POW_ON"));
		memcpy(m_uEXT_POW_ON.wEXT_POW_ON, tmpBuf, len * 2);

		if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			m_txtVAL_V1.SetWindowTextW(_T("0"));

			m_txtVAL_A1.SetWindowTextW(_T("0"));
		}
		else
		{
			m_txtVAL_V1.SetWindowTextW(_T("0"));

			m_txtVAL_A1.SetWindowTextW(_T("0"));
		}

		UpdateData(FALSE);

		break;

	case CASE_MSL_BIT_CHK:
		m_pRecvView->AddEventString(_T("R] MSL_BIT_CHK"));
		m_bDisplayMSL_BIT = TRUE;
		memcpy(m_uMSL_BIT_CHK.wMSL_BIT_CHK, tmpBuf, len * 2);

		updateMSL_BIT_CHK();
		break;

	case CASE_CUSQ:
		memcpy(m_uCUSQ.wCMD_RSLT, tmpBuf, len * 2);
		SetTimer(CASE_GSTREAMER, 700, NULL);

		if (m_u8Mode == CASE_TEST_MODE)
		{
			m_pRecvView->AddEventString(_T("R] CUSQ_TEST"));
			ChangeLED(&m_ledCUSQ_TEST, IDI_LED_GREEN);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			m_pRecvView->AddEventString(_T("R] CUSQ"));
			m_pFCU_STS_Dlg->PostMessageW(WM_SQB_CU, GREEN, NULL);

			// OnBnClickedBtnMslBitChk();
		}
		break;

	case CASE_SKR_CAGE_CMD:
		m_pRecvView->AddEventString(_T("R] SKR_CAGE_CMD"));
		m_bDisplaySKR_CAGE = TRUE;
		memcpy(m_uSKR_CAGE_CMD.wSKR_CAGE_CMD, tmpBuf, len * 2);

		updateSKR_CAGE_CMD();

		break;

	case CASE_MSL_ID_CHK:
		m_pRecvView->AddEventString(_T("R] MSL_ID_CHK"));
		m_bDisplayMSL_ID = TRUE;
		memcpy(m_uMSL_ID_CHK.wMSL_ID_CHK, tmpBuf, len * 2);

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledMSL_ID_CHK_TEST, IDI_LED_GREEN);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{

			m_pFCU_STS_Dlg->PostMessageW(WM_MSL_ID_CHK, GREEN, NULL);

			OnBnClickedBtnSkrRdyChk();
		}

		if (m_bMSL_ID_CHK == TRUE)
			m_ptMSL_ID_CHK->PostMessageW(WM_MSL_ID_CHK, NULL, NULL);

		break;

	case CASE_SKR_RDY_CHK:
		// m_pRecvView->AddEventString(_T("R] SKR_RDY_CHK"));
		m_bDisplaySKR_RDY = TRUE;
		memcpy(m_uSKR_RDY_CHK.wSKR_RDY_CHK, tmpBuf, len * 2);

		updateSKR_RDY_CHK();

		break;

	case CASE_SKR_PLC_CHK:
		// m_pRecvView->AddEventString(_T("R] SKR_PLC_CHK"));
		m_bDisplaySKR_PLC = TRUE;
		memcpy(m_uSKR_PLC_CHK.wSKR_PLC_CHK, tmpBuf, len * 2);

		updateSKR_PLC_CHK();

		if (m_bSKR_PLC_CHK == TRUE)
			m_ptSKR_PLC_CHK->PostMessageW(WM_SKR_PLC_CHK, NULL, NULL);
		break;

	case CASE_LOCK_ON_CMD:
		m_pRecvView->AddEventString(_T("R] LOCK_ON_CMD"));
		memcpy(m_uLOCK_ON_CMD.wLOCK_ON_CMD, tmpBuf, len * 2);

		if (m_uLOCK_ON_CMD.LOCK_ON_CMD.SKR_RDY.SKR_RDY_RSLT == 0x0)
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, YELLOW, NULL);
			m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, GREEN, NULL);

			if (m_bRE_ROCK_ON_LED_Flag == TRUE)
				m_pFCU_STS_Dlg->PostMessageW(WM_RELCK_CMD, YELLOW, NULL);

			m_bAimT = TRUE;
			m_bAimTracking = TRUE;
			m_bAimSight = FALSE;

			KillTimer(HEADER_SKR_PLC_CHK);
			OnBnClickedBtnSkrTrkStatus();
		}
		else
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, RED, NULL);
			SetMslStat(RED);
		}


		break;

	case CASE_RE_LOCK_ON_CMD:
		m_pRecvView->AddEventString(_T("R] RE_LOCK_ON_CMD"));
		memcpy(m_uRE_LOCK_ON_CMD.wLOCK_ON_CMD, tmpBuf, len * 2);

		if (m_uRE_LOCK_ON_CMD.LOCK_ON_CMD.SKR_RDY.SKR_RDY_RSLT == 0x0)
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, YELLOW, NULL);
			m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, YELLOW, NULL);
			m_pFCU_STS_Dlg->PostMessageW(WM_RELCK_CMD, GREEN, NULL);

			m_bAimT = TRUE;
			m_bAimTracking = TRUE;
			m_bAimSight = FALSE;

			m_bRE_ROCK_ON_Flag = TRUE;
			m_bRE_ROCK_ON_LED_Flag = TRUE;

			KillTimer(HEADER_SKR_TRK_STATUS);
			OnBnClickedBtnSkrTrkStatus();
		}
		else
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, RED, NULL);
			SetMslStat(RED);
		}


		break;

	case CASE_SKR_TRK_STATUS:
		m_pRecvView->AddEventString(_T("R] SKR_TRK_STATUS"));
		m_bDisplaySKR_TRK = TRUE;
		memcpy(m_uSKR_TRK_STATUS.wSKR_TRK_STATUS, tmpBuf, len * 2);

		updateSKR_TRK_STATUS();
		break;

	case CASE_ATK_MODE_CMD:
		m_pRecvView->AddEventString(_T("R] ATK_MODE_CMD"));
		memcpy(m_uATK_MODE_CMD.wATK_MODE_CMD, tmpBuf, len * 2);

		// AfxMessageBox(_T("ATK_MOD"));

		KillTimer(CASE_SET_MAX_ATK_MOD_TIME);

		if (m_uATK_MODE_CMD.wATK_MODE_CMD[2] == 0x0000)
		{
			if (m_u8Mode == CASE_TEST_MODE)
			{
			}
			else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
			{
				m_pFCU_STS_Dlg->PostMessageW(WM_ATK_MOD, GREEN, NULL);
				OnBnClickedBtnBatsq();

			}
		}
		else
		{
			if (m_u8Mode == CASE_TEST_MODE)
			{
				m_pFCU_STS_Dlg->PostMessageW(WM_ATK_MOD, RED, NULL);
			}
			else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
			{
				m_pFCU_STS_Dlg->PostMessageW(WM_ATK_MOD, GREEN, NULL);
				OnBnClickedBtnBatsq();

			}
		}

		break;

	case CASE_BATSQ:

		m_pRecvView->AddEventString(_T("R] BATSQ"));
		m_pFCU_STS_Dlg->PostMessageW(WM_SQB_BAT, GREEN, NULL);

		SetTimer(HEADER_BATSQ, 800, NULL);


		break;

	case CASE_MBAT_ON:
		m_pRecvView->AddEventString(_T("R] MBAT_ON"));

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledBATSQ_TEST, IDI_LED_GREEN);
		}
		else if (m_u8Mode == CASE_DRYRUN_MODE)
		{
			// m_pFCU_STS_Dlg->PostMessageW(WM_SQB_MBAT, GREEN, NULL);
		}

		break;

	case CASE_ABAT_ON:
		m_pRecvView->AddEventString(_T("R] ABAT_ON"));

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledBATSQ_TEST, IDI_LED_GREEN);
		}
		else if (m_u8Mode == CASE_DRYRUN_MODE)
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_SQB_MBAT, GREEN, NULL);
		}

		break;

	case CASE_MSL_STS_CHK:
		m_pRecvView->AddEventString(_T("R] MSL_STS_CHK"));
		memcpy(m_uMSL_STS_CHK.wMSL_STS_CHK, tmpBuf, len * 2);

		m_bDisplayMSL_STS = TRUE;

		m_pRecvView->AddEventString(str);

		updateMSL_STS_CHK();

		break;

	case CASE_LIFTOFF_RDY_CMD:
		m_pRecvView->AddEventString(_T("R] LIFTOFF_RDY_CMD"));
		memcpy(m_uLIFTOFF_RDY_CMD.wCMD_RSLT, tmpBuf, len * 2);

		updateLIFTOFF_RDY_CMD();

		break;

	case CASE_PINSQ:
		m_pRecvView->AddEventString(_T("R] PINSQ"));
		memcpy(m_uPINSQ.wCMD_RSLT, tmpBuf, len * 2);

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledPINSQ_TEST, IDI_LED_GREEN);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_SQB_PIN, GREEN, NULL);
			SetTimer(HEADER_PINSQ, 100, NULL);
		}

		break;

	case CASE_EMSQ:
		m_pRecvView->AddEventString(_T("R] EMSQ"));
		memcpy(m_uEMSQ.wCMD_RSLT, tmpBuf, len * 2);

		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledEMSQ_TEST, IDI_LED_GREEN);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			SetTimer(HEADER_EMSQ, 100, NULL);
			SetTimer(CASE_SET_MAX_EMSQUIB_TIME, 200, NULL);
		}

		break;

	//case CASE_EXT_POW_CHK:
	//	// m_pRecvView->AddEventString(_T("R] EXT_POW_CHK"));
	//	memcpy(m_uEXT_POW_CHK.wEXT_POW_CHK, tmpBuf, len * 2);

	//	updatePOW_CHK(CASE_EXT_POW_CHK, m_uEXT_POW_CHK.EXT_POW_CHK.EXT_POW_VOL, m_uEXT_POW_CHK.EXT_POW_CHK.EXT_POW_CUR);
	//	break;

	//case CASE_ABAT_POW_CHK:
	//	// m_pRecvView->AddEventString(_T("R] ABAT_POW_CHK"));
	//	memcpy(m_uABAT_POW_CHK.wABAT_POW_CHK, tmpBuf, len * 2);

	//	updatePOW_CHK(CASE_ABAT_POW_CHK, m_uABAT_POW_CHK.ABAT_POW_CHK.ABAT_POW_VOL, m_uABAT_POW_CHK.ABAT_POW_CHK.ABAT_POW_CUR);
	//	break;

	//case CASE_MBAT_POW_CHK:
	//	// m_pRecvView->AddEventString(_T("R] MBAT_POW_CHK"));
	//	memcpy(m_uMBAT_POW_CHK.wMBAT_POW_CHK, tmpBuf, len * 2);

	//	updatePOW_CHK(CASE_MBAT_POW_CHK, m_uMBAT_POW_CHK.MBAT_POW_CHK.MBAT_POW_VOL, m_uMBAT_POW_CHK.MBAT_POW_CHK.MBAT_POW_CUR);
	//	break;

	//case CASE_MSLCON_CHK:
	//	m_pRecvView->AddEventString(_T("R] MSLCON_CHK"));
	//	memcpy(m_uMSLCON_CHK.wMSLCON_CHK, tmpBuf, len * 2);

	//	if (m_uMSLCON_CHK.MSLCON_CHK.MSLCON_CHK_RSLT == 0x0001)
	//		ChangeLED(&m_ledMSLCON, IDI_LED_GREEN);

	//	break;

	//case CASE_PINCHK_CHK:
	//	m_pRecvView->AddEventString(_T("R] PINCHK_CHK"));
	//	memcpy(m_uPINCHK_CHK.wPINCHK_CHK, tmpBuf, len * 2);

	//	if (m_uPINCHK_CHK.PINCHK_CHK.PINCHK_CHK_RSLT == 0x0000)
	//		ChangeLED(&m_ledPINCHK, IDI_LED_GREEN);

	//	break;

	case CASE_DISC_TEST_MODE_SET:
		m_pRecvView->AddEventString(_T("R] DISC_TEST_MODE_SET"));
		memcpy(m_uDISC_TEST_MODE_SET.wDISC_TEST_MODE_SET, tmpBuf, len * 2);

		break;

	//case CASE_PINCHK_MSLCON:
	//	// m_pRecvView->AddEventString(_T("R] PINCHK_MSLCON"));
	//	memcpy(m_uPINCHK_MSLCON.wPINCHK_MSLCON, tmpBuf, len * 2);

	//	if (m_uPINCHK_MSLCON.wPINCHK_MSLCON[2] == 0x0000)
	//	{
	//		m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, GREEN, NULL);
	//	}
	//	else if (m_uPINCHK_MSLCON.wPINCHK_MSLCON[2] == 0x0001)
	//	{
	//		m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, WHITE, NULL);
	//	}

	//	if (m_uPINCHK_MSLCON.wPINCHK_MSLCON[3] == 0x0000)
	//	{
	//		// MSL_CONNET 상태에서 유도탄 상태 전시 아이콘이 BLACK이면 GRAY로 변경(점검 중에는 X)
	//		if (m_u8MslTestFlag == 0)
	//		{
	//			if (m_u8MslStat == BLACK)
	//				SetMslStat(WHITE);
	//		}

	//		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_CON, GREEN, NULL);
	//	}
	//	else if (m_uPINCHK_MSLCON.wPINCHK_MSLCON[3] == 0x0001)
	//	{
	//		// MSL_DISCONNET 상태에서 유도탄 상태 전시 아이콘이 BLACK이 아니면 BLACK으로 변경
	//		SetMslStat(BLACK);

	//		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_CON, WHITE, NULL);
	//	}

	//	break;

	default:
		m_pRecvView->AddEventString(_T("Unknown Data"));

		break;
	}
	return 0;
}


void CFCU_SWDlg::OnBnClickedBtnTryConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_imgWarn)->ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0);
	GetDlgItem(IDC_imgWarn)->ShowWindow(TRUE);
	GetDlgItem(IDC_imgWarn)->BringWindowToTop();
}


void CFCU_SWDlg::OnBnClickedBtnUp()
{
	m_bAimSight = TRUE;

	if (s16AimRT_Y <= 0)
	{
		return;
	}
	// m_pRecvView->AddEventString(s16AimRT_Y, TYPE_DEC);

	if ((m_bAimSight == TRUE) && (m_bAimT == FALSE) && (m_bAimTracking == FALSE))
	{
		s16AimRT_Y = s16AimRT_Y - 2;
		s16AimLB_Y = s16AimLB_Y + 2;
	}
	else if ((m_bAimT == TRUE) && (m_bAimTracking == TRUE))
	{
		s16AimRT_Y = s16AimRT_Y - 2;
		s16AimLB_Y = s16AimLB_Y - 2;
	}

	m_s16RT_Y = convertCV2MSL(s16AimRT_Y, AXIS_Y);
	m_s16LB_Y = convertCV2MSL(s16AimLB_Y, AXIS_Y);

	m_strAimSize_Y.Format(_T("%d"), ((s16AimLB_Y - s16AimRT_Y + 1)) / 2);

	UpdateData(FALSE);

	LoadnDraw();

	ChangeLED(&m_LED_L1, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_UPPER, 500, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnLeft()
{
	m_bAimSight = TRUE;

	if ((m_bAimSight == TRUE) && (m_bAimT == FALSE) && (m_bAimTracking == FALSE))
	{
		if ((s16AimRT_X - s16AimLB_X) <= 10)
			return;

		s16AimRT_X = s16AimRT_X - 2;
		s16AimLB_X = s16AimLB_X + 2;
	}
	else if ((m_bAimT == TRUE) && (m_bAimTracking == TRUE))
	{
		if (s16AimLB_X <= 0)
			return;

		s16AimRT_X = s16AimRT_X - 2;
		s16AimLB_X = s16AimLB_X - 2;
	}

	m_s16RT_X = convertCV2MSL(s16AimRT_X, AXIS_X);
	m_s16LB_X = convertCV2MSL(s16AimLB_X, AXIS_X);

	m_strAimSize_X.Format(_T("%d"), (s16AimRT_X - s16AimLB_X + 1) / 2);

	UpdateData(FALSE);

	LoadnDraw();

	ChangeLED(&m_LED_L2, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_LEFT, 500, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnRight()
{
	m_bAimSight = TRUE;

	if ((m_bAimSight == TRUE) && (m_bAimT == FALSE) && (m_bAimTracking == FALSE))
	{
		if ((s16AimRT_X >= 511) || (s16AimLB_X <= 0))
			return;

		s16AimRT_X = s16AimRT_X + 2;
		s16AimLB_X = s16AimLB_X - 2;
	}
	else if ((m_bAimT == TRUE) && (m_bAimTracking == TRUE))
	{
		if (s16AimRT_X >= 511)
			return;

		s16AimRT_X = s16AimRT_X + 2;
		s16AimLB_X = s16AimLB_X + 2;
	}

	m_s16RT_X = convertCV2MSL(s16AimRT_X, AXIS_X);
	m_s16LB_X = convertCV2MSL(s16AimLB_X, AXIS_X);

	m_strAimSize_X.Format(_T("%d"), (s16AimRT_X - s16AimLB_X + 1) / 2);

	UpdateData(FALSE);

	LoadnDraw();

	ChangeLED(&m_LED_L4, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_RIGHT, 500, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnDown()
{
	m_bAimSight = TRUE;

	if ((m_bAimSight == TRUE) && (m_bAimT == FALSE) && (m_bAimTracking == FALSE))
	{
		if ((s16AimLB_Y - s16AimRT_Y) <= 10)
			return;

		s16AimRT_Y = s16AimRT_Y + 2;
		s16AimLB_Y = s16AimLB_Y - 2;
	}
	else if ((m_bAimT == TRUE) && (m_bAimTracking == TRUE))
	{
		if (511 <= s16AimLB_Y)
			return;

		s16AimRT_Y = s16AimRT_Y + 2;
		s16AimLB_Y = s16AimLB_Y + 2;
	}

	m_s16RT_Y = convertCV2MSL(s16AimRT_Y, AXIS_Y);
	m_s16LB_Y = convertCV2MSL(s16AimLB_Y, AXIS_Y);

	m_strAimSize_Y.Format(_T("%d"), (s16AimLB_Y - s16AimRT_Y + 1) / 2);

	UpdateData(FALSE);

	LoadnDraw();

	ChangeLED(&m_LED_L5, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_BOTTOM, 500, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnMslBitChk()
{
	// m_u16currentCMD = HEADER_MSL_BIT_CHK;
	// 10초 이내 완료
		// 커맨드 중복 실행 방지용 Flag TRUE
	SetTimer(HEADER_MSL_BIT_CHK, 75, NULL);
	SetTimer(CASE_SET_MAX_MSL_BIT_TIME, 2000, NULL);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledMSL_BIT_CHK_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		// MSL_BIT_CHK 커맨드 Send
		m_SocketServer.SendData(HEADER_MSL_BIT_CHK);

		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_BIT_CHK, YELLOW, NULL);

		this->SetFocus();
	}
}

void CFCU_SWDlg::OnBnClickedBtnCusq()
{
	// m_u16currentCMD = HEADER_CUSQ;
	ChangeLED(&m_ledCUSQ, IDI_LED_WHITE);
	m_pFCU_STS_Dlg->PostMessageW(WM_SQB_CU, GREEN, NULL);
	m_SocketServer.SendData(HEADER_CUSQ);

	if (m_bSetGasOnce == FALSE)
	{
		m_bSetGasOnce = TRUE;
		// SetTimer(CASE_GSTREAMER, 700, NULL);
		SetTimer(HEADER_CUSQ, 16000, NULL);
	}

	//if (m_bThreadCamDataRecv == FALSE)
	//{
	//	// AfxMessageBox(_T("!"));
	//	m_bThreadCamDataRecv = TRUE;
	//	m_pThread = ::AfxBeginThread(CamDataRecv, this);

	//	// SetTimer(CASE_GSTREAMER, 500, NULL);
	//}
	SetTimer(CASE_SKR_STAT_CHANGE, 500, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnSkrCageCmd()
{
	// m_u16currentCMD = HEADER_SKR_CAGE_CMD;

	// 2초 이내 완료

	m_SocketServer.SendData(HEADER_SKR_CAGE_CMD);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledSKR_CAGE_CMD_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		SetTimer(HEADER_SKR_CAGE_CMD, 75, NULL);
		SetTimer(CASE_SET_MAX_SKR_CAGE_TIME, 2000, NULL);
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, YELLOW, NULL);
	}

}


void CFCU_SWDlg::OnBnClickedBtnMslIdChk()
{
	// m_u16currentCMD = HEADER_MSL_ID_CHK;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_SocketServer.SendData(HEADER_MSL_ID_CHK);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledMSL_ID_CHK_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_ID_CHK, YELLOW, NULL);
	}
}


void CFCU_SWDlg::OnBnClickedBtnSkrRdyChk()
{
	// m_u16currentCMD = HEADER_SKR_RDY_CHK;
	// 15초 이내 완료
	m_SocketServer.SendData(HEADER_SKR_RDY_CHK);

	SetTimer(HEADER_SKR_RDY_CHK, 75, NULL);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledSKR_RDY_CHK_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		// SetTimer(HEADER_SKR_RDY_CHK, 75, NULL);
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, YELLOW, NULL);
	}
}


void CFCU_SWDlg::OnBnClickedBtnSkrPlcChk()
{
	// 현재 명령어 저장
	m_u16currentCMD = HEADER_SKR_PLC_CHK;

	// 표적 지정 명령(LOCK_ON_CMD) 전까지 75ms 주기로 수행

	m_SocketServer.SendData(HEADER_SKR_PLC_CHK);
	SetTimer(HEADER_SKR_PLC_CHK, 75, NULL);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledSKR_PLC_CHK_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, YELLOW, NULL);
	}
}


void CFCU_SWDlg::OnBnClickedBtnSkrTrkStatus()
{
	m_u16currentCMD = HEADER_SKR_TRK_STATUS;

	m_SocketServer.SendData(HEADER_SKR_TRK_STATUS);
	SetTimer(HEADER_SKR_TRK_STATUS, 75, NULL);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledSKR_TRK_STATUS_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		// m_pFCU_STS_Dlg->PostMessageW(WM_SKR_TRK_STATUS, YELLOW, NULL);
	}

}


void CFCU_SWDlg::OnBnClickedBtnMslStsChk()
{
	// m_u16currentCMD = HEADER_MSL_STS_CHK;
	// 75ms 주기로 500ms 동안 수행. 정상 완료 시 500ms까지 기다리지 않고, 바로 다음 명령(LIFTOFF_RDY_CMD) 전송
	m_SocketServer.SendData(HEADER_MSL_STS_CHK);

	SetTimer(HEADER_MSL_STS_CHK, 75, NULL);
	SetTimer(CASE_SET_MAX_MSL_STS_TIME, 500, NULL);

	ChangeLED(&m_ledMSL_STS_CHK_TEST, IDI_LED_WHITE);
}


void CFCU_SWDlg::OnBnClickedBtnLiftoffRdyCmd()
{
	// m_u16currentCMD = HEADER_LIFTOFF_RDY_CMD;
	m_SocketServer.SendData(HEADER_LIFTOFF_RDY_CMD);

	// m_pFCU_STS_Dlg->PostMessageW(WM_LIFTOFF_RDY, GREEN, NULL);
	SetTimer(CASE_SET_MAX_LIFTOFF_RDY_TIME, 400, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnPinsq()
{
	// m_u16currentCMD = HEADER_PINSQ;

	m_SocketServer.SendData(HEADER_PINSQ);
	ChangeLED(&m_ledPINSQ_TEST, IDI_LED_WHITE);
	SetTimer(CASE_SET_MAX_PINSQB_TIME, 1000, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnEmsq()
{
	// m_u16currentCMD = HEADER_EMSQ;
	m_SocketServer.SendData(HEADER_EMSQ);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledEMSQ_TEST, IDI_LED_WHITE);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
	}
}


void CFCU_SWDlg::OnBnClickedBtnBatsq()
{

	m_SocketServer.SendData(HEADER_BATSQ);

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledBATSQ_TEST, IDI_LED_GREEN);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_SQB_BAT, GREEN, NULL);
	}
}


void CFCU_SWDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CFCU_SWDlg::ChangeLED(CStatic* icon, U16BIT flag)
{
	HICON h_Icon;   // 아이콘 객체 생성

	h_Icon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(flag));

	icon->SetIcon(h_Icon);
}


void CFCU_SWDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CFCU_SWDlg::OnMoving(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnMoving(fwSide, pRect);

	//CRect rectRecvView;
	//CRect rectFCU_STS_Dlg;

	//if (m_pRecvView)
	//{
	//	m_pRecvView->GetClientRect(&rectRecvView);
	//	m_pRecvView->SetWindowPos(NULL, pRect->right, pRect->top, 0, 0, SWP_NOSIZE);
	//}
	//if (m_pFCU_STS_Dlg)
	//{
	//	m_pFCU_STS_Dlg->GetClientRect(&rectFCU_STS_Dlg);
	//	m_pFCU_STS_Dlg->SetWindowPos(NULL, pRect->left, pRect->bottom, 0, 0, SWP_NOSIZE);
	//}

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CFCU_SWDlg::OnStnClickedBtnHidden()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bRecvView == TRUE)
	{
		m_bRecvView = FALSE;
		m_pRecvView->ShowWindow(SW_HIDE);
	}
	else
	{
		m_bRecvView = TRUE;
		m_pRecvView->ShowWindow(SW_SHOW);
	}
}


void CFCU_SWDlg::OnStnClickedimglnchstat()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_SocketServer.m_ptrClientSocketList.GetHeadPosition() != NULL)
		m_SocketServer.SendData(HEADER_FCU_BIT_CHK);
}


void CFCU_SWDlg::setEnableBTN(BOOL flag)
{
	if (flag == FALSE)
	{
		// GetDlgItem(IDC_BTN_POWER)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MSL_BIT_CHK_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_CUSQ_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SKR_CAGE_CMD_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MSL_ID_CHK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SKR_RDY_CHK)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SKR_PLC_CHK_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_SKR_TRK_STATUS_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_BATSQ_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MSL_STS_CHK_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LIFTOFF_RDY_CMD_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_PINSQ_TEST)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_EMSQ)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LOCK_ON_CMD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_RE_LOCK_ON_CMD)->EnableWindow(FALSE);
		GetDlgItem(IDC_ATK_MODE_CMD)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LAUNCH)->EnableWindow(FALSE);
	}
	else
	{
		// GetDlgItem(IDC_BTN_POWER)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_MSL_BIT_CHK_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CUSQ_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SKR_CAGE_CMD_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_MSL_ID_CHK)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SKR_RDY_CHK)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SKR_PLC_CHK_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_SKR_TRK_STATUS_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_BATSQ_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_MSL_STS_CHK_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LIFTOFF_RDY_CMD_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_PINSQ_TEST)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_EMSQ)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LOCK_ON_CMD)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_RE_LOCK_ON_CMD)->EnableWindow(TRUE);
		GetDlgItem(IDC_ATK_MODE_CMD)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LAUNCH)->EnableWindow(TRUE);
	}
}


void CFCU_SWDlg::updateFCU_BIT_CHK(void)
{
	// FCU_BIT_CHK
	if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[2] == 0x0003)
	{
		SetLnchStat(GREEN);
	}
	else
	{
		SetLnchStat(RED);
	}

	// PIN_CHK
	if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[3] == 0x0000)
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, GREEN, NULL);
	}
	else if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[3] == 0x0001)
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, WHITE, NULL);
	}


	// MSL_CON
	if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[4] == 0x0000)
	{
		// MSL_CONNET 상태에서 유도탄 상태 전시 아이콘이 BLACK이면 GRAY로 변경(점검 중에는 X)
		if (m_u8MslTestFlag == 0)
		{
			if (m_u8MslStat == BLACK)
				SetMslStat(WHITE);
		}

		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_CON, GREEN, NULL);
	}
	else if (m_uFCU_BIT_CHK.wFCU_BIT_CHK[4] == 0x0001)
	{
		// MSL_DISCONNET 상태에서 유도탄 상태 전시 아이콘이 BLACK이 아니면 BLACK으로 변경
		SetMslStat(BLACK);

		m_pFCU_STS_Dlg->PostMessageW(WM_MSL_CON, WHITE, NULL);
	}

	// EXT_POW_CHK
	updatePOW_CHK(CASE_EXT_POW_CHK, m_uFCU_BIT_CHK.wFCU_BIT_CHK[5], m_uFCU_BIT_CHK.wFCU_BIT_CHK[6]);

	// ABAT_POW_CHK
	updatePOW_CHK(CASE_ABAT_POW_CHK, m_uFCU_BIT_CHK.wFCU_BIT_CHK[7], m_uFCU_BIT_CHK.wFCU_BIT_CHK[8]);

	// MBAT_POW_CHK
	updatePOW_CHK(CASE_MBAT_POW_CHK, m_uFCU_BIT_CHK.wFCU_BIT_CHK[9], m_uFCU_BIT_CHK.wFCU_BIT_CHK[10]);
}


void CFCU_SWDlg::updatePOW_CHK(WORD header, WORD vol, WORD cur)
{
	CString strTmp;
	double dVOLTmp;
	double dCURTmp;

	dVOLTmp = 3.261 / 4096.0 * 16.0 * (double)vol;
	strTmp.Format(_T("%.3lf"), dVOLTmp);

	switch (header)
	{
	case CASE_EXT_POW_CHK:
		m_txtVAL_V1.SetWindowTextW(strTmp);
		break;
	case CASE_MBAT_POW_CHK:
		m_txtVAL_V2.SetWindowTextW(strTmp);
		break;
	case CASE_ABAT_POW_CHK:
		m_txtVAL_V3.SetWindowTextW(strTmp);
		break;
	}

	dCURTmp = (double)cur * 3.261 / 4096.0 * 20.0;
	strTmp.Format(_T("%.3lf"), dCURTmp);

	switch (header)
	{
	case CASE_EXT_POW_CHK:
		m_txtVAL_A1.SetWindowTextW(strTmp);
		break;
	case CASE_MBAT_POW_CHK:
		m_txtVAL_A2.SetWindowTextW(strTmp);
		break;
	case CASE_ABAT_POW_CHK:
		m_txtVAL_A3.SetWindowTextW(strTmp);
		break;
	}
}


void CFCU_SWDlg::killAllTimer(void)
{
	KillTimer(FCU_AUTO_START);
	KillTimer(CASE_MSL_STAT_CHANGE);
	KillTimer(CASE_SKR_STAT_CHANGE);
	KillTimer(CASE_SET_MAX_SKR_RDY_TIME);
	KillTimer(CASE_SET_MAX_MSL_BIT_TIME);
	KillTimer(CASE_SET_MAX_SKR_PLC_TIME);
	KillTimer(CASE_SET_MAX_MSL_STS_TIME);
	KillTimer(CASE_GSTREAMER);
	KillTimer(CASE_SET_MAX_ATK_MOD_TIME);
	KillTimer(CASE_SET_MAX_LIFTOFF_RDY_TIME);
	KillTimer(CASE_SET_MAX_PINSQB_TIME);
	KillTimer(CASE_SET_MAX_EMSQUIB_TIME);
	KillTimer(CASE_SET_MAX_SKR_CAGE_TIME);

	m_u8MaxSkrRdyTime = 0;
	m_u8MslTestFlag = 0;

	KillTimer(HEADER_SKR_CAGE_CMD);
	KillTimer(HEADER_SKR_RDY_CHK);
	KillTimer(HEADER_SKR_PLC_CHK);
	KillTimer(HEADER_SKR_TRK_STATUS);
	KillTimer(HEADER_MSL_STS_CHK);
	KillTimer(HEADER_BATSQ);
	KillTimer(HEADER_EXT_POW_CHK);
	KillTimer(HEADER_PINSQ);

	//m_btnMslBitChkTest.LoadBitmaps(IDB_BTN_MSL_BIT_01, IDB_BTN_MSL_BIT_02, NULL, NULL);
	//m_btnSkrCageCmdTest.LoadBitmaps(IDB_BTN_SKR_CAGE_CMD_01, IDB_BTN_SKR_CAGE_CMD_02, NULL, NULL);
	//m_btnSkrRdyChk.LoadBitmaps(IDB_BTN_SKR_RDY_CHK_01, IDB_BTN_SKR_RDY_CHK_02, NULL, NULL);
	//m_btnSkrPlcChkTest.LoadBitmaps(IDB_BTN_SKR_PLC_CHK_01, IDB_BTN_SKR_PLC_CHK_02, NULL, NULL);
	//m_btnSkrTrkStatusTest.LoadBitmaps(IDB_BTN_SKR_TRK_STATUS_01, IDB_BTN_SKR_TRK_STATUS_02, NULL, NULL);
	//m_btnMslStsChk.LoadBitmaps(IDB_BTN_MSL_STS_CHK_TEST_01, IDB_BTN_MSL_STS_CHK_TEST_02, NULL, NULL);
}


void CFCU_SWDlg::updateMSL_BIT_CHK(void)
{

	if (m_u8Mode == CASE_TEST_MODE)
	{
		CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_MSL_BIT_CHK_TEST);
		pWnd->EnableWindow(FALSE);
		m_btnMslBitChkTest.LoadBitmaps(IDB_BTN_MSL_BIT_01, IDB_BTN_MSL_BIT_02, NULL, NULL);
		pWnd->EnableWindow(TRUE);

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[2] == 0x0001)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[3] == 0x0102)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[4] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_BIT_CHK.wMSL_BIT_CHK[12] == 0x4002) || (m_uMSL_BIT_CHK.wMSL_BIT_CHK[12] == 0x4000))
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[13] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_BIT_CHK.wMSL_BIT_CHK[14] & 0x8200) == 0x8200)
		{
			bLED_State = FALSE;
			u16LED_Cnt = 0;
			m_u8MslTestFlag = 0;

			KillTimer(HEADER_MSL_BIT_CHK);
			KillTimer(CASE_MSL_STAT_CHANGE);
			KillTimer(CASE_SET_MAX_MSL_BIT_TIME);
			SetMslStat(GREEN);
			ChangeLED(&m_ledMSL_BIT_CHK_TEST, IDI_LED_GREEN);
		}
		else
		{
			return;
		}

		if (m_bMSL_BIT_CHK)
		{
			ChangeLED(&m_ledMSL_BIT_CHK_TEST, IDI_LED_GREEN_MID);
		}
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[2] == 0x0001)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[3] == 0x0102)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[4] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_BIT_CHK.wMSL_BIT_CHK[12] == 0x4002) || (m_uMSL_BIT_CHK.wMSL_BIT_CHK[12] == 0x4000))
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_BIT_CHK.wMSL_BIT_CHK[13] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_BIT_CHK.wMSL_BIT_CHK[14] & 0x8200) == 0x8200)
		{
			bLED_State = FALSE;
			u16LED_Cnt = 0;
			m_u8MslTestFlag = 0;

			KillTimer(HEADER_MSL_BIT_CHK);
			KillTimer(CASE_MSL_STAT_CHANGE);
			KillTimer(CASE_SET_MAX_MSL_BIT_TIME);
			SetMslStat(GREEN);

			m_pFCU_STS_Dlg->PostMessageW(WM_MSL_BIT_CHK, GREEN, NULL);

			OnBnClickedBtnSkrCageCmd();

		}
		else
		{
			return;
		}
	}

	if (m_bMSL_BIT_CHK)
		m_ptMSL_BIT_CHK->PostMessageW(WM_MSL_BIT_CHK, NULL, NULL);
}


void CFCU_SWDlg::updateSKR_CAGE_CMD(void)
{
	// m_u16currentCMD의 값이HEADER_SKR_TRK_STATUS이면 Lock-on 해제 커맨드로 판별
	if (m_u16currentCMD == HEADER_SKR_TRK_STATUS)
	{
		m_pRecvView->AddEventString(_T("LOCK_ON_RELEASE"));
		SetSkrLamp(BLACK);

		// SKR_CAGE_CMD 상태 LED 황색 전시
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, GREEN, NULL);
		m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, YELLOW, NULL);

		if (m_bRE_ROCK_ON_LED_Flag == TRUE)
			m_pFCU_STS_Dlg->PostMessageW(WM_RELCK_CMD, YELLOW, NULL);

		m_bAimT = FALSE;
		m_bAimTracking = FALSE;
		m_bAimSight = TRUE;

		OnBnClickedBtnSkrPlcChk();

		return;
	}

	if (m_u8Mode == CASE_TEST_MODE)
	{
		CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_CAGE_CMD_TEST);
		pWnd->EnableWindow(FALSE);
		m_btnSkrCageCmdTest.LoadBitmaps(IDB_BTN_SKR_CAGE_CMD_01, IDB_BTN_SKR_CAGE_CMD_02, NULL, NULL);
		pWnd->EnableWindow(TRUE);

		if (m_uSKR_CAGE_CMD.wSKR_CAGE_CMD[2] == 0x0000)
		{
			bLED_State = FALSE;
			u16LED_Cnt = 0;
			KillTimer(HEADER_SKR_CAGE_CMD);
			KillTimer(CASE_SET_MAX_SKR_CAGE_TIME);
			ChangeLED(&m_ledSKR_CAGE_CMD_TEST, IDI_LED_GREEN);
		}
		else
		{
			return;
		}
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		if (m_uSKR_CAGE_CMD.wSKR_CAGE_CMD[2] == 0x0000)
		{
			bLED_State = FALSE;
			u16LED_Cnt = 0;
			KillTimer(HEADER_SKR_CAGE_CMD);
			KillTimer(CASE_SET_MAX_SKR_CAGE_TIME);

			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, GREEN, NULL);

			OnBnClickedBtnMslIdChk();
		}
		else
		{
			return;
		}
		// ChangeLED(&m_ledSKR_CAGE_CMD, IDI_LED_GREEN);
	}
	if (m_bSKR_CAGE_CMD == TRUE)
		m_ptSKR_CAGE_CMD->PostMessageW(WM_SKR_CAGE_CMD, NULL, NULL);
}


void CFCU_SWDlg::updateSKR_RDY_CHK(void)
{
	// static BOOL bThreadCamDataRecv = FALSE;

	if (m_u8Mode == CASE_TEST_MODE)
	{
		if (m_uSKR_RDY_CHK.wSKR_RDY_CHK[2] == 0x0000)
		{
			CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_RDY_CHK);
			pWnd->EnableWindow(FALSE);

			m_btnSkrRdyChk.LoadBitmaps(IDB_BTN_SKR_RDY_CHK_01, IDB_BTN_SKR_RDY_CHK_02, NULL, NULL);
			pWnd->EnableWindow(TRUE);

			ChangeLED(&m_ledSKR_RDY_CHK_TEST, IDI_LED_GREEN);

			m_bThreadCamDataRecv = FALSE;
			KillTimer(HEADER_SKR_RDY_CHK);
			bLED_State = FALSE;
			u16LED_Cnt = 0;

		}
		else
		{
			ChangeLED(&m_ledSKR_RDY_CHK_TEST, IDI_LED_RED);
			// SetSkrStat(RED);
		}
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		// SKR_RDY_CHK 정상 응답 시
		if (m_uSKR_RDY_CHK.wSKR_RDY_CHK[2] == 0x0000)
		{
			KillTimer(HEADER_SKR_RDY_CHK);
			KillTimer(CASE_SET_MAX_SKR_RDY_TIME);
			KillTimer(CASE_SKR_STAT_CHANGE);

			m_u8MaxSkrRdyTime = 0;
			// 영상 좌측 탐색기 상태 GREEN 점등
			SetSkrStat(GREEN);

			// 하단 Stat창 SKR_RDY_CHK의 LED GREEN 점등
			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, GREEN, NULL);

			m_bThreadCamDataRecv = FALSE;
			bLED_State = FALSE;
			u16LED_Cnt = 0;

			OnBnClickedBtnSkrPlcChk();
		}
		else
		{
			//m_pFCU_STS_Dlg->PostMessageW(WM_SKR_RDY_CHK, RED, NULL);
		}
	}

	if (m_bSKR_RDY_CHK == TRUE)
		m_ptSKR_RDY_CHK->PostMessageW(WM_SKR_RDY_CHK, NULL, NULL);
}


void CFCU_SWDlg::updateSKR_PLC_CHK(void)
{
	INT32 s32PlcBitRslt = 0;

	if (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 1)
	{
		m_sclAimResult = SCL_RED;
		m_pRecvView->AddEventString(_T("SCL_RED"));
	}
	else if (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 2)
	{
		m_sclAimResult = SCL_YELLOW;
		m_pRecvView->AddEventString(_T("SCL_YELLOW"));
	}
	else if (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 4)
	{
		m_sclAimResult = SCL_GREEN;
		m_pRecvView->AddEventString(_T("SCL_GREEN"));
	}
	else
	{
		m_pRecvView->AddEventString(_T("ERROR : SKR_PLC_CHK.PLC_BIT_RSLT"));
	}

	s32PlcBitRslt = m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_NUM_RSLT;
	m_strPLC_VALUE.Format(_T("%.4lf"), (double)s32PlcBitRslt / (double)10000);
	UpdateData(FALSE);

	if (m_uSKR_PLC_CHK.wSKR_PLC_CHK[4] == 0x0000)
	{
		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledSKR_PLC_CHK_TEST, IDI_LED_GREEN);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			if (m_sclAimResult == SCL_GREEN)
				m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, HIGH, NULL);
			else if (m_sclAimResult == SCL_YELLOW)
				m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, MID, NULL);
			else if (m_sclAimResult == SCL_RED)
				m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, LOW, NULL);
		}
	}
	else
	{
		if (m_u8Mode == CASE_TEST_MODE)
		{
			ChangeLED(&m_ledSKR_PLC_CHK_TEST, IDI_LED_RED);
		}
		else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
		{
			m_pFCU_STS_Dlg->PostMessageW(WM_SKR_PLC_CHK, RED, NULL);
		}
		m_pRecvView->AddEventString(_T("ERROR : SKR_PLC_CHK"));
		SetMslStat(RED);
	}

}


void CFCU_SWDlg::updateSKR_TRK_STATUS(void)
{
	// 가운데 0, 0 기준
	S16BIT s16SX = 0;
	S16BIT s16SY = 0;
	S16BIT s16EX = 0;
	S16BIT s16EY = 0;
	S16BIT s16YAW = 0;
	S16BIT s16PITCH = 0;

	// m_bRE_ROCK_ON_Flag = TRUE;

	if (m_bRE_ROCK_ON_Flag == FALSE)
	{
		if ((m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 1) || (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 1))
			m_sclAim = SCL_RED;
		else if ((m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 0) && (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 2))
			m_sclAim = SCL_YELLOW;
		else if ((m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 0) && (m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT == 4))
			m_sclAim = SCL_GREEN;
	}
	else
	{
		if (m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 1)
		{
			m_bLOCK_ON_RSLT_FAULT = TRUE;
			m_sclAim = SCL_RED;
		}
		else if (m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 0)
		{
			if (m_bLOCK_ON_RSLT_FAULT == TRUE)
			{
				m_sclAim = SCL_RED;
			}	
			else
			{
				m_sclAim = SCL_GREEN;
			}
		}
	}

	//if (m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 1)
	//{
	//	m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, GREEN, NULL);
	//	m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, YELLOW, NULL);
	//}
	//else if (m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 0)
	//{
	//	m_pFCU_STS_Dlg->PostMessageW(WM_SKR_CAGE_CMD, YELLOW, NULL);
	//	m_pFCU_STS_Dlg->PostMessageW(WM_LCK_CMD, GREEN, NULL);
	//}

	s16YAW = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[3];
	s16PITCH = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[4];
	s16SX = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[5] / 100;
	s16SY = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[6] / 100;
	s16EX = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[7] / 100;
	s16EY = (INT16)m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[8] / 100;


	m_s16YAW_CAM = convertMSL2CV(s16YAW * (-1), AXIS_X);
	m_s16PITCH_CAM = convertMSL2CV(s16PITCH * (-1), AXIS_Y);

	m_s16SX_CAM = convertMSL2CV(s16SX, AXIS_X);
	m_s16SY_CAM = convertMSL2CV(s16SY, AXIS_Y);
	m_s16EX_CAM = convertMSL2CV(s16EX, AXIS_X);
	m_s16EY_CAM = convertMSL2CV(s16EY, AXIS_Y);

	if ((m_s16EX_CAM < m_s16YAW_CAM) && (m_s16YAW_CAM < m_s16SX_CAM) && (m_s16SY_CAM < m_s16PITCH_CAM) && (m_s16PITCH_CAM < m_s16EY_CAM))
	{
		if (m_u8LampStat == BLACK)
		{
			SetSkrLamp(RED);
		}
	}
	else
	{
		SetSkrLamp(BLACK);
	}

	if (m_bAimSight == FALSE)
	{
		s16AimLB_X = m_s16EX_CAM;
		s16AimLB_Y = m_s16EY_CAM;
		s16AimRT_X = m_s16SX_CAM;
		s16AimRT_Y = m_s16SY_CAM;
	}
	if (m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[9] == 0x0000)
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_TRK_STATUS, GREEN, NULL);
	}
	else
	{
		m_pFCU_STS_Dlg->PostMessageW(WM_SKR_TRK_STATUS, RED, NULL);
		SetMslStat(RED);
	}

	if (m_bSKR_TRK_STATUS == TRUE)
		m_ptSKR_TRK_STATUS->PostMessageW(WM_SKR_TRK_STATUS, NULL, NULL);

	m_strRUX.Format(_T("%d"), s16SX);
	m_strRUY.Format(_T("%d"), s16SY);
	m_strLLX.Format(_T("%d"), s16EX);
	m_strLLY.Format(_T("%d"), s16EY);

	UpdateData(FALSE);
}


void CFCU_SWDlg::updateMSL_STS_CHK(void)
{
	// AfxMessageBox(_T("updateMSL_STS_CHK"));

	if (m_u8Mode == CASE_TEST_MODE)
	{
		if (m_uMSL_STS_CHK.wMSL_STS_CHK[2] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[3] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[4] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[12] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_STS_CHK.wMSL_STS_CHK[13] & 0x8FFF) == 0x0000)
		{
			KillTimer(HEADER_MSL_STS_CHK);
			KillTimer(CASE_SET_MAX_MSL_STS_TIME);

			CWnd* pWnd;
			pWnd = (CWnd*)GetDlgItem(IDC_BTN_MSL_STS_CHK_TEST);
			pWnd->EnableWindow(FALSE);
			m_btnMslStsChk.LoadBitmaps(IDB_BTN_MSL_STS_CHK_TEST_01, IDB_BTN_MSL_STS_CHK_TEST_02, NULL, NULL);
			pWnd->EnableWindow(TRUE);

			u16LED_Cnt = 0;
			bLED_State = FALSE;

			m_pFCU_STS_Dlg->PostMessageW(WM_MSL_STS_CHK, GREEN, NULL);
			OnBnClickedBtnLiftoffRdyCmd();
		}
		else
		{
			return;
		}
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		if (m_uMSL_STS_CHK.wMSL_STS_CHK[2] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[3] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[4] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if (m_uMSL_STS_CHK.wMSL_STS_CHK[12] == 0x0000)
		{
		}
		else
		{
			return;
		}

		if ((m_uMSL_STS_CHK.wMSL_STS_CHK[13] & 0x8FFF) == 0x0000)
		{
			KillTimer(HEADER_MSL_STS_CHK);
			KillTimer(CASE_SET_MAX_MSL_STS_TIME);

			u16LED_Cnt = 0;
			bLED_State = FALSE;

			m_pFCU_STS_Dlg->PostMessageW(WM_MSL_STS_CHK, GREEN, NULL);

			SetTimer(HEADER_LIFTOFF_RDY_CMD, 100, NULL);
		}
		else
		{
			return;
		}
	}

	if (m_bMSL_STS_CHK == TRUE)
		m_ptMSL_STS_CHK->PostMessageW(WM_MSL_STS_CHK, NULL, NULL);

}


void CFCU_SWDlg::updateLIFTOFF_RDY_CMD(void)
{
	u16LED_Cnt = 0;
	bLED_State = FALSE;

	if (m_u8Mode == CASE_TEST_MODE)
	{
		ChangeLED(&m_ledLIFTOFF_RDY_CMD_TEST, IDI_LED_GREEN);
	}
	else if ((m_u8Mode == CASE_DRYRUN_MODE) || (m_u8Mode == CASE_LAUNCH_MODE))
	{
		KillTimer(CASE_SET_MAX_LIFTOFF_RDY_TIME);

		m_pFCU_STS_Dlg->PostMessageW(WM_LIFTOFF_RDY, GREEN, NULL);
		OnBnClickedBtnPinsq();
	}


}


void CFCU_SWDlg::OnBnClickedBtnDiscBit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWnd* pWnd;

	pWnd = (CWnd*)GetDlgItem(IDC_BTN_DISC_TEST_MODE_SET);
	pWnd->EnableWindow(FALSE);

	if (bDISC_TEST_MODE_SET == FALSE)
	{
		bDISC_TEST_MODE_SET = TRUE;
		m_btnDISC_TEST_MODE_SET.LoadBitmaps(IDB_BTN_TMSL_TRUE_01, IDB_BTN_TMSL_TRUE_02, NULL, NULL);
	}
	else
	{
		bDISC_TEST_MODE_SET = FALSE;
		m_btnDISC_TEST_MODE_SET.LoadBitmaps(IDB_BTN_TMSL_FALSE_01, IDB_BTN_TMSL_FALSE_02, NULL, NULL);
	}
	m_SocketServer.SendData(HEADER_DISC_TEST_MODE_SET);
	pWnd->EnableWindow(TRUE);
}


void CFCU_SWDlg::everyLEDOff(void)
{
	CString str;

	//ChangeLED(&m_ledTCP, IDI_LED_WHITE_MID);
	//ChangeLED(&m_ledUDP, IDI_LED_WHITE_MID);
	ChangeLED(&m_ledMSL_BIT_CHK, IDI_LED_WHITE);
	ChangeLED(&m_ledMSL_BIT_CHK_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledCUSQ, IDI_LED_WHITE);
	ChangeLED(&m_ledCUSQ_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_CAGE_CMD, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_CAGE_CMD_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledMSL_ID_CHK, IDI_LED_WHITE);
	ChangeLED(&m_ledMSL_ID_CHK_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_RDY_CHK, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_RDY_CHK_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_PLC_CHK, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_PLC_CHK_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_TRK_STATUS, IDI_LED_WHITE);
	ChangeLED(&m_ledSKR_TRK_STATUS_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledBATSQ, IDI_LED_WHITE);
	ChangeLED(&m_ledBATSQ_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledMSL_STS_CHK, IDI_LED_WHITE);
	ChangeLED(&m_ledMSL_STS_CHK_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledLIFTOFF_RDY_CMD, IDI_LED_WHITE);
	ChangeLED(&m_ledLIFTOFF_RDY_CMD_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledPINSQ, IDI_LED_WHITE);
	ChangeLED(&m_ledPINSQ_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledEMSQ_TEST, IDI_LED_WHITE);
	ChangeLED(&m_ledMSLCON, IDI_LED_WHITE);
	ChangeLED(&m_ledPINCHK, IDI_LED_WHITE);

	str.Format(_T("0"));

	m_txtVAL_A1.SetWindowTextW(str);
	m_txtVAL_A2.SetWindowTextW(str);
	m_txtVAL_A3.SetWindowTextW(str);
	m_txtVAL_V1.SetWindowTextW(str);
	m_txtVAL_V2.SetWindowTextW(str);
	m_txtVAL_V3.SetWindowTextW(str);

	UpdateData(FALSE);
}


void CFCU_SWDlg::OnStnClickedLedEmsq()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRecvView->AddEventString(_T("사출 모터 점화"));
}



void CFCU_SWDlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete[]m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}


void CFCU_SWDlg::DrawImage(int control, cv::Mat* buffer)
{
	CClientDC dc(GetDlgItem(control));

	CRect rect;

	GetDlgItem(control)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, buffer->cols, buffer->rows, buffer->data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}


void CFCU_SWDlg::KillSKR_TRK_STATUS(void)
{
	u16LED_Cnt = 0;
	bLED_State = FALSE;
	KillTimer(HEADER_SKR_TRK_STATUS);

	// m_sclAimResult = SCL_GREEN;

	// m_bModifyAxis = TRUE;

	//CWnd* pWnd;
	//pWnd = (CWnd*)GetDlgItem(IDC_BTN_SKR_TRK_STATUS_TEST);
	//pWnd->EnableWindow(FALSE);
	//m_btnSkrTrkStatusTest.LoadBitmaps(IDB_BTN_SKR_TRK_STATUS_01, IDB_BTN_SKR_TRK_STATUS_02, NULL, NULL);
	//pWnd->EnableWindow(TRUE);

	//ChangeLED(&m_ledSKR_TRK_STATUS_TEST, IDI_LED_WHITE);

}


UINT CFCU_SWDlg::CamDataRecv(LPVOID _mothod)
{
	// TODO: 여기에 구현 코드 추가
	CFCU_SWDlg* pDlg = (CFCU_SWDlg*)AfxGetApp()->m_pMainWnd;

		HDC dc;
		int bpp;
		int padding;
		int border;
		RECT rect;
		cv::Size* winSize;
		BITMAPINFO* bmp_info;

	pDlg->m_pRecvView->AddEventString(_T("CamDataRecv START !!!"));

	pDlg->m_pVC_Cam = new cv::VideoCapture("udpsrc port=52999 caps=\"application/x-rtp,encoding-name=H264,payload=96\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
	// cap = new cv::VideoCapture("videotestsrc ! appsink", cv::CAP_GSTREAMER);
	if (!(pDlg->m_pVC_Cam)->isOpened())
	{
		AfxMessageBox(_T("Camera Open Error. \n"));

		return -1;
	}
	else
	{
		pDlg->m_pRecvView->AddEventString(_T("Camera Open Success"));

	}

	pDlg->m_bSkrRecvFlag = TRUE;
	// pDlg->SetTimer(CASE_RECV_CAM, 30, NULL);

	while(1)
	{
	if (!(pDlg->m_pVC_Cam->read(pDlg->m_matMain)))
	{
		pDlg->m_pVC_Cam->release();
		pDlg->m_pVC_Cam = new cv::VideoCapture("udpsrc port=52999 caps=\"application/x-rtp,encoding-name=H264,payload=96\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
		continue;
	}

	////카메라에서 프레임 1장 캡쳐
	//if (m_pVC_Cam->read(m_matMain))
	//{
	//	m_pVC_Cam->release();
	//	m_pVC_Cam = new cv::VideoCapture("udpsrc port=52999 caps=\"application/x-rtp,encoding-name=H264,payload=96\" ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
	//	
	//	break;
	//}


	resize(pDlg->m_matMain, pDlg->m_matMain, Size(512, 512), 0, 0, 1);

	//화면 회전
	//rotate(m_matMain, m_matMain, cv::ROTATE_180);
	//화면 좌우 반전
	// flip(m_matMain, m_matMain, 1);
	//화면 상하 반전
	//flip(m_matMain, m_matMain, 0);

	if (pDlg->m_bAimT == TRUE)
	{
		// T자선 X축
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16YAW_CAM - 35, pDlg->m_s16PITCH_CAM), cv::Point(pDlg->m_s16YAW_CAM - 5, pDlg->m_s16PITCH_CAM), pDlg->m_sclAim, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16YAW_CAM + 5, pDlg->m_s16PITCH_CAM), cv::Point(pDlg->m_s16YAW_CAM + 35, pDlg->m_s16PITCH_CAM), pDlg->m_sclAim, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16YAW_CAM, pDlg->m_s16PITCH_CAM), cv::Point(pDlg->m_s16YAW_CAM, pDlg->m_s16PITCH_CAM), pDlg->m_sclAim, 2, 1, 0);

		// T자선 Y축
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16YAW_CAM, pDlg->m_s16PITCH_CAM + 5), cv::Point(pDlg->m_s16YAW_CAM, pDlg->m_s16PITCH_CAM + 35), pDlg->m_sclAim, 2, 1, 0);
	}

	if (pDlg->m_bAimTracking == TRUE)
	{
		// 위 가로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16EX_CAM, pDlg->m_s16SY_CAM), cv::Point(pDlg->m_s16SX_CAM, pDlg->m_s16SY_CAM), pDlg->m_sclAim, 2, 1, 0);

		// 밑 가로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16EX_CAM, pDlg->m_s16EY_CAM), cv::Point(pDlg->m_s16SX_CAM, pDlg->m_s16EY_CAM), pDlg->m_sclAim, 2, 1, 0);

		// 위 세로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16SX_CAM, pDlg->m_s16SY_CAM), cv::Point(pDlg->m_s16SX_CAM, pDlg->m_s16EY_CAM), pDlg->m_sclAim, 2, 1, 0);

		// 밑 세로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->m_s16EX_CAM, pDlg->m_s16SY_CAM), cv::Point(pDlg->m_s16EX_CAM, pDlg->m_s16EY_CAM), pDlg->m_sclAim, 2, 1, 0);
	}

	if (pDlg->m_bAimSight == TRUE)
	{
		if (pDlg->m_u16currentCMD == HEADER_SKR_TRK_STATUS)
		{
			pDlg->m_sclAimResult = SCL_GREEN;
		}

		// 위 가로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimLB_X, pDlg->s16AimRT_Y), cv::Point(pDlg->s16AimLB_X + 5, pDlg->s16AimRT_Y), pDlg->m_sclAimResult, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimRT_X - 5, pDlg->s16AimRT_Y), cv::Point(pDlg->s16AimRT_X, pDlg->s16AimRT_Y), pDlg->m_sclAimResult, 2, 1, 0);

		// 밑 가로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimLB_X, pDlg->s16AimLB_Y), cv::Point(pDlg->s16AimLB_X + 5, pDlg->s16AimLB_Y), pDlg->m_sclAimResult, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimRT_X - 5, pDlg->s16AimLB_Y), cv::Point(pDlg->s16AimRT_X, pDlg->s16AimLB_Y), pDlg->m_sclAimResult, 2, 1, 0);

		// 위 세로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimLB_X, pDlg->s16AimRT_Y), cv::Point(pDlg->s16AimLB_X, pDlg->s16AimRT_Y + 5), pDlg->m_sclAimResult, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimRT_X, pDlg->s16AimRT_Y), cv::Point(pDlg->s16AimRT_X, pDlg->s16AimRT_Y + 5), pDlg->m_sclAimResult, 2, 1, 0);

		// 밑 세로
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimLB_X, pDlg->s16AimLB_Y - 5), cv::Point(pDlg->s16AimLB_X, pDlg->s16AimLB_Y), pDlg->m_sclAimResult, 2, 1, 0);
		cv::line(pDlg->m_matMain, cv::Point(pDlg->s16AimRT_X, pDlg->s16AimLB_Y - 5), cv::Point(pDlg->s16AimRT_X, pDlg->s16AimLB_Y), pDlg->m_sclAimResult, 2, 1, 0);

	}

	//화면 상하 반전
	flip(pDlg->m_matMain, pDlg->m_matMain, 0);

	// 화면에 보여주기 위한 처리
	bpp = 8 * (int)pDlg->m_matMain.elemSize();
	assert((bpp == 8 || bpp == 24 || bpp == 32));

	padding = 0;
	if (bpp < 32) {
		padding = 4 - (pDlg->m_matMain.cols % 4);
	}
	if (padding == 4) {
		padding = 0;
	}

	border = 0;
	if (bpp < 32) {
		border = 4 - (pDlg->m_matMain.cols % 4);
	}

	pDlg->m_matTmp = pDlg->m_matMain;

	//picture_control UI 크기 가져오기
	pDlg->m_imgCam.GetClientRect(&rect);

	//picture_control UI 크기정보를 cv::Size에 저장
	winSize = new cv::Size(rect.right, rect.bottom);

	//CImage 생성
	pDlg->m_cimgCam.Create(winSize->width, winSize->height, 24);

	//bitmap 헤더정보
	bmp_info = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
	bmp_info->bmiHeader.biBitCount = bpp;
	bmp_info->bmiHeader.biWidth = pDlg->m_matTmp.cols;
	bmp_info->bmiHeader.biHeight = pDlg->m_matTmp.rows;
	bmp_info->bmiHeader.biPlanes = 1;
	bmp_info->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmp_info->bmiHeader.biCompression = BI_RGB;
	bmp_info->bmiHeader.biClrImportant = 0;
	bmp_info->bmiHeader.biClrUsed = 0;
	bmp_info->bmiHeader.biSizeImage = 0;
	bmp_info->bmiHeader.biXPelsPerMeter = 0;
	bmp_info->bmiHeader.biYPelsPerMeter = 0;

	if (bpp == 8) {
		RGBQUAD* palette = bmp_info->bmiColors;
		for (int i = 0; i < 256; i++) {
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}

	//CImage buffer에 frame update
	if (pDlg->m_matTmp.cols == winSize->width && pDlg->m_matTmp.rows == winSize->height) {
		SetDIBitsToDevice(pDlg->m_cimgCam.GetDC(),
			0, 0, winSize->width, winSize->height,
			0, 0, 0, pDlg->m_matTmp.rows,
			pDlg->m_matTmp.data, bmp_info, DIB_RGB_COLORS);
	}
	else {
		int destx = 0;
		int desty = 0;
		int destw = winSize->width;
		int desth = winSize->height;
		int imgx = 0;
		int imgy = 0;
		int imgWidth = pDlg->m_matTmp.cols - border;
		int imgHeight = pDlg->m_matTmp.rows;

		StretchDIBits(pDlg->m_cimgCam.GetDC(),
			destx, desty, destw, desth,
			imgx, imgy, imgWidth, imgHeight,
			pDlg->m_matTmp.data, bmp_info, DIB_RGB_COLORS, SRCCOPY);
	}

	//picture control에 CImage buffer update
	dc = ::GetDC(pDlg->m_imgCam.m_hWnd);
	pDlg->m_cimgCam.BitBlt(dc, 0, 0);

	::ReleaseDC(pDlg->m_imgCam.m_hWnd, dc);
	pDlg->m_cimgCam.ReleaseDC();
	pDlg->m_cimgCam.Destroy();

	Sleep(20);
	}

	return 0;
}


void CFCU_SWDlg::DestroyThread()
{
	// TODO: 여기에 구현 코드 추가.
	if (NULL != m_pThread)

	{
		m_pThread->SuspendThread();

		DWORD dwResult;
		::GetExitCodeThread(m_pThread->m_hThread, &dwResult);

		delete m_pThread;

		m_pThread = NULL;

	}

	return;
}


INT16 CFCU_SWDlg::convertMSL2CV(INT16 num, UINT8 axisCase)
{
	INT16 s16Ret = 0;

	if (axisCase == AXIS_X)
	{
		if (num < 0)
			s16Ret = (num * 2) + 256;
		else
			s16Ret = (num * 2) + 257;
	}
	else if (axisCase == AXIS_Y)
	{
		if (num < 0)
			s16Ret = (num * (-2)) + 255;
		else
			s16Ret = (num * (-2)) + 254;
	}

	return s16Ret;
}


INT16 CFCU_SWDlg::convertCV2MSL(INT16 num, UINT8 axisCase)
{
	// TODO: 여기에 구현 코드 추가.
	INT16 s16Ret = 0;

	if (axisCase == AXIS_X)
	{
		if (num < 0)
			s16Ret = (num - 256) / 2;
		else
			s16Ret = (num - 257) / 2;
	}
	else if (axisCase == AXIS_Y)
	{
		if (num < 0)
			s16Ret = (num - 255) / (-2);
		else
			s16Ret = (num - 254) / (-2);
	}

	return s16Ret;
}


void CFCU_SWDlg::OnBnClickedBtnGstreamer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_SocketServer.SendData(HEADER_SKR_IMG_CTRL);

	//if (m_bSKR_IMG_CTRL == FALSE)
	//{
	//	m_bSKR_IMG_CTRL = TRUE;
	//}
	//else if (m_bSKR_IMG_CTRL == TRUE)
	//{
	//	m_bSKR_IMG_CTRL = FALSE;
	//}

	KillTimer(CASE_RECV_CAM);
	m_pRecvView->AddEventString(_T("1"));
	DestroyThread();
	m_pRecvView->AddEventString(_T("2"));
	m_bSKR_IMG_CTRL = FALSE;
	m_pRecvView->AddEventString(_T("3"));
	m_SocketServer.SendData(HEADER_SKR_IMG_CTRL);
	m_pRecvView->AddEventString(_T("4"));
	// delete m_pVC_Cam;
}


void CFCU_SWDlg::OnBnClickedBtnSendImgVal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_SocketServer.SendData(HEADER_IMG_VAL);
}


void CFCU_SWDlg::LoadnDraw()
{
	if (m_bSkrRecvFlag == TRUE)
		return;

	Mat m_matMain(512, 512, CV_8UC3, Scalar(0, 0, 0));

	CreateBitmapInfo(m_matMain.cols, m_matMain.rows, m_matMain.channels() * 8);

	if (m_bAimT == TRUE)
	{
		// T자선 X축
		cv::line(m_matMain, cv::Point(m_s16YAW_CAM - 35, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM - 5, m_s16PITCH_CAM), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(m_s16YAW_CAM + 5, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM + 35, m_s16PITCH_CAM), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM), cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM), m_sclAimResult, 2, 1, 0);

		// T자선 Y축
		cv::line(m_matMain, cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM + 5), cv::Point(m_s16YAW_CAM, m_s16PITCH_CAM + 35), m_sclAimResult, 2, 1, 0);
	}

	if (m_bAimTracking == TRUE)
	{
		// 위 가로
		cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16SY_CAM), cv::Point(m_s16SX_CAM, m_s16SY_CAM), m_sclAimResult, 2, 1, 0);

		// 밑 가로
		cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16EY_CAM), cv::Point(m_s16SX_CAM, m_s16EY_CAM), m_sclAimResult, 2, 1, 0);

		// 위 세로
		cv::line(m_matMain, cv::Point(m_s16SX_CAM, m_s16SY_CAM), cv::Point(m_s16SX_CAM, m_s16EY_CAM), m_sclAimResult, 2, 1, 0);

		// 밑 세로
		cv::line(m_matMain, cv::Point(m_s16EX_CAM, m_s16SY_CAM), cv::Point(m_s16EX_CAM, m_s16EY_CAM), m_sclAimResult, 2, 1, 0);
	}

	if (m_bAimSight == TRUE)
	{
		// 위 가로
		cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimRT_Y), cv::Point(s16AimLB_X + 5, s16AimRT_Y), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(s16AimRT_X - 5, s16AimRT_Y), cv::Point(s16AimRT_X, s16AimRT_Y), m_sclAimResult, 2, 1, 0);

		// 밑 가로
		cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimLB_Y), cv::Point(s16AimLB_X + 5, s16AimLB_Y), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(s16AimRT_X - 5, s16AimLB_Y), cv::Point(s16AimRT_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);

		// 위 세로
		cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimRT_Y), cv::Point(s16AimLB_X, s16AimRT_Y + 5), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(s16AimRT_X, s16AimRT_Y), cv::Point(s16AimRT_X, s16AimRT_Y + 5), m_sclAimResult, 2, 1, 0);

		// 밑 세로
		cv::line(m_matMain, cv::Point(s16AimLB_X, s16AimLB_Y - 5), cv::Point(s16AimLB_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);
		cv::line(m_matMain, cv::Point(s16AimRT_X, s16AimLB_Y - 5), cv::Point(s16AimRT_X, s16AimLB_Y), m_sclAimResult, 2, 1, 0);

	}

	//화면 상하 반전
	//flip(m_matMain, m_matMain, 0);

	DrawImage(IDC_CAM, &m_matMain);

}


void CFCU_SWDlg::OnAcceleratorAltP()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_u8Mode != CASE_INITIAL_MODE)
	{
		ChangeLED(&m_LED_L7, IDI_BTN_GREEN_DOWN);
		SetTimer(HEADER_EXT_POW_ON, 1000, NULL);

		OnBnClickedBtnPower();
	}

}


void CFCU_SWDlg::OnAcceleratorAltA()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnStnClickedimgmode();

	ChangeLED(&m_LED_L6, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_ATK_MODE, 1000, NULL);
}


void CFCU_SWDlg::OnBnClickedBtnFold()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static BOOL bFold = FALSE;

	if (bFold == FALSE)
	{
		bFold = TRUE;
		this->MoveWindow(0, 80, 205, 43);
	}
	else
	{
		bFold = FALSE;
		this->MoveWindow(0, 80, 960, 720);
		LoadnDraw();
	}
}


void CFCU_SWDlg::OnAcceleratorFold()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnBnClickedBtnFold();
}


void CFCU_SWDlg::OnBnClickedBtnCenter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ChangeLED(&m_LED_L3, IDI_BTN_GREEN_DOWN);

	if (m_u16currentCMD == HEADER_SKR_TRK_STATUS)
	{
		OnBnClickedReLockOnCmd();
	}
	else
	{
		SetTimer(CASE_KEY_CENTER, 500, NULL);

		ResetAim();
	}

	ChangeLED(&m_LED_L3, IDI_BTN_GREEN_DOWN);
	SetTimer(CASE_KEY_CENTER, 500, NULL);
}


void CFCU_SWDlg::OnAcceleratorSpace()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// OnBnClickedReLockOnCmd();

	OnBnClickedBtnCenter();
}


BOOL CFCU_SWDlg::resetValue()
{
	// TODO: 여기에 구현 코드 추가.
	return 0;
}


void CFCU_SWDlg::OnAcceleratorAltL()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	if ((m_u16currentCMD == HEADER_SKR_PLC_CHK))
	{
		ChangeLED(&m_LED_L7, IDI_BTN_GREEN_DOWN);
		// SetTimer(CASE_KEY_MSL_POW, 1000, NULL);

		OnBnClickedLockOnCmd();
	}
	else if ((m_u16currentCMD == HEADER_SKR_TRK_STATUS) || (m_u16currentCMD == HEADER_LOCK_ON_CMD))
	{
		ChangeLED(&m_LED_L7, IDI_BTN_GREEN_UP);
		ChangeLED(&m_LED_L3, IDI_BTN_GREEN_UP);

		u16LED_Cnt = 0;
		bLED_State = FALSE;
		m_bLOCK_ON_RSLT_FAULT = FALSE;
		m_bRE_ROCK_ON_Flag = FALSE;

		// SKR_TRK_STATUS 타이머 Kill
		KillTimer(HEADER_SKR_TRK_STATUS);

		//ChangeLED(&m_LED_L7, IDI_BTN_GREEN_DOWN);
		//SetTimer(CASE_KEY_MSL_POW, 1000, NULL);

		// Lock-on 해제 명령 send
		m_SocketServer.SendData(HEADER_SKR_CAGE_CMD);

		ResetAim();
	}
	this->SetFocus();
}




void CFCU_SWDlg::OnAcceleratorF6()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_u8Mode == CASE_INITIAL_MODE)
	{
		OnBnClickedBtnModeTest();
	}
	else
	{
		m_pRecvView->AddEventString(_T("운용 모드를 변경할 수 없습니다!"));
	}
	this->SetFocus();
}


void CFCU_SWDlg::OnAcceleratorAltF()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	if (m_u16currentCMD == HEADER_SKR_TRK_STATUS)
	{
		// AfxMessageBox(_T("Success : Fire"));
		KillTimer(HEADER_SKR_TRK_STATUS);
		m_SocketServer.SendData(HEADER_ATK_MODE_CMD);
		// SetTimer(CASE_SET_MAX_ATK_MOD_TIME, 50, NULL);

		ChangeLED(&m_LED_L6, IDI_BTN_GREEN_DOWN);
		SetTimer(CASE_KEY_ATK_MODE, 1000, NULL);

		m_u16currentCMD = NULL;
	}
	else
	{
	}
}


afx_msg LRESULT CFCU_SWDlg::OnSelectMode(WPARAM wParam, LPARAM lParam)
{


	return 0;
}


void CFCU_SWDlg::DP_selectingMode()
{

}


afx_msg LRESULT CFCU_SWDlg::OnSetLaunchMode(WPARAM wParam, LPARAM lParam)
{
	OnAcceleratorF1();

	return 0;
}


afx_msg LRESULT CFCU_SWDlg::OnSetDryrunMode(WPARAM wParam, LPARAM lParam)
{
	OnAcceleratorF2();

	return 0;
}


void CFCU_SWDlg::OnAcceleratorF10()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_u8Mode == CASE_INITIAL_MODE)
		OnBnClickedCancelDlg();
}


void CFCU_SWDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	POSITION pos;
	pos = m_SocketServer.m_ptrClientSocketList.GetHeadPosition();
	CSocketClient* pClient = NULL;

	while (pos != NULL)
	{
		pClient = (CSocketClient*)m_SocketServer.m_ptrClientSocketList.GetNext(pos);

		if (pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();

			delete pClient;
		}
	}

	m_SocketServer.ShutDown();
	m_SocketServer.Close();
}


void CFCU_SWDlg::OnStnClickedimgtitle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


afx_msg LRESULT CFCU_SWDlg::OnCloseEvent(WPARAM wParam, LPARAM lParam)
{
	CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_POWER);

	m_wEXTPOW = DISABLE;

	pWnd->EnableWindow(FALSE);
	m_btnPower.LoadBitmaps(IDB_BTN_POWER_02, IDB_BTN_POWER_02, NULL, NULL);
	pWnd->EnableWindow(TRUE);

	SetMslStat(BLACK);
	SetLnchStat(MONO);
	SetSkrStat(BLACK);
	KillTimer(HEADER_FCU_BIT_CHK);
	(GetDlgItem(IDC_LAMP_SKR_RDY))->ShowWindow(FALSE);

	m_pRecvView->AddEventString(_T("ERROR : 클라이언트 접속 해제"));

	m_u8ClientCnt = 0;

	return 0;
}


afx_msg LRESULT CFCU_SWDlg::OnReceiveEventHils(WPARAM wParam, LPARAM lParam)
{
	CString str, strTmp;
	U32BIT u32Len = 0;
	U32BIT idx = 0;

	BYTE buffer[MESSAGE_SIZE_MAX] = { 0, };

	if (WSAGETSELECTEVENT(lParam) == FD_CONNECT)
	{
		m_bConnectionStateHILS = TRUE;
	}
	else if (WSAGETSELECTEVENT(lParam) == FD_READ)
	{
		WSAAsyncSelect(wParam, m_hWnd, WM_RECEIVE_EVENT_HILS, FD_CLOSE);

		u32Len = recv(wParam, (char*)buffer, MESSAGE_SIZE_MAX, 0);

		if (u32Len > 0)
		{
			// 발사통제모드 진입/종료
			if ((buffer[0] == 0x10) && (buffer[1] == 0x02))
			{
				if (buffer[8] == 0x00)
				{
					m_pModeIO.m_u16HILS_RTN_Disconnect = FALSE;
				}
				else if (buffer[8] == 0x0F)
				{
					m_pModeIO.m_u16HILS_RTN_Connect = FALSE;
				}
				else if (buffer[8] == 0xF0)
				{
					m_pModeIO.m_u16HILS_RTN_Disconnect = TRUE;
				}
				else if (buffer[8] == 0xFF)
				{
					m_pModeIO.m_u16HILS_RTN_Connect = TRUE;
				}
			}

			m_pRecvView->AddEventString(str);
		}
		else
		{
			m_pRecvView->AddEventString(_T("ERROR : recv()"));
		}

		WSAAsyncSelect(wParam, m_hWnd, WM_RECEIVE_EVENT_HILS, FD_READ | FD_CLOSE);
	}
	else if (WSAGETSELECTEVENT(lParam) == FD_CLOSE)
	{
		m_pRecvView->AddEventString(_T("HILS 연결이 해제 되었습니다"));
		m_bConnectionStateHILS = FALSE;
		killAllTimer();

		// closesocket(m_ClientSocket_HILS.m_hSocket);//클라이언트 소켓 클로즈
		// m_ClientSocket_HILS.End();
		closesocket(m_ClientSocket_HILS.m_hSocket);;
		m_ClientSocket_HILS.m_hSocket = INVALID_SOCKET;
		m_ClientSocket_HILS.bSocketOpen = FALSE; // 연결 해제 flag 변경
		// SetTimer(TRY_CONNECT_TO_SERVER, 3000, NULL);
	}

	//WSAAsyncSelect(wParam, m_hWnd, WM_RECEIVE_EVENT_HILS, FD_READ | FD_CLOSE);

	return 0;
}


afx_msg LRESULT CFCU_SWDlg::OnClientDisconnect(WPARAM wParam, LPARAM lParam)
{
	CString str;

	// SetLnchStat(BLACK);
	m_wEXTPOW = DISABLE;
	killAllTimer();

	(GetDlgItem(IDC_LAMP_SKR_RDY))->ShowWindow(FALSE);

	m_pFCU_STS_Dlg->PostMessageW(WM_PIN_CHK, WHITE, NULL);
	m_pFCU_STS_Dlg->PostMessageW(WM_MSL_CON, WHITE, NULL);

	str.Format(_T("0"));

	m_txtVAL_A1.SetWindowTextW(str);
	m_txtVAL_A2.SetWindowTextW(str);
	m_txtVAL_A3.SetWindowTextW(str);
	m_txtVAL_V1.SetWindowTextW(str);
	m_txtVAL_V2.SetWindowTextW(str);
	m_txtVAL_V3.SetWindowTextW(str);

	UpdateData(FALSE);

	return 0;
}


void CFCU_SWDlg::SetInitialDlg()
{
	// TODO: 여기에 구현 코드 추가.
	CString str;
	m_u8Mode = CASE_INITIAL_MODE;

	(GetDlgItem(IDC_imgTitle))->ShowWindow(FALSE);

	m_pFCU_STS_Dlg->ShowWindow(SW_HIDE);
	m_ptCModeSelect->ShowWindow(SW_SHOW);

	m_wEXTPOW = DISABLE;
	killAllTimer();

	UpdateData(FALSE);
}


void CFCU_SWDlg::OnAcceleratorAltC()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(HEADER_SKR_TRK_STATUS);

	OnBnClickedBtnSkrCageCmd();
}


void CFCU_SWDlg::OnBnClickedBtnPowerMbat()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_u8Mode != CASE_INITIAL_MODE)
	{
		CWnd* pWnd = (CWnd*)GetDlgItem(IDC_BTN_POWER_MBAT);

		if (m_wMBATABAT == DISABLE)
		{
			m_wMBATABAT = ENABLE;

			pWnd->EnableWindow(FALSE);
			m_btnMbatOn.LoadBitmaps(IDB_BTN_POWER_01, IDB_BTN_POWER_01, NULL, NULL);
			pWnd->EnableWindow(TRUE);

			m_SocketServer.SendData(HEADER_MBAT_ON);
			SetTimer(HEADER_MBAT_ON, 200, NULL);
		}
		else
		{
			m_wMBATABAT = DISABLE;

			pWnd->EnableWindow(FALSE);
			m_btnMbatOn.LoadBitmaps(IDB_BTN_POWER_02, IDB_BTN_POWER_02, NULL, NULL);
			pWnd->EnableWindow(TRUE);

			m_SocketServer.SendData(HEADER_OFF_ABAT);
			SetTimer(HEADER_OFF_ABAT, 200, NULL);
		}
	}
}


void CFCU_SWDlg::ResetAim()
{
	// TODO: 여기에 구현 코드 추가.
	// 조준창 좌표 초기화(20×20)
	s16AimRT_X = 275;
	s16AimRT_Y = 236;
	s16AimLB_X = 236;
	s16AimLB_Y = 275;

	m_strAimSize_X.Format(_T("%d"), (s16AimRT_X - s16AimLB_X + 1) / 2);
	m_strAimSize_Y.Format(_T("%d"), (s16AimLB_Y - s16AimRT_Y + 1) / 2);

	m_s16RT_X = convertCV2MSL(s16AimRT_X, AXIS_X);
	m_s16LB_X = convertCV2MSL(s16AimLB_X, AXIS_X);
	m_s16RT_Y = convertCV2MSL(s16AimRT_Y, AXIS_Y);
	m_s16LB_Y = convertCV2MSL(s16AimLB_Y, AXIS_Y);

	m_strLLX.Format(_T("-"));
	m_strLLY.Format(_T("-"));
	m_strRUX.Format(_T("-"));
	m_strRUY.Format(_T("-"));

	m_sclAim = SCL_WHITE;
	m_sclAimResult = SCL_WHITE;

	UpdateData(FALSE);
}


void CFCU_SWDlg::ShowMSL_FAIL()
{
	// TODO: 여기에 구현 코드 추가.

	if (m_bShowWarning == FALSE)
	{
		m_pShowWarning = new CShowWarning;
		m_bShowWarning = m_pShowWarning->Create(IDD_ShowWarning);
		m_pShowWarning->ShowWindow(SW_SHOW);
	}
}


UINT16 CFCU_SWDlg::Byte2WORD(UINT8* byte)
{
	return (byte[0] << 8 | byte[1]);
}
