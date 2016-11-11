#pragma once
#include "GameObject.h"
#include "Resource.h"
//�л�
class CEnemy :
	public CGameObject
{


private:
	int m_speed;
	int m_nImgIndex;//ͼ������
	int m_nMotion;//���� 1->���� 0->ֹͣ -1->����

public:
	CEnemy();
	virtual ~CEnemy();
	int GetMontion() 
	{
		return m_nMotion;
	}
	int GetSpeed()//����ٶ�
	{
		return m_speed;
	}
	CRect GetRect()//��þ���λ��
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 50, m_ptPos.y + 60));
	}
	static BOOL LoadImage();
	static CImageList m_Images;
	BOOL Draw(CDC* pDC);//ս������
	int GetPointx(){
		return m_ptPos.x;
	}
	int GetPointy(){
		return m_ptPos.y;
	}
};

