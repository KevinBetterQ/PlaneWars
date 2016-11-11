#pragma once
#include "GameObject.h"
class CBomb :
	public CGameObject
{
public:
	CBomb(int x, int y);
	virtual ~CBomb();
	BOOL Draw(CDC* pDC);
	CRect GetRect()//获得矩形位置
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + 20));
	}
	static BOOL LoadImage1();
	static BOOL LoadImage2();
	static BOOL LoadImage3();
	static BOOL LoadImage4();
	void remove()
	{
		if (m_Images != NULL){
			m_Images.DeleteImageList(); //此函数删除一个图象列表
		}	
	}
private:
	static CImageList m_Images;
};

