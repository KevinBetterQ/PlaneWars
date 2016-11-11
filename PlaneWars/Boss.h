#pragma once
#include "GameObject.h"
#include "Resource.h"


//客机的类
class CAirplane :
	public CGameObject
{
private:
	int m_speed;
	int m_nMotion;//方向 1->向右 0->停止 -1->向左
public:
	CAirplane();
	~CAirplane();
	int GetMontion()
	{
		return m_nMotion;
	}
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
		return CRect(m_ptPos, CPoint(m_ptPos.x + 300, m_ptPos.y + 138));
	}
	CRect GetRect1()//获得矩形位置（机头）
	{
		CPoint n;
		n.x = m_ptPos.x + 10;
		n.y = m_ptPos.y+10;
		return CRect(n, CPoint(m_ptPos.x + 70, m_ptPos.y + 138));
	}
	CRect GetRect2()//获得矩形位置（机身）
	{
		CPoint n;
		n.x = m_ptPos.x + 80;
		n.y = m_ptPos.y;
		return CRect(n,CPoint(m_ptPos.x + 200, m_ptPos.y + 69));
	}
	CRect GetRect3()//获得矩形位置（机翅）
	{
		CPoint n;
		n.x = m_ptPos.x + 80;
		n.y = m_ptPos.y + 69;
		return CRect(n, CPoint(m_ptPos.x + 180, m_ptPos.y + 138));
	}
	CRect GetRect4()//获得矩形位置（油箱）
	{
		CPoint n;
		n.x = m_ptPos.x + 210;
		n.y = m_ptPos.y + 40 ;
		return CRect(n, CPoint(m_ptPos.x + 300, m_ptPos.y + 138));
	}
	static BOOL LoadImage1();
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

};

