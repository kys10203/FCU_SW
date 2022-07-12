// MSL_STS_03.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "MSL_STS_03.h"


// MSL_STS_03 대화 상자

IMPLEMENT_DYNAMIC(MSL_STS_03, CDialogEx)

MSL_STS_03::MSL_STS_03(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MSL_STS_03, pParent)
	, m_strEOH_ECC(_T(""))
	, m_strEOH_COOL(_T(""))
	, m_strNUC_CHECK_SUM(_T(""))
	, m_strIPF_ECC(_T(""))
	, m_strIPF_CHECK_SUM(_T(""))
	, m_strIPC_IMAGE_CHECK(_T(""))
{

}

MSL_STS_03::~MSL_STS_03()
{
}

void MSL_STS_03::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEOH_ECC);
	DDX_Text(pDX, IDC_EDIT2, m_strEOH_COOL);
	DDX_Text(pDX, IDC_EDIT3, m_strNUC_CHECK_SUM);
	DDX_Text(pDX, IDC_EDIT4, m_strIPF_ECC);
	DDX_Text(pDX, IDC_EDIT5, m_strIPF_CHECK_SUM);
	DDX_Text(pDX, IDC_EDIT6, m_strIPC_IMAGE_CHECK);
}


BEGIN_MESSAGE_MAP(MSL_STS_03, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MSL_STS_03 메시지 처리기


BOOL MSL_STS_03::OnInitDialog()
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


HBRUSH MSL_STS_03::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
