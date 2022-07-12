#pragma once
#include "afxext.h"
#include "afxcmn.h"
#include "DlgMSL_BIT_01.h"
#include "DlgMSL_BIT_02.h"
#include "DlgMSL_BIT_03.h"
#include "DlgMSL_BIT_04.h"
#include "DlgMSL_BIT_05.h"
#include "DlgMSL_BIT_06.h"
#include "DlgMSL_BIT_07.h"

// CMSL_BIT_CHK 대화 상자입니다.

class CMSL_BIT_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CMSL_BIT_CHK)

public:
	CMSL_BIT_CHK(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMSL_BIT_CHK();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_BIT_CHK };

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
    CTabCtrl m_tabMain;
    afx_msg void OnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);

    CDlgMSL_BIT_01 m_tDlgMSL_BIT_01;
    CDlgMSL_BIT_02 m_tDlgMSL_BIT_02;
    CDlgMSL_BIT_03 m_tDlgMSL_BIT_03;
    CDlgMSL_BIT_04 m_tDlgMSL_BIT_04;
    CDlgMSL_BIT_05 m_tDlgMSL_BIT_05;
    CDlgMSL_BIT_06 m_tDlgMSL_BIT_06;
    CDlgMSL_BIT_07 m_tDlgMSL_BIT_07;

    CWnd* m_pwndShow;
    int a;
protected:
    afx_msg LRESULT OnMslBitChk(WPARAM wParam, LPARAM lParam);
public:
    double Convert2Double(WORD input, UINT16 type, INT16 FS);
    void ResetAll();
};
