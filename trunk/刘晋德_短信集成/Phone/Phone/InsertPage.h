#pragma once


// InsertPage �Ի���

class InsertPage : public CPropertyPage
{
	DECLARE_DYNAMIC(InsertPage)

public:
	InsertPage();
	virtual ~InsertPage();
	CComboBox	_combox;
// �Ի�������
	enum { IDD = IDD_Address_insert };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void Onadd();
	afx_msg void Oncancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnChangemobelphone();
	DECLARE_MESSAGE_MAP()
};
