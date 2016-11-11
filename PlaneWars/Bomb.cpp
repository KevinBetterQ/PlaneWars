#include "stdafx.h"
#include "Bomb.h"
#include "Resource.h"

CImageList CBomb::m_Images;
CBomb::CBomb(int x, int y)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
}


CBomb::~CBomb()
{
}

BOOL CBomb::Draw(CDC *pDC)
{
	m_ptPos.y -= 23;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	//使导弹在屏幕内
	if (m_ptPos.x >= 1366)
		return FALSE;
	if (m_ptPos.y >= 766)
		return FALSE;
	
}


BOOL CBomb::LoadImage1()
{
	return CGameObject::LoadImageW(m_Images, IDB_bomb, RGB(0, 0, 0), 10, 20, 1);
}

BOOL CBomb::LoadImage2()
{
	return CGameObject::LoadImageW(m_Images, IDB_bomb2, RGB(0, 0, 0), 10, 20, 1);
}
BOOL CBomb::LoadImage3()
{
	return CGameObject::LoadImageW(m_Images, IDB_bomb3, RGB(0, 0, 0), 10, 20, 1);
}
BOOL CBomb::LoadImage4()
{
	return CGameObject::LoadImageW(m_Images, IDB_bomb4, RGB(0, 0, 0), 10, 20, 1);
}
