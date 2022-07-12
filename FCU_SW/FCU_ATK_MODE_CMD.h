#pragma once
#include "afxwin.h"


// CFCU_ATK_MODE_CMD 대화 상자입니다.

class CFCU_ATK_MODE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_ATK_MODE_CMD)

public:
	CFCU_ATK_MODE_CMD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFCU_ATK_MODE_CMD();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FCU_ATK_MODE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    CBitmapButton m_btnAtkModeU;
    CBitmapButton m_btnAtkModeD;
    afx_msg void OnBnClickedAtkModeU();
    afx_msg void OnBnClickedAtkModeD();
    CBitmapButton m_btnCancel;
    afx_msg void OnBnClickedBtnCancel();
    virtual void OnCancel();
};
