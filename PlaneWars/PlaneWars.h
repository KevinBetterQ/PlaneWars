
// PlaneWars.h : PlaneWars Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPlaneWarsApp:
// �йش����ʵ�֣������ PlaneWars.cpp
//

class CPlaneWarsApp : public CWinApp
{
public:
	CPlaneWarsApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPlaneWarsApp theApp;
