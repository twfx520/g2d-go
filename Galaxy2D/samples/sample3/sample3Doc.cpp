// sample3Doc.cpp :  Csample3Doc 类的实现
//

#include "stdafx.h"
#include "sample3.h"

#include "sample3Doc.h"
#include ".\sample3doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Csample3Doc

IMPLEMENT_DYNCREATE(Csample3Doc, CDocument)

BEGIN_MESSAGE_MAP(Csample3Doc, CDocument)
END_MESSAGE_MAP()


// Csample3Doc 构造/析构

Csample3Doc::Csample3Doc()
{
	// TODO: 在此添加一次性构造代码
	

}

Csample3Doc::~Csample3Doc()
{
	
}


// Csample3Doc 序列化

void Csample3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// Csample3Doc 诊断

#ifdef _DEBUG
void Csample3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Csample3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

