// DlgMSL_BIT_03.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgMSL_BIT_03.h"
#include "afxdialogex.h"


// CDlgMSL_BIT_03 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMSL_BIT_03, CDialogEx)

CDlgMSL_BIT_03::CDlgMSL_BIT_03(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMSL_BIT_03::IDD, pParent)
    , m_strGCU_ADC(_T(""))
    , m_strGCU_SRAM(_T(""))
    , m_strGCU_FLASH(_T(""))
    , m_strGCU_R2GYRO(_T(""))
    , m_strGCU_POW(_T(""))
    , m_strGCU_FPGA(_T(""))
{

}

CDlgMSL_BIT_03::~CDlgMSL_BIT_03()
{
}

void CDlgMSL_BIT_03::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_strGCU_ADC);
    DDX_Text(pDX, IDC_EDIT2, m_strGCU_SRAM);
    DDX_Text(pDX, IDC_EDIT3, m_strGCU_FLASH);
    DDX_Text(pDX, IDC_EDIT4, m_strGCU_R2GYRO);
    DDX_Text(pDX, IDC_EDIT5, m_strGCU_POW);
    DDX_Text(pDX, IDC_EDIT6, m_strGCU_FPGA);
}


BEGIN_MESSAGE_MAP(CDlgMSL_BIT_03, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgMSL_BIT_03 메시지 처리기입니다.


HBRUSH CDlgMSL_BIT_03::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgMSL_BIT_03::OnInitDialog()
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
