// MSL_STS_01.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "MSL_STS_01.h"


// MSL_STS_01 대화 상자

IMPLEMENT_DYNAMIC(MSL_STS_01, CDialogEx)

MSL_STS_01::MSL_STS_01(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MSL_STS_01, pParent)
	, m_strMSL_STS1(_T(""))
	, m_strMSL_STS2(_T(""))
	, m_strGCU_STS(_T(""))
	, m_strMBAT(_T(""))
	, m_str30VDC(_T(""))
	, m_str15VDC(_T(""))
	, m_str15VDC_negative(_T(""))
	, m_str5VDC(_T(""))
	, m_str3_3VDC(_T(""))
	, m_str1_2VDC(_T(""))
	, m_strSKR_STS(_T(""))
	, m_strACT_STS(_T(""))
{

}

MSL_STS_01::~MSL_STS_01()
{
}

void MSL_STS_01::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strMSL_STS1);
	DDX_Text(pDX, IDC_EDIT2, m_strMSL_STS2);
	DDX_Text(pDX, IDC_EDIT3, m_strGCU_STS);
	DDX_Text(pDX, IDC_EDIT4, m_strMBAT);
	DDX_Text(pDX, IDC_EDIT5, m_str30VDC);
	DDX_Text(pDX, IDC_EDIT6, m_str15VDC);
	DDX_Text(pDX, IDC_EDIT7, m_str15VDC_negative);
	DDX_Text(pDX, IDC_EDIT8, m_str5VDC);
	DDX_Text(pDX, IDC_EDIT9, m_str3_3VDC);
	DDX_Text(pDX, IDC_EDIT10, m_str1_2VDC);
	DDX_Text(pDX, IDC_EDIT11, m_strSKR_STS);
	DDX_Text(pDX, IDC_EDIT12, m_strACT_STS);
}


BEGIN_MESSAGE_MAP(MSL_STS_01, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MSL_STS_01 메시지 처리기


BOOL MSL_STS_01::OnInitDialog()
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
	((CEdit*)GetDlgItem(IDC_EDIT7))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT8))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT9))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT10))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT11))->SetRect(rect);
	((CEdit*)GetDlgItem(IDC_EDIT12))->SetRect(rect);

	SetBackgroundColor(RGB(50, 50, 50));

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH MSL_STS_01::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
