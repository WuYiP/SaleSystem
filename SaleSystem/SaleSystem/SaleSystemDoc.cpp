// SaleSystemDoc.cpp : CSaleSystemDoc ���ʵ��
//

#include "stdafx.h"
#include "SaleSystem.h"

#include "SaleSystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSaleSystemDoc

IMPLEMENT_DYNCREATE(CSaleSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CSaleSystemDoc, CDocument)
END_MESSAGE_MAP()


// CSaleSystemDoc ����/����

CSaleSystemDoc::CSaleSystemDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSaleSystemDoc::~CSaleSystemDoc()
{
}

BOOL CSaleSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	//����������λ��
SetTitle(TEXT("���۹���ϵͳ"));
	return TRUE;
}




// CSaleSystemDoc ���л�

void CSaleSystemDoc::Serialize(CArchive& ar)
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


// CSaleSystemDoc ���

#ifdef _DEBUG
void CSaleSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSaleSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSaleSystemDoc ����
