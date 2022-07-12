// SKR_CAGE_CMD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_CAGE_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_CAGE_CMD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSKR_CAGE_CMD, CDialogEx)

CSKR_CAGE_CMD::CSKR_CAGE_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSKR_CAGE_CMD::IDD, pParent)
    , m_strSKR_CAGE_CMD_RSLT(_T(""))
{

	EnableAutomation();

}

CSKR_CAGE_CMD::~CSKR_CAGE_CMD()
{
}

void CSKR_CAGE_CMD::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CSKR_CAGE_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strSKR_CAGE_CMD_RSLT);
}


BEGIN_MESSAGE_MAP(CSKR_CAGE_CMD, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CSKR_CAGE_CMD::OnBnClickedBtnCancel)
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_SKR_CAGE_CMD, &CSKR_CAGE_CMD::OnSkrCageCmd)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSKR_CAGE_CMD, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISKR_CAGE_CMD에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {1CB9166D-AE96-4B1D-A0F9-166CF5FB9CB0}
static const IID IID_ISKR_CAGE_CMD =
{ 0x1CB9166D, 0xAE96, 0x4B1D, { 0xA0, 0xF9, 0x16, 0x6C, 0xF5, 0xFB, 0x9C, 0xB0 } };

BEGIN_INTERFACE_MAP(CSKR_CAGE_CMD, CDialogEx)
	INTERFACE_PART(CSKR_CAGE_CMD, IID_ISKR_CAGE_CMD, Dispatch)
END_INTERFACE_MAP()


// CSKR_CAGE_CMD 메시지 처리기입니다.


BOOL CSKR_CAGE_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 8;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


BOOL CSKR_CAGE_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bSKR_CAGE_CMD = FALSE;

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


void CSKR_CAGE_CMD::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_CAGE_CMD = FALSE;

    CDialogEx::OnOK();
}


HBRUSH CSKR_CAGE_CMD::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CSKR_CAGE_CMD::OnSkrCageCmd(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_CAGE == FALSE)
    {
        ResetAll();
    }
    else
    {
        if (((CFCU_SWDlg*)GetParent())->m_uSKR_CAGE_CMD.SKR_CAGE_CMD.SKR_CAGE_RSLT == 0)
            m_strSKR_CAGE_CMD_RSLT.Format(_T("GOOD"));
        else
            m_strSKR_CAGE_CMD_RSLT.Format(_T("FAULT"));

        UpdateData(FALSE);
    }
    return 0;
}


void CSKR_CAGE_CMD::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_strSKR_CAGE_CMD_RSLT.Format(_T("-"));

    UpdateData(FALSE);
}
