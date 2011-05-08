#pragma once


// ClockDlg 对话框

class ClockDlg : public CDialog
{
	DECLARE_DYNAMIC(ClockDlg)

public:
	ClockDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClockDlg();

// 对话框数据
	enum { IDD = IDD_Main_Clockdlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
