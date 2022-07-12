// FCU_MODE_SELECT.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "FCU_MODE_SELECT.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CFCU_MODE_SELECT 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFCU_MODE_SELECT, CDialogEx)

CFCU_MODE_SELECT::CFCU_MODE_SELECT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFCU_MODE_SELECT::IDD, pParent)
	, ret(0)
{
}

CFCU_MODE_SELECT::~CFCU_MODE_SELECT()
{
}

void CFCU_MODE_SELECT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_MODE_TEST, m_btnModeTest);
	DDX_Control(pDX, IDC_BTN_MODE_DRYRUN, m_btnModeDryrun);
	DDX_Control(pDX, IDC_BTN_MODE_LAUNCH, m_btnModeLaunch);
	DDX_Control(pDX, IDC_BTN_MODE_ESCAPE, m_btnModeEscape);
}


BEGIN_MESSAGE_MAP(CFCU_MODE_SELECT, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_MODE_TEST, &CFCU_MODE_SELECT::OnBnClickedBtnModeTest)
	ON_BN_CLICKED(IDC_BTN_MODE_DRYRUN, &CFCU_MODE_SELECT::OnBnClickedBtnModeDryrun)
	ON_BN_CLICKED(IDC_BTN_MODE_LAUNCH, &CFCU_MODE_SELECT::OnBnClickedBtnModeLaunch)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BTN_MODE_ESCAPE, &CFCU_MODE_SELECT::OnBnClickedBtnModeEscape)
END_MESSAGE_MAP()


// CFCU_MODE_SELECT 메시지 처리기입니다.


BOOL CFCU_MODE_SELECT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 800, 960, 240);

	m_btnModeTest.LoadBitmaps(IDB_BTN_MODE_TEST_01, IDB_BTN_MODE_TEST_02, NULL, NULL);
	m_btnModeTest.SizeToContent();
	m_btnModeDryrun.LoadBitmaps(IDB_BTN_MODE_DRYRUN_01, IDB_BTN_MODE_DRYRUN_02, NULL, NULL);
	m_btnModeDryrun.SizeToContent();
	m_btnModeLaunch.LoadBitmaps(IDB_BTN_MODE_LAUNCH_01, IDB_BTN_MODE_LAUNCH_02, NULL, NULL);
	m_btnModeLaunch.SizeToContent();
	m_btnModeEscape.LoadBitmaps(IDB_BTN_MODE_ESC_01, IDB_BTN_MODE_ESC_02, NULL, NULL);
	m_btnModeEscape.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CFCU_MODE_SELECT::OnBnClickedBtnModeTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_u8Mode = CASE_TEST_MODE;
	// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->PostMessageW(WM_SELECT_MODE, NULL, NULL);
	// OnOK();
}


void CFCU_MODE_SELECT::OnBnClickedBtnModeDryrun()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_u8Mode = CASE_DRYRUN_MODE;
	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->PostMessageW(WM_SET_DRYRUN_MODE, NULL, NULL);
	// OnOK();
}


void CFCU_MODE_SELECT::OnBnClickedBtnModeLaunch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_u8Mode = CASE_LAUNCH_MODE;

	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->PostMessageW(WM_SET_LAUNCH_MODE, NULL, NULL);
	// OnOK();
}


void CFCU_MODE_SELECT::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case SET_FOCUS:
		((CFCU_SWDlg*)GetParent())->SetFocus();
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}



void CFCU_MODE_SELECT::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CFCU_MODE_SELECT::PreTranslateMessage(MSG* pMsg)
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


void CFCU_MODE_SELECT::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(SET_FOCUS, 1000, NULL);
	//((CFCU_SWDlg*)GetParent())->SetFocus();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CFCU_MODE_SELECT::OnBnClickedBtnModeEscape()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->OnBnClickedCancelDlg();
}
