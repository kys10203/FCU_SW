// ClientSocket.cpp : 구현 파일입니다.
#include "stdafx.h"
#include "ClientSocket.h"
#include "FCU_SWDlg.h"

// CClientSocket
CFCU_SWDlg m_FCU_SWDlg;

CClientSocket::CClientSocket()
	: bSocketOpen(FALSE)
	, retVal(0)
	, dwRet(0)
{
}

CClientSocket::~CClientSocket()
{
}


BOOL CClientSocket::Init(CString ip, u_short port)
{
	tcp_keepalive tcpkl;
	linger lingerOption;
	DWORD dwRet = 0;
	BOOL bNoDelay = TRUE;
	CString strTmp;
	unsigned long nonBlockingMode = 1;
	INT32 ret = 0;

	//----------------------
	// Initialize Winsock
	WSADATA wsaData;

	if (bSocketOpen == TRUE)
	{
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->killAllTimer();

		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("설정 된 소켓을 해제합니다"));

		closesocket(m_hSocket);
		m_hSocket = INVALID_SOCKET;

		bSocketOpen = FALSE;

		return SOCKET_ERROR;
	}

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != NO_ERROR) {
		strTmp.Format(_T("WSAStartup function failed with error: %d"), iResult);
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(strTmp);
		return SOCKET_ERROR;
	}
	//----------------------
	// Create a SOCKET for connecting to server
	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_hSocket == INVALID_SOCKET) {
		strTmp.Format(_T("socket function failed with error: %ld"), WSAGetLastError());
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(strTmp);
		WSACleanup();
		return SOCKET_ERROR;
	}

	//----------------------
	// The sockaddr_in structure specifies the address family,
	// IP address, and port of the server to be connected to.
	tAddr.sin_family = AF_INET;
	tAddr.sin_addr.s_addr = inet_addr((CStringA)ip);
	tAddr.sin_port = htons(port);

	locAddr.sin_family = AF_INET;
	locAddr.sin_addr.s_addr = inet_addr((CStringA)LOCAL_IP);
	locAddr.sin_port = htons(LOCAL_PORT);

	WSAAsyncSelect(m_hSocket, (reinterpret_cast<CWnd*>(AfxGetMainWnd()))->m_hWnd, WM_RECEIVE_EVENT_HILS, FD_CONNECT);
	bSocketOpen = TRUE;
	//----------------------
	// Connect to server.

	int optval = 1;
	setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&optval, sizeof(optval));

	ret = bind(m_hSocket, (struct sockaddr*)&locAddr, sizeof(struct sockaddr));

	// NONBLOCK으로 변경
	ret = ::ioctlsocket(m_hSocket, FIONBIO, &nonBlockingMode);

	if (ret == INVALID_SOCKET)
		return 0;


	strTmp.Format(_T("ioctlsocket return value: %ld"), ret);
	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(strTmp);

	while (true)
	{
		if (::connect(m_hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr)) == SOCKET_ERROR)
		{

			// 원래 블록했어야 했는데... 너가 논블로킹으로 하라며?
			//strTmp.Format(_T("ioctlsocket return value: %ld"), ::WSAGetLastError());
			//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(strTmp);

			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;

			// 이미 연결된 상태라면 break
			if (::WSAGetLastError() == WSAEISCONN)
			{
				(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("WSAEISCONN"));
				break;
			}

			Sleep(250);
			// Error
			break;
		}
	}

	tcpkl.onoff = 1;    // KEEPALIVE ON
	tcpkl.keepalivetime = 3000; // 1초 마다 KEEPALIVE 신호를 보냄
	tcpkl.keepaliveinterval = 1000;

	memset(&lingerOption, NULL, sizeof(lingerOption));
	lingerOption.l_onoff = 1;
	lingerOption.l_linger = 0;

	WSAIoctl(m_hSocket, SIO_KEEPALIVE_VALS, &tcpkl, sizeof(tcpkl), 0, 0, &dwRet, NULL, NULL);
	setsockopt(m_hSocket, SOL_SOCKET, SO_LINGER, (char*)&lingerOption, sizeof(lingerOption));
	setsockopt(m_hSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&bNoDelay, sizeof(bNoDelay));

	WSAAsyncSelect(m_hSocket, (reinterpret_cast<CWnd*>(AfxGetMainWnd()))->m_hWnd, WM_RECEIVE_EVENT_HILS, FD_READ | FD_CLOSE);

	WSACleanup();

	return TRUE;
}



void CClientSocket::End(void)
{
	closesocket(m_hSocket);

	WSACleanup();
}


U8BIT CClientSocket::SendCommand(U16BIT msgType)
{
	U8BIT retVal = 0;
	U8BIT CmdLen_Byte = 0;
	WORD CRC = 0;
	uCommandType uCommand;
	int nCmdIndex = 0;
	WORD m_wEXTPOW = (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_wEXTPOW;

	if (bSocketOpen == FALSE)
	{
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("ERROR : need to open socket"));

		return 0;
	}

	memset(uCommand.bCommand, 0, sizeof(uCommand));

	switch (msgType)
	{
	case HEADER_CONNECT_HILS:
		uCommand.wCommand[nCmdIndex++] = htons(0x1001);
		uCommand.wCommand[nCmdIndex++] = htons(0x2B40);
		uCommand.wCommand[nCmdIndex++] = htons(0x0025);
		uCommand.wCommand[nCmdIndex++] = htons(0x0100);
		uCommand.wCommand[nCmdIndex++] = 0x0F;
		Send(uCommand.bCommand, (nCmdIndex * 2) - 1);
		memset(uCommand.bCommand, 0, sizeof(uCommand));
		nCmdIndex = 0;
		return 0;
		break;
	case HEADER_DISCONNECT_HILS:
		uCommand.wCommand[nCmdIndex++] = htons(0x1001);
		uCommand.wCommand[nCmdIndex++] = htons(0x2B40);
		uCommand.wCommand[nCmdIndex++] = htons(0x0025);
		uCommand.wCommand[nCmdIndex++] = htons(0x0100);
		uCommand.wCommand[nCmdIndex++] = 0x00;
		Send(uCommand.bCommand, (nCmdIndex * 2) - 1);
		memset(uCommand.bCommand, 0, sizeof(uCommand));
		nCmdIndex = 0;
		return 0;
		break;
	}
	int ret = Send(uCommand.bCommand, nCmdIndex * 2);

	memset(uCommand.bCommand, 0, sizeof(uCommand));
	nCmdIndex = 0;

	return 0;
}


WORD CClientSocket::Calc_CRC(BYTE* msg, U32BIT len)
{
	WORD wRecvedCRC = 0;

	while (len--)
	{
		wRecvedCRC = CRC_XMODEM_UPDATE(wRecvedCRC, (WORD)*msg++);
	}

	return wRecvedCRC;
}


WORD CClientSocket::CRC_XMODEM_UPDATE(WORD crc, U8BIT data)
{
	int idx;

	crc = crc ^ ((WORD)data << 8);

	for (idx = 0; idx < 8; idx++)
	{
		if (crc & 0x8000)
		{
			crc = (crc << 1) ^ (WORD)VAL_POLY;
		}
		else
		{
			crc <<= 1;
		}
	}

	return crc;
}


int CClientSocket::connectTo(SOCKET s, CString host, int port)
{
	return TRUE;
}
