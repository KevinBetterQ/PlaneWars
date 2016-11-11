#pragma once
#include "GameObject.h"
class CBomb :
	public CGameObject
{
public:
	CBomb(int x, int y);
	virtual ~CBomb();
	BOOL Draw(CDC* pDC);
	CRect GetRect()//��þ���λ��
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + 20));
	}
	static BOOL LoadImage1();
	static BOOL LoadImage2();
	static BOOL LoadImage3();
	static BOOL LoadImage4();
	void remove()
	{
		if (m_Images != NULL){
			m_Images.DeleteImageList(); //�˺���ɾ��һ��ͼ���б�
		}	
	}
private:
	static CImageList m_Images;
};

