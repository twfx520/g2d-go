// sample3View.cpp : Csample3View ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Csample3View ����/����

Csample3View::Csample3View()
{
	// TODO: �ڴ˴���ӹ������

}

Csample3View::~Csample3View()
{
	GGE_RELEASE(chain);
	GGE_RELEASE(spr);
}

BOOL Csample3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CView::PreCreateWindow(cs);
}

// Csample3View ����

void Csample3View::OnDraw(CDC* /*pDC*/)
{
	Csample3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	float PosY = (float)GetScrollPos(SB_VERT);
	float PosX = (float)GetScrollPos(SB_HORZ);
	if (chain->BeginScene())
	{
		if (spr != 0) 
			spr->Render(-PosX, -PosY);
		chain->EndScene();
	}
}


// Csample3View ��ӡ

BOOL Csample3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Csample3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡǰ��Ӷ���ĳ�ʼ��
}

void Csample3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡ������������
}


// Csample3View ���

#ifdef _DEBUG
void Csample3View::AssertValid() const
{
	CView::AssertValid();
}

void Csample3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csample3Doc* Csample3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csample3Doc)));
	return (Csample3Doc*)m_pDocument;
}
#endif //_DEBUG


// Csample3View ��Ϣ�������

void Csample3View::OnFileOpen()
{
	// TODO: �ڴ���������������

	//����ͼƬ
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

	// TODO: �ڴ����ר�ô����/����û���

	CSize sizeTotal;
	sizeTotal.cx = 1000;
	sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);


	//�Ե�ǰ��ͼ������Ⱦ������
	chain = SwapChain_Create(m_hWnd);
	//��������
	spr = Sprite_Create(0);
}

BOOL Csample3View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return true;
}