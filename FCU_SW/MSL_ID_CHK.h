#pragma once
#include "afxwin.h"


// CMSL_ID_CHK 대화 상자입니다.

class CMSL_ID_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CMSL_ID_CHK)

public:
	CMSL_ID_CHK(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMSL_ID_CHK();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_ID_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
