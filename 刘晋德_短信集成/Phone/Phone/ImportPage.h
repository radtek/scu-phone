#pragma once


// ImportPage �Ի���
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
// �Ի�������
	enum { IDD = IDD_Address_import };
	CListCtrl	m_listCtr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��	
	virtual BOOL OnInitDialog();
	afx_msg void OnOpen();
	afx_msg void Onimport();
	DECLARE_MESSAGE_MAP()
};
