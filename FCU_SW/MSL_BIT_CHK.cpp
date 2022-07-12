// MSL_BIT_CHK.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "MSL_BIT_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CMSL_BIT_CHK 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMSL_BIT_CHK, CDialogEx)

    CMSL_BIT_CHK::CMSL_BIT_CHK(CWnd* pParent /*=NULL*/)
    : CDialogEx(CMSL_BIT_CHK::IDD, pParent)
    , m_pwndShow(NULL)
    , a(0)
{

    EnableAutomation();

}

CMSL_BIT_CHK::~CMSL_BIT_CHK()
{
}

void CMSL_BIT_CHK::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CMSL_BIT_CHK::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);
}


BEGIN_MESSAGE_MAP(CMSL_BIT_CHK, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CMSL_BIT_CHK::OnBnClickedBtnCancel)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CMSL_BIT_CHK::OnSelchangeTabMain)
    ON_MESSAGE(WM_MSL_BIT_CHK, &CMSL_BIT_CHK::OnMslBitChk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMSL_BIT_CHK, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IMSL_BIT_CHK에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {A9AB739A-5E47-4B16-BB72-67EC59AD0F53}
static const IID IID_IMSL_BIT_CHK =
{ 0xA9AB739A, 0x5E47, 0x4B16, { 0xBB, 0x72, 0x67, 0xEC, 0x59, 0xAD, 0xF, 0x53 } };

BEGIN_INTERFACE_MAP(CMSL_BIT_CHK, CDialogEx)
    INTERFACE_PART(CMSL_BIT_CHK, IID_IMSL_BIT_CHK, Dispatch)
END_INTERFACE_MAP()


// CMSL_BIT_CHK 메시지 처리기입니다.


BOOL CMSL_BIT_CHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(10, 10, 10));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    CRect rect;
    m_tabMain.InsertItem(0, _T("MSL BIT"));
    m_tabMain.InsertItem(1, _T("통신 상태"));
    m_tabMain.InsertItem(2, _T("GCU"));
    m_tabMain.InsertItem(3, _T("탐색기 1"));
    m_tabMain.InsertItem(4, _T("탐색기 2"));
    m_tabMain.InsertItem(5, _T("구동장치"));
    m_tabMain.InsertItem(6, _T("유도탄 상태"));

    m_tabMain.SetCurSel(0);
    m_tabMain.GetClientRect(&rect);

    m_tDlgMSL_BIT_01.Create(IDD_MSL_BIT_01, &m_tabMain);
    m_tDlgMSL_BIT_01.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
    m_tDlgMSL_BIT_02.Create(IDD_MSL_BIT_02, &m_tabMain);
    m_tDlgMSL_BIT_02.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);
    m_tDlgMSL_BIT_03.Create(IDD_MSL_BIT_03, &m_tabMain);
    m_tDlgMSL_BIT_03.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);
    m_tDlgMSL_BIT_04.Create(IDD_MSL_BIT_04, &m_tabMain);
    m_tDlgMSL_BIT_04.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);
    m_tDlgMSL_BIT_05.Create(IDD_MSL_BIT_05, &m_tabMain);
    m_tDlgMSL_BIT_05.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);
    m_tDlgMSL_BIT_06.Create(IDD_MSL_BIT_06, &m_tabMain);
    m_tDlgMSL_BIT_06.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);
    m_tDlgMSL_BIT_07.Create(IDD_MSL_BIT_07, &m_tabMain);
    m_tDlgMSL_BIT_07.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30,  SWP_NOZORDER);

    m_pwndShow = &this->m_tDlgMSL_BIT_01;

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CMSL_BIT_CHK::OnBnClickedBtnCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ((CFCU_SWDlg *)GetParent())->m_bMSL_BIT_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CMSL_BIT_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC 키 이벤트에 대한 처리 추가
            ((CFCU_SWDlg *)GetParent())->m_bMSL_BIT_CHK = FALSE;

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


void CMSL_BIT_CHK::OnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    if(IDC_TAB_MAIN == pNMHDR->idFrom)
    {
        UINT32 u32Select = m_tabMain.GetCurSel();

        switch(u32Select)
        {
        case 0:
            m_tDlgMSL_BIT_01.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 1:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 2:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 3:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 4:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 5:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_SHOW);
            m_tDlgMSL_BIT_07.ShowWindow(SW_HIDE);
            break;
        case 6:
            m_tDlgMSL_BIT_01.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_02.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_03.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_04.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_05.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_06.ShowWindow(SW_HIDE);
            m_tDlgMSL_BIT_07.ShowWindow(SW_SHOW);
            break;
        }
    }

    *pResult = 0;
}



