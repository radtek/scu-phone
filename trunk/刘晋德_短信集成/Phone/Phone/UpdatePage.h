#pragma once


// UpdatePage 对话框
#include "ListTable.h"
class UpdatePage : public CPropertyPage
{
	DECLARE_DYNAMIC(UpdatePage)

public:
	UpdatePage();
	virtual ~UpdatePage();
	CComboBox	m_comboxType;
	CListCtrl	m_listCtr;
	CComboBox	m_combox;
private:
		ListTable *table;
		DataAccess da;	
		CStringArray m_list;
// 对话框数据
	enum { IDD = IDD_Address_update };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnBquery();
	afx_msg void OnClear();
	afx_msg void OnSave();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnDblclkResult(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickResult(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemedit();
	DECLARE_MESSAGE_MAP()
};
