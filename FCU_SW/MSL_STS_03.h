#pragma once
#include "afxdialogex.h"


// MSL_STS_03 대화 상자

class MSL_STS_03 : public CDialogEx
{
	DECLARE_DYNAMIC(MSL_STS_03)

public:
	MSL_STS_03(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MSL_STS_03();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MSL_STS_03 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strEOH_ECC;
	CString m_strEOH_COOL;
	CString m_strNUC_CHECK_SUM;
	CString m_strIPF_ECC;
	CString m_strIPF_CHECK_SUM;
	CString m_strIPC_IMAGE_CHECK;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
