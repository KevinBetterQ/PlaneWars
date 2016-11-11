#pragma once
#include "GameObject.h"
#include "Resource.h"
class CPlane :
	public CGameObject
{
private:
	int m_speed;
	
public:
	CPlane();
	virtual ~CPlane();
	void SetSpeed(int speed)//修改速度
	{
		m_speed = speed;
	}
	int GetSpeed()//获得速度
	{
		return m_speed;
	}
	int GetPointy()//获得位置y值
	{
		return m_ptPos.y;
	}
	int GetPointx()//获得位置y值
	{
		return m_ptPos.x;
	}
	CRect GetRect()//获得矩形位置
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 50, m_ptPos.y + 60));
	}
	static BOOL LoadImage1();
	static BOOL LoadImage2();
	static BOOL LoadImage3();
	static BOOL LoadImage4();
	static BOOL LoadImage5();
	static BOOL LoadImage6();
	void remove()
	{
		if (m_Images != NULL){
			m_Images.DeleteImageList();
		}
	}
	static CImageList m_Images;
	BOOL Draw(CDC* pDC);//战机绘制
public:
	// 飞机上下左右移动
	void move(int n);
	//飞机自行移动（设置难度）
	void Move(int level)
	{
		m_ptPos.y =m_ptPos.y - (m_speed-18)*level;
	}

};

