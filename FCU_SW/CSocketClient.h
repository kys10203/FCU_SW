#pragma once

// CSocketClient 명령 대상

class CSocketClient : public CSocket
{
public:
	CSocketClient();
	virtual ~CSocketClient();
	void SetListenSocket(CAsyncSocket* pSocket);

	CAsyncSocket* m_pSocketServer;	// CSocketServer 클래스 객체의 주소를 저장하는 멤버
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	BYTE m_bBuffer[1024];
};


