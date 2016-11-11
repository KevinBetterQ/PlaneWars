#include "stdafx.h"
#include "Plane.h"
#include "resource.h"

CImageList CPlane::m_Images;

CPlane::CPlane()
{
	m_speed = 20;
	m_ptPos.x = 450;
	m_ptPos.y = 400;
}


CPlane::~CPlane()
{
}



BOOL CPlane::LoadImage1()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane5, RGB(0, 0, 0), 60, 72, 1);//获得战机
}
BOOL CPlane::LoadImage2()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane2, RGB(0, 0, 0), 60, 72, 1);//获得战机
}
BOOL CPlane::LoadImage3()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane3, RGB(0, 0, 0), 60, 72, 1);//获得战机
}
BOOL CPlane::LoadImage4()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane4, RGB(0, 0, 0), 60, 72, 1);//获得战机
}
BOOL CPlane::LoadImage5()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane, RGB(0, 0, 0), 60, 72, 1);//获得战机
}
BOOL CPlane::LoadImage6()
{
	return CGameObject::LoadImageW(m_Images, IDB_planef, RGB(0, 0, 0), 100, 70, 1);//获得战机
}


BOOL CPlane::Draw(CDC* pDC)
{

	//使飞机在屏幕内
	if (m_ptPos.x >= 1305)
		m_ptPos.x = 1305;
	if (m_ptPos.x <= 0)
		m_ptPos.x = 0;
	if (m_ptPos.y <= 0)
		m_ptPos.y = 0;
	if (m_ptPos.y >= 580)
		m_ptPos.y = 580;
	return m_Images.Draw(pDC, 0, m_ptPos, NULL);;
}

// 飞机上下左右移动
void CPlane::move(int n)
{
	if (n == 1) m_ptPos.y -= m_speed;//向上移动
	if (n == 2) m_ptPos.y += m_speed;//向下移动
	if (n == 3) m_ptPos.x -= m_speed;//向左移动
	if (n == 4) m_ptPos.x += m_speed;//向右移动
}