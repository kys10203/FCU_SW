// SKR_PLC_CHK.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_PLC_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_PLC_CHK 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSKR_PLC_CHK, CDialogEx)

CSKR_PLC_CHK::CSKR_PLC_CHK(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSKR_PLC_CHK::IDD, pParent)
    , m_strPLC_BIT_RSLT(_T(""))
    , m_strPLC_NUM_RSLT(_T(""))
    , m_strSKR_RDY(_T(""))
    , m_strFPA_TEMP(_T(""))
    , m_strSKR_TEMP(_T(""))
{

	EnableAutomation();

}

CSKR_PLC_CHK::~CSKR_PLC_CHK()
{
}

void CSKR_PLC_CHK::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CSKR_PLC_CHK::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strPLC_BIT_RSLT);
    DDX_Text(pDX, IDC_EDIT2, m_strPLC_NUM_RSLT);
    DDX_Text(pDX, IDC_EDIT3, m_strSKR_RDY);
    DDX_Text(pDX, IDC_EDIT4, m_strFPA_TEMP);
    DDX_Text(pDX, IDC_EDIT5, m_strSKR_TEMP);
}


BEGIN_MESSAGE_MAP(CSKR_PLC_CHK, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CSKR_PLC_CHK::OnBnClickedBtnCancel)
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_SKR_PLC_CHK, &CSKR_PLC_CHK::OnSkrPlcChk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSKR_PLC_CHK, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISKR_PLC_CHK에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {E9B16C71-49A4-4037-8B7C-26B9CD9A2748}
static const IID IID_ISKR_PLC_CHK =
{ 0xE9B16C71, 0x49A4, 0x4037, { 0x8B, 0x7C, 0x26, 0xB9, 0xCD, 0x9A, 0x27, 0x48 } };

BEGIN_INTERFACE_MAP(CSKR_PLC_CHK, CDialogEx)
	INTERFACE_PART(CSKR_PLC_CHK, IID_ISKR_PLC_CHK, Dispatch)
END_INTERFACE_MAP()


// CSKR_PLC_CHK 메시지 처리기입니다.


BOOL CSKR_PLC_CHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 8;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT2))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT3))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT4))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT5))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CSKR_PLC_CHK::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_PLC_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CSKR_PLC_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bSKR_PLC_CHK = FALSE;

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


HBRUSH CSKR_PLC_CHK::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CSKR_PLC_CHK::OnSkrPlcChk(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_PLC == FALSE)
    {
        ResetAll();
    }
    else
    {
        m_strPLC_BIT_RSLT.Format(_T("%04x h"), ((CFCU_SWDlg*)GetParent())->m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_BIT_RSLT.PLC_BIT_RSLT);
        m_strPLC_NUM_RSLT.Format(_T("%.4lf"), (double)((CFCU_SWDlg*)GetParent())->m_uSKR_PLC_CHK.SKR_PLC_CHK.PLC_NUM_RSLT / (double)10000);
        m_strSKR_RDY.Format(_T("%04x h"), ((CFCU_SWDlg*)GetParent())->m_uSKR_PLC_CHK.SKR_PLC_CHK.SKR_RDY.SKR_RDY_RSLT);
        m_strFPA_TEMP.Format(_T("%.2lf K"), (double)((CFCU_SWDlg*)GetParent())->m_uSKR_PLC_CHK.SKR_PLC_CHK.FPA_TEMP / (double)100);
        m_strSKR_TEMP.Format(_T("%.2lf ℃"), (double)((CFCU_SWDlg*)GetParent())->m_uSKR_PLC_CHK.SKR_PLC_CHK.SKR_TEMP.SKR_TEMP / (double)100);

        UpdateData(FALSE);
    }

    return 0;
}


double CSKR_PLC_CHK::Convert2Double(WORD input, INT16 signBit)
{
    double dRet = 0;

        dRet = (double)input * (double)327.67 / (double)32767;

    if(signBit)
        dRet = dRet * (-1);

    return dRet;
}


void CSKR_PLC_CHK::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_strPLC_BIT_RSLT.Format(_T("-"));
    m_strPLC_NUM_RSLT.Format(_T("-"));
    m_strSKR_RDY.Format(_T("-"));
    m_strFPA_TEMP.Format(_T("-"));
    m_strSKR_TEMP.Format(_T("-"));

    UpdateData(FALSE);
}
