#pragma once


// CDlgMSL_BIT_05 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_05 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_05)

public:
	CDlgMSL_BIT_05(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_05();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_05 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_strIPC_BIT0;
    CString m_strIPC_BIT1;
    CString m_strIPC_BIT2;
    CString m_strIPC_BIT4;
    CString m_strIPC_BIT5;
    CString m_strIPC_BIT6;
    CString m_strIPC_BIT7;
    CString m_strIPF_BIT0;
    CString m_strIPF_BIT1;
    CString m_strNUC_BIT0;
    CString m_strNUC_BIT1;
};
