// DataAccess.h: interface for the DataAccess class.
//
//////////////////////////////////////////////////////////////////////
#ifndef DATAACCESS_H
#define DATAACCESS_H
#include<vector>
using namespace std;
typedef struct PHONE
{
	CString ID;
	CString name;
	CString phonenum;
	CString group;
}PhoneInfo;
static CString getDateTime()
{   
	SYSTEMTIME st;
	CString strDateTime;
	GetLocalTime(&st);
	strDateTime.Format(L"%4d-%2d-%2d-%2d-%2d-%2d-%3d",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);
	return strDateTime;
}

class DataAccess  
{
public:
	DataAccess();
	virtual ~DataAccess();
	bool add(PhoneInfo phone);
    bool del(CString id);
	bool update(PhoneInfo phone);
	PhoneInfo *queryByID(CString ID);
    vector<PhoneInfo> queryByName(CString name);
	vector<PhoneInfo> queryByGroup(CString group);
	static void ReadData();
	static void SaveData();
	static vector<PhoneInfo> getList();
	static CString getFilePath();
private:
	static PhoneInfo spilitor(CString oneline);
	int find(CString ID);
	static vector<PhoneInfo> _list;
	static CString filepath;

};
#endif 
