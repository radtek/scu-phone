// QueryPage.cpp : 实现文件
//

#include "stdafx.h"
#include "Phone.h"
#include "QueryPage.h"
#include "afxdialogex.h"


// QueryPage 对话框

IMPLEMENT_DYNAMIC(QueryPage, CPropertyPage)

QueryPage::QueryPage()
	: CPropertyPage(QueryPage::IDD)
{
	table=NULL;
    m_bClickOnCheck = FALSE;
	m_bSelAll = FALSE;
}

QueryPage::~QueryPage()
{
	delete table;
	table=NULL;
}

void QueryPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_list_data, m_listCtr);
	DDX_Control(pDX, IDC_condition, m_combox);
}


BEGIN_MESSAGE_MAP(QueryPage, CPropertyPage)
    ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_Bquery, OnBquery)
	ON_BN_CLICKED(IDC_import_in_excel, Onimportinexcel)
	ON_BN_CLICKED(IDC_select_all, Onselectall)
	ON_NOTIFY(NM_RCLICK, IDC_list_data, OnRclicklistdata)
	ON_COMMAND(ID_MENUITEM_DEL, OnMenuitemDel)
	ON_NOTIFY(NM_CLICK, IDC_list_data, OnClicklistdata)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_list_data, OnItemchangedlistdata)
	ON_NOTIFY(NM_DBLCLK, IDC_list_data, OnDblclklistdata)	
	ON_COMMAND(ID_MENU_DIAL, &QueryPage::OnMenuDial)
END_MESSAGE_MAP()


// QueryPage 消息处理程序
void QueryPage::Ondelete() 
{
	// TODO: Add your control notification handler code here
	if(AfxMessageBox(TEXT("是否确认删除？"),MB_YESNO|MB_ICONQUESTION))
	{
		int nR=m_listCtr.GetItemCount();
		for ( int i = 0; i <nR ; i++ )
		{
			CString ID= m_listCtr.GetItemText( i, 0 );
			if ( m_listCtr.GetCheck( i ) )
			{
			   da.del(ID);
			   //m_listCtr.DeleteColumn(i);
			} 
		}
		table->AddItem(DataAccess::getList());
	}

}

BOOL QueryPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_combox.SetCurSel(1);
	table=new ListTable(&m_listCtr);
	table->AddItem(DataAccess::getList());
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void QueryPage::OnCancelMode() 
{
	CPropertyPage::OnCancelMode();
	
	// TODO: Add your message handler code here


}

void QueryPage::OnBquery() 
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

void QueryPage::Onimportinexcel() 
{
	// TODO: Add your control notification handler code here
	/*AccessExcel ex;
    ex.ExportListToExcel(&m_listCtr,"电话簿");*/
}

void QueryPage::Onselectall() 
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	m_bSelAll = !m_bSelAll;
	int iTaskCount =m_listCtr.GetItemCount();
	for (int i = 0; i < iTaskCount; i++)	
	{	
	   m_listCtr.SetCheck(i, m_bSelAll);
	}
	this->UpdateData(FALSE);
}
void QueryPage::OnRclicklistdata(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem != -1)
	{
		DWORD dwPos = GetMessagePos();
		CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
		
		CMenu menu;
		VERIFY( menu.LoadMenu( IDR_MENU1 ) );
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
	} 
	*pResult = 0;
}

void QueryPage::OnMenuitemDel() 
{
	// TODO: Add your command handler code here
	if(AfxMessageBox(TEXT("是否确认删除？"),MB_YESNO|MB_ICONQUESTION))
	{
		POSITION pos = m_listCtr.GetFirstSelectedItemPosition();
		int m_nIndex = m_listCtr.GetNextSelectedItem(pos);  // 得到项目索引
		
		if(m_nIndex>-1)
		{
			CString ID= m_listCtr.GetItemText(m_nIndex, 0 );
			da.del(ID);
			m_listCtr.DeleteItem(m_nIndex); 
			UINT flag = LVIS_SELECTED|LVIS_FOCUSED;
			m_listCtr.SetItemState(m_nIndex-1, flag, flag);
		}
	}
	
	

}
void QueryPage::OnClicklistdata(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		DWORD dwPos = GetMessagePos(); 
	CPoint point(LOWORD(dwPos), HIWORD(dwPos) ); 
	
	m_listCtr.ScreenToClient(&point); 
	
	LVHITTESTINFO lvinfo; 
	lvinfo.pt = point; 
	lvinfo.flags = LVHT_ABOVE; 
	
	UINT nFlag; 
	int nItem = m_listCtr.HitTest(point, &nFlag); 
    //判断是否点在checkbox上 
	if (nFlag == LVHT_ONITEMSTATEICON) 
	{ 
		//m_listCtr.SetItemState(nItem, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED);
		m_bClickOnCheck = TRUE; 
		
	} 
	
	*pResult = 0;
}

void QueryPage::OnItemchangedlistdata(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	if (m_bClickOnCheck)
	{//只响应因点击在CheckBox上而引起的状态改变
	 //因点击在全选按钮上引起的状态改变被忽略
		int nItemCount = m_listCtr.GetItemCount();
		m_bSelAll = TRUE;
		this->UpdateData(TRUE);
		for(int i = 0; i < nItemCount ;i++)
		{
			if(!m_listCtr.GetCheck(i))
			{
				m_bSelAll = FALSE;
			//	m_listCtr.SetItemState(i, 0, LVIS_SELECTED|LVIS_FOCUSED);
				break;
			}
		}
		((CButton*)GetDlgItem(IDC_select_all))->SetCheck(m_bSelAll);
		this->UpdateData(FALSE);
		m_bClickOnCheck = FALSE;
	}
	*pResult = 0;
}

void QueryPage::OnDblclklistdata(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void QueryPage::OnMenuDial()
{
	// TODO: 在此添加命令处理程序代码
	POSITION pos = m_listCtr.GetFirstSelectedItemPosition();
	int m_nIndex = m_listCtr.GetNextSelectedItem(pos);  // 得到项目索引
		
	if(m_nIndex>-1)
		{
			CString phone_number= m_listCtr.GetItemText(m_nIndex, 2 );
			MessageBox(L"正在呼叫"+ phone_number);
		}
}
