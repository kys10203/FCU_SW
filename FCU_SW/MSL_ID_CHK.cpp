// MSL_ID_CHK.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "MSL_ID_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CMSL_ID_CHK 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMSL_ID_CHK, CDialogEx)

    CMSL_ID_CHK::CMSL_ID_CHK(CWnd* pParent /*=NULL*/)
    : CDialogEx(CMSL_ID_CHK::IDD, pParent)
    , m_strMSL_ID(_T(""))
{

}

CMSL_ID_CHK::~CMSL_ID_CHK()
{
}

void CMSL_ID_CHK::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strMSL_ID);
}


BEGIN_MESSAGE_MAP(CMSL_ID_CHK, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CMSL_ID_CHK::OnBnClickedBtnCancel)
    ON_WM_DESTROY()
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_MSL_ID_CHK, &CMSL_ID_CHK::OnMslIdChk)
END_MESSAGE_MAP()


// CMSL_ID_CHK 메시지 처리기입니다.


BOOL CMSL_ID_CHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 8;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    SetWindowTheme(GetDlgItem(IDD_MSL_BIT_CHK)->GetSafeHwnd(), L"", L"");

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CMSL_ID_CHK::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bMSL_ID_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CMSL_ID_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bMSL_ID_CHK = FALSE;

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


HBRUSH CMSL_ID_CHK::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CMSL_ID_CHK::OnMslIdChk(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_ID == FALSE)
    {
        ResetAll();
    }
    else
    {
        m_strMSL_ID.Format(_T("%04x h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_ID_CHK.MSL_ID_CHK.MSL_ID);

        UpdateData(FALSE);
    }

    return 0;
}


void CMSL_ID_CHK::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_strMSL_ID.Format(_T("-"));

    UpdateData(FALSE);
}
