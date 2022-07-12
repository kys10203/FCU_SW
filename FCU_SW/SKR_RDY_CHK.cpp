// SKR_RDY_CHK.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_RDY_CHK.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_RDY_CHK ��ȭ �����Դϴ�.

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
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

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

// ����: IID_ISKR_RDY_CHK�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {F8192AB6-265B-428C-A798-6B1215CFFD06}
static const IID IID_ISKR_RDY_CHK =
{ 0xF8192AB6, 0x265B, 0x428C, { 0xA7, 0x98, 0x6B, 0x12, 0x15, 0xCF, 0xFD, 0x6 } };

BEGIN_INTERFACE_MAP(CSKR_RDY_CHK, CDialogEx)
	INTERFACE_PART(CSKR_RDY_CHK, IID_ISKR_RDY_CHK, Dispatch)
END_INTERFACE_MAP()


// CSKR_RDY_CHK �޽��� ó�����Դϴ�.


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
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_RDY_CHK = FALSE;

    CDialogEx::OnOK();
}


BOOL CSKR_RDY_CHK::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC Ű �̺�Ʈ�� ���� ó�� �߰�
            ((CFCU_SWDlg *)GetParent())->m_bSKR_RDY_CHK = FALSE;

            CDialogEx::OnOK();

            return TRUE;
        }
        else if (pMsg->wParam == VK_RETURN)
        {
            // Enter Ű �̺�Ʈ�� ���� ó�� �߰�
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
        m_strSKR_TEMP.Format(_T("%.2lf ��"), Convert2Double(((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.SKR_TEMP.SKR_TEMP, ((CFCU_SWDlg*)GetParent())->m_uSKR_RDY_CHK.SKR_RDY_CHK.SKR_TEMP.SignBIT));
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
    // TODO: ���⿡ ���� �ڵ� �߰�.
    m_strSKR_RDY.Format(_T("-"));
    m_strFPA_TEMP.Format(_T("-"));
    m_strSKR_TEMP.Format(_T("-"));
    m_strMAX_SKR_RDY_TIME.Format(_T("-"));

    UpdateData(FALSE);
}
