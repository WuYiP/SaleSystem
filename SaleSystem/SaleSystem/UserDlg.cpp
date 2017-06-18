// UserDlg.cpp : ʵ���ļ�
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������

void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ʼ��
	m_user = TEXT("����Ա");
	CInfoFile file;
	CString name,pwd;
	file.ReadLogin(name,pwd);
	m_name = name;
	UpdateData(FALSE);//�ѱ���д���ؼ���


}

void CUserDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸����빦��
	UpdateData(TRUE);
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ�գ�"));
		return;
	}
	//�������ȷ������һ��
	
	if(m_newpwd !=m_surepwd)
	{
		MessageBox(TEXT("�������������Ҫһ�£�"));
		return;

	}
	//������������벻��һ��
	CInfoFile file;
	CString name,pwd;
	file.ReadLogin(name,pwd);

	if(pwd ==m_newpwd)
	{
		MessageBox(TEXT("������������벻��һ�£�"));
		return;

	}
		//CString ת char*
	CStringA tmp;
	CStringA tmp2;
	tmp = name; 
	tmp2 = m_newpwd;
	file.WritePwd(tmp.GetBuffer(),tmp2.GetBuffer());//tmp.GetBuffer(),tmp2.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ�"));

	//�������
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);


}

void CUserDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȡ����ť
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);

}

void CUserDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CUserDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CUserDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CUserDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
