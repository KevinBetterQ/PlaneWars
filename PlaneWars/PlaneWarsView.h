
// PlaneWarsView.h : CPlaneWarsView ��Ľӿ�
//
#include <ctime>
#include <cstdlib>
#include "Enemy.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ball.h"
#include "Explosion.h"
#include "Protection.h"
#include "Protect.h"
#include "Boss.h"
#pragma once


class CPlaneWarsView : public CView
{
private:
	CClientDC* pDC;

	CEnemy* pEnemy; //����л�ָ��
	CPlane* pMyPlane;//����ɻ�ָ��
	CBomb*  pBomb;     //���嵼��ָ��
	CBall*  pBall;     //����л��ڵ�ָ��
	CExplosion* pExplosion; //����һ����ըָ��
	CAirplane* airp;  //����ͻ�ָ��

	CObList list_enemy;//�л�  
	CObList list_bomb;//����   
	CObList list_ball;//�ӵ�  
	CObList list_explosion;//��ը
	CObList list_protection;//����Ĥ
	
public:

	CRect rect;
	int level;//�����Ѷȼ���
	CProtect shield;//��Ᵽ����

protected: // �������л�����
	CPlaneWarsView();
	DECLARE_DYNCREATE(CPlaneWarsView)

// ����
public:
	CPlaneWarsDoc* GetDocument() const;
	CBrush m_brBk;//ˢ��
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CPlaneWarsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetlevel();
	afx_msg void Onsetmodel();
	afx_msg void On32773();
	afx_msg void Onfuhuo();
	afx_msg void Onagain();
};

#ifndef _DEBUG  // PlaneWarsView.cpp �еĵ��԰汾
inline CPlaneWarsDoc* CPlaneWarsView::GetDocument() const
   { return reinterpret_cast<CPlaneWarsDoc*>(m_pDocument); }
#endif

