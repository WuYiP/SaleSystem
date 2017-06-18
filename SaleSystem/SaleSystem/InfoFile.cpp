#include "stdafx.h"
#include "InfoFile.h"

CInfoFile:: CInfoFile()
{
	
}
CInfoFile:: ~CInfoFile()
{
	
}
//�޸�����
void CInfoFile::WritePwd(char* name,char* pwd)
{
	ofstream ofs;//�����ļ��������
	ofs.open(_F_LOGIN);//���ļ�
	ofs<<name<<endl;//nameд���ļ�
	ofs<<pwd<<endl;//pwdд���ļ�
	ofs.close();//�ر��ļ�
}

//��ȡ��¼��Ϣ
void CInfoFile::ReadLogin(CString &name,CString &pwd)
{
	ifstream ifs;//�����ļ��������
	ifs.open(_F_LOGIN);//���ļ�
	char buf[1024] ={0};
	ifs.getline(buf,sizeof(buf));//��ȡһ������
	name =CString(buf);
	ifs.getline(buf,sizeof(buf));
	pwd =CString(buf);
	
	
	
}

//��ȡ��Ʒ����
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK);//���뷽ʽ���ļ�
	char buf[1024]={0};
	num =0;//��ʼ����Ʒ��ĿΪ0
	ls.clear();
	//ȡ����ͷ
	ifs.getline(buf,sizeof(buf));
	while (!ifs.eof())//û���ļ���β
	{
		msg tmp;
		ifs.getline(buf,sizeof(buf));//��ȡһ������
		num++;//��Ʒ��Ŀ��һ
		//AfxMessageBox(CString(buf));
		char *sst=strtok(buf,"|");//��|�и�
		if (sst !=NULL)
		{
			tmp.id = atoi(sst);//��Ʒid
			
		}
		else
		{
			break;
		}
		sst =strtok(NULL,"|");
		tmp.name = sst;//��Ʒ����
		sst =strtok(NULL,"|");
		tmp.price=atoi(sst);//��Ʒ�۸�
		sst =strtok(NULL,"|");
		tmp.num= atoi(sst);//��Ʒ��Ŀ
		
		ls.push_back(tmp);//��������ĺ���
		
	}
	ifs.close();//�ر��ļ�
	
}


//��Ʒд���ļ�
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_STOCK);//�����ʽ���ļ�
	
	if(ls.size()>0)//��Ʒ���������ݲ�ִ��
	{
		ofs<<"��ƷID|��Ʒ����|��Ʒ�۸�|���"<<endl;//д���ͷ
		//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<msg>::iterator it=ls.begin();it !=ls.end();it++)
		{
			ofs <<it->id <<"|"; 
			ofs <<it->name <<"|";
			ofs <<it->price<<"|";
			ofs <<it->num <<endl;
		}
	}
	ofs.close();//�ر��ļ�
}
//�������Ʒ
void CInfoFile::Addline (CString name,int num,int price)
{
	ifstream ifs(_F_STOCK);//���뷽ʽ���ļ�
	char buf[1024]={0};
	num =0;//��ʼ����Ʒ��ĿΪ0
	ls.clear();
	//ȡ����ͷ
	ifs.getline(buf,sizeof(buf));
	while (!ifs.eof())//û���ļ���β
	{
		msg tmp;
		ifs.getline(buf,sizeof(buf));//��ȡһ������
		num++;//��Ʒ��Ŀ��һ
		//AfxMessageBox(CString(buf));
		char *sst=strtok(buf,"|");//��|�и�
		if (sst !=NULL)
		{
			tmp.id = atoi(sst);//��Ʒid
			
		}
		else
		{
			break;
		}
		sst =strtok(NULL,"|");
		tmp.name = sst;//��Ʒ����
		sst =strtok(NULL,"|");
		tmp.price=atoi(sst);//��Ʒ�۸�
		sst =strtok(NULL,"|");
		tmp.num= atoi(sst);//��Ʒ��Ŀ
		
		ls.push_back(tmp);//��������ĺ���
		
	}
	ifs.close();//�ر��ļ�
	
}