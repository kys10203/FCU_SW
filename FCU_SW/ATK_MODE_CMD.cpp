// ATK_MODE_CMD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "ATK_MODE_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CATK_MODE_CMD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CATK_MODE_CMD, CDialogEx)

CATK_MODE_CMD::CATK_MODE_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATK_MODE_CMD::IDD, pParent)
{

	EnableAutomation();

}

CATK_MODE_CMD::~CATK_MODE_CMD()
{
}

void CATK_MODE_CMD::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CATK_MODE_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CATK_MODE_CMD, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CATK_MODE_CMD::OnBnClickedBtnCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CATK_MODE_CMD, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IATK_MODE_CMD에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {EACA9016-528F-43E0-A4F4-74DCAC527636}
static const IID IID_IATK_MODE_CMD =
{ 0xEACA9016, 0x528F, 0x43E0, { 0xA4, 0xF4, 0x74, 0xDC, 0xAC, 0x52, 0x76, 0x36 } };

BEGIN_INTERFACE_MAP(CATK_MODE_CMD, CDialogEx)
	INTERFACE_PART(CATK_MODE_CMD, IID_IATK_MODE_CMD, Dispatch)
END_INTERFACE_MAP()


// CATK_MODE_CMD 메시지 처리기입니다.


BOOL CATK_MODE_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


HBRUSH CATK_MODE_CMD::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd -> GetDlgCtrlID();

    switch(nID)
    {
    case IDC_STATIC:
        pDC -> SetTextColor( RGB(250, 250, 250) );
    }
    return hbr;
}


BOOL CATK_MODE_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bATK_MODE_CMD = FALSE;

            CDialogEx::OnOK();

            return TRUE;
        }
        else if (pMsg->wParam == VK_RETURN)
        {
            // Enter 키 이벤트에 대한 처리 추가
            return TRUE;
        }
    }
    return CDialogEx::PreTranslateMessage(pMsg);
}


void CATK_MODE_CMD::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bATK_MODE_CMD = FALSE;

    CDialogEx::OnOK();
}
