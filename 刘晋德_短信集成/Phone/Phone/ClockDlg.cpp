// ClockDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Phone.h"
#include "ClockDlg.h"
#include "afxdialogex.h"


// ClockDlg �Ի���

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


// ClockDlg ��Ϣ�������
