#pragma once
#include "GameObject.h"
#include "Resource.h"


//�ͻ�����
class CAirplane :
	public CGameObject
{
private:
	int m_speed;
	int m_nMotion;//���� 1->���� 0->ֹͣ -1->����
public:
	CAirplane();
	~CAirplane();
	int GetMontion()
	{
		return m_nMotion;
	}
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
		return CRect(m_ptPos, CPoint(m_ptPos.x + 300, m_ptPos.y + 138));
	}
	CRect GetRect1()//��þ���λ�ã���ͷ��
	{
		CPoint n;
		n.x = m_ptPos.x + 10;
		n.y = m_ptPos.y+10;
		return CRect(n, CPoint(m_ptPos.x + 70, m_ptPos.y + 138));
	}
	CRect GetRect2()//��þ���λ�ã�����
	{
		CPoint n;
		n.x = m_ptPos.x + 80;
		n.y = m_ptPos.y;
		return CRect(n,CPoint(m_ptPos.x + 200, m_ptPos.y + 69));
	}
	CRect GetRect3()//��þ���λ�ã����ᣩ
	{
		CPoint n;
		n.x = m_ptPos.x + 80;
		n.y = m_ptPos.y + 69;
		return CRect(n, CPoint(m_ptPos.x + 180, m_ptPos.y + 138));
	}
	CRect GetRect4()//��þ���λ�ã����䣩
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
	BOOL Draw(CDC* pDC);//ս������
public:
	// �ɻ����������ƶ�
	void move(int n);
	//�ɻ������ƶ��������Ѷȣ�

};

