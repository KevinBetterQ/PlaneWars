#include "stdafx.h"
#include "Protect.h"
#include "resource.h"
CImageList CProtect::m_Images;

CProtect::CProtect()
{
	m_nProcess = 0;
	on = 0;
	w_nWait = 15000;
}
CProtect::CProtect(int _x, int _y)
{
	m_ptPos.x = _x;
	m_ptPos.y = _y;
	m_nProcess = 0;
	on = 0;
	w_nWait = 10000;
}

CProtect::~CProtect()
{
}
BOOL CProtect::draw(CDC* pDC, BOOL bPause)
{
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	++m_nProcess;
	if (m_nProcess > 14)//ѭ�����ţ�ÿ��15��
	{
		m_nProcess = 0;//����ͼ�������Ĳ�������
	}
	return true;
}
BOOL CProtect::Draw(CDC* pDC)
{
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	++m_nProcess;
	if (m_nProcess > 14)//ѭ�����ţ�ÿ��15��
	{
		m_nProcess = 0;//����ͼ�������Ĳ�������
	}
	return true;
}

BOOL CProtect::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_protection, RGB(0, 0, 0), _WIDTH, _HEIGHT, 15);
}

void CProtect::SetPos(int _x, int _y)
{
	m_ptPos.x = _x;
	m_ptPos.y = _y;
}

BOOL CProtect::CloseShield(int Time)//����ϵͳʱ���ж�
{
	if (Time - st_time > w_nWait)
	{
		on = 0;
		return true;
	}
	return false;
}