#pragma once


// CDlgMSL_BIT_03 ��ȭ �����Դϴ�.

class CDlgMSL_BIT_03 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_03)

public:
	CDlgMSL_BIT_03(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMSL_BIT_03();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSL_BIT_03 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    virtual BOOL OnInitDialog();
    CString m_strGCU_ADC;
    CString m_strGCU_SRAM;
    CString m_strGCU_FLASH;
    CString m_strGCU_R2GYRO;
    CString m_strGCU_POW;
    CString m_strGCU_FPGA;
};
