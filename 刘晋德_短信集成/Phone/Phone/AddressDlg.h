#pragma once


// AddressDlg �Ի���
#include "InsertPage.h"
#include "UpdatePage.h"
#include "QueryPage.h"
#include "ImportPage.h"
class AddressDlg : public CDialog
{
	DECLARE_DYNAMIC(AddressDlg)

public:
	ImportPage importpage;
	InsertPage insertpage;
	QueryPage querypage;
    UpdatePage updatepage;
	AddressDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddressDlg();

// �Ի�������
	enum { IDD = IDD_Main_Addressdlg };

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedquery();
	afx_msg void OnBnClickedinsert();
	afx_msg void OnBnClickedupdate();
	afx_msg void OnBnClickedimport();
private:
	bool m_dlg_created;
};
