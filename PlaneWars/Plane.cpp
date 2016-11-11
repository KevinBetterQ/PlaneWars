#include "stdafx.h"
#include "Plane.h"
#include "resource.h"

CImageList CPlane::m_Images;

CPlane::CPlane()
{
	m_speed = 20;
	m_ptPos.x = 450;
	m_ptPos.y = 400;
}


CPlane::~CPlane()
{
}



BOOL CPlane::LoadImage1()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane5, RGB(0, 0, 0), 60, 72, 1);//���ս��
}
BOOL CPlane::LoadImage2()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane2, RGB(0, 0, 0), 60, 72, 1);//���ս��
}
BOOL CPlane::LoadImage3()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane3, RGB(0, 0, 0), 60, 72, 1);//���ս��
}
BOOL CPlane::LoadImage4()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane4, RGB(0, 0, 0), 60, 72, 1);//���ս��
}
BOOL CPlane::LoadImage5()
{
	return CGameObject::LoadImageW(m_Images, IDB_plane, RGB(0, 0, 0), 60, 72, 1);//���ս��
}
BOOL CPlane::LoadImage6()
{
	return CGameObject::LoadImageW(m_Images, IDB_planef, RGB(0, 0, 0), 100, 70, 1);//���ս��
}


BOOL CPlane::Draw(CDC* pDC)
{

	//ʹ�ɻ�����Ļ��
	if (m_ptPos.x >= 1305)
		m_ptPos.x = 1305;
	if (m_ptPos.x <= 0)
		m_ptPos.x = 0;
	if (m_ptPos.y <= 0)
		m_ptPos.y = 0;
	if (m_ptPos.y >= 580)
		m_ptPos.y = 580;
	return m_Images.Draw(pDC, 0, m_ptPos, NULL);;
}

// �ɻ����������ƶ�
void CPlane::move(int n)
{
	if (n == 1) m_ptPos.y -= m_speed;//�����ƶ�
	if (n == 2) m_ptPos.y += m_speed;//�����ƶ�
	if (n == 3) m_ptPos.x -= m_speed;//�����ƶ�
	if (n == 4) m_ptPos.x += m_speed;//�����ƶ�
}