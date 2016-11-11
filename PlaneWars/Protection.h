#pragma once
#include "GameObject.h"


class CProtection :
	public CGameObject
{
public:
	CProtection();
	virtual ~CProtection();


BOOL draw(CDC* pDC, BOOL bPause);
BOOL Draw(CDC* pDC);
static BOOL LoadImage();

CRect GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + _HEIGHT, m_ptPos.y + _HEIGHT));
}

private:
	static const int _HEIGHT = 30;
	static const int _WIDTH = 21;
	static CImageList m_Images;
};



