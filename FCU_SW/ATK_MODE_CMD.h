#pragma once
#include "afxext.h"


// CATK_MODE_CMD 대화 상자입니다.

class CATK_MODE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CATK_MODE_CMD)

public:
	CATK_MODE_CMD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CATK_MODE_CMD();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ATK_MODE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnBnClickedBtnCancel();
    CBitmapButton m_btnCancel;
};
