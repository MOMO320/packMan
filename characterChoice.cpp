#include "stdafx.h"
#include "characterChoice.h"

HRESULT characterChoice::init()
{
	//=======================================================================
	//  ù��° ĳ����(������)
	paily.NUM	= PAILY;
	paily.NAME	= "���̸�";
	paily.img	= IMAGEMANAGER->addFrameImage("������", "images/������.bmp", 78 * 3, 91 * 3, 3, 4, true, RGB(255, 0, 255));
	paily.rc	= RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2 + 70, paily.img->getFrameWidth(), paily.img->getFrameHeight());
	paily.ani	= IDLE;
	paily.HP	= 100;
	paily.MP	= 30;
	paily.STR	= 10;
	paily.INT	= 5;
	paily.LEVEL = 1;
	paily.isChoise = false;

	//  �ι�° ĳ����(�ֹ���)
	warm.NUM	= WARM;
	warm.NAME	= "ĳ����";
	warm.img	= IMAGEMANAGER->addFrameImage("ĳ����", "images/ĳ����.bmp", 72 * 3, 90 * 3, 3, 4, true, RGB(255, 0, 255));
	warm.rc		= RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2+ 70, warm.img->getFrameWidth(), warm.img->getFrameHeight());
	warm.ani	= IDLE;
	warm.HP		= 100;
	warm.MP		= 40;
	warm.STR	= 3;
	warm.INT	= 30;
	warm.LEVEL	= 1;
	warm.isChoise = false;

	//����° ĳ����(��)
	bird.NUM	= BIRD;
	bird.NAME	= "������";
	bird.img	= IMAGEMANAGER->addFrameImage("������", "images/������.bmp", 78 * 3, 90 * 3, 3, 4, true, RGB(255, 0, 255));
	bird.rc		= RectMakeCenter(WINSIZEX / 2 + 100, WINSIZEY / 2 + 70, bird.img->getFrameWidth(), bird.img->getFrameHeight());
	bird.ani	= IDLE;
	bird.HP		= 100;
	bird.MP		= 40;
	bird.STR	= 15;
	bird.INT	= 25;
	bird.LEVEL	= 1;
	bird.isChoise = false;
	
	//=======================================================================
	
	// �ִϸ��̼� init()
	animation();
	ANIMATIONMANAGER->start("������_IDLE");
	ANIMATIONMANAGER->start("ĳ����_IDLE");
	ANIMATIONMANAGER->start("������_IDLE");
	// �ִϸ��̼� init()
	isClick = false;
	
	return S_OK;
}

void characterChoice::release()
{
	/*SAFE_DELETE(bird.ANIM);
	SAFE_DELETE(warm.ANIM);
	SAFE_DELETE(paily.ANIM);*/
}

