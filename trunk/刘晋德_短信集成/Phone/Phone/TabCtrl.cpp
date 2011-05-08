#include "stdafx.h"
#include "Phone.h"
#include "TabCtrl.h"
#include "ClockDlg.h"
#include "MessageDlg.h"
#include "DialDlg.h"
#include "AddressDlg.h"
TabCtrl::TabCtrl()
{
	m_tabPages[0]=new DialDlg;
	m_tabPages[1]=new AddressDlg;
	m_tabPages[2]=new MessageDlg;
	m_tabPages[3]=new ClockDlg;
	m_nNumberOfPages=4;
}

TabCtrl::~TabCtrl()
{
	for(int nCount=0; nCount < m_nNumberOfPages; nCount++){
		delete m_tabPages[nCount];
	}
}

void TabCtrl::Init()
{
	m_tabCurrent=0;
	m_tabPages[0]->Create(IDD_Main_Dialdlg,this);
	m_tabPages[1]->Create(IDD_Main_Addressdlg,this);
	m_tabPages[2]->Create(IDD_Main_Messagedlg,this);
	m_tabPages[3]->Create(IDD_Main_Clockdlg,this);
	m_tabPages[0]->ShowWindow(SW_SHOW);
	m_tabPages[1]->ShowWindow(SW_HIDE);
	m_tabPages[2]->ShowWindow(SW_HIDE);
	m_tabPages[3]->ShowWindow(SW_HIDE);
	SetRectangle();
}

void TabCtrl::SetRectangle()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	nX=itemRect.left;
	nY=itemRect.bottom+1;
	nXc=tabRect.right-itemRect.left-1;
	nYc=tabRect.bottom-nY-1;

	m_tabPages[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for(int nCount=1; nCount < m_nNumberOfPages; nCount++){
		m_tabPages[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
	}
}

BEGIN_MESSAGE_MAP(TabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(TabCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TabCtrl message handlers

void TabCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CTabCtrl::OnLButtonDown(nFlags, point);

	if(m_tabCurrent != GetCurFocus()){
		m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
		m_tabCurrent=GetCurFocus();
		m_tabPages[m_tabCurrent]->ShowWindow(SW_SHOW);
		m_tabPages[m_tabCurrent]->SetFocus();
	}
}
