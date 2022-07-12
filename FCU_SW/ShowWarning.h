#pragma once
#include "afxdialogex.h"


// CShowWarning 대화 상자

class CShowWarning : public CDialogEx
{
	DECLARE_DYNAMIC(CShowWarning)

public:
	CShowWarning(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CShowWarning();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ShowWarning };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
