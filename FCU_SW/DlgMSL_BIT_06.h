#pragma once


// CDlgMSL_BIT_06 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_06 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_06)

public:
	CDlgMSL_BIT_06(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_06();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_06 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
