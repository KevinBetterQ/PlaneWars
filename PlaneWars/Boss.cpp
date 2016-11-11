#include "stdafx.h"

#include "Boss.h"

#include "resource.h"


//�ͻ�����

CImageList CAirplane::m_Images;
CAirplane::CAirplane()
{
	m_speed = 2;
	m_ptPos.x = 1300;
	m_ptPos.y = rand() % 4 * 50;
}


CAirplane::~CAirplane()
{
}


BOOL CAirplane::LoadImage1()
{
	return CGameObject::LoadImageW(m_Images, IDB_airliner1, RGB(0, 0, 0), 300, 138, 1);//��ÿͻ�1
}



BOOL CAirplane::Draw(CDC* pDC)
{
	m_ptPos.x = m_ptPos.x - m_speed;
	return m_Images.Draw(pDC, 0, m_ptPos, NULL);;
}

// �ɻ����������ƶ�
void CAirplane::move(int n)
{
	if (n == 1)
	{
		m_ptPos.y += 100;//�����ƶ�
		m_ptPos.x -= 100;
	}
	if (n == 2) m_ptPos.y += 20;//�����ƶ�
	if (n == 3) m_ptPos.x -= m_speed;//�����ƶ�
	if (n == 4) m_ptPos.x += m_speed;//�����ƶ�
}