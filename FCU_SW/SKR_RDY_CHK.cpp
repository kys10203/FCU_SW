// SKR_RDY_CHK.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_RDY_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_RDY_CHK 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSKR_RDY_CHK, CDialogEx)

CSKR_RDY_CHK::CSKR_RDY_CHK(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSKR_RDY_CHK::IDD, pParent)
    , m_strSKR_RDY(_T(""))
    , m_strFPA_TEMP(_T(""))
    , m_strSKR_TEMP(_T(""))
    , m_strMAX_SKR_RDY_TIME(_T(""))
{

	EnableAutomation();

}

CSKR_RDY_CHK::~CSKR_RDY_CHK()
{
}

void CSKR_RDY_CHK::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CSKR_RDY_CHK::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strSKR_RDY);
    DDX_Text(pDX, IDC_EDIT2, m_strFPA_TEMP);
    DDX_Text(pDX, IDC_EDIT3, m_strSKR_TEMP);
    DDX_Text(pDX, IDC_EDIT4, m_strMAX_SKR_RDY_TIME);
}


BEGIN_MESSAGE_MAP(CSKR_RDY_CHK, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CSKR_RDY_CHK::OnBnClickedBtnCancel)
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_SKR_RDY_CHK, &CSKR_RDY_CHK::OnSkrRdyChk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSKR_RDY_CHK, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISKR_RDY_CHK에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {F8192AB6-265B-428C-A798-6B1215CFFD06}
static const IID IID_ISKR_RDY_CHK =
{ 0xF8192AB6, 0x265B, 0x428C, { 0xA7, 0x98, 0x6B, 0x12, 0x15, 0xCF, 0xFD, 0x6 } };

BEGIN_INTERFACE_MAP(CSKR_RDY_CHK, CDialogEx)
	INTERFACE_PART(CSKR_RDY_CHK, IID_ISKR_RDY_CHK, Dispatch)
END_INTERFACE_MAP()


// CSKR_RDY_CHK 메시지 처리기입니다.


BOOL CSKR_RDY_CHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 8;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT2))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT3))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT4))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CSKR_RDY_CHK::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_RDY_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CSKR_RDY_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bSKR_RDY_CHK = FALSE;

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


HBRUSH CSKR_RDY_CHK::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CSKR_RDY_CHK::OnSkrRdyChk(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_RDY == FALSE)
    {
        ResetAll();
    }
    else
    {
        m_strSKR_RDY.Format(_T("%04x h"), ((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.SKR_RDY);
        m_strFPA_TEMP.Format(_T("%.2lf K"), (double)((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.FPA_TEMP / (double)100);
        m_strSKR_TEMP.Format(_T("%.2lf ℃"), Convert2Double(((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.SKR_TEMP.SKR_TEMP, ((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.SKR_TEMP.SignBIT));
        m_strMAX_SKR_RDY_TIME.Format(_T("%d sec"), ((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.MAX_SKR_RDY_TIME);

        UpdateData(FALSE);
    }
    return 0;
}


double CSKR_RDY_CHK::Convert2Double(WORD input, INT16 signBit)
{
    double dRet = 0;

        dRet = (double)input * (double)327.67 / (double)32767;

    if(signBit)
        dRet = dRet * (-1);

    return dRet;
}


void CSKR_RDY_CHK::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_strSKR_RDY.Format(_T("-"));
    m_strFPA_TEMP.Format(_T("-"));
    m_strSKR_TEMP.Format(_T("-"));
    m_strMAX_SKR_RDY_TIME.Format(_T("-"));

    UpdateData(FALSE);
}
