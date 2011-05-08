
// PhoneDlg.h : 头文件
//

#pragma once
// CPhoneDlg 对话框
#include "TabCtrl.h"
class CPhoneDlg : public CDialogEx
{
// 构造
public:
	CPhoneDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_Maindlg };
	TabCtrl _TabCtrl;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	
private:
	int m_tabCurrent;
	int m_nNumberOfPages;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};
