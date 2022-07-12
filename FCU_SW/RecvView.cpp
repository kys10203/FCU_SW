// RecvView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "RecvView.h"
#include "afxdialogex.h"


// CRecvView 대화 상자입니다.

IMPLEMENT_DYNAMIC(CRecvView, CDialogEx)

CRecvView::CRecvView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRecvView::IDD, pParent)
{

	EnableAutomation();

}

CRecvView::~CRecvView()
{
}

void CRecvView::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CRecvView::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_RICHEDIT21, m_editRecvLog);
}


BEGIN_MESSAGE_MAP(CRecvView, CDialogEx)
    ON_BN_CLICKED(IDCANCEL, &CRecvView::OnBnClickedCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CRecvView, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IRecvView에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {04DA761A-E2C1-44B4-A18C-5B0DA0AD9A94}
static const IID IID_IRecvView =
{ 0x4DA761A, 0xE2C1, 0x44B4, { 0xA1, 0x8C, 0x5B, 0xD, 0xA0, 0xAD, 0x9A, 0x94 } };

BEGIN_INTERFACE_MAP(CRecvView, CDialogEx)
	INTERFACE_PART(CRecvView, IID_IRecvView, Dispatch)
END_INTERFACE_MAP()


// CRecvView 메시지 처리기입니다.


void CRecvView::AddEventString(wchar_t* ap_string)
{
    //CString str = (LPCTSTR)ap_string;

    //m_u16LogCnt++;
    //m_editRecvLog.SetSel(-1, -1);

    //int len = m_editRecvLog.GetWindowTextLengthW();

    //str += _T("\r\n");

    //m_editRecvLog.SetSel(len, len);
    //m_editRecvLog.ReplaceSel(str);

    //AutoScroll();
}


void CRecvView::AddEventString(CString str)
{
    //m_u16LogCnt++;
    //m_editRecvLog.SetSel(-1, -1);

    //int len = m_editRecvLog.GetWindowTextLengthW();

    //str += _T("\r\n");

    //m_editRecvLog.SetSel(len, len);
    //m_editRecvLog.ReplaceSel(str);

    //AutoScroll();
}


void CRecvView::AutoScroll(void)
{
     if(1024 <m_u16LogCnt)
    {
        clearLog();
        m_u16LogCnt = 0;
    }

    int nDoLineScroll = m_editRecvLog.GetLineCount() - 21 - m_editRecvLog.GetFirstVisibleLine();	// 18 : 보여지는 Line 수 조정

    if (nDoLineScroll > 0)
        m_editRecvLog.LineScroll(nDoLineScroll);
}


void CRecvView::AddEventString(WORD num, WORD type)
{
    //CString str;

    //m_u16LogCnt++;
    //m_editRecvLog.SetSel(-1, -1);

    //int len = m_editRecvLog.GetWindowTextLengthW();

    //switch(type)
    //{
    //case TYPE_WORD:
    //    str.Format(_T("%04X "), num);
    //    break;
    //case TYPE_DOUBLE:
    //    str.Format(_T("%.3lf "), num);
    //    break;
    //    case TYPE_DEC:
    //    str.Format(_T("%d "), (INT16)num);
    //    break;
    //}
    //str += _T("\r\n");

    //m_editRecvLog.SetSel(len, len);
    //m_editRecvLog.ReplaceSel(str);

    //AutoScroll();
}


void CRecvView::clearLog(void)
{
    m_editRecvLog.SetSel(0, m_editRecvLog.GetWindowTextLength());
    m_editRecvLog.ReplaceSel(_T(""), false);
}


void CRecvView::OnBnClickedCancel()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // SaveLog();

    CDialogEx::OnCancel();
}
