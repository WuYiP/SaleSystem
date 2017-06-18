// DelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DelDlg.h"
#include "InfoFile.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(CDelDlg::IDD)
	, m_price(0)
	, m_num(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDelDlg 诊断

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg 消息处理程序

void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//读取文件，获取商品名，给组合框添加字符串
	//需要包含#include "InfoFile.h"
	CInfoFile file;
	//把商品读到file对象中
	file.ReadDocline();

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)
	{
		//遍历商品容器 把容器名称放到下拉框中
		//it->name 是 string AddString(CString)
		//string ->CString

		m_combo.AddString(CString(it->name.c_str()));


		//默认选中第一个商品
		m_combo.SetCurSel(0);
		//OnCbnSelchangeCombo1();//更新库存中的数据
	}
}

void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_combo.GetCurSel();

	//根据索引获取到具体内容
	CString text;
	m_combo.GetLBText(index,text);

	//根据商品名称获取到该商品的价格和库存 并且显示到控件中

	CInfoFile file;
	//把商品读到file对象中
	file.ReadDocline();//读取商品信息

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)//进行遍历

	{
		if(text==it->name.c_str())
		{
			m_price=it->price;
			m_num=0;
			//m_left=it->num;

			//同步到控件上
			UpdateData(FALSE);//内容更新到对应的控件

		}
	}
}

void CDelDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_num==0)
	{
		MessageBox(TEXT("个数数不能为0"));
		return;
	}

	 // 获取到具体要买的商品名称
	int index=m_combo.GetCurSel();//获取当选中项

	//根据索引获取到具体内容
	CString type;
	m_combo.GetLBText(index,type);
	
	CString str;
	str.Format(_T("删除商品：%s \r\n单价： %d \r\n个数： %d"),type,m_price,m_num);
	MessageBox(str);
	


	CInfoFile file;
	//把商品读到file对象中
	file.ReadDocline();

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)//进行遍历

	{
		if((CString)it->name.c_str())
		{
			
			it->num=it->num-m_num;
			
		
			
			
		}
	}
	//更新文件内容
    file.WriteDocline();
	m_num=0;
	UpdateData(FALSE);//更新到对应的控件


}

void CDelDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_combo.SetCurSel(0);//选择第0项目
	m_num=0;
	UpdateData(FALSE);//更新到对应的控件

}
