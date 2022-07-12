// CModeIO.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "CModeIO.h"
#include "FCU_SWDlg.h"

// CModeIO 대화 상자

IMPLEMENT_DYNAMIC(CModeIO, CDialogEx)

CModeIO::CModeIO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CModeIO, pParent)
	, m_u16HILS_RTN_Connect(FALSE)
{

}

CModeIO::~CModeIO()
{
}

void CModeIO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_CONNECT_STATE, m_staticConnectState);
}


BEGIN_MESSAGE_MAP(CModeIO, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CModeIO 메시지 처리기


BOOL CModeIO::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	this->MoveWindow(0, 80, 960, 720);
	SetBackgroundColor(RGB(0, 0, 0));

	if ((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_bWantExitHILS == TRUE)
	{
		SetConnectState(IDB_TXT_CONNECT_HILS_ESC_01);

		if ((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_bConnectionStateHILS == TRUE)
		{
			// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_DISCONNECT_HILS);
			SetTimer(DISCONNECTION_COMMAND, 500, NULL);
		}
		else
		{
			(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.Init(CONNECTION_IP, CONNECTION_PORT);
			// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_DISCONNECT_HILS);
			SetTimer(CONNECT_AND_DISCONNECT, 500, NULL);
		}
	}

	else
	{
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.Init(CONNECTION_IP, CONNECTION_PORT);
		// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_CONNECT_HILS);
		SetTimer(CONNECTION_COMMAND, 500, NULL);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CModeIO::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	static INT16 cnt = 0;
	INT16 n = cnt % 4;

	switch (nIDEvent)
	{
	case CONNECTION_COMMAND:
		if (cnt > 10)
		{
			KillTimer(CONNECTION_COMMAND);
			SetConnectState(IDB_TXT_CONNECT_HILS_FAIL);
			m_u8CNNCT_RSLT = 0x0F;
			m_u16HILS_RTN_Connect = FALSE;
			cnt = 0;
			Sleep(1200);
			CDialogEx::OnOK();
		}
		else
		{
			if (cnt % 2 == 0)
			{
				(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_CONNECT_HILS);
			}

			if (m_u16HILS_RTN_Connect == TRUE)
			{
				cnt = 0;

				m_u8CNNCT_RSLT = 0xFF;
				KillTimer(CONNECTION_PORT);

				CDialogEx::OnOK();
			}
			else
			{
				SetConnectState(IDB_TXT_CONNECT_HILS_01 + n);
				cnt++;
			}
		}

		break;

	case DISCONNECTION_COMMAND:
		if (cnt > 10)
		{
			KillTimer(DISCONNECTION_COMMAND);
			SetConnectState(IDB_TXT_CONNECT_HILS_ESC_FAIL);
			(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_bWantExitHILS = FALSE;
			m_u8DSCNNCT_RSLT = 0x00;
			m_u16HILS_RTN_Disconnect = FALSE;
			cnt = 0;
			Sleep(1200);
			CDialogEx::OnOK();
		}
		else
		{
			if (cnt % 2 == 0)
			{
				(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_DISCONNECT_HILS);
			}

			if (m_u16HILS_RTN_Disconnect == TRUE)
			{
				cnt = 0;

				KillTimer(DISCONNECTION_COMMAND);
				m_u8DSCNNCT_RSLT = 0xF0;

				CDialogEx::OnOK();
			}
			else
			{
				SetConnectState(IDB_TXT_CONNECT_HILS_ESC_01 + n);
				cnt++;
			}
		}
		break;

	case CONNECT_AND_DISCONNECT:
		if (cnt > 10)
		{
			KillTimer(CONNECT_AND_DISCONNECT);
			SetConnectState(IDB_TXT_CONNECT_HILS_ESC_FAIL);
			(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_bWantExitHILS = FALSE;
			m_u8DSCNNCT_RSLT = 0x00;
			m_u16HILS_RTN_Connect = FALSE;
			m_u16HILS_RTN_Disconnect = FALSE;
			cnt = 0;
			Sleep(1200);
			CDialogEx::OnOK();
		}
		else
		{
			if ((m_u16HILS_RTN_Connect == FALSE) && (m_u16HILS_RTN_Disconnect == FALSE))
			{
				(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_CONNECT_HILS);
			}
			else if ((m_u16HILS_RTN_Connect == TRUE) && (m_u16HILS_RTN_Disconnect == FALSE))
			{
				(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_ClientSocket_HILS.SendCommand(HEADER_DISCONNECT_HILS);
			}
			else if ((m_u16HILS_RTN_Connect == TRUE) && (m_u16HILS_RTN_Disconnect == TRUE))
			{
				cnt = 0;

				KillTimer(CONNECT_AND_DISCONNECT);

				m_u8DSCNNCT_RSLT = 0xF0;

				CDialogEx::OnOK();
			}

			SetConnectState(IDB_TXT_CONNECT_HILS_ESC_01 + n);
			cnt++;
		}

		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CModeIO::SetConnectState(UINT16 wParam)
{
	// TODO: 여기에 구현 코드 추가.
	CStatic* m_pPicture = (CStatic*)GetDlgItem(IDC_STATIC_CONNECT_STATE);
	CBitmap new_image;

	new_image.LoadBitmapW(wParam);

	// Picture 컨트롤에 새로 읽어들인 이미지를 설정하고 이전에 사용하던 이미지 핸들을
		// p_old_ bitmap 변수에 저장한다.
	HBITMAP h_old_bitmap = m_pPicture->SetBitmap(new_image);

	// Picture 컨트롤이 이전에 사용하던 이미지가 있었다면 제거한다.
	if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);

	// Picture 컨트롤에 이미지를 설정하기 위해서 생성했던 이미지는 Picture 컨트롤이

   //사용하기 때문에 lamp_image 객체가 종료되면서 삭제되지 않도록 연결을 해제한다.
   // 이 코드를 사용하지 않아도 되는 것처럼 보이지만 해당 Picture 컨트롤이 가려졌다가
   // 다시 보이게 되는 경우 그림이 그려지지 않는다. 따라서 꼭 사용해야 합니다. 
	new_image.Detach();

	//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->PostMessageW(WM_SELECT_MODE, NULL, NULL);
	//KillTimer(CONNECTION_PORT);
	//CDialogEx::OnOK();
}


BOOL CModeIO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
