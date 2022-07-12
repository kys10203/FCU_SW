#pragma once


// CDlgMSL_BIT_03 대화 상자입니다.

class CDlgMSL_BIT_03 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMSL_BIT_03)

public:
	CDlgMSL_BIT_03(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMSL_BIT_03();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSL_BIT_03 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
