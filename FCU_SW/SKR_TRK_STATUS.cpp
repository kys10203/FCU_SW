// SKR_TRK_STATUS.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_TRK_STATUS.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_TRK_STATUS 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSKR_TRK_STATUS, CDialogEx)

CSKR_TRK_STATUS::CSKR_TRK_STATUS(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSKR_TRK_STATUS::IDD, pParent)
    , m_strLOCK_ON_RSLT(_T(""))
    , m_strYAW_RPOS_P(_T(""))
    , m_strPITCH_RPOS_P(_T(""))
    , m_strOG_SX_STS(_T(""))
    , m_strOG_SY_STS(_T(""))
    , m_strOG_EX_STS(_T(""))
    , m_strOG_EY_STS(_T(""))
    , m_strSKR_RDY(_T(""))
    , m_strFPA_TEMP(_T(""))
    , m_strSKR_TEMP(_T(""))
{

	EnableAutomation();

}

CSKR_TRK_STATUS::~CSKR_TRK_STATUS()
{
}

void CSKR_TRK_STATUS::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CSKR_TRK_STATUS::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strLOCK_ON_RSLT);
    DDX_Text(pDX, IDC_EDIT2, m_strYAW_RPOS_P);
    DDX_Text(pDX, IDC_EDIT3, m_strPITCH_RPOS_P);
    DDX_Text(pDX, IDC_EDIT4, m_strOG_SX_STS);
    DDX_Text(pDX, IDC_EDIT5, m_strOG_SY_STS);
    DDX_Text(pDX, IDC_EDIT6, m_strOG_EX_STS);
    DDX_Text(pDX, IDC_EDIT7, m_strOG_EY_STS);
    DDX_Text(pDX, IDC_EDIT8, m_strSKR_RDY);
    DDX_Text(pDX, IDC_EDIT9, m_strFPA_TEMP);
    DDX_Text(pDX, IDC_EDIT10, m_strSKR_TEMP);
}


BEGIN_MESSAGE_MAP(CSKR_TRK_STATUS, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CSKR_TRK_STATUS::OnBnClickedBtnCancel)
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_SKR_TRK_STATUS, &CSKR_TRK_STATUS::OnSkrTrkStatus)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSKR_TRK_STATUS, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISKR_TRK_STATUS에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {873BDC63-8783-4F63-AF3D-715FDEA9E30A}
static const IID IID_ISKR_TRK_STATUS =
{ 0x873BDC63, 0x8783, 0x4F63, { 0xAF, 0x3D, 0x71, 0x5F, 0xDE, 0xA9, 0xE3, 0xA } };

BEGIN_INTERFACE_MAP(CSKR_TRK_STATUS, CDialogEx)
	INTERFACE_PART(CSKR_TRK_STATUS, IID_ISKR_TRK_STATUS, Dispatch)
END_INTERFACE_MAP()


// CSKR_TRK_STATUS 메시지 처리기입니다.


BOOL CSKR_TRK_STATUS::OnInitDialog()
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
    ((CEdit *)GetDlgItem(IDC_EDIT6))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT7))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT8))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT9))->SetRect(rect);
    ((CEdit *)GetDlgItem(IDC_EDIT10))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control
}


void CSKR_TRK_STATUS::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_TRK_STATUS = FALSE;

    CDialogEx::OnOK();
}


BOOL CSKR_TRK_STATUS::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bSKR_TRK_STATUS = FALSE;

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


HBRUSH CSKR_TRK_STATUS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CSKR_TRK_STATUS::OnSkrTrkStatus(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_TRK == FALSE)
    {
        ResetAll();
    }
    else
    {
        INT16 s16YAW_RPOS_P = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[3];
        INT16 s16PITCH_RPOS_P = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[4];
        INT16 s16OG_SX_STS = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[5];
        INT16 s16OG_SY_STS = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[6];
        INT16 s16OG_EX_STS = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[7];
        INT16 s16OG_EY_STS = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[8];
        INT16 s16FPA_TEMP = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[10];
        INT16 s16SKR_TEMP = ((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.wSKR_TRK_STATUS[11];

        // ((CFCU_SWDlg*)GetParent())->m_pRecvView->AddEventString(((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT, TYPE_WORD);

        if (((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.SKR_TRK_STATUS.LOCK_ON_RSLT.LOCK_ON_RSLT == 0)
            m_strLOCK_ON_RSLT.Format(_T("GOOD"));
        else
            m_strLOCK_ON_RSLT.Format(_T("FAULT"));


        m_strYAW_RPOS_P.Format(_T("%d Pixel"), s16YAW_RPOS_P);
        m_strPITCH_RPOS_P.Format(_T("%d Pixel"), s16PITCH_RPOS_P);

        m_strOG_SX_STS.Format(_T("%d Pixel"), s16OG_SX_STS / 100);
        m_strOG_SY_STS.Format(_T("%d Pixel"), s16OG_SY_STS / 100);
        m_strOG_EX_STS.Format(_T("%d Pixel"), s16OG_EX_STS / 100);
        m_strOG_EY_STS.Format(_T("%d Pixel"), s16OG_EY_STS / 100);

        if (((CFCU_SWDlg*)GetParent())->m_uSKR_TRK_STATUS.SKR_TRK_STATUS.SKR_RDY.SKR_RDY_RSLT == 0)
            m_strSKR_RDY.Format(_T("GOOD"));
        else
            m_strSKR_RDY.Format(_T("FAULT"));

        m_strFPA_TEMP.Format(_T("%.2lf K"), (double)s16FPA_TEMP / (double)100);
        m_strSKR_TEMP.Format(_T("%.2lf ℃"), (double)s16SKR_TEMP / (double)100);

        UpdateData(FALSE);
    }

        return 0;
}


double CSKR_TRK_STATUS::Convert2Double(WORD input, UINT16 LSB, INT16 signBit)
{
    double dRet = 0;

    switch(LSB)
    {
    case LSB_1:
        dRet = (double)input * (double)32767 / (double)32767;
        break;
    case LSB_100:
        dRet = (double)input * (double)327.67 / (double)32767;
        break;
    default :
        dRet = 0;

    }
    if(signBit)
        dRet = dRet * (-1);

    return dRet;
}


void CSKR_TRK_STATUS::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
        m_strLOCK_ON_RSLT.Format(_T("-"));


    m_strYAW_RPOS_P.Format(_T("-"));
    m_strPITCH_RPOS_P.Format(_T("-"));

    m_strOG_SX_STS.Format(_T("-"));
    m_strOG_SY_STS.Format(_T("-"));
    m_strOG_EX_STS.Format(_T("-"));
    m_strOG_EY_STS.Format(_T("-"));

        m_strSKR_RDY.Format(_T("-"));

    m_strFPA_TEMP.Format(_T("-"));
    m_strSKR_TEMP.Format(_T("-"));

    UpdateData(FALSE);
}
