#include "stdafx.h"
#include "Ball.h"

CImageList CBall::m_Images;

CBall::CBall(int x, int y, int nMotion)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	m_nMotion = nMotion;
}

CBall::~CBall(void)
{
}

BOOL CBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ball, RGB(0, 0, 0), 8, 8, 1);//����ӵ�
}

BOOL CBall::Draw(CDC *pDC)
{
	m_ptPos.y = m_ptPos.y + m_nMotion * 10;//�̶��ӵ��ٶ�Ϊ10
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	////ʹ�ӵ�����Ļ��
	//if (m_ptPos.x >= 1366)
	//	return FALSE;
	//if (m_ptPos.y >= 768)
	//	return FALSE;;

}


