// sample3View.cpp : Csample3View 类的实现
//

#include "stdafx.h"
#include "sample3.h"

#include "sample3Doc.h"
#include "sample3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "ggebase.h"
#include "ggesprite.h"
#include "ggetexture.h"
#include "ggeswapchain.h"
using namespace gge;

#include ".\sample3view.h"
ggeSprite		*spr = 0;
ggeSwapChain	*chain = 0;

// Csample3View

IMPLEMENT_DYNCREATE(Csample3View, CScrollView)

BEGIN_MESSAGE_MAP(Csample3View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Csample3View 构造/析构

Csample3View::Csample3View()
{
	// TODO: 在此处添加构造代码

}

Csample3View::~Csample3View()
{
	GGE_RELEASE(chain);
	GGE_RELEASE(spr);
}

BOOL Csample3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CView::PreCreateWindow(cs);
}

// Csample3View 绘制

void Csample3View::OnDraw(CDC* /*pDC*/)
{
	Csample3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	float PosY = (float)GetScrollPos(SB_VERT);
	float PosX = (float)GetScrollPos(SB_HORZ);
	if (chain->BeginScene())
	{
		if (spr != 0) 
			spr->Render(-PosX, -PosY);
		chain->EndScene();
	}
}


// Csample3View 打印

BOOL Csample3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Csample3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印前添加额外的初始化
}

void Csample3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印后添加清除过程
}


// Csample3View 诊断

#ifdef _DEBUG
void Csample3View::AssertValid() const
{
	CView::AssertValid();
}

void Csample3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csample3Doc* Csample3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csample3Doc)));
	return (Csample3Doc*)m_pDocument;
}
#endif //_DEBUG


// Csample3View 消息处理程序

void Csample3View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码

	//载入图片
	CFileDialog dlg(true);
	if (dlg.DoModal() == IDOK)
	{
		ggeTexture *tex = Texture_Load((char*)(LPCSTR)dlg.GetPathName());
		spr->SetTexture(tex);
		GGE_RELEASE(tex);
		CSize sizeTotal;
		sizeTotal.cx = spr->GetWidth();
		sizeTotal.cy = spr->GetHeight();
		SetScrollSizes(MM_TEXT, sizeTotal);
		Invalidate(FALSE);
	}
}

void Csample3View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	CSize sizeTotal;
	sizeTotal.cx = 1000;
	sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);


	//对当前视图创建渲染交换链
	chain = SwapChain_Create(m_hWnd);
	//创建精灵
	spr = Sprite_Create(0);
}

BOOL Csample3View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return true;
}