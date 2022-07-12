#pragma once
#include "afxext.h"


// CSKR_CAGE_CMD 대화 상자입니다.

class CSKR_CAGE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_CAGE_CMD)

public:
	CSKR_CAGE_CMD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSKR_CAGE_CMD();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SKR_CAGE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    CBitmapButton m_btnCancel;
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnBnClickedBtnCancel();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
    afx_msg LRESULT OnSkrCageCmd(WPARAM wParam, LPARAM lParam);
public:
    CString m_strSKR_CAGE_CMD_RSLT;
	void ResetAll();
};
