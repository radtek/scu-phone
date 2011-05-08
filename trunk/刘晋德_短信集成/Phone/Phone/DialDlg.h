#pragma once


// DialDlg 对话框

class DialDlg : public CDialog
{
	DECLARE_DYNAMIC(DialDlg)

public:
	DialDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DialDlg();

// 对话框数据
	enum { IDD = IDD_Main_Dialdlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
