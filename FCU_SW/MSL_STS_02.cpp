// MSL_STS_02.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "MSL_STS_02.h"


// MSL_STS_02 대화 상자

IMPLEMENT_DYNAMIC(MSL_STS_02, CDialogEx)

MSL_STS_02::MSL_STS_02(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MSL_STS_02, pParent)
	, m_strGCU_ADC(_T(""))
	, m_strGCU_SRAM(_T(""))
	, m_strGCU_FLASH(_T(""))
	, m_strGCU_R2GYRO(_T(""))
	, m_strGCU_POW(_T(""))
	, m_strGCU_SYS_RDY(_T(""))
{

}

MSL_STS_02::~MSL_STS_02()
{
}

void MSL_STS_02::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strGCU_ADC);
	DDX_Text(pDX, IDC_EDIT2, m_strGCU_SRAM);
	DDX_Text(pDX, IDC_EDIT3, m_strGCU_FLASH);
	DDX_Text(pDX, IDC_EDIT4, m_strGCU_R2GYRO);
	DDX_Text(pDX, IDC_EDIT5, m_strGCU_POW);
	DDX_Text(pDX, IDC_EDIT6, m_strGCU_SYS_RDY);
}


BEGIN_MESSAGE_MAP(MSL_STS_02, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MSL_STS_02 메시지 처리기


BOOL MSL_STS_02::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	((CEdit*)GetDlgItem(IDC_EDIT1))->GetRect(rect);
	rect.top += 4;
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT3))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT4))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT5))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT6))->SetRect(rect);

	SetBackgroundColor(RGB(50, 50, 50));

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH MSL_STS_02::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT nID = pWnd->GetDlgCtrlID();

	switch (nID)
	{
	case IDC_STATIC:
		pDC->SetTextColor(RGB(250, 250, 250));
	}

	return hbr;
}
