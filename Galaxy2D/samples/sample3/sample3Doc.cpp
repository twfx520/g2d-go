// sample3Doc.cpp :  Csample3Doc ���ʵ��
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


// Csample3Doc ����/����

Csample3Doc::Csample3Doc()
{
	// TODO: �ڴ����һ���Թ������
	

}

Csample3Doc::~Csample3Doc()
{
	
}


// Csample3Doc ���л�

void Csample3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// Csample3Doc ���

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

