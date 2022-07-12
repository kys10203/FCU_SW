// MSL_STS_CHK.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "MSL_STS_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CMSL_STS_CHK 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMSL_STS_CHK, CDialogEx)

CMSL_STS_CHK::CMSL_STS_CHK(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMSL_STS_CHK::IDD, pParent)
    , m_pwndShow(NULL)
{

	EnableAutomation();

}

CMSL_STS_CHK::~CMSL_STS_CHK()
{
}

void CMSL_STS_CHK::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CMSL_STS_CHK::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);
}


BEGIN_MESSAGE_MAP(CMSL_STS_CHK, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CMSL_STS_CHK::OnBnClickedBtnCancel)
    ON_MESSAGE(WM_MSL_STS_CHK, &CMSL_STS_CHK::OnMslStsChk)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CMSL_STS_CHK::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMSL_STS_CHK, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IMSL_STS_CHK에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {655B3638-80B2-4C05-A7FC-8A6C2FB71485}
static const IID IID_IMSL_STS_CHK =
{ 0x655B3638, 0x80B2, 0x4C05, { 0xA7, 0xFC, 0x8A, 0x6C, 0x2F, 0xB7, 0x14, 0x85 } };

BEGIN_INTERFACE_MAP(CMSL_STS_CHK, CDialogEx)
	INTERFACE_PART(CMSL_STS_CHK, IID_IMSL_STS_CHK, Dispatch)
END_INTERFACE_MAP()


// CMSL_STS_CHK 메시지 처리기입니다.


BOOL CMSL_STS_CHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    CRect rect;
    m_tabMain.InsertItem(0, _T("MSL STS"));
    m_tabMain.InsertItem(1, _T("통신 상태"));
    m_tabMain.InsertItem(2, _T("GCU"));
    m_tabMain.InsertItem(3, _T("탐색기"));
    m_tabMain.InsertItem(4, _T("구동장치"));
    m_tabMain.InsertItem(5, _T("유도탄 상태"));

    m_tabMain.SetCurSel(0);
    m_tabMain.GetClientRect(&rect);

    m_tDlgMSL_STS_01.Create(IDD_MSL_STS_01, &m_tabMain);
    m_tDlgMSL_STS_01.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
    m_tDlgMSL_BIT_02.Create(IDD_MSL_BIT_02, &m_tabMain);
    m_tDlgMSL_BIT_02.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);
    m_tDlgMSL_STS_02.Create(IDD_MSL_STS_02, &m_tabMain);
    m_tDlgMSL_STS_02.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);
    m_tDlgMSL_STS_03.Create(IDD_MSL_STS_03, &m_tabMain);
    m_tDlgMSL_STS_03.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);
    m_tDlgMSL_BIT_06.Create(IDD_MSL_BIT_06, &m_tabMain);
    m_tDlgMSL_BIT_06.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);
    m_tDlgMSL_BIT_07.Create(IDD_MSL_BIT_07, &m_tabMain);
    m_tDlgMSL_BIT_07.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);

    m_pwndShow = &this->m_tDlgMSL_STS_01;

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CMSL_STS_CHK::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bMSL_STS_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CMSL_STS_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bMSL_STS_CHK = FALSE;

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


