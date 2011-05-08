// InsertPage.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "InsertPage.h"
#include "afxdialogex.h"



// InsertPage 对话框

IMPLEMENT_DYNAMIC(InsertPage, CPropertyPage)

InsertPage::InsertPage()
	: CPropertyPage(InsertPage::IDD)
{

}

InsertPage::~InsertPage()
{
}

void InsertPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_type, _combox);
}


BEGIN_MESSAGE_MAP(InsertPage, CPropertyPage)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_cancel, Oncancel)
	ON_WM_CANCELMODE()
	ON_EN_CHANGE(IDC_mobel_phone, OnChangemobelphone)
END_MESSAGE_MAP()


// InsertPage 消息处理程序
void InsertPage::Oncancel() 
{
 	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_ShowError)->SetWindowText(L"");
 	GetDlgItem(IDC_name)-> SetWindowText(L"");
 	GetDlgItem(IDC_type)-> SetWindowText(L"");
 	GetDlgItem(IDC_mobel_phone)-> SetWindowText(L"");
 }

void InsertPage::Onadd() 
{
	// TODO: Add your control notification handler code here
	PhoneInfo _phone;
	 _phone.ID=getDateTime();
    GetDlgItem(IDC_name)-> GetWindowText(_phone.name);
	GetDlgItem(IDC_type)-> GetWindowText(_phone.group);
	GetDlgItem(IDC_mobel_phone)-> GetWindowText(_phone.phonenum);
	DataAccess dc;
	if(_phone.name!=""&&_phone.phonenum!=""&&dc.add(_phone))
	{
		GetDlgItem(IDC_ShowError)->SetWindowText(L"");
		MessageBox(L"添加成功");
	}
	else MessageBox(L"添加失败");

}

BOOL InsertPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	/*_combox.AddString(_T("好友"));
	_combox.AddString(_T("亲人"));
	_combox.AddString(_T("同学"));
	_combox.AddString(_T("同事"));
	_combox.AddString(_T("上司"));
	*/
	_combox.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void InsertPage::OnCancelMode() 
{
	CPropertyPage::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void InsertPage::OnChangemobelphone() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString _temp;
	int size=0;
	GetDlgItem(IDC_mobel_phone)->GetWindowText(_temp);
	size=_temp.GetLength();
	if(size>0)
	{
		char ch=_temp.GetAt(size-1);
		if(!((ch>'47'&&ch<'58')||ch=='95'))GetDlgItem(IDC_ShowError)->SetWindowText(L"非法字符");
	}
	
}
