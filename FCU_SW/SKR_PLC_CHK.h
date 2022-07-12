#pragma once
#include "afxext.h"


// CSKR_PLC_CHK 대화 상자입니다.

class CSKR_PLC_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_PLC_CHK)

public:
	CSKR_PLC_CHK(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSKR_PLC_CHK();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SKR_PLC_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
