#pragma once
#include "afxext.h"


// CSKR_CAGE_CMD ��ȭ �����Դϴ�.

class CSKR_CAGE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CSKR_CAGE_CMD)

public:
	CSKR_CAGE_CMD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSKR_CAGE_CMD();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SKR_CAGE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
