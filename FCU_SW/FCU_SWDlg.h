
// FCU_SWDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "atlimage.h"
#include "atltypes.h"
#include "fcu_atk_mode_cmd.h"
#include "FCU_MODE_SELECT.h"
#include "RecvView.h"
#include "afxext.h"
#include "ClientSocket.h"
#include <string>
#include <thread>
#include "ATK_MODE_CMD.h"
#include "LOCK_ON_CMD.h"
#include "MSL_BIT_CHK.h"
#include "MSL_ID_CHK.h"
#include "MSL_STS_CHK.h"
#include "SKR_CAGE_CMD.h"
#include "SKR_PLC_CHK.h"
#include "SKR_RDY_CHK.h"
#include "SKR_TRK_STATUS.h"
#include "FCU_STS_Dlg.h"
#include "CModeIO.h"
#include "CSocketServer.h"
#include "CSocketClient.h"
#include "ShowWarning.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types_c.h>

using namespace cv;
using std::thread;

class CFCU_SWDlgAutoProxy;


// CFCU_SWDlg 대화 상자
class CFCU_SWDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFCU_SWDlg);
	friend class CFCU_SWDlgAutoProxy;

	// 생성입니다.
public:
	CFCU_SWDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	virtual ~CFCU_SWDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_FCU_SW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	CFCU_SWDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	CMSL_BIT_CHK* m_ptMSL_BIT_CHK;
	CSKR_CAGE_CMD* m_ptSKR_CAGE_CMD;
	CMSL_ID_CHK* m_ptMSL_ID_CHK;
	CSKR_RDY_CHK* m_ptSKR_RDY_CHK;
	CSKR_PLC_CHK* m_ptSKR_PLC_CHK;
	CLOCK_ON_CMD* m_ptLOCK_ON_CMD;
	CSKR_TRK_STATUS* m_ptSKR_TRK_STATUS;
	CATK_MODE_CMD* m_ptATK_MODE_CMD;
	CMSL_STS_CHK* m_ptMSL_STS_CHK;
	CModeIO m_pModeIO;
	CShowWarning* m_pShowWarning;

	BOOL m_bMSL_BIT_CHK;
	BOOL m_bSKR_CAGE_CMD;
	BOOL m_bMSL_ID_CHK;
	BOOL m_bSKR_RDY_CHK;
	BOOL m_bSKR_PLC_CHK;
	BOOL m_bLOCK_ON_CMD;
	BOOL m_bSKR_TRK_STATUS;
	BOOL m_bATK_MODE_CMD;
	BOOL m_bMSL_STS_CHK;

	CStatic m_staticTitle;
	CStatic m_staticMode;
	CStatic m_staticMslStat;
	CStatic m_staticLnchStat;
	CStatic m_staticBright;
	CStatic m_staticContrast;
	CStatic m_staticGas;
	CStatic m_staticWarn;

	CStatic m_imgCam;

	CImage m_img;
	CImage m_imgTitle;
	CImage m_imgMode;
	CImage m_imgMslStat;
	CImage m_imgLnchStat;
	CImage m_imgBright;
	CImage m_imgContrast;
	CImage m_imgGas;
	CImage m_imgWarn;

	CRect m_rect;
	void TransparentPNG(CImage* png);
	BOOL MyLoadFromResource(CImage& img, LPCTSTR pName, LPCTSTR pType, HMODULE hInst);

	BOOL SetTitle(UINT16 state);
	BOOL SetMode(UINT16 state);
	BOOL SetMslStat(UINT16 state);
	BOOL SetLnchStat(UINT16 state);
	BOOL SetFixResource(UINT16 state);
	BOOL SetBrightness(UINT16 state);
	BOOL SetContrast(UINT16 state);
	BOOL SetGas(UINT16 state);
	BOOL SetWarn(UINT16 state);

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBitmapButton m_btnMslBitChkTest;
	CBitmapButton m_btnMslIdChk;
	CBitmapButton m_btnSkrRdyChk;
	CBitmapButton m_btnLockOnCmd;
	CBitmapButton m_btnAtkModeCmd;
	CBitmapButton m_btnCUSQTest;
	CBitmapButton m_btnMslStsChk;
	CBitmapButton m_btnLiftoffRdyCmd;
	CBitmapButton m_btnRdyRelease;
	CBitmapButton m_btnRdyInjection;
	CBitmapButton m_btnLaunch;
	CBitmapButton m_btnUp;
	CBitmapButton m_btnLeft;
	CBitmapButton m_btnRight;
	CBitmapButton m_btnDown;
	CBitmapButton m_btnCenter;

	CBitmapButton m_btnModeDryrun;
	CBitmapButton m_btnModeLaunch;
	CBitmapButton m_btnEMSQ;
	CBitmapButton m_btnReLockOnCmd;
	CBitmapButton m_btnPower;
	CBitmapButton m_btnCusqD;
	CBitmapButton m_btnCancelDlg;
	CBitmapButton m_btnChangeMode;

	afx_msg void OnBnClickedBtnModeDryrun();
	afx_msg void OnBnClickedBtnModeLaunch();
	BOOL bPaintOnce;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CImage m_imgMSLCON;

	afx_msg void OnBnClickedOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	HACCEL m_hAccel;
	BOOL m_bLaunch;
	afx_msg void OnBnClickedAtkModeCmd();
	CFCU_ATK_MODE_CMD m_CAtkModeCmd;
	CFCU_MODE_SELECT* m_ptCModeSelect;
	WORD m_u16AtkMode;
	afx_msg void OnMenuDryrun();
	afx_msg void OnMenuLaunch();
	CImage m_imgPINCHK;
	CStatic m_staticMSLCON;
	CStatic m_staticPINCHK;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCancelDlg();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnAcceleratorF1();
	UINT8 m_u8Mode;
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

	afx_msg void OnBnClickedChangeMode();
	afx_msg void OnBnClickedBtnLaunch();
	UINT8 m_u8LaunchStat;
	afx_msg void OnAcceleratorF2();
	afx_msg void OnAcceleratorF3();
	CBitmapButton m_btnSkrCageCmdTest;
	CBitmapButton m_btnSkrPlcChkTest;
	CBitmapButton m_btnSkrTrkStatusTest;
	CBitmapButton m_btnBATSQTest;
	CBitmapButton m_btnPINSQTest;
	afx_msg void OnStnClickedLedMslBitChkTest();
	afx_msg void OnStnClickedLedCusqTest();
	afx_msg void OnStnClickedLedSkrCageCmdTest();
	afx_msg void OnStnClickedLedSkrCageCmd();
	afx_msg void OnStnClickedLedMslIdChkTest();
	afx_msg void OnStnClickedLedSkrRdyChkTest();
	afx_msg void OnStnClickedLedSkrPlcChkTest();
	afx_msg void OnStnClickedLedSkrPlcChk();
	afx_msg void OnStnClickedLedSkrTrkStatusTest();
	afx_msg void OnStnClickedLedSkrTrkStatus();
	afx_msg void OnStnClickedLedMslStsChkTest();
	afx_msg void OnStnClickedLedLiftoffRdyCmd();
	afx_msg void OnStnClickedLedPinsq();
	afx_msg void OnStnClickedLedPinsqTest();
	afx_msg void OnStnClickedLedEmsqTest();
	afx_msg void OnBnClickedBtnPower();
	CClientSocket m_ClientSocket;
	CClientSocket m_ClientSocket_HILS;
	afx_msg void OnBnClickedLockOnCmd();
	bool IsHex(const std::string& str);
	int asc2hex(BYTE* hex, int start, int end);

