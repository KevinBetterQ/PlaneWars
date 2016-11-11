#include "stdafx.h"
#include "Explosion.h"
#include "Resource.h"


CImageList CExplosion::m_Images;

CExplosion::CExplosion(int x, int y)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	count = 0;
}


CExplosion::~CExplosion()
{
}

BOOL CExplosion::Draw(CDC* pDC)
{
	m_Images.Draw(pDC, count, m_ptPos, ILD_TRANSPARENT);
	count++;
	if (count == 8)
		return FALSE;
	else
		return TRUE;
}
BOOL CExplosion::LoadImageW()
{
	return CGameObject::LoadImageW(m_Images, IDB_explosion, RGB(0, 0, 0), 66, 66, 8);
}