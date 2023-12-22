/*
**  =======================================================
**  与MFC等GUI库结合制作游戏工具示例
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


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
	Engine_Release();
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//初始化
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
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	SetTitle("Galaxy2D Game Engine - MFC");

	cs.style &= ~FWS_ADDTOTITLE;   
	cs.style &= ~WS_THICKFRAME;
	cs.style &= ~WS_MAXIMIZEBOX;

	return TRUE;
}


// CMainFrame 诊断

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


// CMainFrame 消息处理程序

