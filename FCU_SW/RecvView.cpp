// RecvView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "FCU_SW.h"
#include "RecvView.h"
#include "afxdialogex.h"


// CRecvView ��ȭ �����Դϴ�.

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
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

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

// ����: IID_IRecvView�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {04DA761A-E2C1-44B4-A18C-5B0DA0AD9A94}
static const IID IID_IRecvView =
{ 0x4DA761A, 0xE2C1, 0x44B4, { 0xA1, 0x8C, 0x5B, 0xD, 0xA0, 0xAD, 0x9A, 0x94 } };

BEGIN_INTERFACE_MAP(CRecvView, CDialogEx)
	INTERFACE_PART(CRecvView, IID_IRecvView, Dispatch)
END_INTERFACE_MAP()


// CRecvView �޽��� ó�����Դϴ�.


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

    int nDoLineScroll = m_editRecvLog.GetLineCount() - 21 - m_editRecvLog.GetFirstVisibleLine();	// 18 : �������� Line �� ����

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
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    // SaveLog();

    CDialogEx::OnCancel();
}
