// ClockDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "ClockDlg.h"
#include "afxdialogex.h"


// ClockDlg 对话框

IMPLEMENT_DYNAMIC(ClockDlg, CDialog)

ClockDlg::ClockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ClockDlg::IDD, pParent)
{

}

ClockDlg::~ClockDlg()
{
}

void ClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClockDlg, CDialog)
END_MESSAGE_MAP()


// ClockDlg 消息处理程序
