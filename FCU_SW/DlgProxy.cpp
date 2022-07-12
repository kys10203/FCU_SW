
// DlgProxy.cpp : 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "DlgProxy.h"
#include "FCU_SWDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFCU_SWDlgAutoProxy

IMPLEMENT_DYNCREATE(CFCU_SWDlgAutoProxy, CCmdTarget)

CFCU_SWDlgAutoProxy::CFCU_SWDlgAutoProxy()
{
	EnableAutomation();
	
	// 자동화 개체가 활성화되어 있는 동안 계속 응용 프로그램을 실행하기 위해 
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 응용 프로그램의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다. 프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CFCU_SWDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFCU_SWDlg)))
		{
			m_pDialog = reinterpret_cast<CFCU_SWDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CFCU_SWDlgAutoProxy::~CFCU_SWDlgAutoProxy()
{
	// 모든 개체가 OLE 자동화로 만들어졌을 때 응용 프로그램을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CFCU_SWDlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_IFCU_SW에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {D25C2D4F-EC60-4967-BEFC-5CC7B67E80F7}
static const IID IID_IFCU_SW =
{ 0xD25C2D4F, 0xEC60, 0x4967, { 0xBE, 0xFC, 0x5C, 0xC7, 0xB6, 0x7E, 0x80, 0xF7 } };

BEGIN_INTERFACE_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CFCU_SWDlgAutoProxy, IID_IFCU_SW, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 매크로가 이 프로젝트의 StdAfx.h에 정의됩니다.
// {2CF26EA6-E1A0-4CFA-92C2-9B5D0219DFE5}
IMPLEMENT_OLECREATE2(CFCU_SWDlgAutoProxy, "FCU_SW.Application", 0x2cf26ea6, 0xe1a0, 0x4cfa, 0x92, 0xc2, 0x9b, 0x5d, 0x2, 0x19, 0xdf, 0xe5)


// CFCU_SWDlgAutoProxy 메시지 처리기
