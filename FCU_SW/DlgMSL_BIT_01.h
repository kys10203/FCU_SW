#pragma once
#include "afxwin.h"


// CDlgMSL_BIT_01 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_01 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_01)

public:
	CDlgMSL_BIT_01(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_01();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_01 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

    CString m_strMSL_BIT1;
    CString m_strMSL_BIT2;
    CString m_strGCU_BIT;
    CString m_strMBAT;
    CString m_str30VDC;
    CString m_str15VDC;
    CString m_str15VDC_negative;
    CString m_str5VDC;
    CString m_str3_3VDC;
    CString m_str1_2VDC;
    CString m_strSKR_BIT1;
    CString m_strSKR_BIT2;
    CString m_strACT_BIT;
};
