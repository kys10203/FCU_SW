// FCU_ATK_MODE_CMD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "FCU_ATK_MODE_CMD.h"
#include "afxdialogex.h"
#include "FCU_SWDlg.h"

// CFCU_ATK_MODE_CMD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFCU_ATK_MODE_CMD, CDialogEx)

CFCU_ATK_MODE_CMD::CFCU_ATK_MODE_CMD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFCU_ATK_MODE_CMD::IDD, pParent)
{

	EnableAutomation();

}

CFCU_ATK_MODE_CMD::~CFCU_ATK_MODE_CMD()
{
}

void CFCU_ATK_MODE_CMD::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CFCU_ATK_MODE_CMD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ATK_MODE_U, m_btnAtkModeU);
	DDX_Control(pDX, IDC_ATK_MODE_D, m_btnAtkModeD);
	DDX_Control(pDX, IDC_BTN_CANCEL, m_btnCancel);
}


BEGIN_MESSAGE_MAP(CFCU_ATK_MODE_CMD, CDialogEx)
	ON_BN_CLICKED(IDC_ATK_MODE_U, &CFCU_ATK_MODE_CMD::OnBnClickedAtkModeU)
	ON_BN_CLICKED(IDC_ATK_MODE_D, &CFCU_ATK_MODE_CMD::OnBnClickedAtkModeD)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CFCU_ATK_MODE_CMD::OnBnClickedBtnCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFCU_ATK_MODE_CMD, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IFCU_ATK_MODE_CMD에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {48B1EF4E-DBB4-4B2B-838A-58A4D2EA8610}
static const IID IID_IFCU_ATK_MODE_CMD =
{ 0x48B1EF4E, 0xDBB4, 0x4B2B, { 0x83, 0x8A, 0x58, 0xA4, 0xD2, 0xEA, 0x86, 0x10 } };

BEGIN_INTERFACE_MAP(CFCU_ATK_MODE_CMD, CDialogEx)
	INTERFACE_PART(CFCU_ATK_MODE_CMD, IID_IFCU_ATK_MODE_CMD, Dispatch)
END_INTERFACE_MAP()


// CFCU_ATK_MODE_CMD 메시지 처리기입니다.


BOOL CFCU_ATK_MODE_CMD::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetBackgroundColor(RGB(30, 30, 30));

	m_btnAtkModeU.LoadBitmaps(IDB_BTN_ATK_MODE_U01, IDB_BTN_ATK_MODE_U02, NULL, NULL);
	m_btnAtkModeU.SizeToContent();
	m_btnAtkModeD.LoadBitmaps(IDB_BTN_ATK_MODE_D01, IDB_BTN_ATK_MODE_D02, NULL, NULL);
	m_btnAtkModeD.SizeToContent();
	m_btnCancel.LoadBitmaps(IDB_BTN_CANCEL_01, IDB_BTN_CANCEL_02, NULL, NULL);
	m_btnCancel.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
}



void CFCU_ATK_MODE_CMD::OnBnClickedAtkModeU()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->m_ClientSocket.m_u16AtkMode = ATK_MODE_UPPER;
	CDialogEx::OnOK();
}


void CFCU_ATK_MODE_CMD::OnBnClickedAtkModeD()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFCU_SWDlg*)GetParent())->m_ClientSocket.m_u16AtkMode = ATK_MODE_DIRECT;
	CDialogEx::OnOK();
}


void CFCU_ATK_MODE_CMD::OnBnClickedBtnCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnCancel();
	CDialogEx::OnOK();
}


void CFCU_ATK_MODE_CMD::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//this->ShowWindow(SW_HIDE);
}
