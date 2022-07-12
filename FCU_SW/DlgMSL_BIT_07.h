#pragma once


// CDlgMSL_BIT_07 대화 상자입니다.

class CDlgMSL_BIT_07 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_07)

public:
	CDlgMSL_BIT_07(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMSL_BIT_07();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_BIT_07 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_strMSLAWY;
    CString m_strFUZGOOD;
    CString m_strMBAT;
};
