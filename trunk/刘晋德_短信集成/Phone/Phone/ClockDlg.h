#pragma once


// ClockDlg �Ի���

class ClockDlg : public CDialog
{
	DECLARE_DYNAMIC(ClockDlg)

public:
	ClockDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClockDlg();

// �Ի�������
	enum { IDD = IDD_Main_Clockdlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
