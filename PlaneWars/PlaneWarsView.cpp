
// PlaneWarsView.cpp : CPlaneWarsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
#pragma comment(lib, "WINMM.LIB")//��������

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

// CPlaneWarsView ����/����

static int fighter = 1;//ս���ȼ� ��ս��
static int score = 0;  //�÷� ���ؿ�
static int pass = 1;//�ؿ�
static int life = 99;//����
static int airjudge = 0;//�ͻ������жϣ�1Ϊ������0Ϊ��ʧ
static int airlife = 10;//�ͻ�����ֵ

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
	airp = new CAirplane;//�ͻ�
	// TODO:  �ڴ˴���ӹ������

}

CPlaneWarsView::~CPlaneWarsView()
{
}

BOOL CPlaneWarsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
	
}

// CPlaneWarsView ����

void CPlaneWarsView::OnDraw(CDC* pDC)
{
	CPlaneWarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPlaneWarsView ���

#ifdef _DEBUG
void CPlaneWarsView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarsDoc* CPlaneWarsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarsDoc)));
	return (CPlaneWarsDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarsView ��Ϣ�������


void CPlaneWarsView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	pDC = new CClientDC(this);;//��ô��ڴ�С
	
	SetTimer(1, 50, NULL);//��ʼ����
	
	// TODO:  �ڴ����ר�ô����/����û���
}


