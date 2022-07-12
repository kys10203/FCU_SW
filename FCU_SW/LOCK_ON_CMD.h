#pragma once
#include "afxext.h"


// CLOCK_ON_CMD 대화 상자입니다.

class CLOCK_ON_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CLOCK_ON_CMD)

public:
	CLOCK_ON_CMD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLOCK_ON_CMD();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOCK_ON_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    CBitmapButton m_btnCancel;
    afx_msg void OnBnClickedBtnCancel();
};
