// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"
#include "LoginDlg.h"
// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newpwd(_T(""))
	, m_surepwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_newpwd);
	DDX_Text(pDX, IDC_EDIT3, m_surepwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &CUserDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &CUserDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CUserDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CUserDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序

void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//初始化
	m_user = TEXT("销售员");
	CInfoFile file;
	CString name,pwd;
	file.ReadLogin(name,pwd);
	m_name = name;
	UpdateData(FALSE);//把变量写到控件上


}

void CUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改密码功能
	UpdateData(TRUE);
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空！"));
		return;
	}
	//新密码和确定密码一致
	
	if(m_newpwd !=m_surepwd)
	{
		MessageBox(TEXT("新密码与旧密码要一致！"));
		return;

	}
	//新密码与旧密码不能一致
	CInfoFile file;
	CString name,pwd;
	file.ReadLogin(name,pwd);

	if(pwd ==m_newpwd)
	{
		MessageBox(TEXT("新密码与旧密码不能一致！"));
		return;

	}
		//CString 转 char*
	CStringA tmp;
	CStringA tmp2;
	tmp = name; 
	tmp2 = m_newpwd;
	file.WritePwd(tmp.GetBuffer(),tmp2.GetBuffer());//tmp.GetBuffer(),tmp2.GetBuffer());
	MessageBox(TEXT("修改成功"));

	//清空内容
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);


}

void CUserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//取消按钮
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);

}

void CUserDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CUserDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CUserDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CUserDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
