#pragma once


// ImportPage 对话框
#include "ListTable.h"
class ImportPage : public CPropertyPage
{
	DECLARE_DYNAMIC(ImportPage)

public:
	ImportPage();
	virtual ~ImportPage();
	ListTable *table;
	DataAccess da;
	vector<PhoneInfo> _tempList;
// 对话框数据
	enum { IDD = IDD_Address_import };
	CListCtrl	m_listCtr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持	
	virtual BOOL OnInitDialog();
	afx_msg void OnOpen();
	afx_msg void Onimport();
	DECLARE_MESSAGE_MAP()
};
