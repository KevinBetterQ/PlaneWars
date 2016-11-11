#include "stdafx.h"
#include "Protection.h"
#include "resource.h"
CImageList CProtection::m_Images;
CProtection::CProtection()
{
	//设置随机产生位置
	srand(GetTickCount());
	m_ptPos.x = rand() % 10*100;
	m_ptPos.y = rand() % 6*100;
}


CProtection::~CProtection()
{
}

BOOL CProtection::draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.y += 4;//竖直掉落
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}
BOOL CProtection::Draw(CDC* pDC)
{
	m_ptPos.y += 4;//竖直掉落
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
}

BOOL CProtection::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_protect, RGB(0, 0, 0), 30, 21, 1);
}