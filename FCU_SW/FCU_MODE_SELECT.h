#pragma once
#include "afxext.h"


// CFCU_MODE_SELECT ��ȭ �����Դϴ�.

class CFCU_MODE_SELECT : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_MODE_SELECT)

public:
	CFCU_MODE_SELECT(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFCU_MODE_SELECT();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FCU_MODE_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    CBitmapButton m_btnModeTest;
    CBitmapButton m_btnModeDryrun;
    CBitmapButton m_btnModeLaunch;
    afx_msg void OnBnClickedBtnModeTest();
    afx_msg void OnBnClickedBtnModeDryrun();
    afx_msg void OnBnClickedBtnModeLaunch();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    INT16 ret;
    UINT8 m_u8Mode;
    UINT8 m_u8HILS_ConnectingERR;
    CBitmapButton m_btnModeEscape;
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnBnClickedBtnModeEscape();
};
