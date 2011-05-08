// ListTable.cpp: implementation of the ListTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Phone.h"
#include "ListTable.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ListTable::ListTable()
{
}
ListTable::ListTable(CListCtrl *_Ctr)
{
	_listCtr=_Ctr;
	Initial();
}
ListTable::~ListTable()
{
}
bool ListTable::AddItem(vector<PhoneInfo> _list)
{
   _listCtr->DeleteAllItems();
	if(_list.size()>0)
	{
		int len=_list.size();
		for(int i=0;i<len;i++)
		{
			_listCtr->InsertItem(i,_list[i].ID); 
			_listCtr->SetItemText(i,1,_list[i].name);
			_listCtr->SetItemText(i,2,_list[i].phonenum);
			_listCtr->SetItemText(i,3,_list[i].group);
		}
		return true;
	}
	else return false;
}
void ListTable::setListCtr(CListCtrl *_listCtr)
{
	this->_listCtr=_listCtr;
}
void ListTable::Initial()
{
	LONG lStyle;
	lStyle = GetWindowLong(_listCtr->m_hWnd, GWL_STYLE);//获取当前窗口style
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位
	lStyle |= LVS_REPORT; //设置style
	SetWindowLong(_listCtr->m_hWnd, GWL_STYLE, lStyle);//设置style
	DWORD dwStyle = _listCtr->GetExtendedStyle();
	
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
	_listCtr->SetExtendedStyle(dwStyle); //设置扩展风格
	//初始化数据
	_listCtr->InsertColumn(0,L"ID",LVCFMT_LEFT,20);
    _listCtr->InsertColumn(1,L"姓名",LVCFMT_CENTER,100);
    _listCtr->InsertColumn(2,L"电话",LVCFMT_CENTER,250);
    _listCtr->InsertColumn(3,L"分组",LVCFMT_LEFT,94);
}