void CPlaneWarsView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPlaneWarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	//���Ƚ������һ����ʼ���棩
	if (nIDEvent == 1){
		CPen pen1;
		CBrush brush1;
		//CRect rect;
		//GetClientRect(&rect);
		CDC MemDC;//����һ����ʾ�豸����
		CBitmap MemBmap;//����һ��λͼ����
		MemDC.CreateCompatibleDC(NULL);//��������Ļ��ʾ���ݵ��ڴ���ʾ�豸

		MemBmap.LoadBitmapW(IDB_back1);//��ӿ�ʼ����
		CBitmap*oldBit = MemDC.SelectObject(&MemBmap);

		//�������ֱ���Ϊ͸��
		MemDC.SetBkMode(TRANSPARENT);
		//����������ɫ
		/*MemDC.SetTextColor(RGB(0, 255, 0));
		MemDC.TextOutW(350, 250, L"��ENTER��������Ϸ", 11);
		MemDC.SetTextColor(RGB(0, 0, 255));*/
		/*MemDC.TextOutW(350, 280, L"�������Ҽ����Ʒ��򣬿ո�����Ʒ��䵼��", 22);
		MemDC.TextOutW(350, 310, L"ս�����������������󵼵���仯", 18);
		MemDC.TextOutW(350, 340, L"�ؿ��Ѷ��𼶵������ؿ����ߣ��л�����ֵ����Ӧ����", 24);
		MemDC.TextOutW(350, 370, L"��һ�����ʳ��ֿͻ������пͻ������������÷�", 22);*/
		//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ�� 
		pDC->BitBlt(0, 0, 1366, 766, &MemDC, 0, 0, SRCCOPY);
		//��ͼ��ɺ������
		//��ǰ���pOldBitѡ����.��ɾ��MemBitmap֮ǰҪ�ȴ��豸���Ƴ���
		MemDC.SelectObject(oldBit);
		
		MemBmap.DeleteObject();
		MemDC.DeleteDC();
	}

	//������������Ϸ���棩
	
    if (nIDEvent == 2){
		CPen mypen;
		CBrush mybrush;
		CRect rect;
		GetClientRect(&rect);
		CDC MemDC;//����һ����ʾ�豸����
		CBitmap MemBmap;//����һ��λͼ����
		MemDC.CreateCompatibleDC(NULL);//��������Ļ��ʾ���ݵ��ڴ���ʾ�豸
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
			MemBmap.LoadBitmapW(IDB_gameover);//��ӽ�������
			KillTimer(2);
		}	
		CBitmap*oldBit = MemDC.SelectObject(&MemBmap);

		//�������ֱ���Ϊ͸��
		MemDC.SetBkMode(TRANSPARENT);
		//����������ɫ
		MemDC.SetTextColor(RGB(0, 255, 0));
		//��ʾ����ֵ
		CString Life;
		Life.Format(L"������:    %d", life);
		MemDC.TextOutW(30 , 10, Life);
		//��ʾ����
		CString grade;
		grade.Format(L"������    %d", score);
		MemDC.TextOutW(30 , 30, grade);

		MemDC.SetTextColor(RGB(0, 255, 255));
		//��ʾ�ؿ�
		CString pa;
		pa.Format(L"�ؿ�:    %d", pass);
		MemDC.TextOutW(600, 50, pa);

		//����������ɫ
		MemDC.SetTextColor(RGB(255, 255, 0));
		if (pMyPlane != NULL&&fighter<5)
		{
			CString fer;
			fer.Format(L"�ȼ���%d", fighter);
			MemDC.TextOutW(pMyPlane->GetPointx() + 3, pMyPlane->GetPointy() + 70, fer);
		}
		if (pMyPlane != NULL&&fighter >= 5)
		{
			MemDC.SetTextColor(RGB(255, 97, 0));
			MemDC.TextOutW(pMyPlane->GetPointx() + 2, pMyPlane->GetPointy() + 70, L"��ǿս��", 4);
		}
		

		//��ս��
		
		if (pMyPlane != NULL)
		{
			pMyPlane->Draw(&MemDC);
			pMyPlane->Move(level);
		}

		//���ƿͻ�
		if (airp != NULL&&airjudge==1)
		{
			airp->Draw(&MemDC);
			if (airp->GetPointx() <= -1300)
			{
				delete airp;
				airp = NULL;
				airp = new CAirplane;//�ͻ�
			}
		}
		

		//ս���ӵ�ը���ͻ�

		if (airp != NULL)
		{
			POSITION aPos1 = NULL, aPos = NULL;

			CRect mRect1 = airp->GetRect1();//��ÿͻ�����(��ͷ)
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//����ӵ�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect1))//�ӵ�������ͻ������ཻ
				{
						airlife -= 1;
						life -= 1;
						//���ը��Ч��
						list_explosion.AddTail(new CExplosion(mRect1.left, mRect1.top+20));
						PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					//ɾ���ӵ�
					list_bomb.RemoveAt(aPos);
					delete pBomb;
					//�ͻ�ƫ�뺽��
					airp->move(1);
					//ɾ���ͻ�
					if (airlife == 0&&airjudge==1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//�ͻ�
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}

			CRect mRect2 = airp->GetRect2();//��ÿͻ����򣨻���
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//����ӵ�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect2))//�ӵ�������ս�������ཻ
				{
					airlife -= 1;
					score -= 20;
					//���ը��Ч��
					list_explosion.AddTail(new CExplosion(mRect2.left+20, mRect2.top));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					//ɾ���ӵ�
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//ɾ���ͻ�
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//�ͻ�
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}

			CRect mRect3 = airp->GetRect3();//��ÿͻ����򣨻��ᣩ
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//����ӵ�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect3))//�ӵ�������ս�������ཻ
				{
					airlife -= 1;
					score -= 20;
					//���ը��Ч��
					list_explosion.AddTail(new CExplosion(mRect3.left+50, mRect3.top+30));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//�ͻ�ƫ�뺽��
					airp->move(2);
					//ɾ���ӵ�
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//ɾ���ͻ�
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//�ͻ�
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}
			CRect mRect4 = airp->GetRect4();//��ÿͻ��������䣩
			aPos1 = list_bomb.GetHeadPosition();
			while ((aPos = aPos1) != NULL)
			{
				
				pBomb = (CBomb*)list_bomb.GetNext(aPos1);
				CRect bRect = pBomb->GetRect();//����ӵ�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect4))//�ӵ�������ս�������ཻ
				{
					//���ը��Ч��
					list_explosion.AddTail(new CExplosion(mRect4.left, mRect4.top));
					list_explosion.AddTail(new CExplosion(mRect1.left, mRect1.top+20));
					list_explosion.AddTail(new CExplosion(mRect2.left+20, mRect2.top));
					list_explosion.AddTail(new CExplosion(mRect3.left+50, mRect3.top+30));
					PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//�ͻ�׹��
					airlife = 0;
					life -= 2;
					score -= 50;
					//ɾ���ӵ�
					list_bomb.RemoveAt(aPos);
					delete pBomb;

					//ɾ���ͻ�
					if (airlife == 0 && airjudge == 1)
					{
						delete airp;
						airp = NULL;
						airp = new CAirplane;//�ͻ�
						airjudge = 0;
						airlife = 10;
						PlaySound((LPCTSTR)IDR_WAVE4, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						break;
					}
					break;

				}
			}
	
		}






		//����ս������
		POSITION pos1=NULL;
		POSITION bmOldPos;
		pos1 = list_bomb.GetHeadPosition();
		while (pos1 != NULL)
		{
			    bmOldPos = pos1;
				CBomb *pBomb = (CBomb *)list_bomb.GetNext(pos1); 
				CRect BombPos = pBomb->GetRect();
				//�������������
				if (BombPos.top < rect.top|| BombPos.left > rect.right || BombPos.right < rect.left)
				{
					list_bomb.RemoveAt(bmOldPos);
					delete pBomb;
				}
				else
					pBomb->Draw(&MemDC);
		}
		
		//���Ʊ�ը
		POSITION pos2 = NULL;
		for (pos2 = list_explosion.GetHeadPosition(); pos2 != NULL;)
		{
			pExplosion = (CExplosion*)list_explosion.GetNext(pos2);
			pExplosion->Draw(&MemDC);
		}



		//���Ƶл�
			static int n = 0;
			if (n <= 0)
			{
				n = rand() % 25-pass;
				list_enemy.AddTail(new CEnemy);
			}
			n--;
			//�жϲ����ĵл��Ƿ���磬���Ѿ����磬��ɾ���õл�
			POSITION posEn = NULL, posEn_t = NULL;
			posEn = list_enemy.GetHeadPosition();
			while (posEn != NULL)
			{
				posEn_t = posEn;
				CEnemy *enemy = (CEnemy *)list_enemy.GetNext(posEn);
				//�жϵл��Ƿ����
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

			//�жϲ����ĵл�ը���Ƿ���磬���Ѿ����磬��ɾ���õл�ը��
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



		//��ײ���//

		//ս���ӵ�ը���л�
		static int num=1;//���ùؿ��Ѷ�
		if (pMyPlane != NULL&&pBomb!=NULL)
		{
			POSITION B1 = NULL, B2 = NULL;
			B1 = list_bomb.GetHeadPosition();
			while ((B2 = B1) != NULL)//GetHeadPosition  �����б�����Ԫ�ص�λ��
			{
				pBomb = (CBomb*)list_bomb.GetNext(B1);//GetNext��ȡѭ�������е���һ��Ԫ�� 
				CRect bRect = pBomb->GetRect();//��õ�������
				POSITION E1 = NULL, E2 = NULL;
				E1 = list_enemy.GetHeadPosition();
				while ((E2 = E1) != NULL)
				{
					pEnemy = (CEnemy*)list_enemy.GetNext(E1);
					CRect eRect = pEnemy->GetRect();//��õл�����
					CRect enRect;//����һ�����򣬸���������Ϊ��õ����͵л�����Ľ�����
					if (enRect.IntersectRect(&bRect, eRect))//�������͵л��н�����ɾ�������͵л�����ӱ�ըЧ��
					{
						num++;
						
						if (score % 100 == 30)
						{
							airjudge = 1;
						}
						score += 10;
						//���ը��Ч��
						list_explosion.AddTail(new CExplosion(eRect.left, eRect.top));
						PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//ɾ������
						list_bomb.RemoveAt(B2);//RemoveAt  ���б���ɾ��ָ��λ�õ�Ԫ�� 
							delete pBomb;//
							//pBomb = NULL;

						if (num % pass == 0)       //���õл�������
						{
							//ɾ���л�
							list_enemy.RemoveAt(E2);
							delete pEnemy;
							pEnemy = NULL;
						}

						//�ӵȼ�
						static int a;
						a++;
						if (a % 25 == 0)
						{
							if (fighter < 5)
							{
								/*AfxMessageBox(L"��ϲ���ɻ��ȼ�+1");
								Sleep(500);*/
								fighter += 1;//ÿ����100�ܵл��ȼ���һ	
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
							
							pass += 1;//�÷ּ�3000��һ��
							//AfxMessageBox(L"��������");
						}
							
						break;
					}
				}
			}
		}



			







		//�л��ӵ�ը��ս��
		if (pMyPlane != NULL)
		{
			POSITION bPos1 = NULL, bPos2 = NULL;
			CRect mRect = pMyPlane->GetRect();//���ս������
			bPos1 = list_ball.GetHeadPosition();
			while ((bPos2 = bPos1) != NULL)
			{
				pBall = (CBall*)list_ball.GetNext(bPos1);
				CRect bRect = pBall->GetRect();//����ӵ�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&bRect, mRect))//�ӵ�������ս�������ཻ
				{
					
					if (!shield.on){
						life -= 1;
						//���ը��Ч��
						list_explosion.AddTail(new CExplosion(mRect.left, mRect.top));
						//PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					}
					
					//ɾ���ӵ�
					list_ball.RemoveAt(bPos2);
					delete pBall;
					
					//ɾ��ս��
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

		//�л���ս����ײ
		if (pMyPlane != NULL)
		{
			POSITION bPos1 = NULL, bPos2 = NULL;
			CRect mRect = pMyPlane->GetRect();//���ս������
			bPos1 = list_enemy.GetHeadPosition();
			while ((bPos2 = bPos1) != NULL)
			{
				pEnemy = (CEnemy*)list_enemy.GetNext(bPos1);
				CRect eRect = pEnemy->GetRect();//��õл�����
				CRect tmpRect;
				if (tmpRect.IntersectRect(&eRect, mRect))//�л�������ս�������ཻ
				{
					
					if (!shield.on){
						life -= 1;
						//���ը��Ч��
						list_explosion.AddTail(new CExplosion(mRect.left, mRect.top));
						PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					}
					else score += 10;

					//ɾ���л�
					list_enemy.RemoveAt(bPos2);
					if (pEnemy != NULL)
						delete pEnemy;

					//ɾ��ս��
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
				////�����������������
				if (list_protection.GetCount() < 3)
				{
					srand(GetTickCount());//GetTickCount()���شӲ���ϵͳ�����������������ĺ�����
					if (rand() % 2571 > 2500 && rand() % 2571 < 2000)
						list_protection.AddTail(new CProtection());
				}
				POSITION Pos;
				for (POSITION SJPos = list_protection.GetHeadPosition(); SJPos != NULL;)
				{
					Pos = SJPos;
					CProtection *pro = (CProtection *)list_protection.GetNext(SJPos);
					CRect interRect;

					//�������һ�����
					if (interRect.IntersectRect(pro->GetRect(), pMyPlane->GetRect()))
					{
						PlaySound((LPCTSTR)IDR_WAVE5, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
						//����������
						shield.on = 1;
						//��¼ʱ��
						shield.st_time = GetTickCount();
						//���ٷ�����
						list_protection.RemoveAt(Pos);
						delete pro;
					}

					//��������
					else if (pro->GetPoint().y > rect.bottom)
					{
						list_protection.RemoveAt(Pos);
						delete pro;
					}
					else pro->draw(&MemDC, true);
				}

				if (shield.on)//�������ִ�
				{
					shield.SetPos(pMyPlane->GetPoint().x - 70, pMyPlane->GetPoint().y - 65);
					shield.draw(&MemDC, TRUE);
					shield.CloseShield(GetTickCount());
				}
			}
			

		}


		//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ�� 
		pDC->BitBlt(0, 0, 1366, 766, &MemDC, 0, 0, SRCCOPY);
		//��ͼ��ɺ������
		//��ǰ���pOldBitѡ����.��ɾ��MemBitmap֮ǰҪ�ȴ��豸���Ƴ���
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
	// TODO:  �ڴ˴������Ϣ����������
}


void CPlaneWarsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (nChar == VK_RETURN)//��Enter��������Ϸ����
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
	// TODO:  �ڴ���������������
}


void CPlaneWarsView::Onsetmodel()//�޸��޵�ģʽ
{
	life =  99999;
	// TODO:  �ڴ���������������
}


void CPlaneWarsView::On32773()//�޸���ͨģʽ
{

	life = 10;
	// TODO:  �ڴ���������������
}


void CPlaneWarsView::Onfuhuo()//ԭ�ظ���
{
	pMyPlane = new CPlane;
	life = 10;
	SetTimer(2, 50, NULL);
	// TODO:  �ڴ���������������
}


void CPlaneWarsView::Onagain()//���¿�ʼ
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
	// TODO:  �ڴ���������������
}
