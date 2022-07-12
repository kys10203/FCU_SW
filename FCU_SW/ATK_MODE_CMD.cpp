// ATK_MODE_CMD.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "ATK_MODE_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CATK_MODE_CMD ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CATK_MODE_CMD, CDialogEx)

CATK_MODE_CMD::CATK_MODE_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATK_MODE_CMD::IDD, pParent)
{

	EnableAutomation();

}

CATK_MODE_CMD::~CATK_MODE_CMD()
{
}

void CATK_MODE_CMD::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CATK_MODE_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CATK_MODE_CMD, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CATK_MODE_CMD::OnBnClickedBtnCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CATK_MODE_CMD, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_IATK_MODE_CMD�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {EACA9016-528F-43E0-A4F4-74DCAC527636}
static const IID IID_IATK_MODE_CMD =
{ 0xEACA9016, 0x528F, 0x43E0, { 0xA4, 0xF4, 0x74, 0xDC, 0xAC, 0x52, 0x76, 0x36 } };

BEGIN_INTERFACE_MAP(CATK_MODE_CMD, CDialogEx)
	INTERFACE_PART(CATK_MODE_CMD, IID_IATK_MODE_CMD, Dispatch)
END_INTERFACE_MAP()


// CATK_MODE_CMD �޽��� ó�����Դϴ�.


BOOL CATK_MODE_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


HBRUSH CATK_MODE_CMD::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CATK_MODE_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC Ű �̺�Ʈ�� ���� ó�� �߰�
            ((CFCU_SWDlg *)GetParent())->m_bATK_MODE_CMD = FALSE;

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


void CATK_MODE_CMD::OnBnClickedBtnCancel()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CFCU_SWDlg *)GetParent())->m_bATK_MODE_CMD = FALSE;

    CDialogEx::OnOK();
}
