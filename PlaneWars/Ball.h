#pragma once
#include "GameObject.h"
#include "Resource.h"

//�л�ը��
class CBall :
	public CGameObject
{
public:
	CBall(int x, int y, int nMontion);
	virtual ~CBall();
	BOOL Draw(CDC* pDC);
    static BOOL LoadImage();
	CRect GetRect()//��þ���λ��
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 8, m_ptPos.y + 8));
	}
private:
	static CImageList m_Images;
	int m_nMotion;
};

