#pragma once
#include "afxdialogex.h"


// MSL_STS_01 대화 상자

class MSL_STS_01 : public CDialogEx
{
	DECLARE_DYNAMIC(MSL_STS_01)

public:
	MSL_STS_01(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MSL_STS_01();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MSL_STS_01 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMSL_STS1;
	CString m_strMSL_STS2;
	CString m_strGCU_STS;
	CString m_strMBAT;
	CString m_str30VDC;
	CString m_str15VDC;
	CString m_str15VDC_negative;
	CString m_str5VDC;
	CString m_str3_3VDC;
	CString m_str1_2VDC;
	CString m_strSKR_STS;
	CString m_strACT_STS;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