afx_msg LRESULT CMSL_BIT_CHK::OnMslBitChk(WPARAM wParam, LPARAM lParam)
{
    UINT32 u32Select = m_tabMain.GetCurSel();

    if (((CFCU_SWDlg*)GetParent())->m_bDisplayMSL_BIT == FALSE)
    {
        ResetAll();
    }
    else
    {
        /* MSL BIT(MSL_BIT_01) */
        INT16 s16MBAT = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[5];
        INT16 s1630VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[6];
        INT16 s1615VDC_p = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[7];
        INT16 s1615VDC_n = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[8];
        INT16 s165VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[9];
        INT16 s163_3VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[10];
        INT16 s161_2VDC = ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.wMSL_BIT_CHK[11];

        m_tDlgMSL_BIT_01.m_strMSL_BIT1.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT1);
        m_tDlgMSL_BIT_01.m_strMSL_BIT2.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2);
        m_tDlgMSL_BIT_01.m_strGCU_BIT.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT);
        m_tDlgMSL_BIT_01.m_strMBAT.Format(_T("%.3lf"), (double)s16MBAT * (double)40 / (double)32767);
        m_tDlgMSL_BIT_01.m_str30VDC.Format(_T("%.3lf"), (double)s1630VDC * (double)40 / (double)32767);
        m_tDlgMSL_BIT_01.m_str15VDC.Format(_T("%.3lf"), (double)s1615VDC_p * (double)20 / (double)32767);
        m_tDlgMSL_BIT_01.m_str15VDC_negative.Format(_T("%.3lf"), (double)s1615VDC_n * (double)20 / (double)32767);
        m_tDlgMSL_BIT_01.m_str5VDC.Format(_T("%.3lf"), (double)s165VDC * (double)20 / (double)32767);
        m_tDlgMSL_BIT_01.m_str3_3VDC.Format(_T("%.3lf"), (double)s163_3VDC * (double)20 / (double)32767);
        m_tDlgMSL_BIT_01.m_str1_2VDC.Format(_T("%.3lf"), (double)s161_2VDC * (double)20 / (double)32767);

        m_tDlgMSL_BIT_01.m_strSKR_BIT1.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1);
        m_tDlgMSL_BIT_01.m_strSKR_BIT2.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2);
        m_tDlgMSL_BIT_01.m_strACT_BIT.Format(_T("%04X h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT);

        m_tDlgMSL_BIT_01.UpdateData(FALSE);

        /* 통신 상태(MSL_BIT_02) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.CAN == 0)
            m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.UART == 0)
            m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("FAIL"));

        m_tDlgMSL_BIT_02.UpdateData(FALSE);

        /* GCU(MSL_BIT_03) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.ADC == 0)
            m_tDlgMSL_BIT_03.m_strGCU_ADC.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_ADC.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.SRAM == 0)
            m_tDlgMSL_BIT_03.m_strGCU_SRAM.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_SRAM.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.FLASH == 0)
            m_tDlgMSL_BIT_03.m_strGCU_FLASH.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_FLASH.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.SPI == 0)
            m_tDlgMSL_BIT_03.m_strGCU_R2GYRO.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_R2GYRO.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.GCU == 0)
            m_tDlgMSL_BIT_03.m_strGCU_POW.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_POW.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.FPGA == 0)
            m_tDlgMSL_BIT_03.m_strGCU_FPGA.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_03.m_strGCU_FPGA.Format(_T("FAIL"));

        m_tDlgMSL_BIT_03.UpdateData(FALSE);

        /* 탐색기1(MSL_BIT_04) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.EOH_COOL == 0)
            m_tDlgMSL_BIT_04.m_strEOH_COOL.Format(_T("ON"));
        else
            m_tDlgMSL_BIT_04.m_strEOH_COOL.Format(_T("OFF"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPB_POWER == 0)
            m_tDlgMSL_BIT_04.m_strIPB_POWER.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_04.m_strIPB_POWER.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.NUC_PERIPHERAL == 0)
            m_tDlgMSL_BIT_04.m_strNUC_PERIPHRAL.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_04.m_strNUC_PERIPHRAL.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPF_PERIPHERAL == 0)
            m_tDlgMSL_BIT_04.m_strIPF_PERIPHERAL.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_04.m_strIPF_PERIPHERAL.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPC_PERIPHERAL == 0)
            m_tDlgMSL_BIT_04.m_strIPC_PERIPHERAL.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_04.m_strIPC_PERIPHERAL.Format(_T("FAIL"));

        m_tDlgMSL_BIT_04.m_strSKR_BIT_DON.Format(_T("%04x h"), ((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.SKR_BIT_DONE);

        m_tDlgMSL_BIT_04.UpdateData(FALSE);

        /* 탐색기2(MSL_BIT_05) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_0 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT0.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT0.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_1 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT1.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT1.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_2 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT2.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT2.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_4 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT4.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT4.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_5 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT5.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT5.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_6 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT6.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT6.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_7 == 0)
            m_tDlgMSL_BIT_05.m_strIPC_BIT7.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPC_BIT7.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPF_BIT_0 == 0)
            m_tDlgMSL_BIT_05.m_strIPF_BIT0.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPF_BIT0.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPF_BIT_1 == 0)
            m_tDlgMSL_BIT_05.m_strIPF_BIT1.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strIPF_BIT1.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.NUC_BIT_0 == 0)
            m_tDlgMSL_BIT_05.m_strNUC_BIT0.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strNUC_BIT0.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.NUC_BIT_1 == 0)
            m_tDlgMSL_BIT_05.m_strNUC_BIT1.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_05.m_strNUC_BIT1.Format(_T("FAIL"));

        m_tDlgMSL_BIT_05.UpdateData(FALSE);

        /* 구동장치(MSL_BIT_06) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p5V == 0)
            m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.m10V == 0)
            m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p10V == 0)
            m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.m15V == 0)
            m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p15V == 0)
            m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p30V == 0)
            m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.CAN == 0)
            m_tDlgMSL_BIT_06.m_strCAN.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strCAN.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.ADC == 0)
            m_tDlgMSL_BIT_06.m_strADC.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strADC.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.FLASH == 0)
            m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.DSP == 0)
            m_tDlgMSL_BIT_06.m_strDSP.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_06.m_strDSP.Format(_T("FAIL"));

        m_tDlgMSL_BIT_06.UpdateData(FALSE);

        /* 유도탄 상태(MSL_BIT_07) */
        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.MSLAWY == 0)
            m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.FUZGOOD == 0)
            m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("FAIL"));

        if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.MBAT == 0)
            m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("GOOD"));
        else
            m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("FAIL"));

        m_tDlgMSL_BIT_07.UpdateData(FALSE);
    }
    return 0;
}


