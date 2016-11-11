#pragma once
#include "afx.h"


//游戏对象的父类
class CGameObject :
	public CObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	virtual BOOL Draw(CDC* pDC) = 0;//绘制对象
    virtual CRect GetRect() = 0;//获得矩形区域
    CPoint GetPoint()//获得左上角坐标
	{
		return m_ptPos;
	}
protected:
	//加载图像
	static BOOL LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial);
protected:
	//物体的位置
	CPoint  m_ptPos;

};

