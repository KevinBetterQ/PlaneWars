#include "stdafx.h"

#include "Boss.h"

#include "resource.h"


//客机的类

CImageList CAirplane::m_Images;
CAirplane::CAirplane()
{
	m_speed = 2;
	m_ptPos.x = 1300;
	m_ptPos.y = rand() % 4 * 50;
}


CAirplane::~CAirplane()
{
}


BOOL CAirplane::LoadImage1()
{
	return CGameObject::LoadImageW(m_Images, IDB_airliner1, RGB(0, 0, 0), 300, 138, 1);//获得客机1
}



BOOL CAirplane::Draw(CDC* pDC)
{
	m_ptPos.x = m_ptPos.x - m_speed;
	return m_Images.Draw(pDC, 0, m_ptPos, NULL);;
}

// 飞机上下左右移动
void CAirplane::move(int n)
{
	if (n == 1)
	{
		m_ptPos.y += 100;//向下移动
		m_ptPos.x -= 100;
	}
	if (n == 2) m_ptPos.y += 20;//向下移动
	if (n == 3) m_ptPos.x -= m_speed;//向左移动
	if (n == 4) m_ptPos.x += m_speed;//向右移动
}