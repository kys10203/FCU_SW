// FCU_STS_Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "FCU_STS_Dlg.h"
#include "FCU_SWDlg.h"

// CFCU_STS_Dlg 대화 상자

IMPLEMENT_DYNAMIC(CFCU_STS_Dlg, CDialogEx)

CFCU_STS_Dlg::CFCU_STS_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FCU_STS_Dlg, pParent)
{

}

CFCU_STS_Dlg::~CFCU_STS_Dlg()
{
}

void CFCU_STS_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_LNCH_MODE_START, m_btnLNCH_MODE_START);
	DDX_Control(pDX, IDC_BTN_LNCH_MODE_STOP, m_btnLNCH_MODE_STOP);
	DDX_Control(pDX, IDC_BTN_MAIN_SCREEN, m_btnMainScreen);
	DDX_Control(pDX, IDC_LED_01_MSL_BIT, m_led01);
	DDX_Control(pDX, IDC_LED_02_SKR_RDY, m_led02);
	DDX_Control(pDX, IDC_LED_03_SKR_CAGE, m_led03);
	DDX_Control(pDX, IDC_LED_04_SKR_TRK, m_led04);
	DDX_Control(pDX, IDC_LED_05_SKR_PLC, m_led05);
	DDX_Control(pDX, IDC_LED_06_MSL_STS, m_led06);
	DDX_Control(pDX, IDC_LED_07_MSL_ID, m_led07);
	DDX_Control(pDX, IDC_LED_08_ATK_MOD, m_led08);
	DDX_Control(pDX, IDC_LED_09_LCK_CMD, m_led09);
	DDX_Control(pDX, IDC_LED_10_ReLCK_CMD, m_led10);
	DDX_Control(pDX, IDC_LED_11_LiftOff_RDY, m_led11);
	DDX_Control(pDX, IDC_LED_12_MSL_CON, m_led12);
	DDX_Control(pDX, IDC_LED_13_PIN_CON, m_led13);
	DDX_Control(pDX, IDC_LED_14_SQB_MBAT, m_led14);
	DDX_Control(pDX, IDC_LED_15_SQB_CU, m_led15);
	DDX_Control(pDX, IDC_LED_16_SQB_PIN, m_led16);
	DDX_Control(pDX, IDC_STATIC14, m_staticSQB_BAT);
	DDX_Control(pDX, IDC_STATIC17, m_txtSkrPlc);
	DDX_Control(pDX, IDC_STATIC18, m_txtMslIdChk);
}


