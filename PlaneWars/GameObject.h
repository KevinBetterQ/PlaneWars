#pragma once
#include "afx.h"


//��Ϸ����ĸ���
class CGameObject :
	public CObject
{
public:
	CGameObject();
	virtual ~CGameObject();

	virtual BOOL Draw(CDC* pDC) = 0;//���ƶ���
    virtual CRect GetRect() = 0;//��þ�������
    CPoint GetPoint()//������Ͻ�����
	{
		return m_ptPos;
	}
protected:
	//����ͼ��
	static BOOL LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial);
protected:
	//�����λ��
	CPoint  m_ptPos;

};

