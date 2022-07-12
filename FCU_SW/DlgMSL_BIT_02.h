#pragma once


// CDlgMSL_BIT_02 대화 상자입니다.

class CDlgMSL_BIT_02 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_02)

public:
	CDlgMSL_BIT_02(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMSL_BIT_02();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_BIT_02 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    WORD m_wCAN_ACT;
    WORD m_wUART_OLU;
    CString m_strCAN_ACT;
    CString m_strUART_OLU;
};
