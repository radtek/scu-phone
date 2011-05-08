// MessageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "MessageDlg.h"
#include "afxdialogex.h"
#include <afxmsg_.h>


// MessageDlg 对话框

IMPLEMENT_DYNAMIC(MessageDlg, CDialog)

MessageDlg::MessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MessageDlg::IDD, pParent)
	, SMS_TextContent(_T(""))
	, SMS_PhoneNM(_T(""))
{
	
}

MessageDlg::~MessageDlg()
{
}

void MessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, SMS_listbox_shoujian);
	DDX_Control(pDX, IDC_LIST2, SMS_listbox_caogao);
	DDX_Control(pDX, IDC_LIST3, SMS_listbox_fajian);
	DDX_Control(pDX, IDC_TAB1, SMS_tabctrl);
	DDX_Text(pDX, IDC_EDIT1, SMS_TextContent);
	DDX_Text(pDX, IDC_EDIT2, SMS_PhoneNM);
	DDX_Control(pDX, IDC_BUTTON1, BT_fasong);
	DDX_Control(pDX, IDC_BUTTON2, BT_cuncaogao);
	DDX_Control(pDX, IDC_BUTTON3, BT_huifu);
	DDX_Control(pDX, IDC_BUTTON4, BT_xinduanxin);
	DDX_Control(pDX, IDC_BUTTON5, BT_qingkong);
	DDX_Control(pDX, IDC_BUTTON7, BT_shanchu);
	DDX_Control(pDX, IDC_COMBO1, SMS_ComboCtrl);
}


BEGIN_MESSAGE_MAP(MessageDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &MessageDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON2, &MessageDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &MessageDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &MessageDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &MessageDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &MessageDlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &MessageDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &MessageDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &MessageDlg::OnBnClickedButton7)
	ON_LBN_DBLCLK(IDC_LIST1, &MessageDlg::OnLbnDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, &MessageDlg::OnLbnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON4, &MessageDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// MessageDlg 消息处理程序


void MessageDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = SMS_tabctrl.GetCurSel();
	switch(sel)
	{
	case 0:
		SMS_listbox_shoujian.ShowWindow(SW_SHOW);
		SMS_listbox_caogao.ShowWindow(SW_HIDE);
		SMS_listbox_fajian.ShowWindow(SW_HIDE);
		SMS_listbox_shoujian.SetFocus();
		m_currentTab = sel;
		BT_fasong.EnableWindow(false);
		BT_cuncaogao.EnableWindow(false);
		BT_huifu.EnableWindow(true);
		UpdateData(false);
		break;
	case 1:
		SMS_listbox_shoujian.ShowWindow(SW_HIDE);
		SMS_listbox_caogao.ShowWindow(SW_SHOW);
		SMS_listbox_fajian.ShowWindow(SW_HIDE);
		SMS_listbox_caogao.SetFocus();
		m_currentTab = sel;
		BT_fasong.EnableWindow(true);
		BT_cuncaogao.EnableWindow(false);
		BT_huifu.EnableWindow(false);
		UpdateData(false);
		break;
	case  2:
		SMS_listbox_shoujian.ShowWindow(SW_HIDE);
		SMS_listbox_caogao.ShowWindow(SW_HIDE);
		SMS_listbox_fajian.ShowWindow(SW_SHOW);
		SMS_listbox_fajian.SetFocus();
		m_currentTab = sel;
		BT_fasong.EnableWindow(false);
		BT_cuncaogao.EnableWindow(false);
		BT_huifu.EnableWindow(false);
		UpdateData(false);
		break;
	}
}
BOOL MessageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_currentTab = 0;
	SMS_tabctrl.InsertItem(0, _T("收件箱"));
	SMS_tabctrl.InsertItem(1, _T("草稿箱"));
	SMS_tabctrl.InsertItem(2, _T("发件箱"));
	CRect tabRect,itemRect;
	SMS_tabctrl.GetItemRect(0, &tabRect);
	GetClientRect(&itemRect);
	int X, Y, nX, nY;
	X = tabRect.left;
	Y = tabRect.top +20;
	nX = itemRect.right;
	nY = itemRect.bottom  - 250;
	SMS_listbox_shoujian.SetWindowPos(&wndTop,X, Y, nX, nY, SWP_SHOWWINDOW);
	SMS_listbox_caogao.SetWindowPos(&wndTop, X, Y, nX, nY,  SWP_HIDEWINDOW);
	SMS_listbox_fajian.SetWindowPos(&wndTop, X, Y, nX, nY,  SWP_HIDEWINDOW);
	SMS_listbox_shoujian.AddString(_T("短信内容：你好！ 短信号码：110"));
	SMS_listbox_shoujian.AddString(_T("短信内容：请速回短信！ 短信号码：119"));
	SMS_listbox_shoujian.AddString(_T("短信内容：该短信不用回！ 短信号码：120"));
	SMS_ComboCtrl.AddString(_T("你好！"));
	SMS_ComboCtrl.AddString(_T("正在忙，稍后回复"));
	SMS_ComboCtrl.AddString(_T("老地方见！"));
	BT_qingkong.EnableWindow(false);
	BT_fasong.EnableWindow(false);
	BT_cuncaogao.EnableWindow(false);
	BT_huifu.EnableWindow(true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}





void MessageDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	SMS_listbox_caogao.AddString(_T("短信内容：") + SMS_TextContent + _T("号码：") + SMS_PhoneNM);
}


void MessageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	SMS_listbox_fajian.AddString(_T("短信内容：") + SMS_TextContent + _T("号码：") + SMS_PhoneNM);
}


void MessageDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	BT_qingkong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
	BT_fasong.EnableWindow(true);
}


void MessageDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	BT_qingkong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
	BT_fasong.EnableWindow(true);
}


void MessageDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	SMS_PhoneNM.Empty();
	SMS_TextContent.Empty();
	BT_qingkong.EnableWindow(false);
	UpdateData(false);
}



void MessageDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = SMS_ComboCtrl.GetCurSel();
	CString strModel;
	SMS_ComboCtrl.GetLBText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	SMS_listbox_fajian.AddString(SMS_TextContent);
}


void MessageDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = 0;
	switch(m_currentTab)
	{
	case 0:
		sel = SMS_listbox_shoujian.GetCurSel();
		SMS_listbox_shoujian.DeleteString(sel);
		UpdateData(false);
		break;
	case 1:
		sel = SMS_listbox_caogao.GetCurSel();
		SMS_listbox_caogao.DeleteString(sel);
		UpdateData(false);
		break;
	case 3:
		sel = SMS_listbox_fajian.GetCurSel();
		SMS_listbox_fajian.DeleteString(sel);
		UpdateData(false);
		break;
	}
}


void MessageDlg::OnLbnDblclkList1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = SMS_listbox_shoujian.GetCurSel();
	CString strModel;
	SMS_listbox_shoujian.GetText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnLbnDblclkList2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = SMS_listbox_caogao.GetCurSel();
	CString strModel;
	SMS_listbox_caogao.GetText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	BT_huifu.EnableWindow(false);
	BT_fasong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
}
