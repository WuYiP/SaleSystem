// MainFrm.cpp : CMainFrame ���ʵ��
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


//ON_MESSAGE��Ӧ�����Զ�����Ϣ
//����NM_X��Ϣ���Զ�����OnMyChange����
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	//����ͼ�� IDI_ICON_WINΪͼ����ԴID,��ΪWINAPI����
	SetClassLong(m_hWnd,GCL_HICON,(LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));

    //���ñ���  �Ҳ����

	SetTitle(TEXT("2017/5/26"));
	//���ô��ڴ�С
	MoveWindow(0,0,800,500);
	//���þ�����ʾ
	CenterWindow();

	////����CInfoFile��
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

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


// CMainFrame ��Ϣ�������




BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	//���1������
	m_spliter.CreateStatic(this,1,2);
	//�����Ҳ�������ʾ����
	m_spliter.CreateView(0,0,RUNTIME_CLASS(CSelectView), CSize(200,500), pContext);
	m_spliter.CreateView(0,1,RUNTIME_CLASS(CDisplayView), CSize(600,500), pContext);

	//�Լ����
	return TRUE;
}


LRESULT CMainFrame::OnMyChange(WPARAM wParam,LPARAM lParam)//����
{
	CCreateContext Context;
	if(wParam == NM_A)
	{
		//MessageBox(TEXT("������Ϣ������أ�"));
		//���ؽ���
		Context.m_pNewViewClass =RUNTIME_CLASS(CUserDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CUserDlg),CSize(600,500),&Context);
		CUserDlg *pNewView =(CUserDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//��ʼ��
		m_spliter.SetActivePane(0,1);//����

	}
	else if(wParam == NM_B)
	{
		//MessageBox(TEXT("��Ϣ������أ�"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CSellDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CSellDlg),CSize(600,500),&Context);
		CSellDlg *pNewView =(CSellDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//��ʼ��
		m_spliter.SetActivePane(0,1);//����

	}
	else if(wParam == NM_C)
	{
		//MessageBox(TEXT("��Ϣ������أ�"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CInfoDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CInfoDlg),CSize(600,0),&Context);
		CInfoDlg *pNewView =(CInfoDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//��ʼ��
		m_spliter.SetActivePane(0,1);//����


	}
	else if(wParam == NM_D)
	{
		//MessageBox(TEXT("��Ϣ������أ�"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CAddDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CAddDlg),CSize(600,500),&Context);
		CAddDlg *pNewView =(CAddDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//��ʼ��
		m_spliter.SetActivePane(0,1);//����


	}
	else if(wParam == NM_E)
	{
		//MessageBox(TEXT("��Ϣ������أ�"));
		Context.m_pNewViewClass =RUNTIME_CLASS(CDelDlg);
		Context.m_pCurrentFrame =this;
		Context.m_pLastView=(CFormView*)m_spliter.GetPane(0,1);
		m_spliter.DeleteView(0,1);
		m_spliter.CreateView(0,1,RUNTIME_CLASS(CDelDlg),CSize(600,500),&Context);
		CDelDlg *pNewView =(CDelDlg *)m_spliter.GetPane(0,1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();//��ʼ��
		m_spliter.SetActivePane(0,1);//����


	}
	return 0;
}

void CMainFrame::On32771()
{
	// TODO: �ڴ���������������
	//�˳���ť
	exit(0);
}

void CMainFrame::On32772()
{
	// TODO: �ڴ���������������
	//������Ϣ
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_A,(WPARAM) NM_A,(LPARAM)0);
}

void CMainFrame::On32773()
{
	// TODO: �ڴ���������������
	//���۹���
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_B,(WPARAM) NM_B,(LPARAM)0);
}

void CMainFrame::On32776()
{
	// TODO: �ڴ���������������
	//���ɾ��
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_E,(WPARAM) NM_E,(LPARAM)0);
}



void CMainFrame::On32777()
{
	// TODO: �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),NM_C,(WPARAM) NM_C,(LPARAM)0);
}
