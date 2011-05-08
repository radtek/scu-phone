// MessageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Phone.h"
#include "MessageDlg.h"
#include "afxdialogex.h"
#include <afxmsg_.h>


// MessageDlg �Ի���

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


// MessageDlg ��Ϣ�������


void MessageDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_currentTab = 0;
	SMS_tabctrl.InsertItem(0, _T("�ռ���"));
	SMS_tabctrl.InsertItem(1, _T("�ݸ���"));
	SMS_tabctrl.InsertItem(2, _T("������"));
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
	SMS_listbox_shoujian.AddString(_T("�������ݣ���ã� ���ź��룺110"));
	SMS_listbox_shoujian.AddString(_T("�������ݣ����ٻض��ţ� ���ź��룺119"));
	SMS_listbox_shoujian.AddString(_T("�������ݣ��ö��Ų��ûأ� ���ź��룺120"));
	SMS_ComboCtrl.AddString(_T("��ã�"));
	SMS_ComboCtrl.AddString(_T("����æ���Ժ�ظ�"));
	SMS_ComboCtrl.AddString(_T("�ϵط�����"));
	BT_qingkong.EnableWindow(false);
	BT_fasong.EnableWindow(false);
	BT_cuncaogao.EnableWindow(false);
	BT_huifu.EnableWindow(true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}





void MessageDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	SMS_listbox_caogao.AddString(_T("�������ݣ�") + SMS_TextContent + _T("���룺") + SMS_PhoneNM);
}


void MessageDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	SMS_listbox_fajian.AddString(_T("�������ݣ�") + SMS_TextContent + _T("���룺") + SMS_PhoneNM);
}


void MessageDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BT_qingkong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
	BT_fasong.EnableWindow(true);
}


void MessageDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BT_qingkong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
	BT_fasong.EnableWindow(true);
}


void MessageDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SMS_PhoneNM.Empty();
	SMS_TextContent.Empty();
	BT_qingkong.EnableWindow(false);
	UpdateData(false);
}



void MessageDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = SMS_ComboCtrl.GetCurSel();
	CString strModel;
	SMS_ComboCtrl.GetLBText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	SMS_listbox_fajian.AddString(SMS_TextContent);
}


void MessageDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = SMS_listbox_shoujian.GetCurSel();
	CString strModel;
	SMS_listbox_shoujian.GetText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnLbnDblclkList2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = SMS_listbox_caogao.GetCurSel();
	CString strModel;
	SMS_listbox_caogao.GetText(nIndex,strModel);
	SMS_TextContent.SetString(strModel);
	BT_qingkong.EnableWindow(true);
	UpdateData(false);
}


void MessageDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BT_huifu.EnableWindow(false);
	BT_fasong.EnableWindow(true);
	BT_cuncaogao.EnableWindow(true);
}
