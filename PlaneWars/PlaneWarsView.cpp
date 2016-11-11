
// PlaneWarsView.cpp : CPlaneWarsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneWars.h"
#endif

#include "PlaneWarsDoc.h"
#include "PlaneWarsView.h"
#include "Resource.h"
#include "Setlevel.h"
#include "Protection.h"
#include "Boss.h"

//#pragma comment(lib,"winmm.lib")
//#include "mmsystem.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")//加载声音

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneWarsView

IMPLEMENT_DYNCREATE(CPlaneWarsView, CView)

BEGIN_MESSAGE_MAP(CPlaneWarsView, CView)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32771, &CPlaneWarsView::OnSetlevel)
	ON_COMMAND(ID_32774, &CPlaneWarsView::Onsetmodel)
	ON_COMMAND(ID_32773, &CPlaneWarsView::On32773)
	ON_COMMAND(ID_32777, &CPlaneWarsView::Onfuhuo)
	ON_COMMAND(ID_32778, &CPlaneWarsView::Onagain)
END_MESSAGE_MAP()

// CPlaneWarsView 构造/析构

static int fighter = 1;//战机等级 换战机
static int score = 0;  //得分 换关卡
static int pass = 1;//关卡
static int life = 99;//生命
static int airjudge = 0;//客机产生判断，1为产生，0为消失
static int airlife = 10;//客机生命值

CPlaneWarsView::CPlaneWarsView()
{
	CPlane::LoadImage1();
	CEnemy::LoadImageW();
	CBall::LoadImageW();
	CExplosion::LoadImageW();
	CBomb::LoadImage2();
	CProtect::LoadImageW();
	CProtection::LoadImageW();
	CAirplane::LoadImage1();
	level = 0;
	pMyPlane = new CPlane;
	airp = new CAirplane;//客机
	// TODO:  在此处添加构造代码

}

CPlaneWarsView::~CPlaneWarsView()
{
}

BOOL CPlaneWarsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
	
}

// CPlaneWarsView 绘制

void CPlaneWarsView::OnDraw(CDC* pDC)
{
	CPlaneWarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此处为本机数据添加绘制代码
}


// CPlaneWarsView 诊断

#ifdef _DEBUG
void CPlaneWarsView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarsDoc* CPlaneWarsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarsDoc)));
	return (CPlaneWarsDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarsView 消息处理程序


void CPlaneWarsView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	pDC = new CClientDC(this);;//获得窗口大小
	
	SetTimer(1, 50, NULL);//开始界面
	
	// TODO:  在此添加专用代码和/或调用基类
}


