#pragma once
#include "afxext.h"


// CSKR_PLC_CHK ��ȭ �����Դϴ�.

class CSKR_PLC_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_PLC_CHK)

public:
	CSKR_PLC_CHK(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSKR_PLC_CHK();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SKR_PLC_CHK };

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
protected:
    afx_msg LRESULT OnSkrPlcChk(WPARAM wParam, LPARAM lParam);
public:
    CString m_strPLC_BIT_RSLT;
    CString m_strPLC_NUM_RSLT;
    CString m_strSKR_RDY;
    CString m_strFPA_TEMP;
    CString m_strSKR_TEMP;
    double Convert2Double(WORD input, INT16 signBit);
    void ResetAll();
};
