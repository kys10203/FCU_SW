// SKR_CAGE_CMD.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "SKR_CAGE_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CSKR_CAGE_CMD ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSKR_CAGE_CMD, CDialogEx)

CSKR_CAGE_CMD::CSKR_CAGE_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSKR_CAGE_CMD::IDD, pParent)
    , m_strSKR_CAGE_CMD_RSLT(_T(""))
{

	EnableAutomation();

}

CSKR_CAGE_CMD::~CSKR_CAGE_CMD()
{
}

void CSKR_CAGE_CMD::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CSKR_CAGE_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
    DDX_Text(pDX, IDC_EDIT1, m_strSKR_CAGE_CMD_RSLT);
}


BEGIN_MESSAGE_MAP(CSKR_CAGE_CMD, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CSKR_CAGE_CMD::OnBnClickedBtnCancel)
    ON_WM_CTLCOLOR()
    ON_MESSAGE(WM_SKR_CAGE_CMD, &CSKR_CAGE_CMD::OnSkrCageCmd)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSKR_CAGE_CMD, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_ISKR_CAGE_CMD�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {1CB9166D-AE96-4B1D-A0F9-166CF5FB9CB0}
static const IID IID_ISKR_CAGE_CMD =
{ 0x1CB9166D, 0xAE96, 0x4B1D, { 0xA0, 0xF9, 0x16, 0x6C, 0xF5, 0xFB, 0x9C, 0xB0 } };

BEGIN_INTERFACE_MAP(CSKR_CAGE_CMD, CDialogEx)
	INTERFACE_PART(CSKR_CAGE_CMD, IID_ISKR_CAGE_CMD, Dispatch)
END_INTERFACE_MAP()


// CSKR_CAGE_CMD �޽��� ó�����Դϴ�.


BOOL CSKR_CAGE_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->GetRect(rect);
    rect.top += 8;
    ((CEdit *)GetDlgItem(IDC_EDIT1))->SetRect(rect);

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


BOOL CSKR_CAGE_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC Ű �̺�Ʈ�� ���� ó�� �߰�
            ((CFCU_SWDlg *)GetParent())->m_bSKR_CAGE_CMD = FALSE;

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


void CSKR_CAGE_CMD::OnBnClickedBtnCancel()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CFCU_SWDlg *)GetParent())->m_bSKR_CAGE_CMD = FALSE;

    CDialogEx::OnOK();
}


HBRUSH CSKR_CAGE_CMD::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


afx_msg LRESULT CSKR_CAGE_CMD::OnSkrCageCmd(WPARAM wParam, LPARAM lParam)
{
    if (((CFCU_SWDlg*)GetParent())->m_bDisplaySKR_CAGE == FALSE)
    {
        ResetAll();
    }
    else
    {
        if (((CFCU_SWDlg*)GetParent())->m_uSKR_CAGE_CMD.SKR_CAGE_CMD.SKR_CAGE_RSLT == 0)
            m_strSKR_CAGE_CMD_RSLT.Format(_T("GOOD"));
        else
            m_strSKR_CAGE_CMD_RSLT.Format(_T("FAULT"));

        UpdateData(FALSE);
    }
    return 0;
}


void CSKR_CAGE_CMD::ResetAll()
{
    // TODO: ���⿡ ���� �ڵ� �߰�.
    m_strSKR_CAGE_CMD_RSLT.Format(_T("-"));

    UpdateData(FALSE);
}
