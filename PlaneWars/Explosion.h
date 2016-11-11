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
	//ը����ͼƬ�б�
	static CImageList m_Images;
	//ͼ�������Ĳ�����������ʾ�ڼ���ͼƬ��
	int count;
};

