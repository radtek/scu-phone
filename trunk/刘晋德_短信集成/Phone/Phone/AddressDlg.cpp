// AddressDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "AddressDlg.h"
#include "afxdialogex.h"


// AddressDlg 对话框

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


// AddressDlg 消息处理程序
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	if(m_dlg_created)
	{
		(&insertpage)->ShowWindow(SW_HIDE);
		(&importpage)->ShowWindow(SW_SHOW);
		(&querypage)->ShowWindow(SW_HIDE);
		(&updatepage)->ShowWindow(SW_HIDE);
	}
}
