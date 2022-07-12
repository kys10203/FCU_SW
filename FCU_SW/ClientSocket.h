#pragma once
#include <stdio.h>
#include <WinSock2.h>
#include "FCU_SW.h"
#include "FCU_Define.h"
#include <mstcpip.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32")

class CClientSocket : public CSocket
{
public:
    CClientSocket();
    virtual ~CClientSocket();
    void SetWnd(HWND hWnd);
    //    virtual void OnReceive(int nErrorCode);
    BOOL Init(CString ip, u_short port);
    WSADATA wsaData;
    SOCKADDR_IN tAddr;
    void End(void);
    BOOL bSocketOpen;
    S16BIT retVal;
    tcp_keepalive tcpkl;
    linger lingerOption;
    DWORD dwRet;
    U8BIT SendCommand(U16BIT msgType);
    WORD CRC_XMODEM_UPDATE(WORD crc, U8BIT data);
    WORD Calc_CRC(BYTE* msg, U32BIT n);
    WORD m_u16AtkMode;
    HWND m_hWnd;
    SOCKADDR_IN locAddr;
    int connectTo(SOCKET s, CString host, int port);
};