void CPlaneWarsView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CPlaneWarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	//首先进入界面一（开始界面）
	if (nIDEvent == 1){
		CPen pen1;
		CBrush brush1;
		//CRect rect;
		//GetClientRect(&rect);
		CDC MemDC;//定义一个显示设备对象　
		CBitmap MemBmap;//定义一个位图对象
		MemDC.CreateCompatibleDC(NULL);//建立与屏幕显示兼容的内存显示设备

		MemBmap.LoadBitmapW(IDB_back1);//添加开始背景
		CBitmap*oldBit = MemDC.SelectObject(&MemBmap);

		//设置文字背景为透明
		MemDC.SetBkMode(TRANSPARENT);
		//设置文字颜色
		/*MemDC.SetTextColor(RGB(0, 255, 0));
		MemDC.TextOutW(350, 250, L"按ENTER键进入游戏", 11);
		MemDC.SetTextColor(RGB(0, 0, 255));*/
		/*MemDC.TextOutW(350, 280, L"上下左右键控制方向，空格键控制发射导弹", 22);
		MemDC.TextOutW(350, 310, L"战机可以升级，升级后导弹会变化", 18);
		MemDC.TextOutW(350, 340, L"关卡难度逐级递增，关卡升高，敌机生命值会相应增加", 24);
		MemDC.TextOutW(350, 370, L"有一定几率出现客机，击中客机会减少生命与得分", 22);*/
		//将内存中的图拷贝到屏幕上进行显示　 
		pDC->BitBlt(0, 0, 1366, 766, &MemDC, 0, 0, SRCCOPY);
		//绘图完成后的清理　
		//把前面的pOldBit选回来.在删除MemBitmap之前要先从设备中移除它
		MemDC.SelectObject(oldBit);
		
		MemBmap.DeleteObject();
		MemDC.DeleteDC();
	}

	//进入界面二（游戏界面）
	
    if (nIDEvent == 2){
		CPen mypen;
		CBrush mybrush;
		CRect rect;
		GetClientRect(&rect);
		CDC MemDC;//定义一个显示设备对象　
		CBitmap MemBmap;//定义一个位图对象
		MemDC.CreateCompatibleDC(NULL);//建立与屏幕显示兼容的内存显示设备
		if (life != 0)
		{
			if (pass % 4 == 1)
			    MemBmap.LoadBitmapW(IDB_back2);
			if (pass % 4 == 2)
				MemBmap.LoadBitmapW(IDB_back3);
			if (pass % 4 == 3)
				MemBmap.LoadBitmapW(IDB_back4);
			if (pass % 4 == 0)
				MemBmap.LoadBitmapW(IDB_back5);
		}
		else
		{
			MemBmap.LoadBitmapW(IDB_gameover);//添加结束背景
			KillTimer(2);
		}	
		CBitmap*oldBit = MemDC.SelectObject(&MemBmap);

		//设置文字背景为透明
		MemDC.SetBkMode(TRANSPARENT);
		//设置文字颜色
		MemDC.SetTextColor(RGB(0, 255, 0));
		//显示生命值
		CString Life;
		Life.Format(L"生命数:    %d", life);
		MemDC.TextOutW(30 , 10, Life);
		//显示分数
		CString grade;
		grade.Format(L"分数：    %d", score);
		MemDC.TextOutW(30 , 30, grade);

		MemDC.SetTextColor(RGB(0, 255, 255));
		//显示关卡
		CString pa;
		pa.Format(L"关卡:    %d", pass);
		MemDC.TextOutW(600, 50, pa);

		//设置文字颜色
		MemDC.SetTextColor(RGB(255, 255, 0));
		if (pMyPlane != NULL&&fighter<5)
		{
			CString fer;
			fer.Format(L"等级：%d", fighter);
			MemDC.TextOutW(pMyPlane->GetPointx() + 3, pMyPlane->GetPointy() + 70, fer);
		}
		if (pMyPlane != NULL&&fighter >= 5)
		{
			MemDC.SetTextColor(RGB(255, 97, 0));
			MemDC.TextOutW(pMyPlane->GetPointx() + 2, pMyPlane->GetPointy() + 70, L"最强战机", 4);
		}
		

		//画战机
		
		if (pMyPlane != NULL)
		{
			pMyPlane->Draw(&MemDC);
			pMyPlane->Move(level);
		}

		//绘制客机
		if (airp != NULL&&airjudge==1)
		{
			airp->Draw(&MemDC);
			if (airp->GetPointx() <= -1300)
			{
				delete airp;
				airp = NULL;
				airp = new CAirplane;//客机
			}
		}
		

		//战机子弹炸掉客机

		if (airp != NULL)
		{
			POSITION aPos1 = NULL, aPos = NULL;

			CRect mRect1 = airp->GetRect1();//获得客机区域(机头)
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//获得子弹区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect1))//子弹区域与客机区域相交
				{
						airlife -= 1;
						life -= 1;
						//添加炸弹效果
						list_explosion.AddTail(new CExplosion(mRect1.left, mRect1.top+20));
						PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					//删除子弹
					list_bomb.RemoveAt(aPos);
					delete pBomb;
					//客机偏离航线
					airp->move(1);
					//删除客机
					if (airlife == 0&&airjudge==1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//客机
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}

			CRect mRect2 = airp->GetRect2();//获得客机区域（机身）
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//获得子弹区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect2))//子弹区域与战机区域相交
				{
					airlife -= 1;
					score -= 20;
					//添加炸弹效果
					list_explosion.AddTail(new CExplosion(mRect2.left+20, mRect2.top));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					//删除子弹
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//删除客机
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//客机
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}

			CRect mRect3 = airp->GetRect3();//获得客机区域（机翅）
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//获得子弹区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect3))//子弹区域与战机区域相交
				{
					airlife -= 1;
					score -= 20;
					//添加炸弹效果
					list_explosion.AddTail(new CExplosion(mRect3.left+50, mRect3.top+30));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//客机偏离航线
					airp->move(2);
					//删除子弹
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//删除客机
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//客机
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}
			CRect mRect4 = airp->GetRect4();//获得客机区域（油箱）
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//获得子弹区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect4))//子弹区域与战机区域相交
				{
					//添加炸弹效果
					list_explosion.AddTail(new CExplosion(mRect4.left, mRect4.top));
					list_explosion.AddTail(new CExplosion(mRect1.left, mRect1.top+20));
					list_explosion.AddTail(new CExplosion(mRect2.left+20, mRect2.top));
					list_explosion.AddTail(new CExplosion(mRect3.left+50, mRect3.top+30));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//客机坠毁
					airlife = 0;
					life -= 2;
					score -= 50;
					//删除子弹
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//删除客机
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//客机
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}
	
		}






		//绘制战机导弹
		POSITION pos1=NULL;
		POSITION bmOldPos;
		pos1 = list_bomb.GetHeadPosition();
		while (pos1 != NULL)
		{
			    bmOldPos = pos1;
				CBomb *pBomb = (CBomb *)list_bomb.GetNext(pos1); 
				CRect BombPos = pBomb->GetRect();
				//如果导弹出界面
				if (BombPos.top < rect.top|| BombPos.left > rect.right || BombPos.right < rect.left)
				{
					list_bomb.RemoveAt(bmOldPos);
					delete pBomb;
				}
				else
					pBomb->Draw(&MemDC);
		}
		
		//绘制爆炸
		POSITION pos2 = NULL;
		for (pos2 = list_explosion.GetHeadPosition(); pos2 != NULL;)
		{
			pExplosion = (CExplosion*)list_explosion.GetNext(pos2);
			pExplosion->Draw(&MemDC);
		}



		//绘制敌机
			static int n = 0;
			if (n <= 0)
			{
				n = rand() % 25-pass;
				list_enemy.AddTail(new CEnemy);
			}
			n--;
			//判断产生的敌机是否出界，若已经出界，则删除该敌机
			POSITION posEn = NULL, posEn_t = NULL;
			posEn = list_enemy.GetHeadPosition();
			while (posEn != NULL)
			{
				posEn_t = posEn;
				CEnemy *enemy = (CEnemy *)list_enemy.GetNext(posEn);
				//判断敌机是否出界
				if (enemy->GetPoint().x<rect.left || enemy->GetPoint().x>rect.right
					|| enemy->GetPoint().y<rect.top || enemy->GetPoint().y>rect.bottom)
				{
					list_enemy.RemoveAt(posEn_t);
					delete enemy;
				}//if
				else
				{
					enemy->Draw(&MemDC);
					int x = rand() % 40;
					if (x == 1)
					list_ball.AddTail(new CBall(enemy->GetPoint().x + 12, enemy->GetPoint().y + 25, enemy->GetMontion()));
				}//else
			}//while

			//判断产生的敌机炸弹是否出界，若已经出界，则删除该敌机炸弹
			POSITION posball = NULL, posball_t = NULL;
			posball = list_ball.GetHeadPosition();
			while (posball != NULL)
			{
				posball_t = posball;
				pBall = (CBall *)list_ball.GetNext(posball);
				if (pBall->GetPoint().x<rect.left || pBall->GetPoint().x>rect.right
					|| pBall->GetPoint().y<rect.top || pBall->GetPoint().y>rect.bottom)
				{
					list_ball.RemoveAt(posball_t);
					delete  pBall;
				}//if
				else
				{
					pBall->Draw(&MemDC);
				}//else
			}//while



		//碰撞检测//

		//战机子弹炸掉敌机
		static int num=1;//设置关卡难度
		if (pMyPlane != NULL&&pBomb!=NULL)
		{
			POSITION B1 = NULL, B2 = NULL;
			B1 = list_bomb.GetHeadPosition();
			while ((B2 = B1) != NULL)//GetHeadPosition  返回列表中首元素的位置
			{
				pBomb = (CBomb*)list_bomb.GetNext(B1);//GetNext获取循环遍历中的下一个元素 
				CRect bRect = pBomb->GetRect();//获得导弹区域
				POSITION E1 = NULL, E2 = NULL;
				E1 = list_enemy.GetHeadPosition();
				while ((E2 = E1) != NULL)
				{
					pEnemy = (CEnemy*)list_enemy.GetNext(E1);
					CRect eRect = pEnemy->GetRect();//获得敌机区域
					CRect enRect;//定义一个区域，该区域作用为获得导弹和敌机区域的交集。
					if (enRect.IntersectRect(&bRect, eRect))//若导弹和敌机有交集，删除导弹和敌机，添加爆炸效果
					{
						num++;
						
						if (score % 100 == 30)
						{
							airjudge = 1;
						}
						score += 10;
						//添加炸弹效果
						list_explosion.AddTail(new CExplosion(eRect.left, eRect.top));
						PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//删除导弹
						list_bomb.RemoveAt(B2);//RemoveAt  从列表中删除指定位置的元素 
							delete pBomb;//
							//pBomb = NULL;

						if (num % pass == 0)       //设置敌机生命数
						{
							//删除敌机
							list_enemy.RemoveAt(E2);
							delete pEnemy;
							pEnemy = NULL;
						}

						//加等级
						static int a;
						a++;
						if (a % 25 == 0)
						{
							if (fighter < 5)
							{
								/*AfxMessageBox(L"恭喜，飞机等级+1");
								Sleep(500);*/
								fighter += 1;//每击破100架敌机等级加一	
								pMyPlane->remove();
								pBomb->remove();
								if (fighter == 1){
									CPlane::LoadImage1();
									CBomb::LoadImage2();
								}
								if (fighter == 2){
									CPlane::LoadImage2();
									CBomb::LoadImage1();
								}
								if (fighter == 3){
									CPlane::LoadImage3();
									CBomb::LoadImage3();
								}
								if (fighter == 4){
									CPlane::LoadImage5();
									CBomb::LoadImage4();
								}
								if (fighter == 5){
									CPlane::LoadImage4();
									CBomb::LoadImage1();
								}
							}
							else
							{
								pMyPlane->remove();
								pBomb->remove();
								CPlane::LoadImage4();
								CBomb::LoadImage1();
							}
						}

						if (score % 1000 == 0&&score>0){
							
							pass += 1;//得分加3000过一关
							//AfxMessageBox(L"过关啦！");
						}
							
						break;
					}
				}
			}
		}



			







		//敌机子弹炸掉战机
		if (pMyPlane != NULL)
		{
			POSITION bPos1 = NULL, bPos2 = NULL;
			CRect mRect = pMyPlane->GetRect();//获得战机区域
			bPos1 = list_ball.GetHeadPosition();
			while ((bPos2 = bPos1) != NULL)
			{
				pBall = (CBall*)list_ball.GetNext(bPos1);
				CRect bRect = pBall->GetRect();//获得子弹区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect))//子弹区域与战机区域相交
				{
					
					if (!shield.on){
						life -= 1;
						//添加炸弹效果
						list_explosion.AddTail(new CExplosion(mRect.left, mRect.top));
						//PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					}
					
					//删除子弹
					list_ball.RemoveAt(bPos2);
					delete pBall;
					
					//删除战机
					if (life <= 0)
					{
						delete pMyPlane;
						pMyPlane = NULL;
						break;
					}
					break;

				}
			}
		}

		//敌机与战机相撞
		if (pMyPlane != NULL)
		{
			POSITION bPos1 = NULL, bPos2 = NULL;
			CRect mRect = pMyPlane->GetRect();//获得战机区域
			bPos1 = list_enemy.GetHeadPosition();
			while ((bPos2 = bPos1) != NULL)
			{
				pEnemy = (CEnemy*)list_enemy.GetNext(bPos1);
				CRect eRect = pEnemy->GetRect();//获得敌机区域
				CRect tmpRect;
				if (tmpRect.IntersectRect(&eRect, mRect))//敌机区域与战机区域相交
				{
					
					if (!shield.on){
						life -= 1;
						//添加炸弹效果
						list_explosion.AddTail(new CExplosion(mRect.left, mRect.top));
						PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					}
					else score += 10;

					//删除敌机
					list_enemy.RemoveAt(bPos2);
					if (pEnemy != NULL)
						delete pEnemy;

					//删除战机
					if (life <= 0)
					{
						delete pMyPlane;
						pMyPlane = NULL;
						break;
					}
					break;
				}
			}


			if (pMyPlane != NULL)
			{
				////随机产生防护罩星星
				if (list_protection.GetCount() < 3)
				{
					srand(GetTickCount());//GetTickCount()返回从操作系统启动到现在所经过的毫秒数
					if (rand() % 2571 > 2500 && rand() % 2571 < 2000)
						list_protection.AddTail(new CProtection());
				}
				POSITION Pos;
				for (POSITION SJPos = list_protection.GetHeadPosition(); SJPos != NULL;)
				{
					Pos = SJPos;
					CProtection *pro = (CProtection *)list_protection.GetNext(SJPos);
					CRect interRect;

					//星星与我机相遇
					if (interRect.IntersectRect(pro->GetRect(), pMyPlane->GetRect()))
					{
						PlaySound((LPCTSTR)IDR_WAVE5, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//开启防护罩
						shield.on = 1;
						//记录时间
						shield.st_time = GetTickCount();
						//销毁防护罩
						list_protection.RemoveAt(Pos);
						delete pro;
					}

					//若出界面
					else if (pro->GetPoint().y > rect.bottom)
					{
						list_protection.RemoveAt(Pos);
						delete pro;
					}
					else pro->draw(&MemDC, true);
				}

				if (shield.on)//若防护罩打开
				{
					shield.SetPos(pMyPlane->GetPoint().x - 70, pMyPlane->GetPoint().y - 65);
					shield.draw(&MemDC, TRUE);
					shield.CloseShield(GetTickCount());
				}
			}
			

		}


		//将内存中的图拷贝到屏幕上进行显示　 
		pDC->BitBlt(0, 0, 1366, 766, &MemDC, 0, 0, SRCCOPY);
		//绘图完成后的清理　
		//把前面的pOldBit选回来.在删除MemBitmap之前要先从设备中移除它
		MemDC.SelectObject(oldBit);
		MemBmap.DeleteObject();
		MemDC.DeleteDC();

		if (pMyPlane != NULL)
		{
			if (GetKeyState(VK_UP) < 0)
			{
				pMyPlane->move(1);
			}
			if (GetKeyState(VK_DOWN) < 0)
			{
				pMyPlane->move(2);
			}
			if (GetKeyState(VK_LEFT) < 0)
			{
				pMyPlane->move(3);
			}
			if (GetKeyState(VK_RIGHT) < 0)
			{
				pMyPlane->move(4);
			}
		}

    }
	//this->Invalidate();
	CView::OnTimer(nIDEvent);
}


void CPlaneWarsView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	KillTimer(2);
	delete pDC;
	// TODO:  在此处添加消息处理程序代码
}


void CPlaneWarsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	if (nChar == VK_RETURN)//按Enter键进入游戏界面
	{
		KillTimer(1);
		SetTimer(2, 50, NULL);
	}
	if (pMyPlane != NULL)
	{
		if (nChar == VK_SPACE){
			if (fighter == 1){
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 23, pMyPlane->GetPoint().y));
				//PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			}
			else if (fighter > 1 && fighter <= 4){
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 3, pMyPlane->GetPoint().y + 20));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 23, pMyPlane->GetPoint().y));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 43, pMyPlane->GetPoint().y + 20));
				//PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			}
			else{
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 3, pMyPlane->GetPoint().y + 20));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 23, pMyPlane->GetPoint().y));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 43, pMyPlane->GetPoint().y + 20));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 63, pMyPlane->GetPoint().y + 40));
				list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x - 23, pMyPlane->GetPoint().y + 40));
				//PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			}
			
		}
	}

	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPlaneWarsView::OnSetlevel()
{
	CSetlevel setld;
	setld.m_level = level;
	if (setld.DoModal() == IDOK){
		level = setld.m_level;
	}
	// TODO:  在此添加命令处理程序代码
}


void CPlaneWarsView::Onsetmodel()//修改无敌模式
{
	life =  99999;
	// TODO:  在此添加命令处理程序代码
}


void CPlaneWarsView::On32773()//修改普通模式
{

	life = 10;
	// TODO:  在此添加命令处理程序代码
}


void CPlaneWarsView::Onfuhuo()//原地复活
{
	pMyPlane = new CPlane;
	life = 10;
	SetTimer(2, 50, NULL);
	// TODO:  在此添加命令处理程序代码
}


void CPlaneWarsView::Onagain()//重新开始
{
	pMyPlane = new CPlane;
	life = 10;
	SetTimer(1, 50, NULL);
	score = 0;
	pass = 1;
	fighter = 1;
	pMyPlane->remove();
	pBomb->remove();
	CPlane::LoadImage1();
	CBomb::LoadImage2();
	// TODO:  在此添加命令处理程序代码
}
