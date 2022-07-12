#pragma once
#include "afxdialogex.h"


// CModeIO 대화 상자

class CModeIO : public CDialogEx
{
	DECLARE_DYNAMIC(CModeIO)

public:
	CModeIO(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CModeIO();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CModeIO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void SetConnectState(UINT16 wParam);
	CStatic m_staticConnectState;
	UINT16 m_u16HILS_RTN_Connect;
	UINT8 m_u8CNNCT_RSLT;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	UINT8 m_u8DSCNNCT_RSLT;
	UINT16 m_u16HILS_RTN_Disconnect;
};
