// CSocketServer.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "CSocketServer.h"
#include "CSocketClient.h"
#include "FCU_SWDlg.h"

// CSocketServer

CSocketServer::CSocketServer()
{
}


CSocketServer::~CSocketServer()
{
}


// 클라이언트의 TCP접속이 있을 때 자동으로 호출
void CSocketServer::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CSocketClient* pClient = new CSocketClient;

	if (Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		m_ptrClientSocketList.AddTail(pClient);

		CFCU_SWDlg* pMain = (CFCU_SWDlg*)AfxGetMainWnd();

		pMain->m_pRecvView->AddEventString(_T("OnAccept"));

		pMain->PostMessageW(WM_CONNECT_EVENT, FD_CONNECT, NULL);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("ERROR: Failed to accept new client!"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


// 특정 클라이언트와 접속이 종료되었을 때 통신을 끝내고 클래스 객체 소멸
void CSocketServer::CloseClientSocket(CSocket* pClient)
{
	// TODO: 여기에 구현 코드 추가.
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);

	if (pos != NULL)
	{
		if (pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();
			(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->PostMessageW(WM_CLIENT_DISCONNECT, NULL, NULL);
		}

		m_ptrClientSocketList.RemoveAt(pos);
		delete pClient;
	}
}


void CSocketServer::SendData(WORD msgType)
{	// TODO: 여기에 구현 코드 추가.
	CFCU_SWDlg* pMain = (CFCU_SWDlg*)AfxGetMainWnd();
	if (pMain->m_u8ClientCnt == 0)
	{
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("ERROR : no client"));

		return;
	}

	CString str;
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CSocketClient* pClient = NULL;

	U8BIT retVal = 0;
	U8BIT CmdLen_Byte = 0;
	WORD CRC = 0;
	uCommandType uCommand;
	int nCmdIndex = 0;
	WORD m_wEXTPOW = (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_wEXTPOW;

	pClient = (CSocketClient*)m_ptrClientSocketList.GetHead();

	if ((pos == NULL) || (pClient == NULL))
	{
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("ERROR : need to open socket"));

		return;
	}

	memset(uCommand.bCommand, 0, sizeof(uCommand));

	switch (msgType)
	{
	case HEADER_EXT_POW_ON:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] EXT_POW_ON"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_EXT_POW_ON);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_EXT_POW_ON);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_wEXTPOW);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_OFF_EXT30P:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] EXT_POW_OFF"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_EXT_POW_ON);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_EXT_POW_ON);
		uCommand.wCommand[nCmdIndex++] = htons(DISABLE);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_FCU_BIT_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] FCU_BIT_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_FCU_BIT_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_FCU_BIT_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_EXT_POW_CHK:
		// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] EXT_POW_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_EXT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_EXT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_ABAT_POW_CHK:
		// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] ABAT_POW_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_ABAT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_ABAT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_MBAT_POW_CHK:
		// (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MBAT_POW_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MBAT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MBAT_POW_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_MSL_BIT_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MSL_BIT_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MSL_BIT_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MSL_BIT_CHK);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_SKR_CAGE_CMD:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] SKR_CAGE_CMD"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_SKR_CAGE_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_SKR_CAGE_CMD);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_MSL_ID_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MSL_ID_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MSL_ID_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MSL_ID_CHK);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_SKR_RDY_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] SKR_RDY_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_SKR_RDY_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_SKR_RDY_CHK);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_SKR_PLC_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] SKR_PLC_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_SKR_PLC_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_SKR_PLC_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_u16AtkMode);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
	
		str.Format(_T("RUX : %d, RUY : %d, LLX : %d, LLY : %d"), (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y);
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
		//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X, TYPE_WORD);
		//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y, TYPE_WORD);
		//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X, TYPE_WORD);
		//(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y, TYPE_WORD);
		break;
	case HEADER_LOCK_ON_CMD:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] LOCK_ON_CMD"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_LOCK_ON_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_LOCK_ON_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_u16AtkMode);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);

		str.Format(_T("RUX : %d, RUY : %d, LLX : %d, LLY : %d"), (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X, (reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y);
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
		break;
	case HEADER_RE_LOCK_ON_CMD:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] RE_LOCK_ON_CMD"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_RE_LOCK_ON_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_RE_LOCK_ON_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16RT_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_X) * 100);
		uCommand.wCommand[nCmdIndex++] = htons(((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_s16LB_Y) * 100);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_u16AtkMode);
		uCommand.wCommand[nCmdIndex++] = htons(ZERO_DATA);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_SKR_TRK_STATUS:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] SKR_TRK_STATUS"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_SKR_TRK_STATUS);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_SKR_TRK_STATUS);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_ATK_MODE_CMD:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] ATK_MODE_CMD"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_ATK_MODE_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_ATK_MODE_CMD);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_u16AtkMode);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_BATSQ:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] BATSQ"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_BATSQ);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_BATSQ);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_MBAT_ON:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MBAT_ON"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MABAT_ABAT);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MBAT_ON);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_wMBATABAT);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_ABAT_ON:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] ABAT_ON"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MABAT_ABAT);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_ABAT_ON);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_wMBATABAT);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_MSL_STS_CHK:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MSL_STS_CHK"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MSL_STS_CHK);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MSL_STS_CHK);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_LIFTOFF_RDY_CMD:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] LIFTOFF_RDY_CMD"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_LIFTOFF_RDY_CMD);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_LIFTOFF_RDY_CMD);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_PINSQ:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] PINSQ"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_PINSQ);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_PINSQ);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_EMSQ:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] EMSQ"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_EMSQ);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_EMSQ);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_CUSQ:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] CUSQ"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_CUSQ);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_CUSQ);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_DISC_TEST_MODE_SET:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] DISC_TEST_MODE_SET"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_DISC_TEST_MODE_SET);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_DISC_TEST_MODE_SET);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->bDISC_TEST_MODE_SET);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_SKR_IMG_CTRL:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] SKR_IMG_CTRL"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_SKR_IMG_CTRL);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_SKR_IMG_CTRL);
		uCommand.wCommand[nCmdIndex++] = htons((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_bSKR_IMG_CTRL);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_OFF_MBAT:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] MBAT_OFF"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MABAT_ABAT);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_MBAT_ON);
		uCommand.wCommand[nCmdIndex++] = htons(0x0000);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_OFF_ABAT:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] ABAT_OFF"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_MABAT_ABAT);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_ABAT_ON);
		uCommand.wCommand[nCmdIndex++] = htons(0x0000);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_IMG_VAL:
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(_T("S] IMG_VAL"));
		uCommand.wCommand[nCmdIndex++] = htons(LEN_BATSQ);
		uCommand.wCommand[nCmdIndex++] = htons(HEADER_IMG_VAL);
		uCommand.wCommand[nCmdIndex++] = htons(0);
		CmdLen_Byte = nCmdIndex * 2;
		CRC = Calc_CRC(uCommand.bCommand, CmdLen_Byte);
		uCommand.wCommand[nCmdIndex++] = htons(CRC);
		break;
	case HEADER_CONNECT_HILS:
		uCommand.wCommand[nCmdIndex++] = htons(0x1001);
		uCommand.wCommand[nCmdIndex++] = htons(0x2B40);
		uCommand.wCommand[nCmdIndex++] = htons(0x0025);
		uCommand.wCommand[nCmdIndex++] = htons(0x0100);
		uCommand.wCommand[nCmdIndex++] = 0x0F;
		Send(uCommand.bCommand, (nCmdIndex * 2) - 1);
		memset(uCommand.bCommand, 0, sizeof(uCommand));
		nCmdIndex = 0;
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
		break;
	}

	if ((pos == NULL) || (pClient == NULL))
		return;
	else
		pClient->Send(uCommand.bCommand, nCmdIndex * 2);

	memset(uCommand.bCommand, 0, sizeof(uCommand));
	nCmdIndex = 0;

	return;
}


