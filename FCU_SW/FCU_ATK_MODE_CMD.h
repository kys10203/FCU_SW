#pragma once
#include "afxwin.h"


// CFCU_ATK_MODE_CMD ��ȭ �����Դϴ�.

class CFCU_ATK_MODE_CMD : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_ATK_MODE_CMD)

public:
	CFCU_ATK_MODE_CMD(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFCU_ATK_MODE_CMD();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FCU_ATK_MODE_CMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
