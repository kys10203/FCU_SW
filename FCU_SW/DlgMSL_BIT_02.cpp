// DlgMSL_BIT_02.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgMSL_BIT_02.h"
#include "afxdialogex.h"


// CDlgMSL_BIT_02 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMSL_BIT_02, CDialogEx)

CDlgMSL_BIT_02::CDlgMSL_BIT_02(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMSL_BIT_02::IDD, pParent)
    , m_strCAN_ACT(_T(""))
    , m_strUART_OLU(_T(""))
{

}

CDlgMSL_BIT_02::~CDlgMSL_BIT_02()
{
}

void CDlgMSL_BIT_02::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_strCAN_ACT);
    DDX_Text(pDX, IDC_EDIT2, m_strUART_OLU);
}


BEGIN_MESSAGE_MAP(CDlgMSL_BIT_02, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgMSL_BIT_02 메시지 처리기입니다.


HBRUSH CDlgMSL_BIT_02::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgMSL_BIT_02::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 4;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT2))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    return TRUE;  // return TRUE unless you set the focus to a control
}
