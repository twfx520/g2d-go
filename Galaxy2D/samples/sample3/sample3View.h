// sample3View.h : Csample3View ��Ľӿ�
//


#pragma once


class Csample3View : public CScrollView
{
protected: // �������л�����
	Csample3View();
	DECLARE_DYNCREATE(Csample3View)

// ����
public:
	Csample3Doc* GetDocument() const;

// ����
public:

// ��д
	public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Csample3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // sample3View.cpp �ĵ��԰汾
inline Csample3Doc* Csample3View::GetDocument() const
   { return reinterpret_cast<Csample3Doc*>(m_pDocument); }
#endif

