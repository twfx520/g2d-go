// sample3Doc.h :  Csample3Doc ��Ľӿ�
//


#pragma once

class Csample3Doc : public CDocument
{
protected: // �������л�����
	Csample3Doc();
	DECLARE_DYNCREATE(Csample3Doc)

// ����
public:

// ����
public:

// ��д
	public:
//	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~Csample3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
};


