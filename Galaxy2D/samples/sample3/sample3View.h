// sample3View.h : Csample3View 类的接口
//


#pragma once


class Csample3View : public CScrollView
{
protected: // 仅从序列化创建
	Csample3View();
	DECLARE_DYNCREATE(Csample3View)

// 属性
public:
	Csample3Doc* GetDocument() const;

// 操作
public:

// 重写
	public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Csample3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // sample3View.cpp 的调试版本
inline Csample3Doc* Csample3View::GetDocument() const
   { return reinterpret_cast<Csample3Doc*>(m_pDocument); }
#endif

