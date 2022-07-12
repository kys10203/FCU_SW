#pragma once
#include "afxext.h"


// CSKR_TRK_STATUS 대화 상자입니다.

class CSKR_TRK_STATUS : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_TRK_STATUS)

public:
	CSKR_TRK_STATUS(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSKR_TRK_STATUS();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SKR_TRK_STATUS };

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
    CString m_strLOCK_ON_RSLT;
    CString m_strYAW_RPOS_P;
    CString m_strPITCH_RPOS_P;
    CString m_strOG_SX_STS;
    CString m_strOG_SY_STS;
    CString m_strOG_EX_STS;
    CString m_strOG_EY_STS;
    CString m_strSKR_RDY;
    CString m_strFPA_TEMP;
    CString m_strSKR_TEMP;
protected:
    afx_msg LRESULT OnSkrTrkStatus(WPARAM wParam, LPARAM lParam);
public:
    double Convert2Double(WORD input, UINT16 LSB, INT16 signBit);
    void ResetAll();
};
