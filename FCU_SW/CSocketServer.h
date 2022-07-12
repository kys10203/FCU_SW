#pragma once

// CSocketServer 명령 대상

class CSocketServer : public CAsyncSocket
{
public:
	CSocketServer();
	virtual ~CSocketServer();

	CPtrList m_ptrClientSocketList;
	virtual void OnAccept(int nErrorCode);
	void CloseClientSocket(CSocket* pClient);
	void SendData(WORD msgType);
	virtual void OnConnect(int nErrorCode);
	WORD Calc_CRC(BYTE* msg, UINT32 len);
	WORD CRC_XMODEM_UPDATE(WORD crc, UINT8 data);
	virtual void OnClose(int nErrorCode);
	INT16 SetKeepalive();
	int temp;
	DWORD optval;
};


