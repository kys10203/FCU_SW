#pragma once


// CDlgMSL_BIT_02 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_02 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_02)

public:
	CDlgMSL_BIT_02(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_02();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_02 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    WORD m_wCAN_ACT;
    WORD m_wUART_OLU;
    CString m_strCAN_ACT;
    CString m_strUART_OLU;
};