afx_msg LRESULT CMSL_STS_CHK::OnMslStsChk(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_STS == FALSE)
    {
        ResetAll();
    }
    else
    {
        /* MSL STS(MSL_STS_01) */
        INT16 s16MBAT = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[5];
        INT16 s1630VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[6];
        INT16 s1615VDC_p = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[7];
        INT16 s1615VDC_n = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[8];
        INT16 s165VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[9];
        INT16 s163_3VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[10];
        INT16 s161_2VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.wMSL_STS_CHK[11];

        m_tDlgMSL_STS_01.m_strMSL_STS1.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS1);
        m_tDlgMSL_STS_01.m_strMSL_STS2.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2);
        m_tDlgMSL_STS_01.m_strGCU_STS.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS);
        m_tDlgMSL_STS_01.m_strMBAT.Format(_T("%.3lf"), (double)s16MBAT * (double)40 / (double)32767);
        m_tDlgMSL_STS_01.m_str30VDC.Format(_T("%.3lf"), (double)s1630VDC * (double)40 / (double)32767);
        m_tDlgMSL_STS_01.m_str15VDC.Format(_T("%.3lf"), (double)s1615VDC_p * (double)20 / (double)32767);
        m_tDlgMSL_STS_01.m_str15VDC_negative.Format(_T("%.3lf"), (double)s1615VDC_n * (double)20 / (double)32767);
        m_tDlgMSL_STS_01.m_str5VDC.Format(_T("%.3lf"), (double)s165VDC * (double)20 / (double)32767);
        m_tDlgMSL_STS_01.m_str3_3VDC.Format(_T("%.3lf"), (double)s163_3VDC * (double)20 / (double)32767);
        m_tDlgMSL_STS_01.m_str1_2VDC.Format(_T("%.3lf"), (double)s161_2VDC * (double)20 / (double)32767);
        m_tDlgMSL_STS_01.m_strSKR_STS.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS);
        m_tDlgMSL_STS_01.m_strACT_STS.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS);

        m_tDlgMSL_STS_01.UpdateData(FALSE);

        /* 통신 상태(MSL_BIT_02) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.CAN == 0)
            m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.UART == 0)
            m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("FAULT"));

        m_tDlgMSL_BIT_02.UpdateData(FALSE);

        /* GCU 상태(MSL_STS_02) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.ADC == 0)
            m_tDlgMSL_STS_02.m_strGCU_ADC.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_ADC.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.SRAM == 0)
            m_tDlgMSL_STS_02.m_strGCU_SRAM.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_SRAM.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.FLASH == 0)
            m_tDlgMSL_STS_02.m_strGCU_FLASH.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_FLASH.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.SPI == 0)
            m_tDlgMSL_STS_02.m_strGCU_R2GYRO.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_R2GYRO.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.GCU == 0)
            m_tDlgMSL_STS_02.m_strGCU_POW.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_POW.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.GCU_BIT_RESULT == 0)
            m_tDlgMSL_STS_02.m_strGCU_SYS_RDY.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_02.m_strGCU_SYS_RDY.Format(_T("FAULT"));

        m_tDlgMSL_STS_02.UpdateData(FALSE);

        /*  탐색기 상태(MSL_STS_03) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.EOH_ECC == 0)
            m_tDlgMSL_STS_03.m_strEOH_ECC.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strEOH_ECC.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.EOH_COOL == 0)
            m_tDlgMSL_STS_03.m_strEOH_COOL.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strEOH_COOL.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.NUC_CHKECK_SUM == 0)
            m_tDlgMSL_STS_03.m_strNUC_CHECK_SUM.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strNUC_CHECK_SUM.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPF_ECC == 0)
            m_tDlgMSL_STS_03.m_strIPF_ECC.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strIPF_ECC.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPF_CHECK_SUM == 0)
            m_tDlgMSL_STS_03.m_strIPF_CHECK_SUM.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strIPF_CHECK_SUM.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPC_IMAGE_CHECK == 0)
            m_tDlgMSL_STS_03.m_strIPC_IMAGE_CHECK.Format(_T("GOOD"));
        else
            m_tDlgMSL_STS_03.m_strIPC_IMAGE_CHECK.Format(_T("FAULT"));

        m_tDlgMSL_STS_03.UpdateData(FALSE);

        /*  구동장치 상태(MSL_BIT_06) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p5V == 0)
            m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.m10V == 0)
            m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p10V == 0)
            m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.m15V == 0)
            m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p15V == 0)
            m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p30V == 0)
            m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.CAN == 0)
            m_tDlgMSL_BIT_06.m_strCAN.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strCAN.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.ADC == 0)
            m_tDlgMSL_BIT_06.m_strADC.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strADC.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.FLASH == 0)
            m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("FAULT"));
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.DSP == 0)
            m_tDlgMSL_BIT_06.m_strDSP.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strDSP.Format(_T("FAULT"));

        m_tDlgMSL_BIT_06.UpdateData(FALSE);

        /* 유도탄 상태(MSL_BIT_07) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.MSLAWY == 0)
            m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.FUZGOOD == 0)
            m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("FAULT"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.MBAT == 0)
            m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("FAULT"));

        m_tDlgMSL_BIT_07.UpdateData(FALSE);
    }

    return 0;
}


void CMSL_STS_CHK::OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult)
{
    if (IDC_TAB_MAIN == pNMHDR->idFrom)
    {
        UINT32 u32Select = m_tabMain.GetCurSel();

        switch (u32Select)
        {
        case 0:
            m_tDlgMSL_STS_01.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 1:
            m_tDlgMSL_STS_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_SHOW);
            m_tDlgMSL_STS_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 2:
            m_tDlgMSL_STS_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_02.ShowWindow(SW_SHOW);
            m_tDlgMSL_STS_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 3:
            m_tDlgMSL_STS_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_03.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 4:
            m_tDlgMSL_STS_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 5:
            m_tDlgMSL_STS_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_STS_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_SHOW);
            break;
        }
    }

    *pResult = 0;
}


void CMSL_STS_CHK::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_tDlgMSL_STS_01.m_strMSL_STS1.Format(_T("-"));
    m_tDlgMSL_STS_01.m_strMSL_STS2.Format(_T("-"));
    m_tDlgMSL_STS_01.m_strGCU_STS.Format(_T("-"));
    m_tDlgMSL_STS_01.m_strMBAT.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str30VDC.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str15VDC.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str15VDC_negative.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str5VDC.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str3_3VDC.Format(_T("-"));
    m_tDlgMSL_STS_01.m_str1_2VDC.Format(_T("-"));
    m_tDlgMSL_STS_01.m_strSKR_STS.Format(_T("-"));
    m_tDlgMSL_STS_01.m_strACT_STS.Format(_T("-"));

    m_tDlgMSL_STS_01.UpdateData(FALSE);

    /* 통신 상태(MSL_BIT_02) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.CAN == 0)
        m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("-"));
    else
        m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.UART == 0)
        m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("-"));
    else
        m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("-"));

    m_tDlgMSL_BIT_02.UpdateData(FALSE);

    /* GCU 상태(MSL_STS_02) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.ADC == 0)
        m_tDlgMSL_STS_02.m_strGCU_ADC.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_ADC.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.SRAM == 0)
        m_tDlgMSL_STS_02.m_strGCU_SRAM.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_SRAM.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.FLASH == 0)
        m_tDlgMSL_STS_02.m_strGCU_FLASH.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_FLASH.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.SPI == 0)
        m_tDlgMSL_STS_02.m_strGCU_R2GYRO.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_R2GYRO.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.GCU == 0)
        m_tDlgMSL_STS_02.m_strGCU_POW.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_POW.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.GCU_STS.GCU_BIT_RESULT == 0)
        m_tDlgMSL_STS_02.m_strGCU_SYS_RDY.Format(_T("-"));
    else
        m_tDlgMSL_STS_02.m_strGCU_SYS_RDY.Format(_T("-"));

    m_tDlgMSL_STS_02.UpdateData(FALSE);

    /*  탐색기 상태(MSL_STS_03) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.EOH_ECC == 0)
        m_tDlgMSL_STS_03.m_strEOH_ECC.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strEOH_ECC.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.EOH_COOL == 0)
        m_tDlgMSL_STS_03.m_strEOH_COOL.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strEOH_COOL.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.NUC_CHKECK_SUM == 0)
        m_tDlgMSL_STS_03.m_strNUC_CHECK_SUM.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strNUC_CHECK_SUM.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPF_ECC == 0)
        m_tDlgMSL_STS_03.m_strIPF_ECC.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strIPF_ECC.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPF_CHECK_SUM == 0)
        m_tDlgMSL_STS_03.m_strIPF_CHECK_SUM.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strIPF_CHECK_SUM.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.SKR_STS.IPC_IMAGE_CHECK == 0)
        m_tDlgMSL_STS_03.m_strIPC_IMAGE_CHECK.Format(_T("-"));
    else
        m_tDlgMSL_STS_03.m_strIPC_IMAGE_CHECK.Format(_T("-"));

    m_tDlgMSL_STS_03.UpdateData(FALSE);

    /*  구동장치 상태(MSL_BIT_06) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p5V == 0)
        m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.m10V == 0)
        m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p10V == 0)
        m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.m15V == 0)
        m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p15V == 0)
        m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.p30V == 0)
        m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.CAN == 0)
        m_tDlgMSL_BIT_06.m_strCAN.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strCAN.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.ADC == 0)
        m_tDlgMSL_BIT_06.m_strADC.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strADC.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.FLASH == 0)
        m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("-"));
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.ACT_STS.DSP == 0)
        m_tDlgMSL_BIT_06.m_strDSP.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strDSP.Format(_T("-"));

    m_tDlgMSL_BIT_06.UpdateData(FALSE);

    /* 유도탄 상태(MSL_BIT_07) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.MSLAWY == 0)
        m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.FUZGOOD == 0)
        m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_STS_CHK.MSL_STS_CHK.MSL_STS2.MBAT == 0)
        m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("-"));

    m_tDlgMSL_BIT_07.UpdateData(FALSE);
}