protected:
	afx_msg LRESULT OnClientRecv(WPARAM wParam, LPARAM lParam);

public:
	afx_msg void OnBnClickedReLockOnCmd();
protected:
	afx_msg LRESULT OnConnectEvent(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReceiveEvent(WPARAM wParam, LPARAM lParam);
public:
	S8BIT s8ConnectStat;
	int ParseData(BYTE* buf, U16BIT len, U16BIT recvLen);
	CButton m_btnModeTest;
	afx_msg void OnBnClickedBtnModeTest();
	CBitmapButton m_btnTryConnect;
	afx_msg void OnBnClickedBtnTryConnect();

	afx_msg void OnBnClickedBtnUp();
	afx_msg void OnBnClickedBtnLeft();
	afx_msg void OnBnClickedBtnRight();
	afx_msg void OnBnClickedBtnDown();
	afx_msg void OnBnClickedBtnMslBitChk();
	afx_msg void OnBnClickedBtnCusq();
	afx_msg void OnBnClickedBtnSkrCageCmd();
	afx_msg void OnBnClickedBtnMslIdChk();
	afx_msg void OnBnClickedBtnSkrRdyChk();
	afx_msg void OnBnClickedBtnSkrPlcChk();
	afx_msg void OnBnClickedBtnSkrTrkStatus();
	afx_msg void OnBnClickedBtnMslStsChk();
	afx_msg void OnBnClickedBtnLiftoffRdyCmd();
	afx_msg void OnBnClickedBtnPinsq();
	afx_msg void OnBnClickedBtnEmsq();
	afx_msg void OnBnClickedBtnBatsq();
	afx_msg void OnBnClickedCancel();
	BOOL m_bAtkModeCmdDlg;
	CStatic m_ledTCP;
	CStatic m_ledUDP;
	void ChangeLED(CStatic* icon, U16BIT flag);

	WORD m_wEXTPOW;
	CRecvView* m_pRecvView;
	CFCU_STS_Dlg* m_pFCU_STS_Dlg;
	CRect m_rectMainDlg;

	afx_msg void OnMove(int x, int y);
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	uMSL_BIT_CHK m_uMSL_BIT_CHK;
	CStatic m_ledMSL_BIT_CHK_TEST;
	CStatic m_ledCUSQ;
	CStatic m_ledCUSQ_TEST;
	CStatic m_ledSKR_CAGE_CMD;
	CStatic m_ledMSL_ID_CHK_TEST;
	CStatic m_ledSKR_RDY_CHK_TEST;
	CStatic m_ledSKR_PLC_CHK_TEST;
	CStatic m_ledSKR_PLC_CHK;
	CStatic m_ledSKR_TRK_STATUS_TEST;
	CStatic m_ledSKR_TRK_STATUS;
	CStatic m_ledBATSQ_TEST;
	CStatic m_ledMSL_STS_CHK_TEST;
	CStatic m_ledBATSQ;
	CStatic m_ledMSL_STS_CHK;
	CStatic m_ledLIFTOFF_RDY_CMD_TEST;
	CStatic m_ledLIFTOFF_RDY_CMD;
	CStatic m_ledPINSQ;
	CStatic m_ledPINSQ_TEST;
	CStatic m_ledEMSQ_TEST;

	uEXT_POW_ON m_uEXT_POW_ON;
	uSKR_CAGE_CMD m_uSKR_CAGE_CMD;
	uMSL_ID_CHK m_uMSL_ID_CHK;
	uSKR_RDY_CHK m_uSKR_RDY_CHK;
	uSKR_PLC_CHK m_uSKR_PLC_CHK;
	uLOCK_ON_CMD m_uLOCK_ON_CMD;
	uLOCK_ON_CMD m_uRE_LOCK_ON_CMD;
	uSKR_TRK_STATUS m_uSKR_TRK_STATUS;
	uATK_MODE_CMD m_uATK_MODE_CMD;
	uBATSQ m_uBATSQ;
	uMBAT_ON m_uMBAT_ON;
	uABAT_ON m_uABAT_ON;
	uMSL_STS_CHK m_uMSL_STS_CHK;
	uCMD_RSLT m_uLIFTOFF_RDY_CMD;
	uCMD_RSLT m_uPINSQ;
	uCMD_RSLT m_uEMSQ;
	uCMD_RSLT m_uCUSQ;
	uFCU_BIT_CHK m_uFCU_BIT_CHK;
	uEXT_POW_CHK m_uEXT_POW_CHK;
	uABAT_POW_CHK m_uABAT_POW_CHK;
	uMBAT_POW_CHK m_uMBAT_POW_CHK;
	uMSLCON_CHK m_uMSLCON_CHK;
	uPINCHK_CHK m_uPINCHK_CHK;

	CStatic m_btnHidden;
	afx_msg void OnStnClickedBtnHidden();
	BOOL m_bRecvView;
	afx_msg void OnStnClickedimglnchstat();
	void setEnableBTN(BOOL flag);

	void updateFCU_BIT_CHK(void);
	void updatePOW_CHK(WORD header, WORD vol, WORD cur);
	void updateMSL_BIT_CHK(void);
	void updateSKR_CAGE_CMD(void);
	void updateSKR_RDY_CHK(void);
	void updateSKR_PLC_CHK(void);
	void updateSKR_TRK_STATUS(void);
	void updateMSL_STS_CHK(void);
	void updateLIFTOFF_RDY_CMD(void);

	CStatic m_txtVAL_V1;
	CStatic m_txtVAL_A1;
	CStatic m_txtVAL_V2;
	CStatic m_txtVAL_V3;
	CStatic m_txtVAL_A2;
	CStatic m_txtVAL_A3;
	void killAllTimer(void);
	U16BIT u16LED_Cnt;
	BOOL bLED_State;

	CBitmapButton m_btnDISC_TEST_MODE_SET;
	afx_msg void OnBnClickedBtnDiscBit();
	uDISC_TEST_MODE_SET m_uDISC_TEST_MODE_SET;
	BOOL bDISC_TEST_MODE_SET;
	CStatic m_ledMSLCON;
	CStatic m_ledPINCHK;
	void everyLEDOff(void);
	CBitmapButton m_btnGstreamer;

	SOCKET m_hSocket;

	afx_msg void OnStnClickedLedCusq();
	afx_msg void OnStnClickedLedMslIdChk();
	afx_msg void OnStnClickedLedBatsqTest();
	afx_msg void OnStnClickedLedBatsq();
	afx_msg void OnStnClickedLedMslStsChk();
	afx_msg void OnStnClickedLedLiftoffRdyCmdTest();
	afx_msg void OnStnClickedLedEmsq();
	afx_msg void OnStnClickedLedMslBitChk();
	afx_msg void OnStnClickedLedSkrRdyChk();
	afx_msg void OnBnClickedBtnSkrTrkStatusTest();

	CStatic m_ledMSL_BIT_CHK;
	CStatic m_ledSKR_RDY_CHK;
	CStatic m_ledSKR_CAGE_CMD_TEST;
	CStatic m_ledEMSQ;
	CStatic m_ledMSL_ID_CHK;

	// 좌표_OpenCV
	INT16 s16AimRT_X;
	INT16 s16AimRT_Y;
	INT16 s16AimLB_X;
	INT16 s16AimLB_Y;

	// 좌표_MSL
	INT32 m_s16LB_X;
	INT32 m_s16LB_Y;
	INT32 m_s16RT_X;
	INT32 m_s16RT_Y;

	Mat m_matMain;
	BITMAPINFO* m_pBitmapInfo;
	void CreateBitmapInfo(int w, int h, int bpp);
	void DrawImage(int control, cv::Mat* buffer);
	CImage m_cimgCam;
	cv::VideoCapture* m_pVC_Cam;
	Mat m_matTmp;
	Scalar m_sclAim;
	Scalar m_sclAimResult;
	INT16 convertMSL2CV(INT16 num, UINT8 axisCase);

	S16BIT m_s16SX_CAM;
	S16BIT m_s16SY_CAM;
	S16BIT m_s16EX_CAM;
	S16BIT m_s16EY_CAM;
	S16BIT m_s16YAW_CAM;
	S16BIT m_s16PITCH_CAM;

	BOOL m_bRE_ROCK_ON_Flag;
	void KillSKR_TRK_STATUS(void);
	BOOL m_bModifyAxis;
	CWinThread* m_pThread;
	static UINT  CamDataRecv(LPVOID _mothod);
	HANDLE m_hThread;
	void DestroyThread();
	CString m_strPLC_VALUE;
	CString m_strAimSize_X;
	CString m_strAimSize_Y;
	INT16 convertCV2MSL(INT16 num, UINT8 axisCase);
	afx_msg void OnBnClickedBtnGstreamer();
	BOOL m_bSKR_IMG_CTRL;
	WORD m_wMBATABAT;

	BOOL m_bBAT_STAT;
	CString m_strImgVal;
	afx_msg void OnBnClickedBtnSendImgVal();
	void LoadnDraw();
	UINT8 m_u8HILS_ConnectingERR;
	afx_msg void OnAcceleratorAltP();
	afx_msg void OnAcceleratorAltA();
	afx_msg void OnBnClickedBtnFold();
	afx_msg void OnAcceleratorFold();
	BOOL m_bFCU_STS_Dlg;
	CStatic m_LED_L1;
	CStatic m_LED_L2;
	CStatic m_LED_L3;
	CStatic m_LED_L4;
	CStatic m_LED_L5;
	CStatic m_LED_L6;
	CStatic m_LED_L7;
	afx_msg void OnBnClickedBtnCenter();
	afx_msg void OnAcceleratorSpace();
	BOOL resetValue();
	afx_msg void OnAcceleratorAltL();
	UINT16 m_u16currentCMD;
	CStatic m_staticSkrStat;
	BOOL SetSkrStat(UINT16 state);
	afx_msg void OnStnClickedimgmode();
	afx_msg void OnAcceleratorF6();
	afx_msg void OnAcceleratorAltF();
protected:
	afx_msg LRESULT OnSelectMode(WPARAM wParam, LPARAM lParam);
public:
	BOOL m_bModeIO;
	void DP_selectingMode();
	BOOL m_bCModeSelect;
protected:
	afx_msg LRESULT OnSetLaunchMode(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetDryrunMode(WPARAM wParam, LPARAM lParam);
public:
	uPINCHK_MSLCON m_uPINCHK_MSLCON;
	afx_msg void OnAcceleratorF10();

	CSocketServer m_SocketServer;
	afx_msg void OnDestroy();
	afx_msg void OnStnClickedimgtitle();
	BOOL m_bConnection;
protected:
	afx_msg LRESULT OnCloseEvent(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReceiveEventHils(WPARAM wParam, LPARAM lParam);
public:
	BOOL m_bConnectionStateHILS;
	BYTE m_bBuffer[1024];
	DWORD optval;
	int temp;
	CStatic m_LampSkrRdy;
protected:
	afx_msg LRESULT OnClientDisconnect(WPARAM wParam, LPARAM lParam);
public:
	void SetInitialDlg();
	afx_msg void OnAcceleratorF4();
	afx_msg void OnAcceleratorAltC();
	UINT8 m_u8FCU_BIT_CNT;
	UINT8 m_u8MslStat;
	CBitmapButton m_btnMbatOn;
	afx_msg void OnBnClickedBtnPowerMbat();
	WORD m_wMBATPOW;
	BOOL m_bSetGasOnce;
	BOOL m_bSkrRecvFlag;
	BOOL m_bDisplayMSL_BIT;
	BOOL m_bDisplaySKR_CAGE;
	BOOL m_bDisplayMSL_ID;
	BOOL m_bDisplaySKR_RDY;
	BOOL m_bDisplaySKR_PLC;
	BOOL m_bDisplaySKR_TRK;
	BOOL m_bDisplayMSL_STS;
	BOOL SetSkrLamp(UINT16 state);
	UINT8 m_u8LampStat;
	UINT8 m_u8GasCnt;
	CString m_strRUX;
	CString m_strRUY;
	CString m_strLLX;
	CString m_strLLY;
	BOOL m_bWantExitHILS;
	BOOL m_bThreadCamDataRecv;
	UINT8 m_u8ClientCnt;
	UINT8 m_u8MaxSkrRdyTime;

	// T자 전시 플래그, 추적창 전시 플래그, 조준창 전시 플래그
	BOOL m_bAimT;
	BOOL m_bAimTracking;
	BOOL m_bAimSight;
	UINT8 m_u8MslTestFlag;
	void ResetAim();
	BOOL m_bLOCK_ON_RSLT_FAULT;
	BOOL m_bRE_ROCK_ON_LED_Flag;
	void ShowMSL_FAIL();
	BOOL m_bShowWarning;
	UINT16 Byte2WORD(UINT8* byte);
};