BEGIN_MESSAGE_MAP(CFCU_STS_Dlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_LNCH_MODE_START, &CFCU_STS_Dlg::OnBnClickedBtnLnchModeStart)
	ON_BN_CLICKED(IDC_BTN_LNCH_MODE_STOP, &CFCU_STS_Dlg::OnBnClickedBtnLnchModeStop)
	ON_BN_CLICKED(IDC_BTN_MAIN_SCREEN, &CFCU_STS_Dlg::OnBnClickedBtnMainScreen)
	ON_MESSAGE(WM_RESET_STAT, &CFCU_STS_Dlg::OnResetStat)
	ON_MESSAGE(WM_MSL_BIT_CHK, &CFCU_STS_Dlg::OnMslBitChk)
	ON_MESSAGE(WM_SKR_RDY_CHK, &CFCU_STS_Dlg::OnSkrRdyChk)
	ON_MESSAGE(WM_SKR_CAGE_CMD, &CFCU_STS_Dlg::OnSkrCageCmd)
	ON_MESSAGE(WM_SKR_TRK_STATUS, &CFCU_STS_Dlg::OnSkrTrkStatus)
	ON_MESSAGE(WM_SKR_PLC_CHK, &CFCU_STS_Dlg::OnSkrPlcChk)
	ON_MESSAGE(WM_MSL_STS_CHK, &CFCU_STS_Dlg::OnMslStsChk)
	ON_MESSAGE(WM_MSL_ID_CHK, &CFCU_STS_Dlg::OnMslIdChk)
	ON_MESSAGE(WM_ATK_MOD, &CFCU_STS_Dlg::OnAtkMod)
	ON_MESSAGE(WM_LCK_CMD, &CFCU_STS_Dlg::OnLckCmd)
	ON_MESSAGE(WM_RELCK_CMD, &CFCU_STS_Dlg::OnRelckCmd)
	ON_MESSAGE(WM_LIFTOFF_RDY, &CFCU_STS_Dlg::OnLiftoffRdy)
	ON_MESSAGE(WM_MSL_CON, &CFCU_STS_Dlg::OnMslCon)
	ON_MESSAGE(WM_PIN_CHK, &CFCU_STS_Dlg::OnPinChk)
	ON_MESSAGE(WM_SQB_MBAT, &CFCU_STS_Dlg::OnSqbMbat)
	ON_MESSAGE(WM_SQB_CU, &CFCU_STS_Dlg::OnSqbCu)
	ON_MESSAGE(WM_SQB_PIN, &CFCU_STS_Dlg::OnSqbPin)
	ON_STN_CLICKED(IDC_STATIC1, &CFCU_STS_Dlg::OnStnClickedStatic1)
	ON_STN_CLICKED(IDC_STATIC3, &CFCU_STS_Dlg::OnStnClickedStatic3)
	ON_STN_CLICKED(IDC_STATIC7, &CFCU_STS_Dlg::OnStnClickedStatic7)
	ON_STN_CLICKED(IDC_STATIC2, &CFCU_STS_Dlg::OnStnClickedStatic2)
	ON_STN_CLICKED(IDC_STATIC5, &CFCU_STS_Dlg::OnStnClickedStatic5)
	ON_STN_CLICKED(IDC_STATIC9, &CFCU_STS_Dlg::OnStnClickedStatic9)
	ON_STN_CLICKED(IDC_STATIC10, &CFCU_STS_Dlg::OnStnClickedStatic10)
	ON_STN_CLICKED(IDC_STATIC4, &CFCU_STS_Dlg::OnStnClickedStatic4)
	ON_STN_CLICKED(IDC_STATIC8, &CFCU_STS_Dlg::OnStnClickedStatic8)
	ON_STN_CLICKED(IDC_STATIC6, &CFCU_STS_Dlg::OnStnClickedStatic6)
	ON_STN_CLICKED(IDC_STATIC11, &CFCU_STS_Dlg::OnStnClickedStatic11)
	ON_MESSAGE(WM_PINCHK_MSLCON, &CFCU_STS_Dlg::OnPinchkMslcon)
	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(WM_SET_LAUNCH_MODE, &CFCU_STS_Dlg::OnSetLaunchMode)
	ON_MESSAGE(WM_SET_DRYRUN_MODE, &CFCU_STS_Dlg::OnSetDryrunMode)
	ON_MESSAGE(WM_CLIENT_DISCONNECT, &CFCU_STS_Dlg::OnClientDisconnect)
	ON_MESSAGE(WM_SQB_BAT, &CFCU_STS_Dlg::OnSqbBat)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CFCU_STS_Dlg 메시지 처리기


HBRUSH CFCU_STS_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT nID = pWnd->GetDlgCtrlID();

	switch (nID)
	{
	case IDC_STATIC:
	case IDC_STATIC1:
	case IDC_STATIC2:
	case IDC_STATIC3:
	case IDC_STATIC4:
	case IDC_STATIC5:
	case IDC_STATIC6:
	case IDC_STATIC7:
	case IDC_STATIC8:
	case IDC_STATIC9:
	case IDC_STATIC10:
	case IDC_STATIC11:
	case IDC_STATIC12:
	case IDC_STATIC13:
	case IDC_STATIC14:
	case IDC_STATIC15:
	case IDC_STATIC16:
		pDC->SetTextColor(RGB(250, 250, 250));
		pDC->SetBkColor(RGB(0, 40, 70));
		hbr = ::CreateSolidBrush(RGB(0, 40, 70));
		break;
	}

	return hbr;
}


