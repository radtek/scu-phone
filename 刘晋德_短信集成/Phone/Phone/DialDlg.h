#pragma once


// DialDlg �Ի���

class DialDlg : public CDialog
{
	DECLARE_DYNAMIC(DialDlg)

public:
	DialDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialDlg();

// �Ի�������
	enum { IDD = IDD_Main_Dialdlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
