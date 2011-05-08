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
	lStyle = GetWindowLong(_listCtr->m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
	lStyle &= ~LVS_TYPEMASK; //�����ʾ��ʽλ
	lStyle |= LVS_REPORT; //����style
	SetWindowLong(_listCtr->m_hWnd, GWL_STYLE, lStyle);//����style
	DWORD dwStyle = _listCtr->GetExtendedStyle();
	
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
	_listCtr->SetExtendedStyle(dwStyle); //������չ���
	//��ʼ������
	_listCtr->InsertColumn(0,L"ID",LVCFMT_LEFT,20);
    _listCtr->InsertColumn(1,L"����",LVCFMT_CENTER,100);
    _listCtr->InsertColumn(2,L"�绰",LVCFMT_CENTER,250);
    _listCtr->InsertColumn(3,L"����",LVCFMT_LEFT,94);
}
