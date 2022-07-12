// DlgMSL_BIT_04.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgMSL_BIT_04.h"
#include "afxdialogex.h"


// CDlgMSL_BIT_04 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMSL_BIT_04, CDialogEx)

CDlgMSL_BIT_04::CDlgMSL_BIT_04(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMSL_BIT_04::IDD, pParent)
    , m_strEOH_COOL(_T(""))
    , m_strIPB_POWER(_T(""))
    , m_strNUC_PERIPHRAL(_T(""))
    , m_strIPF_PERIPHERAL(_T(""))
    , m_strIPC_PERIPHERAL(_T(""))
    , m_strSKR_BIT_DON(_T(""))
{

}

CDlgMSL_BIT_04::~CDlgMSL_BIT_04()
{
}

void CDlgMSL_BIT_04::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_strEOH_COOL);
    DDX_Text(pDX, IDC_EDIT2, m_strIPB_POWER);
    DDX_Text(pDX, IDC_EDIT3, m_strNUC_PERIPHRAL);
    DDX_Text(pDX, IDC_EDIT4, m_strIPF_PERIPHERAL);
    DDX_Text(pDX, IDC_EDIT5, m_strIPC_PERIPHERAL);
    DDX_Text(pDX, IDC_EDIT6, m_strSKR_BIT_DON);
}


BEGIN_MESSAGE_MAP(CDlgMSL_BIT_04, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgMSL_BIT_04 메시지 처리기입니다.


HBRUSH CDlgMSL_BIT_04::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgMSL_BIT_04::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    
    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 4;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT2))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT3))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT4))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT5))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT6))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    return TRUE;  // return TRUE unless you set the focus to a control
}
