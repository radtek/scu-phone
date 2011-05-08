// ImportPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Phone.h"
#include "ImportPage.h"
#include "afxdialogex.h"


// ImportPage �Ի���

IMPLEMENT_DYNAMIC(ImportPage, CPropertyPage)

ImportPage::ImportPage()
	: CPropertyPage(ImportPage::IDD)
{
	table=NULL;
}

ImportPage::~ImportPage()
{
	delete table;
	table=NULL;
}

void ImportPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_list_excel_data, m_listCtr);

}


BEGIN_MESSAGE_MAP(ImportPage, CPropertyPage)
	ON_BN_CLICKED(IDC_open, OnOpen)
	ON_BN_CLICKED(IDC_import, Onimport)
END_MESSAGE_MAP()


// ImportPage ��Ϣ�������
BOOL ImportPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	table=new ListTable(&m_listCtr);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void ImportPage::OnOpen() 
{
	// TODO: Add your control notification handler code here
	  CFileDialog *lpszOpenFile;    //����һ��CfileDialog����
      CStdioFile file;
      CString filePathName;
      //����һ���Ի���
      lpszOpenFile = new CFileDialog(TRUE,L"",L"",OFN_FILEMUSTEXIST |OFN_HIDEREADONLY , L"�ļ�����(*.txt)|*.txt");
     
      if(lpszOpenFile->DoModal() == IDOK )//�������Ի���ȷ����ť
      {
             filePathName = lpszOpenFile->GetPathName();//�õ����ļ���·��
             GetDlgItem(IDC_FilePath)->SetWindowText(filePathName);//�ڴ��ڱ�������ʾ·��
      }
 
      if(filePathName == "")  return;
 
      if(!file.Open(filePathName,CFile::modeRead))
      {
             MessageBox(L"can not open file!");
             return;
      }
 
      CString strLine,strTemp;
	  
      while(file.ReadString(strLine))
      {
		  int n=0;
		  for(int i=0;i<strLine.GetLength();i++)
		  {
			  if(strLine.GetAt(i)=='\t')n++;
		  }
		  if(n==2)
		  {
			  PhoneInfo _phone;
			 _phone.ID=getDateTime();
			 _phone.name=strLine.Left(strLine.Find(L"\t"));
			 strTemp=strLine.Right(strLine.GetLength()-strLine.Find(L"\t")-1);
			 _phone.phonenum=strTemp.Left(strTemp.Find(L"\t"));
			 _phone.group=strTemp.Right(strTemp.GetLength()-strTemp.Find(L"\t")-1);
			  _tempList.push_back(_phone);
		  }
		  else 
		  {
			  MessageBox(L"���ݸ�ʽ����ȷ������!");
			  break;
		  }
      }
	  if(_tempList.size()>0)table->AddItem(_tempList);
      delete lpszOpenFile;//�ͷŷ���ĶԻ���
}



void ImportPage::Onimport() 
{
	// TODO: Add your control notification handler code here
	if(_tempList.size()>0&&AfxMessageBox(TEXT("�Ƿ�ȷ�ϱ��棿"),MB_YESNO|MB_ICONQUESTION))
	{
		for(int i=0;i<_tempList.size();i++)da.add(_tempList[i]);
		
	}
}
