
// FCU_SW.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFCU_SWApp:
// �� Ŭ������ ������ ���ؼ��� FCU_SW.cpp�� �����Ͻʽÿ�.
//

class CFCU_SWApp : public CWinApp
{
public:
	CFCU_SWApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFCU_SWApp theApp;
