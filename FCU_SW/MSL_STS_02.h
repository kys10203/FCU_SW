#pragma once
#include "afxdialogex.h"


// MSL_STS_02 대화 상자

class MSL_STS_02 : public CDialogEx
{
	DECLARE_DYNAMIC(MSL_STS_02)

public:
	MSL_STS_02(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MSL_STS_02();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MSL_STS_02 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strGCU_ADC;
	CString m_strGCU_SRAM;
	CString m_strGCU_FLASH;
	CString m_strGCU_R2GYRO;
	CString m_strGCU_POW;
	CString m_strGCU_SYS_RDY;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
