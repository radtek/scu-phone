#include "StdAfx.h"
#include "DataAccess.h"
vector<PhoneInfo> DataAccess::_list;
CString DataAccess::filepath=_T("");
DataAccess::DataAccess()
{
}
DataAccess::~DataAccess()
{
}
bool DataAccess::add(PhoneInfo phone)
{
	if(phone.ID!="")
	{
		_list.push_back(phone);
		return true;
	}else return false;
}
bool DataAccess::del(CString id)
{
	int index=find(id);
	if(index>-1)
	{
		vector<PhoneInfo>::iterator itr = _list.begin();
		_list.erase(itr+index);
		return true;
	}
	else return false;
}
bool DataAccess::update(PhoneInfo phone)
{
	int index=find(phone.ID);
	if(index>-1)
	{
		_list[index].name=phone.name;
		_list[index].phonenum=phone.phonenum;
		_list[index].group=phone.group;
		return true;
	}
	else return false;
}
PhoneInfo *DataAccess::queryByID(CString ID)
{
	if(ID!="")
	{
		int index=find(ID);
		if(index>-1)return &(_list[index]);
		else return NULL;
	}
	else return NULL;
}
vector<PhoneInfo> DataAccess::queryByName(CString name)
{
	 vector<PhoneInfo> _plist;
	if(name!=""&&_list.size()>0)
	{
	 
	  for(int i=0;i<_list.size();i++)
	  {
		  if(_list[i].name.Find(name)>-1)_plist.push_back(_list[i]);
	  }
	}
	return _plist;
}
vector<PhoneInfo> DataAccess::queryByGroup(CString group)
{
	vector<PhoneInfo> _plist;
	if(group!=""&&_list.size()>0)
	{
	  for(int i=0;i<_list.size();i++)
	  {
		  if(_list[i].group==group)_plist.push_back(_list[i]);
	  }
	}
	return _plist;
}
void DataAccess::ReadData()
{
	CStdioFile myFile;

	CFileException fileException;
	if(myFile.Open(L"Data\\data.txt",CFile::typeText|CFile::modeReadWrite),&fileException)
	{
		filepath=myFile.GetFilePath();
		long long filesize=myFile.GetLength();
		if(filesize>0){
		CString line;
		while(myFile.ReadString(line))
		{
			_list.push_back(spilitor(line));
		}
		}
	}
	else
	{
		TRACE("Can't open file %s,error=%u\n","Data\\data.txt",fileException.m_cause);
	}
	myFile.Close();

}
void DataAccess::SaveData()
{
	if(_list.size()>0&&filepath!="")
	{
		int ln=_list.size();
	//	char* pszFileName="Data\\data.txt";
		CStdioFile myFile;
		CFileException fileException;
		if(myFile.Open(filepath,CFile::typeText|CFile::modeCreate|CFile::modeReadWrite),&fileException)
		{
			
			for(int i=0;i<ln;i++)
			{
				CString _line=_list[i].ID+"\t"+_list[i].name+"\t"+_list[i].phonenum+"\t"+_list[i].group;
				myFile.WriteString(_line);
				myFile.WriteString(L"\n");
			}
			myFile.Close();
		}
		else
		{
			TRACE("Can't open file %s,error=%u\n",filepath,fileException.m_cause);
		}
	}

}
vector<PhoneInfo> DataAccess::getList()
{
	return _list;
}
CString DataAccess::getFilePath()
{
	return filepath;
}
PhoneInfo DataAccess::spilitor(CString oneline)
{
	CString _tem=oneline;
	PhoneInfo _phone;
	_phone.ID=_tem.Left(_tem.Find(L"\t"));
	_tem=_tem.Right(_tem.GetLength()-_tem.Find(L"\t")-1);
	_phone.name=_tem.Left(_tem.Find(L"\t"));
	_tem=_tem.Right(_tem.GetLength()-_tem.Find(L"\t")-1);
	_phone.phonenum=_tem.Left(_tem.Find(L"\t"));
	_phone.group=_tem.Right(_tem.GetLength()-_tem.Find(L"\t")-1);
	return _phone;
}
int DataAccess::find(CString ID)
{
	for(int i=0;i<_list.size();i++)
	{
		if(_list[i].ID==ID)return i;
	}
	return -1;
}
