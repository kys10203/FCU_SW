// DlgMSL_BIT_05.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgMSL_BIT_05.h"
#include "afxdialogex.h"


// CDlgMSL_BIT_05 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMSL_BIT_05, CDialogEx)

CDlgMSL_BIT_05::CDlgMSL_BIT_05(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMSL_BIT_05::IDD, pParent)
    , m_strIPC_BIT0(_T(""))
    , m_strIPC_BIT1(_T(""))
    , m_strIPC_BIT2(_T(""))
    , m_strIPC_BIT4(_T(""))
    , m_strIPC_BIT5(_T(""))
    , m_strIPC_BIT6(_T(""))
    , m_strIPC_BIT7(_T(""))
    , m_strIPF_BIT0(_T(""))
    , m_strIPF_BIT1(_T(""))
    , m_strNUC_BIT0(_T(""))
    , m_strNUC_BIT1(_T(""))
{

}

CDlgMSL_BIT_05::~CDlgMSL_BIT_05()
{
}

void CDlgMSL_BIT_05::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_strIPC_BIT0);
    DDX_Text(pDX, IDC_EDIT2, m_strIPC_BIT1);
    DDX_Text(pDX, IDC_EDIT3, m_strIPC_BIT2);
    DDX_Text(pDX, IDC_EDIT4, m_strIPC_BIT4);
    DDX_Text(pDX, IDC_EDIT5, m_strIPC_BIT5);
    DDX_Text(pDX, IDC_EDIT6, m_strIPC_BIT6);
    DDX_Text(pDX, IDC_EDIT7, m_strIPC_BIT7);
    DDX_Text(pDX, IDC_EDIT8, m_strIPF_BIT0);
    DDX_Text(pDX, IDC_EDIT9, m_strIPF_BIT1);
    DDX_Text(pDX, IDC_EDIT10, m_strNUC_BIT0);
    DDX_Text(pDX, IDC_EDIT11, m_strNUC_BIT1);
}


BEGIN_MESSAGE_MAP(CDlgMSL_BIT_05, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgMSL_BIT_05 메시지 처리기입니다.


HBRUSH CDlgMSL_BIT_05::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgMSL_BIT_05::OnInitDialog()
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
    ((CEdit *)GetDlgItem(IDC_EDIT7))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT8))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT9))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT10))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT11))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    return TRUE;  // return TRUE unless you set the focus to a control
}
