// ShowWarning.cpp: 구현 파일
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "afxdialogex.h"
#include "ShowWarning.h"
#include "FCU_SWDlg.h"

// CShowWarning 대화 상자

IMPLEMENT_DYNAMIC(CShowWarning, CDialogEx)

CShowWarning::CShowWarning(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ShowWarning, pParent)
{

}

CShowWarning::~CShowWarning()
{
}

void CShowWarning::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShowWarning, CDialogEx)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CShowWarning 메시지 처리기


BOOL CShowWarning::OnInitDialog()
{
	CDialogEx::OnInitDialog();
    CRect rect;
    this->GetWindowRect(rect);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(255, 0, 0));
    this->SetWindowPos(NULL, (((CFCU_SWDlg*)GetParent())->m_rectMainDlg.right - rect.right) / 2, ((((CFCU_SWDlg*)GetParent())->m_rectMainDlg.bottom - rect.bottom) / 2) + 100, 0, 0, SWP_NOSIZE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CShowWarning::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if (pMsg->message == WM_KEYDOWN)
    {
        ((CFCU_SWDlg*)GetParent())->SetFocus();

        if (pMsg->wParam == VK_F3)
        {
            // ESC 키 이벤트에 대한 처리 추가
            this->ShowWindow(SW_HIDE);
            ((CFCU_SWDlg*)GetParent())->OnAcceleratorF3();

            return TRUE;
        }
        else if (pMsg->wParam == VK_F4)
        {
            // Enter 키 이벤트에 대한 처리 추가
            this->ShowWindow(SW_HIDE);
            ((CFCU_SWDlg*)GetParent())->OnAcceleratorF4();


            return TRUE;
        }
        else
        {
            return TRUE;
        }
    }

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CShowWarning::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    this->ShowWindow(SW_HIDE);

    CDialogEx::OnLButtonDown(nFlags, point);
}
