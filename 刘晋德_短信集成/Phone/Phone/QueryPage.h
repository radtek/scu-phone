#pragma once


// QueryPage 对话框
#include "ListTable.h"
//#include "AccessExcel.h"
class QueryPage : public CPropertyPage
{
	DECLARE_DYNAMIC(QueryPage)

public:
	BOOL m_bClickOnCheck;
	BOOL m_bSelAll;
	CListCtrl	m_listCtr;
	CComboBox	m_combox;
	QueryPage();
	virtual ~QueryPage();

// 对话框数据
	enum { IDD = IDD_Address_query };
	ListTable *table;
	DataAccess da;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Ondelete();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnBquery();
	afx_msg void Onimportinexcel();
	afx_msg void Onselectall();
	afx_msg void OnRclicklistdata(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemDel();
	afx_msg void OnClicklistdata(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedlistdata(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclklistdata(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuDial();
};