double CMSL_BIT_CHK::Convert2Double(WORD input, UINT16 type, INT16 signBit)
{
    double dRet = 0;
    INT16 w2complement = ((input -1) ^ 0xFFFF);

    switch(type)
    {
    case FS20:
        dRet = (double)w2complement * (double)20 / (double)32767;
        break;
    case FS40:
        dRet = (double)w2complement * (double)40 / (double)32767;
        break;
    default :
        dRet = 0;

    }
    
    dRet = dRet * (-1);

    return dRet;
}


void CMSL_BIT_CHK::ResetAll()
{
    // TODO: 여기에 구현 코드 추가.
    m_tDlgMSL_BIT_01.m_strMSL_BIT1.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_strMSL_BIT2.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_strGCU_BIT.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_strMBAT.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str30VDC.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str15VDC.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str15VDC_negative.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str5VDC.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str3_3VDC.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_str1_2VDC.Format(_T("-"));

    m_tDlgMSL_BIT_01.m_strSKR_BIT1.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_strSKR_BIT2.Format(_T("-"));
    m_tDlgMSL_BIT_01.m_strACT_BIT.Format(_T("-"));

    m_tDlgMSL_BIT_01.UpdateData(FALSE);

    /* 통신 상태(MSL_BIT_02) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.CAN == 0)
        m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("-"));
    else
        m_tDlgMSL_BIT_02.m_strCAN_ACT.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.UART == 0)
        m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("-"));
    else
        m_tDlgMSL_BIT_02.m_strUART_OLU.Format(_T("-"));

    m_tDlgMSL_BIT_02.UpdateData(FALSE);

    /* GCU(MSL_BIT_03) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.ADC == 0)
        m_tDlgMSL_BIT_03.m_strGCU_ADC.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_ADC.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.SRAM == 0)
        m_tDlgMSL_BIT_03.m_strGCU_SRAM.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_SRAM.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.FLASH == 0)
        m_tDlgMSL_BIT_03.m_strGCU_FLASH.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_FLASH.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.SPI == 0)
        m_tDlgMSL_BIT_03.m_strGCU_R2GYRO.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_R2GYRO.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.GCU == 0)
        m_tDlgMSL_BIT_03.m_strGCU_POW.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_POW.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.GCU_BIT.FPGA == 0)
        m_tDlgMSL_BIT_03.m_strGCU_FPGA.Format(_T("-"));
    else
        m_tDlgMSL_BIT_03.m_strGCU_FPGA.Format(_T("-"));

    m_tDlgMSL_BIT_03.UpdateData(FALSE);

    /* 탐색기1(MSL_BIT_04) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.EOH_COOL == 0)
        m_tDlgMSL_BIT_04.m_strEOH_COOL.Format(_T("-"));
    else
        m_tDlgMSL_BIT_04.m_strEOH_COOL.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPB_POWER == 0)
        m_tDlgMSL_BIT_04.m_strIPB_POWER.Format(_T("-"));
    else
        m_tDlgMSL_BIT_04.m_strIPB_POWER.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.NUC_PERIPHERAL == 0)
        m_tDlgMSL_BIT_04.m_strNUC_PERIPHRAL.Format(_T("-"));
    else
        m_tDlgMSL_BIT_04.m_strNUC_PERIPHRAL.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPF_PERIPHERAL == 0)
        m_tDlgMSL_BIT_04.m_strIPF_PERIPHERAL.Format(_T("-"));
    else
        m_tDlgMSL_BIT_04.m_strIPF_PERIPHERAL.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT1.IPC_PERIPHERAL == 0)
        m_tDlgMSL_BIT_04.m_strIPC_PERIPHERAL.Format(_T("-"));
    else
        m_tDlgMSL_BIT_04.m_strIPC_PERIPHERAL.Format(_T("-"));

    m_tDlgMSL_BIT_04.m_strSKR_BIT_DON.Format(_T("-"));

    m_tDlgMSL_BIT_04.UpdateData(FALSE);

    /* 탐색기2(MSL_BIT_05) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_0 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT0.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT0.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_1 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT1.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT1.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_2 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT2.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT2.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_4 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT4.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT4.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_5 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT5.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT5.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_6 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT6.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT6.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPC_BIT_7 == 0)
        m_tDlgMSL_BIT_05.m_strIPC_BIT7.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPC_BIT7.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPF_BIT_0 == 0)
        m_tDlgMSL_BIT_05.m_strIPF_BIT0.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPF_BIT0.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.IPF_BIT_1 == 0)
        m_tDlgMSL_BIT_05.m_strIPF_BIT1.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strIPF_BIT1.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.NUC_BIT_0 == 0)
        m_tDlgMSL_BIT_05.m_strNUC_BIT0.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strNUC_BIT0.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.SKR_BIT2.NUC_BIT_1 == 0)
        m_tDlgMSL_BIT_05.m_strNUC_BIT1.Format(_T("-"));
    else
        m_tDlgMSL_BIT_05.m_strNUC_BIT1.Format(_T("-"));

    m_tDlgMSL_BIT_05.UpdateData(FALSE);

    /* 구동장치(MSL_BIT_06) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p5V == 0)
        m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str5VDC_P.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.m10V == 0)
        m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str10VDC_N.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p10V == 0)
        m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str10VDC_P.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.m15V == 0)
        m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str15VDC_N.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p15V == 0)
        m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str15VDC_P.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.p30V == 0)
        m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_str30VDC_P.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.CAN == 0)
        m_tDlgMSL_BIT_06.m_strCAN.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strCAN.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.ADC == 0)
        m_tDlgMSL_BIT_06.m_strADC.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strADC.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.FLASH == 0)
        m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strFLASH.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.ACT_BIT.DSP == 0)
        m_tDlgMSL_BIT_06.m_strDSP.Format(_T("-"));
    else
        m_tDlgMSL_BIT_06.m_strDSP.Format(_T("-"));

    m_tDlgMSL_BIT_06.UpdateData(FALSE);

    /* 유도탄 상태(MSL_BIT_07) */
    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.MSLAWY == 0)
        m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strMSLAWY.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.FUZGOOD == 0)
        m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strFUZGOOD.Format(_T("-"));

    if (((CFCU_SWDlg*)GetParent())->m_uMSL_BIT_CHK.MSL_BIT_CHK.MSL_BIT2.MBAT == 0)
        m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("-"));
    else
        m_tDlgMSL_BIT_07.m_strMBAT.Format(_T("-"));

    m_tDlgMSL_BIT_07.UpdateData(FALSE);
}
