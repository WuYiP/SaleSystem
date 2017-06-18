// SaleSystemDoc.cpp : CSaleSystemDoc 类的实现
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


// CSaleSystemDoc 构造/析构

CSaleSystemDoc::CSaleSystemDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSaleSystemDoc::~CSaleSystemDoc()
{
}

BOOL CSaleSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	//设置左侧标题位置
SetTitle(TEXT("销售管理系统"));
	return TRUE;
}




// CSaleSystemDoc 序列化

void CSaleSystemDoc::Serialize(CArchive& ar)
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


// CSaleSystemDoc 诊断

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


// CSaleSystemDoc 命令
