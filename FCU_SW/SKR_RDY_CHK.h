#pragma once
#include "afxext.h"


// CSKR_RDY_CHK ��ȭ �����Դϴ�.

class CSKR_RDY_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_RDY_CHK)

public:
	CSKR_RDY_CHK(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSKR_RDY_CHK();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SKR_RDY_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    CBitmapButton m_btnCancel;
    afx_msg void OnBnClickedBtnCancel();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    CString m_strSKR_RDY;
    CString m_strFPA_TEMP;
    CString m_strSKR_TEMP;
    CString m_strMAX_SKR_RDY_TIME;
protected:
    afx_msg LRESULT OnSkrRdyChk(WPARAM wParam, LPARAM lParam);
public:
    double Convert2Double(WORD input, INT16 signBit);
    void ResetAll();
};
