// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "SaleSystem.h"

#include "MainFrm.h"
#include "InfoFile.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "UserDlg.h"
#include "SellDlg.h"
#include "AddDlg.h"
#include "DelDlg.h"
#include "InfoDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()


//ON_MESSAGE响应的是自定义消息
//产生NM_X消息，自动调用OnMyChange函数
ON_MESSAGE(NM_A,OnMyChange)
ON_MESSAGE(NM_B,OnMyChange)
ON_MESSAGE(NM_C,OnMyChange)
ON_MESSAGE(NM_D,OnMyChange)
ON_MESSAGE(NM_E,OnMyChange)


ON_COMMAND(ID_32771, &CMainFrame::On32771)
ON_COMMAND(ID_32772, &CMainFrame::On32772)
ON_COMMAND(ID_32773, &CMainFrame::On32773)
ON_COMMAND(ID_32776, &CMainFrame::On32776)

ON_COMMAND(ID_32777, &CMainFrame::On32777)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	//设置图标 IDI_ICON_WIN为图标资源ID,此为WINAPI函数
	SetClassLong(m_hWnd,GCL_HICON,(LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));

    //设置标题  右侧标题

	SetTitle(TEXT("2017/5/26"));
	//设置窗口大小
	MoveWindow(0,0,800,500);
	//设置居中显示
	CenterWindow();

	////测试CInfoFile类
	//CInfoFile file;
	//CString name;
	//CString pwd;
	//file.ReadLogin(name,pwd);
	//MessageBox(name);
	//MessageBox(pwd);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序




BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	//拆成1行两列
	m_spliter.CreateStatic(this,1,2);
	//左侧和右侧具体的显示内容
	m_spliter.CreateView(0,0,RUNTIME_CLASS(CSelectView), CSize(200,500), pContext);
	m_spliter.CreateView(0,1,RUNTIME_CLASS(CDisplayView), CSize(600,500), pContext);

	//自己拆分
	return TRUE;
}


LRESULT CMainFrame::OnMyChange(WPARAM wParam,LPARAM lParam)//接收
{
	CCreateContext Context;
	if(wParam == NM_A)
	{
		//MessageBox(TEXT("个人信息界面挂载！"));
		//挂载界面
		Context.m_pNewViewClass =RUNTIME_CLASS(CUserDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CUserDlg),CSize(600,500),&Context);
		CUserDlg *pNewView =(CUserDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//初始化
		m_spliter.SetActivePane(0,1);//激活

	}
	else if(wParam == NM_B)
	{
		//MessageBox(TEXT("信息界面挂载！"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CSellDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CSellDlg),CSize(600,500),&Context);
		CSellDlg *pNewView =(CSellDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//初始化
		m_spliter.SetActivePane(0,1);//激活

	}
	else if(wParam == NM_C)
	{
		//MessageBox(TEXT("信息界面挂载！"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CInfoDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CInfoDlg),CSize(600,0),&Context);
		CInfoDlg *pNewView =(CInfoDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//初始化
		m_spliter.SetActivePane(0,1);//激活


	}
	else if(wParam == NM_D)
	{
		//MessageBox(TEXT("信息界面挂载！"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CAddDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CAddDlg),CSize(600,500),&Context);
		CAddDlg *pNewView =(CAddDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//初始化
		m_spliter.SetActivePane(0,1);//激活


	}
	else if(wParam == NM_E)
	{
		//MessageBox(TEXT("信息界面挂载！"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CDelDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CDelDlg),CSize(600,500),&Context);
		CDelDlg *pNewView =(CDelDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//初始化
		m_spliter.SetActivePane(0,1);//激活


	}
	return 0;
}

void CMainFrame::On32771()
{
	// TODO: 在此添加命令处理程序代码
	//退出按钮
	exit(0);
}

void CMainFrame::On32772()
{
	// TODO: 在此添加命令处理程序代码
	//个人信息
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_A,(WPARAM) NM_A,(LPARAM)0);
}

void CMainFrame::On32773()
{
	// TODO: 在此添加命令处理程序代码
	//销售管理
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_B,(WPARAM) NM_B,(LPARAM)0);
}

void CMainFrame::On32776()
{
	// TODO: 在此添加命令处理程序代码
	//库存删除
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_E,(WPARAM) NM_E,(LPARAM)0);
}



void CMainFrame::On32777()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_C,(WPARAM) NM_C,(LPARAM)0);
}
