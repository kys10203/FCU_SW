
// DlgProxy.h: ��� ����
//

#pragma once

class CFCU_SWDlg;


// CFCU_SWDlgAutoProxy ��� ���

class CFCU_SWDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CFCU_SWDlgAutoProxy)

	CFCU_SWDlgAutoProxy();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.

// Ư���Դϴ�.
public:
	CFCU_SWDlg* m_pDialog;

// �۾��Դϴ�.
public:

// �������Դϴ�.
	public:
	virtual void OnFinalRelease();

// �����Դϴ�.
protected:
	virtual ~CFCU_SWDlgAutoProxy();

	// ������ �޽��� �� �Լ�

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CFCU_SWDlgAutoProxy)

	// ������ OLE ����ġ �� �Լ�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

