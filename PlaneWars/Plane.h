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
	void SetSpeed(int speed)//�޸��ٶ�
	{
		m_speed = speed;
	}
	int GetSpeed()//����ٶ�
	{
		return m_speed;
	}
	int GetPointy()//���λ��yֵ
	{
		return m_ptPos.y;
	}
	int GetPointx()//���λ��yֵ
	{
		return m_ptPos.x;
	}
	CRect GetRect()//��þ���λ��
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
	BOOL Draw(CDC* pDC);//ս������
public:
	// �ɻ����������ƶ�
	void move(int n);
	//�ɻ������ƶ��������Ѷȣ�
	void Move(int level)
	{
		m_ptPos.y =m_ptPos.y - (m_speed-18)*level;
	}

};

