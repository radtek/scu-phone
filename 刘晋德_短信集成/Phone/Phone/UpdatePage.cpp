// UpdatePage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Phone.h"
#include "UpdatePage.h"
#include "afxdialogex.h"


// UpdatePage �Ի���

IMPLEMENT_DYNAMIC(UpdatePage, CPropertyPage)

UpdatePage::UpdatePage()
	: CPropertyPage(UpdatePage::IDD)
{
	  table=NULL;
	m_list.Add(_T("����"));
	m_list.Add(_T("����"));
	m_list.Add(_T("ͬ��"));
	m_list.Add(_T("ͬѧ"));
}

UpdatePage::~UpdatePage()
{
	delete table;
	table=NULL;
}

void UpdatePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_type, m_comboxType);
	DDX_Control(pDX, IDC_Result, m_listCtr);
	DDX_Control(pDX, IDC_condition, m_combox);
}


BEGIN_MESSAGE_MAP(UpdatePage, CPropertyPage)
	ON_BN_CLICKED(IDC_Bquery, OnBquery)
	ON_BN_CLICKED(IDC_Clear, OnClear)
	ON_BN_CLICKED(IDC_Save, OnSave)
	ON_WM_CANCELMODE()
	ON_NOTIFY(NM_DBLCLK, IDC_Result, OnDblclkResult)
	ON_NOTIFY(NM_RCLICK, IDC_Result, OnRclickResult)
	ON_COMMAND(ID_MENUITEMEDIT, OnMenuitemedit)
END_MESSAGE_MAP()


// UpdatePage ��Ϣ�������
BOOL UpdatePage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
    
	m_combox.SetCurSel(1);
	table=new ListTable(&m_listCtr);
	table->AddItem(DataAccess::getList());
	((CComboBox*)GetDlgItem(IDC_type))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void UpdatePage::OnCancelMode() 
{
	CPropertyPage::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
void UpdatePage::OnBquery() 
{
	// TODO: Add your control notification handler code here
	CString _data;
	
    GetDlgItem(IDC_EDIT)-> GetWindowText(_data);
	if(_data!="")
	{
		int index=m_combox.GetCurSel();
		switch(index)
		{
		case 0:
			table->AddItem(da.queryByGroup(_data));
			break;
		case 1:
			table->AddItem(da.queryByName(_data));
			break;
		default:
			break;
		}
	}
	else table->AddItem(DataAccess::getList());
}

void UpdatePage::OnClear() 
{
	// TODO: Add your control notification handler code here
		GetDlgItem(IDC_name)-> SetWindowText(L"");
		GetDlgItem(IDC_moble_phone)-> SetWindowText(L"");
}
void UpdatePage::OnSave() 
{
	// TODO: Add your control notification handler code here
	PhoneInfo _phone;
	GetDlgItem(IDC_ID)-> GetWindowText(_phone.ID);
	GetDlgItem(IDC_name)-> GetWindowText(_phone.name);
	GetDlgItem(IDC_moble_phone)-> GetWindowText(_phone.phonenum);
	GetDlgItem(IDC_type)-> GetWindowText(_phone.group);

	if(_phone.name!=""&&_phone.phonenum!=""&&_phone.group!="")
	{
		if(da.update(_phone))
		{
			table->AddItem(DataAccess::getList());
			MessageBox(L"�޸ĳɹ�");
		}
		else
		{
			MessageBox(L"�޸�ʧ��");
		}
	}
	else MessageBox(L"��Ϣ����Ϊ��");
}
void UpdatePage::OnDblclkResult(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnMenuitemedit();
	*pResult = 0;
}

void UpdatePage::OnRclickResult(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem != -1)
	{
		DWORD dwPos = GetMessagePos();
		CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
		
		CMenu menu;
		VERIFY( menu.LoadMenu( IDR_MENU2 ) );
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
	} 
	*pResult = 0;
}

void UpdatePage::OnMenuitemedit() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_listCtr.GetFirstSelectedItemPosition();
	int m_nIndex = m_listCtr.GetNextSelectedItem(pos);  // �õ���Ŀ����
	
	if(m_nIndex>-1)
	{
		CString cm;
		GetDlgItem(IDC_ID)-> SetWindowText(m_listCtr.GetItemText(m_nIndex, 0 ));
		GetDlgItem(IDC_name)-> SetWindowText(m_listCtr.GetItemText(m_nIndex, 1 ));
		GetDlgItem(IDC_moble_phone)-> SetWindowText(m_listCtr.GetItemText(m_nIndex, 2));
		CString group=m_listCtr.GetItemText(m_nIndex, 3 );
	
		UpdateData(TRUE);
		for(int i=0;i<m_list.GetSize();i++)
		{
			cm=m_list[i];
			if(group==cm)
			{
				((CComboBox*)GetDlgItem(IDC_type))->SetCurSel(i); UpdateData(FALSE);
					break;
			}
		
		}
	   

	}
}