BOOL CFCU_STS_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1920, 240);

	m_btnLNCH_MODE_START.LoadBitmaps(IDB_BTN_LNCH_MODE_START_01, IDB_BTN_LNCH_MODE_START_02, NULL, NULL);
	m_btnLNCH_MODE_START.SizeToContent();
	m_btnLNCH_MODE_STOP.LoadBitmaps(IDB_BTN_LNCH_MODE_STOP_01, IDB_BTN_LNCH_MODE_STOP_02, NULL, NULL);
	m_btnLNCH_MODE_STOP.SizeToContent();
	m_btnMainScreen.LoadBitmaps(IDB_BTN_MAIN_SCREEN_01, IDB_BTN_MAIN_SCREEN_02, NULL, NULL);
	m_btnMainScreen.SizeToContent();

	resetStat();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFCU_STS_Dlg::OnBnClickedBtnLnchModeStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	resetStat();

}


BOOL CFCU_STS_Dlg::resetStat()
{

	((CFCU_SWDlg*)GetParent())->KillTimer(CASE_SET_MAX_SKR_RDY_TIME);

	// 유도탄 상태 표시등 초기화
	((CFCU_SWDlg*)GetParent())->SetMslStat(BLACK);
	// 탐색기 상태 표시등 초기화
	((CFCU_SWDlg*)GetParent())->SetSkrStat(BLACK);
	// 발사통제기 상태 표시등 초기화
	((CFCU_SWDlg*)GetParent())->SetLnchStat(MONO);
	// 발사 준비상태 표시등(상단 □) 초기화
	((CFCU_SWDlg*)GetParent())->SetSkrLamp(BLACK);

	// ((CFCU_SWDlg*)GetParent())->m_wEXTPOW = ENABLE;
	((CFCU_SWDlg*)GetParent())->m_bAimT = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bAimTracking = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bAimSight = TRUE;

	// 상태창 상세 정보 전시 플래그
	((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_BIT = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_CAGE = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_ID = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_RDY = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_PLC = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_TRK = FALSE;
	((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_STS = FALSE;

	((CFCU_SWDlg*)GetParent())->ResetAim();

	// 상태창 LED 초기화
	SetTimer(CASE_RESET_LED, 100, NULL);

	(GetDlgItem(IDC_STATIC18))->ShowWindow(FALSE);
	m_txtMslIdChk.SetWindowTextW(_T(""));
	(GetDlgItem(IDC_LED_07_MSL_ID))->ShowWindow(TRUE);

	(GetDlgItem(IDC_STATIC17))->ShowWindow(FALSE);
	m_txtSkrPlc.SetWindowTextW(_T(""));
	(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(TRUE);

	((CFCU_SWDlg*)GetParent())->m_strLLX.Format(_T("-"));
	((CFCU_SWDlg*)GetParent())->m_strLLY.Format(_T("-"));
	((CFCU_SWDlg*)GetParent())->m_strRUX.Format(_T("-"));
	((CFCU_SWDlg*)GetParent())->m_strRUY.Format(_T("-"));
	((CFCU_SWDlg*)GetParent())->m_strPLC_VALUE.Format(_T("-"));

	((CFCU_SWDlg*)GetParent())->UpdateData(FALSE);
	// ((CFCU_SWDlg*)GetParent())->OnBnClickedBtnGstreamer();


	return 0;
}


void CFCU_STS_Dlg::ChangeLED(CStatic* icon, UINT16 flag)
{
	// TODO: 여기에 구현 코드 추가.
	HICON h_Icon;   // 아이콘 객체 생성

	h_Icon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(flag));

	icon->SetIcon(h_Icon);
}


void CFCU_STS_Dlg::OnBnClickedBtnLnchModeStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->m_wEXTPOW = ENABLE;
	((CFCU_SWDlg*)GetParent())->OnBnClickedBtnPower();

	((CFCU_SWDlg*)GetParent())->m_wMBATABAT = ENABLE;
	((CFCU_SWDlg*)GetParent())->OnBnClickedBtnPowerMbat();

	((CFCU_SWDlg*)GetParent())->m_pShowWarning->ShowWindow(SW_HIDE);

	resetStat();
}


void CFCU_STS_Dlg::OnBnClickedBtnMainScreen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->m_wEXTPOW = ENABLE;
	((CFCU_SWDlg*)GetParent())->OnBnClickedBtnPower();

	((CFCU_SWDlg*)GetParent())->m_wMBATABAT = ENABLE;
	((CFCU_SWDlg*)GetParent())->OnBnClickedBtnPowerMbat();

	((CFCU_SWDlg*)GetParent())->m_pShowWarning->ShowWindow(SW_HIDE);

	resetStat();
	((CFCU_SWDlg*)GetParent())->SetInitialDlg();
}


afx_msg LRESULT CFCU_STS_Dlg::OnResetStat(WPARAM wParam, LPARAM lParam)
{
	resetStat();

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnMslBitChk(WPARAM wParam, LPARAM lParam)
{
	if (wParam == WHITE)
	{
		ChangeLED(&m_led01, IDI_LED_WHITE_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led01, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == GREEN)
	{
		ChangeLED(&m_led01, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led01, IDI_LED_RED_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSkrRdyChk(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led02, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led02, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led02, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led02, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSkrCageCmd(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led03, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led03, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led03, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led03, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSkrTrkStatus(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led04, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led04, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led04, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led04, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSkrPlcChk(WPARAM wParam, LPARAM lParam)
{

	if (wParam == HIGH)
	{
		(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(FALSE);
		m_txtSkrPlc.SetWindowTextW(_T("High"));
		(GetDlgItem(IDC_STATIC17))->ShowWindow(TRUE);
	}
	else if (wParam == MID)
	{
		(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(FALSE);
		m_txtSkrPlc.SetWindowTextW(_T("MID"));
		(GetDlgItem(IDC_STATIC17))->ShowWindow(TRUE);
	}
	else if (wParam == LOW)
	{
		(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(FALSE);
		m_txtSkrPlc.SetWindowTextW(_T("LOW"));
		(GetDlgItem(IDC_STATIC17))->ShowWindow(TRUE);
	}
	//else if (wParam == WHITE)
	//{
	//	(GetDlgItem(IDC_STATIC17))->ShowWindow(FALSE);
	//	ChangeLED(&m_led05, IDI_LED_WHITE_BIG);
	//	(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(TRUE);
	//}
	else if (wParam == RED)
	{
		(GetDlgItem(IDC_STATIC17))->ShowWindow(FALSE);
		ChangeLED(&m_led05, IDI_LED_RED_BIG);
		(GetDlgItem(IDC_LED_05_SKR_PLC))->ShowWindow(TRUE);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnMslStsChk(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led06, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led06, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led06, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led06, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnMslIdChk(WPARAM wParam, LPARAM lParam)
{
	(GetDlgItem(IDC_LED_07_MSL_ID))->ShowWindow(FALSE);
	m_txtMslIdChk.SetWindowTextW(_T("실 유도탄"));
	UpdateData(FALSE);
	(GetDlgItem(IDC_STATIC18))->ShowWindow(TRUE);

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnAtkMod(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led08, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led08, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led08, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led08, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnLckCmd(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led09, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led09, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led09, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led09, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnRelckCmd(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led10, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led10, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led10, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led10, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnLiftoffRdy(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led11, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led11, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led11, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led11, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnMslCon(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led12, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led12, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led12, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led12, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnPinChk(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led13, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led13, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led13, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led13, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSqbMbat(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led14, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led14, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led14, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led14, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSqbCu(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led15, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led15, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led15, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led15, IDI_LED_WHITE_BIG);
	}

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSqbPin(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led16, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led16, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led16, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led16, IDI_LED_WHITE_BIG);
	}

	return 0;
}


void CFCU_STS_Dlg::OnStnClickedStatic1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedMslBitChk();
}


void CFCU_STS_Dlg::OnStnClickedStatic3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedSkrCageCmd();
}


void CFCU_STS_Dlg::OnStnClickedStatic7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedMslIdChk();
}


void CFCU_STS_Dlg::OnStnClickedStatic2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedSkrRdyChk();
}


void CFCU_STS_Dlg::OnStnClickedStatic5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedSkrPlcChk();
}


void CFCU_STS_Dlg::OnStnClickedStatic9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// ((CFCU_SWDlg*)GetParent())->
}


void CFCU_STS_Dlg::OnStnClickedStatic10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// ((CFCU_SWDlg*)GetParent())->
}


void CFCU_STS_Dlg::OnStnClickedStatic4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedSkrTrkStatus();
}


void CFCU_STS_Dlg::OnStnClickedStatic8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFCU_STS_Dlg::OnStnClickedStatic6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnStnClickedLedMslStsChk();
}


void CFCU_STS_Dlg::OnStnClickedStatic11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


afx_msg LRESULT CFCU_STS_Dlg::OnPinchkMslcon(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


BOOL CFCU_STS_Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		((CFCU_SWDlg*)GetParent())->PreTranslateMessage(pMsg);
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CFCU_STS_Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(SET_FOCUS, 1000, NULL);

	CDialogEx::OnLButtonDown(nFlags, point);
}



afx_msg LRESULT CFCU_STS_Dlg::OnSetLaunchMode(WPARAM wParam, LPARAM lParam)
{
	m_staticSQB_BAT.SetWindowTextW(_T("SQB_BAT"));

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSetDryrunMode(WPARAM wParam, LPARAM lParam)
{
	m_staticSQB_BAT.SetWindowTextW(_T("열전지 모의전원"));

	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnClientDisconnect(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


afx_msg LRESULT CFCU_STS_Dlg::OnSqbBat(WPARAM wParam, LPARAM lParam)
{
	if (wParam == GREEN)
	{
		ChangeLED(&m_led14, IDI_LED_GREEN_BIG);
	}
	else if (wParam == RED)
	{
		ChangeLED(&m_led14, IDI_LED_RED_BIG);
	}
	else if (wParam == YELLOW)
	{
		ChangeLED(&m_led14, IDI_LED_YELLOW_BIG);
	}
	else if (wParam == WHITE)
	{
		ChangeLED(&m_led14, IDI_LED_WHITE_BIG);
	}

	return 0;
}


void CFCU_STS_Dlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case CASE_RESET_LED:
		KillTimer(CASE_RESET_LED);
		ChangeLED(&m_led01, IDI_LED_NONE);
		ChangeLED(&m_led02, IDI_LED_NONE);
		ChangeLED(&m_led03, IDI_LED_NONE);
		ChangeLED(&m_led04, IDI_LED_NONE);
		ChangeLED(&m_led05, IDI_LED_NONE);
		ChangeLED(&m_led06, IDI_LED_NONE);
		ChangeLED(&m_led07, IDI_LED_NONE);
		ChangeLED(&m_led08, IDI_LED_NONE);
		ChangeLED(&m_led09, IDI_LED_NONE);
		ChangeLED(&m_led10, IDI_LED_NONE);
		ChangeLED(&m_led11, IDI_LED_NONE);
		ChangeLED(&m_led12, IDI_LED_NONE);
		ChangeLED(&m_led13, IDI_LED_NONE);
		ChangeLED(&m_led14, IDI_LED_NONE);
		ChangeLED(&m_led15, IDI_LED_NONE);
		ChangeLED(&m_led16, IDI_LED_NONE);

		((CFCU_SWDlg*)GetParent())->SetSkrLamp(BLACK);

		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
