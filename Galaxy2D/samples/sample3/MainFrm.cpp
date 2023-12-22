/*
**  =======================================================
**  ��MFC��GUI����������Ϸ����ʾ��
**  =======================================================
*/

#include "stdafx.h"
#include "sample3.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "ggebase.h"
using namespace gge;

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
	Engine_Release();
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//��ʼ��
	Engine_Create(GGE_VERSION);
	System_SetState(GGE_SCREENWIDTH, 640);
	System_SetState(GGE_SCREENHEIGHT, 480);
	System_SetState(GGE_HWND, m_hWnd);
	System_Initiate();

	RECT rectWnd;
	GetWindowRect(&rectWnd);
	rectWnd.right = rectWnd.left + 640;
	rectWnd.bottom = rectWnd.top + 480;

	MoveWindow(&rectWnd);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	SetTitle("Galaxy2D Game Engine - MFC");

	cs.style &= ~FWS_ADDTOTITLE;   
	cs.style &= ~WS_THICKFRAME;
	cs.style &= ~WS_MAXIMIZEBOX;

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������

