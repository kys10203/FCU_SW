#pragma once
#include "afxext.h"


// CLOCK_ON_CMD ��ȭ �����Դϴ�.

class CLOCK_ON_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CLOCK_ON_CMD)

public:
	CLOCK_ON_CMD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLOCK_ON_CMD();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOCK_ON_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    CBitmapButton m_btnCancel;
    afx_msg void OnBnClickedBtnCancel();
};
