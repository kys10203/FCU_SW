// DlgMSL_BIT_06.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgMSL_BIT_06.h"
#include "afxdialogex.h"


// CDlgMSL_BIT_06 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMSL_BIT_06, CDialogEx)

CDlgMSL_BIT_06::CDlgMSL_BIT_06(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMSL_BIT_06::IDD, pParent)
    , m_str5VDC_P(_T(""))
    , m_str10VDC_N(_T(""))
    , m_str10VDC_P(_T(""))
    , m_str15VDC_N(_T(""))
    , m_str15VDC_P(_T(""))
    , m_str30VDC_P(_T(""))
    , m_strCAN(_T(""))
    , m_strADC(_T(""))
    , m_strFLASH(_T(""))
    , m_strDSP(_T(""))
{

}

CDlgMSL_BIT_06::~CDlgMSL_BIT_06()
{
}

void CDlgMSL_BIT_06::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_str5VDC_P);
    DDX_Text(pDX, IDC_EDIT2, m_str10VDC_N);
    DDX_Text(pDX, IDC_EDIT3, m_str10VDC_P);
    DDX_Text(pDX, IDC_EDIT4, m_str15VDC_N);
    DDX_Text(pDX, IDC_EDIT5, m_str15VDC_P);
    DDX_Text(pDX, IDC_EDIT6, m_str30VDC_P);
    DDX_Text(pDX, IDC_EDIT7, m_strCAN);
    DDX_Text(pDX, IDC_EDIT8, m_strADC);
    DDX_Text(pDX, IDC_EDIT9, m_strFLASH);
    DDX_Text(pDX, IDC_EDIT10, m_strDSP);
}


BEGIN_MESSAGE_MAP(CDlgMSL_BIT_06, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgMSL_BIT_06 메시지 처리기입니다.


HBRUSH CDlgMSL_BIT_06::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgMSL_BIT_06::OnInitDialog()
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

    SetBackgroundColor(RGB(50, 50, 50));

    return TRUE;  // return TRUE unless you set the focus to a control
}
