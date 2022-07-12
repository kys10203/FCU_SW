
// DlgProxy.cpp : ���� ����
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
	
	// �ڵ�ȭ ��ü�� Ȱ��ȭ�Ǿ� �ִ� ���� ��� ���� ���α׷��� �����ϱ� ���� 
	//	�����ڿ��� AfxOleLockApp�� ȣ���մϴ�.
	AfxOleLockApp();

	// ���� ���α׷��� �� â �����͸� ���� ��ȭ ���ڿ� ����
	//  �׼����� �����ɴϴ�. ���Ͻ��� ���� �����͸� �����Ͽ�
	//  ��ȭ ���ڸ� ����Ű�� ��ȭ ������ �Ĺ� �����͸� �� ���Ͻ÷�
	//  �����մϴ�.
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
	// ��� ��ü�� OLE �ڵ�ȭ�� ��������� �� ���� ���α׷��� �����ϱ� ����
	// 	�Ҹ��ڰ� AfxOleUnlockApp�� ȣ���մϴ�.
	//  �̷��� ȣ��� �� ��ȭ ���ڰ� ������ �� �ֽ��ϴ�.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CFCU_SWDlgAutoProxy::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ����: IID_IFCU_SW�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�.
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {D25C2D4F-EC60-4967-BEFC-5CC7B67E80F7}
static const IID IID_IFCU_SW =
{ 0xD25C2D4F, 0xEC60, 0x4967, { 0xBE, 0xFC, 0x5C, 0xC7, 0xB6, 0x7E, 0x80, 0xF7 } };

BEGIN_INTERFACE_MAP(CFCU_SWDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CFCU_SWDlgAutoProxy, IID_IFCU_SW, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ��ũ�ΰ� �� ������Ʈ�� StdAfx.h�� ���ǵ˴ϴ�.
// {2CF26EA6-E1A0-4CFA-92C2-9B5D0219DFE5}
IMPLEMENT_OLECREATE2(CFCU_SWDlgAutoProxy, "FCU_SW.Application", 0x2cf26ea6, 0xe1a0, 0x4cfa, 0x92, 0xc2, 0x9b, 0x5d, 0x2, 0x19, 0xdf, 0xe5)


// CFCU_SWDlgAutoProxy �޽��� ó����
