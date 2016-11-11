#include "stdafx.h"
#include "Enemy.h"
#include "resource.h"
CImageList CEnemy::m_Images;

CEnemy::CEnemy()
{
	m_nImgIndex = rand() % 2;//用随机数确定敌机飞行方向：0为下，1为上
	m_ptPos.x = rand() % 1366;//确定敌机随机在x轴0-1366内移动
	if (m_nImgIndex == 0)
	{
		m_nMotion = 1;
		m_ptPos.y = 0;
	}
	if (m_nImgIndex == 1)
	{
		m_nMotion = -1;
		m_ptPos.y = 720;
	}
	m_speed = rand() % 5 + 2;
}


CEnemy::~CEnemy()
{
}

BOOL CEnemy::Draw(CDC *pDC)
{
	m_ptPos.y = m_ptPos.y + m_nMotion*m_speed;
	return m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);//位图加载在背景上

	////使敌机在游戏界面内
	//if (m_ptPos.x >= 100)
	//	return FALSE;
	//if (m_ptPos.y >= 720)
	//	return FALSE;
}

BOOL CEnemy::LoadImageW()
{
	    return CGameObject::LoadImageW(m_Images, IDB_enemy, RGB(0, 0, 0), 35, 35, 2);//获得敌机
}