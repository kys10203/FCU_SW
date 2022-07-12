// LOCK_ON_CMD.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "LOCK_ON_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CLOCK_ON_CMD ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLOCK_ON_CMD, CDialogEx)

CLOCK_ON_CMD::CLOCK_ON_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLOCK_ON_CMD::IDD, pParent)
{

	EnableAutomation();

}

CLOCK_ON_CMD::~CLOCK_ON_CMD()
{
}

void CLOCK_ON_CMD::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CLOCK_ON_CMD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CLOCK_ON_CMD, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CLOCK_ON_CMD::OnBnClickedBtnCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLOCK_ON_CMD, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_ILOCK_ON_CMD�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {B123823B-465C-418D-995C-859460FE817F}
static const IID IID_ILOCK_ON_CMD =
{ 0xB123823B, 0x465C, 0x418D, { 0x99, 0x5C, 0x85, 0x94, 0x60, 0xFE, 0x81, 0x7F } };

BEGIN_INTERFACE_MAP(CLOCK_ON_CMD, CDialogEx)
	INTERFACE_PART(CLOCK_ON_CMD, IID_ILOCK_ON_CMD, Dispatch)
END_INTERFACE_MAP()


// CLOCK_ON_CMD �޽��� ó�����Դϴ�.


BOOL CLOCK_ON_CMD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetBackgroundColor(RGB(50, 50, 50));

    m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
    m_btnCancel.SizeToContent();

    return TRUE;  // return TRUE unless you set the focus to a control

}


BOOL CLOCK_ON_CMD::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_ESCAPE)
        {
            // ESC Ű �̺�Ʈ�� ���� ó�� �߰�
            ((CFCU_SWDlg *)GetParent())->m_bLOCK_ON_CMD = FALSE;

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


void CLOCK_ON_CMD::OnBnClickedBtnCancel()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CFCU_SWDlg *)GetParent())->m_bLOCK_ON_CMD = FALSE;

    CDialogEx::OnOK();
}
