// DialDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "DialDlg.h"
#include "afxdialogex.h"


// DialDlg 对话框

IMPLEMENT_DYNAMIC(DialDlg, CDialog)

DialDlg::DialDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DialDlg::IDD, pParent)
{

}

DialDlg::~DialDlg()
{
}

void DialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialDlg, CDialog)
END_MESSAGE_MAP()


// DialDlg 消息处理程序