void CSocketServer::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CAsyncSocket::OnConnect(nErrorCode);
}


WORD CSocketServer::Calc_CRC(BYTE* msg, UINT32 len)
{
	// TODO: 여기에 구현 코드 추가.
	WORD wRecvedCRC = 0;

	while (len--)
	{
		wRecvedCRC = CRC_XMODEM_UPDATE(wRecvedCRC, (WORD)*msg++);
	}

	return wRecvedCRC;
}


WORD CSocketServer::CRC_XMODEM_UPDATE(WORD crc, UINT8 data)
{
	// TODO: 여기에 구현 코드 추가.
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


void CSocketServer::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CAsyncSocket::OnClose(nErrorCode);
}


INT16 CSocketServer::SetKeepalive()
{
	// TODO: 여기에 구현 코드 추가.
	CString str;
	BOOL SockOpt_Keepalive = 1;
	BOOL SockOpt_Nodelay = 1;
	temp = sizeof(SockOpt_Keepalive);
	int a = 0;

	//if (a = this->SetSockOpt(SO_KEEPALIVE, &SockOpt_Keepalive, temp, SOL_SOCKET))
	//{
	//	str.Format(_T("ERROR : SetSockOpt %d"), a);
	//	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
	//}
	//if (a = this->SetSockOpt(TCP_NODELAY, &SockOpt_Nodelay, sizeof(BOOL), IPPROTO_TCP))
	//{
	//	str.Format(_T("ERROR : SetSockOpt %d"), a);
	//	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
	//}

	if (a = setsockopt(this->m_hSocket, SOL_SOCKET, SO_KEEPALIVE, (char*)&SockOpt_Keepalive, sizeof(SockOpt_Keepalive)))
	{
		str.Format(_T("ERROR : Set SO_KEEPALIVE %d"), a);
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
	}
	if (a = setsockopt(this->m_hSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&SockOpt_Nodelay, sizeof(SockOpt_Nodelay)))
	{
		str.Format(_T("ERROR : Set TCP_NODELAY %d"), a);
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);
	}

	struct tcp_keepalive alive_in = { 0 };
	struct tcp_keepalive alive_out = { 0 };
	alive_in.keepalivetime = 900;
	alive_in.keepaliveinterval = 300;
	alive_in.onoff = TRUE;
	unsigned long nlBytesReturn = 0;

	if (WSAIoctl(this->m_hSocket,
		SIO_KEEPALIVE_VALS,
		&alive_in,
		sizeof(alive_in),
		&alive_out,
		sizeof(alive_out),
		&nlBytesReturn,
		NULL,
		NULL) == SOCKET_ERROR)
	{
		str.Format(_T("ERROR : WSAIoctl %d"), GetLastError());
		(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);

		return FALSE;
	}
	// WSAAsyncSelect((reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_hSocket, (reinterpret_cast<CWnd*>(AfxGetMainWnd()))->m_hWnd, WM_RECEIVE_EVENT, FD_READ | FD_CLOSE);
	str.Format(_T("SUCCESS : setsockopt"));
	(reinterpret_cast<CFCU_SWDlg*>(AfxGetMainWnd()))->m_pRecvView->AddEventString(str);

	return TRUE;
}
