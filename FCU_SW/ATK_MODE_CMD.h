#pragma once
#include "afxext.h"


// CATK_MODE_CMD ��ȭ �����Դϴ�.

class CATK_MODE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CATK_MODE_CMD)

public:
	CATK_MODE_CMD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CATK_MODE_CMD();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATK_MODE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
