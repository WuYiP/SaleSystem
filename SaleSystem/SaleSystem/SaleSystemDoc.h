// SaleSystemDoc.h : CSaleSystemDoc ��Ľӿ�
//


#pragma once


class CSaleSystemDoc : public CDocument
{
protected: // �������л�����
	CSaleSystemDoc();
	DECLARE_DYNCREATE(CSaleSystemDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CSaleSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


