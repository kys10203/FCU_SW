#pragma once
#include "afxcmn.h"

// CRecvView 대화 상자입니다.

#define TYPE_WORD 20
#define TYPE_DOUBLE 30
#define TYPE_DEC 40


class CRecvView : public CDialogEx
{
	DECLARE_DYNAMIC(CRecvView)

public:
	CRecvView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRecvView();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_RECVVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    CRichEditCtrl m_editRecvLog;
    void AddEventString(wchar_t* ap_string);
    void AddEventString(CString str);
    void AutoScroll(void);
    void AddEventString(WORD num, WORD type);
    void clearLog(void);
    WORD m_u16LogCnt;
	afx_msg void OnBnClickedCancel();
};
