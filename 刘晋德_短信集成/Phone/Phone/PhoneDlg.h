
// PhoneDlg.h : ͷ�ļ�
//

#pragma once
// CPhoneDlg �Ի���
#include "TabCtrl.h"
class CPhoneDlg : public CDialogEx
{
// ����
public:
	CPhoneDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_Maindlg };
	TabCtrl _TabCtrl;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	
private:
	int m_tabCurrent;
	int m_nNumberOfPages;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};
