
// Phone.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "DataAccess.h"
// CPhoneApp:
// �йش����ʵ�֣������ Phone.cpp
//

class CPhoneApp : public CWinApp
{
public:
	CPhoneApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPhoneApp theApp;