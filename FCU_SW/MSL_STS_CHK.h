#pragma once
#include "afxext.h"
#include "afxcmn.h"
#include "MSL_STS_01.h"
#include "MSL_STS_02.h"
#include "MSL_STS_03.h"
#include "DlgMSL_BIT_02.h"
#include "DlgMSL_BIT_06.h"
#include "DlgMSL_BIT_07.h"

// CMSL_STS_CHK 대화 상자입니다.

class CMSL_STS_CHK : public CDialogEx
{
	DECLARE_DYNAMIC(CMSL_STS_CHK)

public:
	CMSL_STS_CHK(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMSL_STS_CHK();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_STS_CHK };

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

    MSL_STS_01 m_tDlgMSL_STS_01;
    MSL_STS_02 m_tDlgMSL_STS_02;
    MSL_STS_03 m_tDlgMSL_STS_03;
    CDlgMSL_BIT_02 m_tDlgMSL_BIT_02;
    CDlgMSL_BIT_06 m_tDlgMSL_BIT_06;
    CDlgMSL_BIT_07 m_tDlgMSL_BIT_07;
protected:
    afx_msg LRESULT OnMslStsChk(WPARAM wParam, LPARAM lParam);
public:
    CTabCtrl m_tabMain;
    afx_msg void OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
    CWnd* m_pwndShow;
    void ResetAll();
};
