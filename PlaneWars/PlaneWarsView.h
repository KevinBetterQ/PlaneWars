
// PlaneWarsView.h : CPlaneWarsView 类的接口
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

	CEnemy* pEnemy; //定义敌机指针
	CPlane* pMyPlane;//定义飞机指针
	CBomb*  pBomb;     //定义导弹指针
	CBall*  pBall;     //定义敌机炮弹指针
	CExplosion* pExplosion; //定义一个爆炸指针
	CAirplane* airp;  //定义客机指针

	CObList list_enemy;//敌机  
	CObList list_bomb;//导弹   
	CObList list_ball;//子弹  
	CObList list_explosion;//爆炸
	CObList list_protection;//保护膜
	
public:

	CRect rect;
	int level;//设置难度级别
	CProtect shield;//监测保护罩

protected: // 仅从序列化创建
	CPlaneWarsView();
	DECLARE_DYNCREATE(CPlaneWarsView)

// 特性
public:
	CPlaneWarsDoc* GetDocument() const;
	CBrush m_brBk;//刷子
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPlaneWarsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // PlaneWarsView.cpp 中的调试版本
inline CPlaneWarsDoc* CPlaneWarsView::GetDocument() const
   { return reinterpret_cast<CPlaneWarsDoc*>(m_pDocument); }
#endif

