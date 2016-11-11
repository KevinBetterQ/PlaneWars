#pragma once
#include "GameObject.h"
class CExplosion :
	public CGameObject
{
public:
	CExplosion(int x, int y);
	virtual ~CExplosion();
	BOOL Draw(CDC* pDC);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 66, m_ptPos.y + 66));
	}

private:
	//炸弹的图片列表
	static CImageList m_Images;
	//图像索引的步进计数（显示第几幅图片）
	int count;
};

