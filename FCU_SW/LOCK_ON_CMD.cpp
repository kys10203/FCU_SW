// LOCK_ON_CMD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "LOCK_ON_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CLOCK_ON_CMD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLOCK_ON_CMD, CDialogEx)

CLOCK_ON_CMD::CLOCK_ON_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLOCK_ON_CMD::IDD, pParent)
{

	EnableAutomation();

}

CLOCK_ON_CMD::~CLOCK_ON_CMD()
{
}

void CLOCK_ON_CMD::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CLOCK_ON_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CLOCK_ON_CMD, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CLOCK_ON_CMD::OnBnClickedBtnCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLOCK_ON_CMD, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ILOCK_ON_CMD에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {B123823B-465C-418D-995C-859460FE817F}
static const IID IID_ILOCK_ON_CMD =
{ 0xB123823B, 0x465C, 0x418D, { 0x99, 0x5C, 0x85, 0x94, 0x60, 0xFE, 0x81, 0x7F } };

BEGIN_INTERFACE_MAP(CLOCK_ON_CMD, CDialogEx)
	INTERFACE_PART(CLOCK_ON_CMD, IID_ILOCK_ON_CMD, Dispatch)
END_INTERFACE_MAP()


// CLOCK_ON_CMD 메시지 처리기입니다.


BOOL CLOCK_ON_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


BOOL CLOCK_ON_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bLOCK_ON_CMD = FALSE;

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


void CLOCK_ON_CMD::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bLOCK_ON_CMD = FALSE;

    CDialogEx::OnOK();
}