void characterChoice::update()
{
	//animation();

	currenttime += TIMEMANAGER->getElapsedTime();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		choice();
	}

	if (isClick)
	{
		if (currenttime - temptime >= 1)
		{
			SCENEMANAGER->changeScene("Ÿ���");
		}
	}



	switch (characterNum)
	{
	case PAILY:
		if(KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&paily.rc, -2, 0);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("������_LEFT");
			ANIMATIONMANAGER->start("������_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&paily.rc, 2, 0);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("������_RIGHT");
			ANIMATIONMANAGER->start("������_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&paily.rc, 0, -2);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("������_UP");
			ANIMATIONMANAGER->start("������_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&paily.rc, 0, 2);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("������_IDLE");
			ANIMATIONMANAGER->start("������_IDLE");
		}
		break;

	case WARM:
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&warm.rc, -2, 0);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("ĳ����_LEFT");
			ANIMATIONMANAGER->start("ĳ����_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&warm.rc, 2, 0);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("ĳ����_RIGHT");
			ANIMATIONMANAGER->start("ĳ����_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&warm.rc, 0, -2);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("ĳ����_UP");
			ANIMATIONMANAGER->start("ĳ����_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&warm.rc, 0, 2);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("ĳ����_DOWN");
			ANIMATIONMANAGER->start("ĳ����_DOWN");
		}
		break;

	case BIRD:
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&bird.rc, -2, 0);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("������_LEFT");
			ANIMATIONMANAGER->start("������_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&bird.rc, 2, 0);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("������_RIGHT");
			ANIMATIONMANAGER->start("������_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&bird.rc, 0, -2);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("������_UP");
			ANIMATIONMANAGER->start("������_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&bird.rc, 0, 2);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("������_DOWN");
			ANIMATIONMANAGER->start("������_DOWN");
		}
		break;

	default:
		break;
	}

}

void characterChoice::render()
{
	//Rectangle(getMemDC(), paily.rc.left, paily.rc.top, paily.rc.right, paily.rc.bottom);
	if (characterNum == 0)
	{
	   paily.img->aniRender(getMemDC(), paily.rc.left, paily.rc.top,paily.ANIM);
	   warm.img->aniRender(getMemDC(), warm.rc.left, warm.rc.top, warm.ANIM);
	   bird.img->aniRender(getMemDC(), bird.rc.left, bird.rc.top, bird.ANIM);
	}

	if (characterNum == 1)
	{
		paily.img->aniRender(getMemDC(), paily.rc.left, paily.rc.top, paily.ANIM);
	}
	if (characterNum == 2)
	{
		warm.img->aniRender(getMemDC(), warm.rc.left, warm.rc.top, warm.ANIM);
	}
	if (characterNum == 3)
	{
		bird.img->aniRender(getMemDC(), bird.rc.left, bird.rc.top, bird.ANIM);
	}
}

void characterChoice::chaChoice()
{

}

void characterChoice::animation()
{
	ANIMATIONMANAGER->addAnimation("������_IDLE", "������", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("������_LEFT", "������", 3, 5, 6,false, true);
	ANIMATIONMANAGER->addAnimation("������_RIGHT", "������", 6, 8, 6, false, true);
	ANIMATIONMANAGER->addAnimation("������_UP", "������", 9, 11, 6, false, true);

	ANIMATIONMANAGER->addAnimation("ĳ����_IDLE", "ĳ����", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("ĳ����_LEFT", "ĳ����", 0, 2, 6, false, true);
	ANIMATIONMANAGER->addAnimation("ĳ����_RIGHT", "ĳ����", 3, 5, 6, false, true);
	ANIMATIONMANAGER->addAnimation("ĳ����_UP", "ĳ����", 6, 8, 6, false, true);
	ANIMATIONMANAGER->addAnimation("ĳ����_DOWN", "ĳ����", 9, 11, 6, false, true);

	ANIMATIONMANAGER->addAnimation("������_IDLE", "������", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("������_LEFT", "������", 0, 2, 6, false, true);
	ANIMATIONMANAGER->addAnimation("������_RIGHT", "������", 3, 5, 6, false, true);
	ANIMATIONMANAGER->addAnimation("������_UP", "������", 9, 11, 6, false, true);
	ANIMATIONMANAGER->addAnimation("������_DOWN", "������", 6, 8, 6, false, true);

	// �ʱ⼳�� �ִϸ��̼�
	paily.ANIM = ANIMATIONMANAGER->findAnimation("������_IDLE");

	warm.ANIM = ANIMATIONMANAGER->findAnimation("ĳ����_IDLE");

	bird.ANIM = ANIMATIONMANAGER->findAnimation("������_IDLE");
	// �ʱ⼳�� �ִϸ��̼�

}

void characterChoice::choice()
{
	if (PtInRect(&paily.rc, m_ptMouse))
	{
		isClick = true;
		temptime = currenttime;
		charact = PAILY;
		characterNum = 1;
	}

	if (PtInRect(&warm.rc, m_ptMouse))
	{
		isClick = true;
		temptime = currenttime;
		charact = WARM;
		characterNum = 2;
	}

	if (PtInRect(&bird.rc, m_ptMouse))
	{
		isClick = true;
		temptime = currenttime;
		charact = BIRD;
		characterNum = 3;
	}

}
