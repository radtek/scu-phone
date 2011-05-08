// ListTable.h: interface for the ListTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTTABLE_H__96761608_E9A4_4ACF_87CD_52FA7101A2F1__INCLUDED_)
#define AFX_LISTTABLE_H__96761608_E9A4_4ACF_87CD_52FA7101A2F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "DataAccess.h"
using namespace std;
class ListTable  
{
public:
	void CancelAll();
	ListTable();
	ListTable(CListCtrl *_Ctr);
	virtual ~ListTable();
	bool AddItem(vector<PhoneInfo> _list);
	void setListCtr(CListCtrl *_listCtr);
private:
	CListCtrl *_listCtr;
	void Initial();

};

#endif // !defined(AFX_LISTTABLE_H__96761608_E9A4_4ACF_87CD_52FA7101A2F1__INCLUDED_)
