#pragma once
#include "afxdialogex.h"


// CFCU_STS_Dlg 대화 상자

class CFCU_STS_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_STS_Dlg)

public:
	CFCU_STS_Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFCU_STS_Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FCU_STS_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	CBitmapButton m_btnLNCH_MODE_START;
	CBitmapButton m_btnLNCH_MODE_STOP;
	CBitmapButton m_btnMainScreen;
	afx_msg void OnBnClickedBtnLnchModeStart();
	CStatic m_led01;
	CStatic m_led02;
	CStatic m_led03;
	CStatic m_led04;
	CStatic m_led05;
	CStatic m_led06;
	CStatic m_led07;
	CStatic m_led08;
	CStatic m_led09;
	CStatic m_led10;
	CStatic m_led11;
	CStatic m_led12;
	CStatic m_led13;
	CStatic m_led14;
	CStatic m_led15;
	CStatic m_led16;
	BOOL resetStat();
	void ChangeLED(CStatic* icon, UINT16 flag);
	afx_msg void OnBnClickedBtnLnchModeStop();
	afx_msg void OnBnClickedBtnMainScreen();

protected:
	afx_msg LRESULT OnResetStat(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMslBitChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSkrRdyChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSkrCageCmd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSkrTrkStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSkrPlcChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMslStsChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMslIdChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnAtkMod(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLckCmd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRelckCmd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLiftoffRdy(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMslCon(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnPinChk(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSqbMbat(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSqbCu(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSqbPin(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnStnClickedStatic3();
	afx_msg void OnStnClickedStatic7();
	afx_msg void OnStnClickedStatic2();
	afx_msg void OnStnClickedStatic5();
	afx_msg void OnStnClickedStatic9();
	afx_msg void OnStnClickedStatic10();
	afx_msg void OnStnClickedStatic4();
	afx_msg void OnStnClickedStatic8();
	afx_msg void OnStnClickedStatic6();
	afx_msg void OnStnClickedStatic11();
protected:
	afx_msg LRESULT OnPinchkMslcon(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected:
	afx_msg LRESULT OnSetLaunchMode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetDryrunMode(WPARAM wParam, LPARAM lParam);
public:
	CStatic m_staticSQB_BAT;
	CStatic m_txtSkrPlc;
protected:
	afx_msg LRESULT OnClientDisconnect(WPARAM wParam, LPARAM lParam);
public:
	CStatic m_txtMslIdChk;
protected:
	afx_msg LRESULT OnSqbBat(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
