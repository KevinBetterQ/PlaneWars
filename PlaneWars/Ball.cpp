#include "stdafx.h"
#include "Ball.h"

CImageList CBall::m_Images;

CBall::CBall(int x, int y, int nMotion)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	m_nMotion = nMotion;
}

CBall::~CBall(void)
{
}

BOOL CBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ball, RGB(0, 0, 0), 8, 8, 1);//获得子弹
}

BOOL CBall::Draw(CDC *pDC)
{
	m_ptPos.y = m_ptPos.y + m_nMotion * 10;//固定子弹速度为10
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	////使子弹在屏幕内
	//if (m_ptPos.x >= 1366)
	//	return FALSE;
	//if (m_ptPos.y >= 768)
	//	return FALSE;;

}


