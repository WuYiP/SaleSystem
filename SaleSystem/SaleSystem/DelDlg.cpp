// DelDlg.cpp : ʵ���ļ�
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


// CDelDlg ���

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


// CDelDlg ��Ϣ�������

void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ȡ�ļ�����ȡ��Ʒ��������Ͽ�����ַ���
	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	//����Ʒ����file������
	file.ReadDocline();

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)
	{
		//������Ʒ���� ���������Ʒŵ���������
		//it->name �� string AddString(CString)
		//string ->CString

		m_combo.AddString(CString(it->name.c_str()));


		//Ĭ��ѡ�е�һ����Ʒ
		m_combo.SetCurSel(0);
		//OnCbnSelchangeCombo1();//���¿���е�����
	}
}

void CDelDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index=m_combo.GetCurSel();

	//����������ȡ����������
	CString text;
	m_combo.GetLBText(index,text);

	//������Ʒ���ƻ�ȡ������Ʒ�ļ۸�Ϳ�� ������ʾ���ؼ���

	CInfoFile file;
	//����Ʒ����file������
	file.ReadDocline();//��ȡ��Ʒ��Ϣ

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)//���б���

	{
		if(text==it->name.c_str())
		{
			m_price=it->price;
			m_num=0;
			//m_left=it->num;

			//ͬ�����ؼ���
			UpdateData(FALSE);//���ݸ��µ���Ӧ�Ŀؼ�

		}
	}
}

void CDelDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_num==0)
	{
		MessageBox(TEXT("����������Ϊ0"));
		return;
	}

	 // ��ȡ������Ҫ�����Ʒ����
	int index=m_combo.GetCurSel();//��ȡ��ѡ����

	//����������ȡ����������
	CString type;
	m_combo.GetLBText(index,type);
	
	CString str;
	str.Format(_T("ɾ����Ʒ��%s \r\n���ۣ� %d \r\n������ %d"),type,m_price,m_num);
	MessageBox(str);
	


	CInfoFile file;
	//����Ʒ����file������
	file.ReadDocline();

	for (list<msg>::iterator it=file.ls.begin();it !=file.ls.end();it++)//���б���

	{
		if((CString)it->name.c_str())
		{
			
			it->num=it->num-m_num;
			
		
			
			
		}
	}
	//�����ļ�����
    file.WriteDocline();
	m_num=0;
	UpdateData(FALSE);//���µ���Ӧ�Ŀؼ�


}

void CDelDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.SetCurSel(0);//ѡ���0��Ŀ
	m_num=0;
	UpdateData(FALSE);//���µ���Ӧ�Ŀؼ�

}
