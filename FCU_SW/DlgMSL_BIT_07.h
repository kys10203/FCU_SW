#pragma once


// CDlgMSL_BIT_07 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_07 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_07)

public:
	CDlgMSL_BIT_07(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_07();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_07 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_strMSLAWY;
    CString m_strFUZGOOD;
    CString m_strMBAT;
};
