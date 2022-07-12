#pragma once


// CDlgMSL_BIT_06 대화 상자입니다.

class CDlgMSL_BIT_06 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_06)

public:
	CDlgMSL_BIT_06(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMSL_BIT_06();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_BIT_06 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_str5VDC_P;
    CString m_str10VDC_N;
    CString m_str10VDC_P;
    CString m_str15VDC_N;
    CString m_str15VDC_P;
    CString m_str30VDC_P;
    CString m_strCAN;
    CString m_strADC;
    CString m_strFLASH;
    CString m_strDSP;
};
