#pragma once


// CDlgMSL_BIT_04 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_04 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_04)

public:
	CDlgMSL_BIT_04(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_04();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_04 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_strEOH_COOL;
    CString m_strIPB_POWER;
    CString m_strNUC_PERIPHRAL;
    CString m_strIPF_PERIPHERAL;
    CString m_strIPC_PERIPHERAL;
    CString m_strSKR_BIT_DON;
};
