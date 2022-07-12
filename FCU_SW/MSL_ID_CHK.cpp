// MSL_ID_CHK.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "MSL_ID_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CMSL_ID_CHK ��ȭ �����Դϴ�.

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


// CMSL_ID_CHK �޽��� ó�����Դϴ�.


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
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CFCU_SWDlg *)GetParent())->m_bMSL_ID_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CMSL_ID_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC Ű �̺�Ʈ�� ���� ó�� �߰�
            ((CFCU_SWDlg *)GetParent())->m_bMSL_ID_CHK = FALSE;

            CDialogEx::OnOK();

            return TRUE;
        }
        else if (pMsg->wParam == VK_RETURN)
        {
            // Enter Ű �̺�Ʈ�� ���� ó�� �߰�
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
    // TODO: ���⿡ ���� �ڵ� �߰�.
    m_strMSL_ID.Format(_T("-"));

    UpdateData(FALSE);
}
