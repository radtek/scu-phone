#pragma once


// InsertPage 对话框

class InsertPage : public CPropertyPage
{
	DECLARE_DYNAMIC(InsertPage)

public:
	InsertPage();
	virtual ~InsertPage();
	CComboBox	_combox;
// 对话框数据
	enum { IDD = IDD_Address_insert };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void Onadd();
	afx_msg void Oncancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnChangemobelphone();
	DECLARE_MESSAGE_MAP()
};
