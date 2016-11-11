// Setlevel.cpp : 实现文件
//

#include "stdafx.h"
#include "PlaneWars.h"
#include "Setlevel.h"
#include "afxdialogex.h"
#include "resource.h"

// CSetlevel 对话框

IMPLEMENT_DYNAMIC(CSetlevel, CDialog)

CSetlevel::CSetlevel(CWnd* pParent /*=NULL*/)
	: CDialog(CSetlevel::IDD, pParent)
	, m_level(0)
{

}

CSetlevel::~CSetlevel()
{
}

void CSetlevel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_level, m_level);
	DDV_MinMaxInt(pDX, m_level, 0, 100);
}


BEGIN_MESSAGE_MAP(CSetlevel, CDialog)
END_MESSAGE_MAP()


// CSetlevel 消息处理程序
