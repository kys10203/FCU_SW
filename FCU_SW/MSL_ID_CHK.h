#pragma once
#include "afxwin.h"


// CMSL_ID_CHK ��ȭ �����Դϴ�.

class CMSL_ID_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CMSL_ID_CHK)

public:
	CMSL_ID_CHK(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMSL_ID_CHK();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_ID_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    CBitmapButton m_btnCancel;
    afx_msg void OnBnClickedBtnCancel();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
    afx_msg LRESULT OnMslIdChk(WPARAM wParam, LPARAM lParam);
public:
    CString m_strMSL_ID;
    void ResetAll();
};
