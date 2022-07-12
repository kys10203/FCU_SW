#pragma once
#include "afxext.h"


// CFCU_MODE_SELECT 대화 상자입니다.

class CFCU_MODE_SELECT : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_MODE_SELECT)

public:
	CFCU_MODE_SELECT(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFCU_MODE_SELECT();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FCU_MODE_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
