// AddressDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Phone.h"
#include "AddressDlg.h"
#include "afxdialogex.h"


// AddressDlg �Ի���

IMPLEMENT_DYNAMIC(AddressDlg, CDialog)

AddressDlg::AddressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AddressDlg::IDD, pParent)
{

}

AddressDlg::~AddressDlg()
{
}

void AddressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddressDlg, CDialog)
	ON_BN_CLICKED(IDC_query, &AddressDlg::OnBnClickedquery)
	ON_BN_CLICKED(IDC_insert, &AddressDlg::OnBnClickedinsert)
	ON_BN_CLICKED(IDC_update, &AddressDlg::OnBnClickedupdate)
	ON_BN_CLICKED(IDC_import, &AddressDlg::OnBnClickedimport)
END_MESSAGE_MAP()


// AddressDlg ��Ϣ�������
BOOL AddressDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	importpage.Create(IDD_Address_import,this);
	insertpage.Create(IDD_Address_insert,this);
	updatepage.Create(IDD_Address_update,this);
	querypage.Create(IDD_Address_query,this);
	CRect rcDlgs;
    GetDlgItem(IDC_panel2)->GetWindowRect(rcDlgs);
    ScreenToClient(rcDlgs);
	importpage.MoveWindow(rcDlgs);
	updatepage.MoveWindow(rcDlgs);
	insertpage.MoveWindow(rcDlgs);
	querypage.MoveWindow(rcDlgs);
    (&querypage)->ShowWindow(SW_SHOW);
	m_dlg_created=true;
	return TRUE;
}


void AddressDlg::OnBnClickedquery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_dlg_created)
	{
		(&insertpage)->ShowWindow(SW_HIDE);
		(&importpage)->ShowWindow(SW_HIDE);
		(&querypage)->ShowWindow(SW_SHOW);
		(&updatepage)->ShowWindow(SW_HIDE);
	}

}


void AddressDlg::OnBnClickedinsert()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_dlg_created)
	{
		(&insertpage)->ShowWindow(SW_SHOW);
		(&importpage)->ShowWindow(SW_HIDE);
		(&querypage)->ShowWindow(SW_HIDE);
		(&updatepage)->ShowWindow(SW_HIDE);
	}
}


void AddressDlg::OnBnClickedupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_dlg_created)
	{
		(&insertpage)->ShowWindow(SW_HIDE);
		(&importpage)->ShowWindow(SW_HIDE);
		(&querypage)->ShowWindow(SW_HIDE);
		(&updatepage)->ShowWindow(SW_SHOW);
	}
}


void AddressDlg::OnBnClickedimport()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_dlg_created)
	{
		(&insertpage)->ShowWindow(SW_HIDE);
		(&importpage)->ShowWindow(SW_SHOW);
		(&querypage)->ShowWindow(SW_HIDE);
		(&updatepage)->ShowWindow(SW_HIDE);
	}
}
