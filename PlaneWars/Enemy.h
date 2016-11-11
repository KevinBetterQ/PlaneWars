#pragma once
#include "GameObject.h"
#include "Resource.h"
//敌机
class CEnemy :
	public CGameObject
{


private:
	int m_speed;
	int m_nImgIndex;//图像索引
	int m_nMotion;//方向 1->向下 0->停止 -1->向上

public:
	CEnemy();
	virtual ~CEnemy();
	int GetMontion() 
	{
		return m_nMotion;
	}
	int GetSpeed()//获得速度
	{
		return m_speed;
	}
	CRect GetRect()//获得矩形位置
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 50, m_ptPos.y + 60));
	}
	static BOOL LoadImage();
	static CImageList m_Images;
	BOOL Draw(CDC* pDC);//战机绘制
	int GetPointx(){
		return m_ptPos.x;
	}
	int GetPointy(){
		return m_ptPos.y;
	}
};

