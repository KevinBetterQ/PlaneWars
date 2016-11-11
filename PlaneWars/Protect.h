#pragma once
#include "GameObject.h"



class CProtect :
	public CGameObject
{
public:
	CProtect();
	CProtect(int _x, int _y);
	virtual ~CProtect();
	BOOL draw(CDC* pDC, BOOL bPause);
	BOOL Draw(CDC* pDC);
	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + _WIDTH, m_ptPos.y + _HEIGHT));
	}

	void SetPos(int _x, int _y);
	BOOL CloseShield(int Time);

	int on;//�����ֿ�����0->�أ�1>��
	int st_time;//�����ֿ�ʼ����ʱ��

private:
	static const int _HEIGHT = 196;
	static const int _WIDTH = 190;
	static CImageList m_Images;
	int m_nImgIndex;
	int m_nProcess;//��ǰ���ŵڼ���
	int w_nWait;//�����ֿ���ʱ��
};

