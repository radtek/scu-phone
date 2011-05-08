#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// MessageDlg 对话框

class MessageDlg : public CDialog
{
	DECLARE_DYNAMIC(MessageDlg)

public:
	MessageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MessageDlg();

// 对话框数据
	enum { IDD = IDD_Main_Messagedlg };
private:
	int m_currentTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CListBox SMS_listbox_shoujian;
	CListBox SMS_listbox_caogao;
	CListBox SMS_listbox_fajian;
	CTabCtrl SMS_tabctrl;
	virtual BOOL OnInitDialog();
	CString SMS_TextContent;
	afx_msg void OnBnClickedButton2();
	CString SMS_PhoneNM;
	afx_msg void OnBnClickedButton1();
	CButton BT_fasong;
	CButton BT_cuncaogao;
	CButton BT_huifu;
	CButton BT_xinduanxin;
	CButton BT_qingkong;
	CButton BT_shanchu;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox SMS_ComboCtrl;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnDblclkList2();
	afx_msg void OnBnClickedButton4();
};

