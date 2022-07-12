// CSocketClient.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "CSocketClient.h"
#include "CSocketServer.h"
#include "FCU_SWDlg.h"

// CSocketClient

CSocketClient::CSocketClient()
{
	m_pSocketServer = NULL;
}

CSocketClient::~CSocketClient()
{
}


// CSocketClient 멤버 함수


void CSocketClient::SetListenSocket(CAsyncSocket* pSocket)
{
	// TODO: 여기에 구현 코드 추가.
	m_pSocketServer = pSocket;
}


void CSocketClient::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CSocket::OnClose(nErrorCode);

	CFCU_SWDlg* pMain = (CFCU_SWDlg*)AfxGetMainWnd();
	pMain->PostMessageW(WM_CLOSE_EVENT, FD_CLOSE, NULL);
	CSocketServer* pServerSocket = (CSocketServer*)m_pSocketServer;
	pServerSocket->CloseClientSocket(this);
}


void CSocketClient::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString strTmp = _T("");
	CString strIPAdress = _T("");
	UINT uPortNumber = 0;
	CFCU_SWDlg* pMain = (CFCU_SWDlg*)AfxGetMainWnd();
	UINT16 len = 0;

	::ZeroMemory(m_bBuffer, sizeof(m_bBuffer));

	GetPeerName(strIPAdress, uPortNumber);

	len = Receive(m_bBuffer, sizeof(m_bBuffer));

	if (len > 0)
	{
		memcpy(pMain->m_bBuffer, m_bBuffer, len);
		pMain->PostMessageW(WM_RECEIVE_EVENT, FD_READ, len);
	}

	// pMain->m_pRecvView->AddEventString(strTmp);

	CSocket::OnReceive(nErrorCode);
}


void CSocketClient::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//CString str;
	//BOOL SockOpt_Keepalive = 1;
	//BOOL SockOpt_Nodelay = 1;
	//int a = 0;

	//CFCU_SWDlg* pMain = (CFCU_SWDlg*)AfxGetMainWnd();

	//pMain->m_pRecvView->AddEventString(_T("OnConnect"));

	//if (a = setsockopt(this->m_hSocket, SOL_SOCKET, SO_KEEPALIVE, (char*)&SockOpt_Keepalive, sizeof(SockOpt_Keepalive)))
	//{
	//	str.Format(_T("ERROR : Set SO_KEEPALIVE %d"), a);
	//	pMain->m_pRecvView->AddEventString(str);
	//}
	//if (a = setsockopt(this->m_hSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&SockOpt_Nodelay, sizeof(SockOpt_Nodelay)))
	//{
	//	str.Format(_T("ERROR : Set TCP_NODELAY %d"), a);
	//	pMain->m_pRecvView->AddEventString(str);
	//}

	//struct tcp_keepalive alive_in = { 0 };
	//struct tcp_keepalive alive_out = { 0 };
	//alive_in.keepalivetime = 2000;
	//alive_in.keepaliveinterval = 500;
	//alive_in.onoff = TRUE;
	//unsigned long nlBytesReturn = 0;

	//if (WSAIoctl(this->m_hSocket,
	//	SIO_KEEPALIVE_VALS,
	//	&alive_in,
	//	sizeof(alive_in),
	//	&alive_out,
	//	sizeof(alive_out),
	//	&nlBytesReturn,
	//	NULL,
	//	NULL) == SOCKET_ERROR)
	//{
	//	str.Format(_T("ERROR : WSAIoctl %d"), GetLastError());
	//	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);

	//	return;
	//}

	//str.Format(_T("SUCCESS : setsockopt"));
	//pMain->m_pRecvView->AddEventString(str);

	CSocket::OnConnect(nErrorCode);
}
