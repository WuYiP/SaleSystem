#include "stdafx.h"
#include "InfoFile.h"

CInfoFile:: CInfoFile()
{
	
}
CInfoFile:: ~CInfoFile()
{
	
}
//修改密码
void CInfoFile::WritePwd(char* name,char* pwd)
{
	ofstream ofs;//创建文件输出对象
	ofs.open(_F_LOGIN);//打开文件
	ofs<<name<<endl;//name写入文件
	ofs<<pwd<<endl;//pwd写入文件
	ofs.close();//关闭文件
}

//读取登录信息
void CInfoFile::ReadLogin(CString &name,CString &pwd)
{
	ifstream ifs;//创建文件输入对象
	ifs.open(_F_LOGIN);//打开文件
	char buf[1024] ={0};
	ifs.getline(buf,sizeof(buf));//读取一行内容
	name =CString(buf);
	ifs.getline(buf,sizeof(buf));
	pwd =CString(buf);
	
	
	
}

//读取商品数据
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK);//输入方式打开文件
	char buf[1024]={0};
	num =0;//初始化商品数目为0
	ls.clear();
	//取出表头
	ifs.getline(buf,sizeof(buf));
	while (!ifs.eof())//没到文件结尾
	{
		msg tmp;
		ifs.getline(buf,sizeof(buf));//读取一行内容
		num++;//商品数目加一
		//AfxMessageBox(CString(buf));
		char *sst=strtok(buf,"|");//以|切割
		if (sst !=NULL)
		{
			tmp.id = atoi(sst);//商品id
			
		}
		else
		{
			break;
		}
		sst =strtok(NULL,"|");
		tmp.name = sst;//商品名称
		sst =strtok(NULL,"|");
		tmp.price=atoi(sst);//商品价格
		sst =strtok(NULL,"|");
		tmp.num= atoi(sst);//商品数目
		
		ls.push_back(tmp);//放在链表的后面
		
	}
	ifs.close();//关闭文件
	
}


//商品写入文件
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_STOCK);//输出方式打开文件
	
	if(ls.size()>0)//商品链表有内容才执行
	{
		ofs<<"商品ID|商品名称|商品价格|库存"<<endl;//写入表头
		//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (list<msg>::iterator it=ls.begin();it !=ls.end();it++)
		{
			ofs <<it->id <<"|"; 
			ofs <<it->name <<"|";
			ofs <<it->price<<"|";
			ofs <<it->num <<endl;
		}
	}
	ofs.close();//关闭文件
}
//添加新商品
void CInfoFile::Addline (CString name,int num,int price)
{
	ifstream ifs(_F_STOCK);//输入方式打开文件
	char buf[1024]={0};
	num =0;//初始化商品数目为0
	ls.clear();
	//取出表头
	ifs.getline(buf,sizeof(buf));
	while (!ifs.eof())//没到文件结尾
	{
		msg tmp;
		ifs.getline(buf,sizeof(buf));//读取一行内容
		num++;//商品数目加一
		//AfxMessageBox(CString(buf));
		char *sst=strtok(buf,"|");//以|切割
		if (sst !=NULL)
		{
			tmp.id = atoi(sst);//商品id
			
		}
		else
		{
			break;
		}
		sst =strtok(NULL,"|");
		tmp.name = sst;//商品名称
		sst =strtok(NULL,"|");
		tmp.price=atoi(sst);//商品价格
		sst =strtok(NULL,"|");
		tmp.num= atoi(sst);//商品数目
		
		ls.push_back(tmp);//放在链表的后面
		
	}
	ifs.close();//关闭文件
	
}