#pragma once
#include "afxcmn.h"

class TabCtrl :
	public CTabCtrl
{
public:
	TabCtrl(void);
	~TabCtrl(void);
	CDialog *m_tabPages[4];
	int m_tabCurrent;
	int m_nNumberOfPages;

// Attributes
public:

// Operations
public:
	void Init();
	void SetRectangle();
protected:
	//{{AFX_MSG(CMyTabCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

