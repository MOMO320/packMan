#include "stdafx.h"
#include "characterChoice.h"

HRESULT characterChoice::init()
{
	//=======================================================================
	//  첫번째 캐릭터(파일이)
	paily.NUM	= PAILY;
	paily.NAME	= "파이리";
	paily.img	= IMAGEMANAGER->addFrameImage("파일이", "images/파일이.bmp", 78 * 3, 91 * 3, 3, 4, true, RGB(255, 0, 255));
	paily.rc	= RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2 + 70, paily.img->getFrameWidth(), paily.img->getFrameHeight());
	paily.ani	= IDLE;
	paily.HP	= 100;
	paily.MP	= 30;
	paily.STR	= 10;
	paily.INT	= 5;
	paily.LEVEL = 1;
	paily.isChoise = false;

	//  두번째 캐릭터(애벌래)
	warm.NUM	= WARM;
	warm.NAME	= "캐터피";
	warm.img	= IMAGEMANAGER->addFrameImage("캐터피", "images/캐터피.bmp", 72 * 3, 90 * 3, 3, 4, true, RGB(255, 0, 255));
	warm.rc		= RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2+ 70, warm.img->getFrameWidth(), warm.img->getFrameHeight());
	warm.ani	= IDLE;
	warm.HP		= 100;
	warm.MP		= 40;
	warm.STR	= 3;
	warm.INT	= 30;
	warm.LEVEL	= 1;
	warm.isChoise = false;

	//세번째 캐릭터(새)
	bird.NUM	= BIRD;
	bird.NAME	= "피죤투";
	bird.img	= IMAGEMANAGER->addFrameImage("피죤투", "images/피죤투.bmp", 78 * 3, 90 * 3, 3, 4, true, RGB(255, 0, 255));
	bird.rc		= RectMakeCenter(WINSIZEX / 2 + 100, WINSIZEY / 2 + 70, bird.img->getFrameWidth(), bird.img->getFrameHeight());
	bird.ani	= IDLE;
	bird.HP		= 100;
	bird.MP		= 40;
	bird.STR	= 15;
	bird.INT	= 25;
	bird.LEVEL	= 1;
	bird.isChoise = false;
	
	//=======================================================================
	
	// 애니메이션 init()
	animation();
	ANIMATIONMANAGER->start("파일이_IDLE");
	ANIMATIONMANAGER->start("캐터피_IDLE");
	ANIMATIONMANAGER->start("피죤투_IDLE");
	// 애니메이션 init()
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
			SCENEMANAGER->changeScene("타운맵");
		}
	}



	switch (characterNum)
	{
	case PAILY:
		if(KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&paily.rc, -2, 0);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("파일이_LEFT");
			ANIMATIONMANAGER->start("파일이_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&paily.rc, 2, 0);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("파일이_RIGHT");
			ANIMATIONMANAGER->start("파일이_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&paily.rc, 0, -2);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("파일이_UP");
			ANIMATIONMANAGER->start("파일이_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&paily.rc, 0, 2);
			paily.ANIM = ANIMATIONMANAGER->findAnimation("파일이_IDLE");
			ANIMATIONMANAGER->start("파일이_IDLE");
		}
		break;

	case WARM:
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&warm.rc, -2, 0);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("캐터피_LEFT");
			ANIMATIONMANAGER->start("캐터피_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&warm.rc, 2, 0);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("캐터피_RIGHT");
			ANIMATIONMANAGER->start("캐터피_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&warm.rc, 0, -2);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("캐터피_UP");
			ANIMATIONMANAGER->start("캐터피_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&warm.rc, 0, 2);
			warm.ANIM = ANIMATIONMANAGER->findAnimation("캐터피_DOWN");
			ANIMATIONMANAGER->start("캐터피_DOWN");
		}
		break;

	case BIRD:
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			OffsetRect(&bird.rc, -2, 0);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("피죤투_LEFT");
			ANIMATIONMANAGER->start("피죤투_LEFT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			OffsetRect(&bird.rc, 2, 0);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("피죤투_RIGHT");
			ANIMATIONMANAGER->start("피죤투_RIGHT");
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			OffsetRect(&bird.rc, 0, -2);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("피죤투_UP");
			ANIMATIONMANAGER->start("피죤투_UP");
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			OffsetRect(&bird.rc, 0, 2);
			bird.ANIM = ANIMATIONMANAGER->findAnimation("피죤투_DOWN");
			ANIMATIONMANAGER->start("피죤투_DOWN");
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
	ANIMATIONMANAGER->addAnimation("파일이_IDLE", "파일이", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("파일이_LEFT", "파일이", 3, 5, 6,false, true);
	ANIMATIONMANAGER->addAnimation("파일이_RIGHT", "파일이", 6, 8, 6, false, true);
	ANIMATIONMANAGER->addAnimation("파일이_UP", "파일이", 9, 11, 6, false, true);

	ANIMATIONMANAGER->addAnimation("캐터피_IDLE", "캐터피", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("캐터피_LEFT", "캐터피", 0, 2, 6, false, true);
	ANIMATIONMANAGER->addAnimation("캐터피_RIGHT", "캐터피", 3, 5, 6, false, true);
	ANIMATIONMANAGER->addAnimation("캐터피_UP", "캐터피", 6, 8, 6, false, true);
	ANIMATIONMANAGER->addAnimation("캐터피_DOWN", "캐터피", 9, 11, 6, false, true);

	ANIMATIONMANAGER->addAnimation("피죤투_IDLE", "피죤투", 0, 2, 6,false, true);
	ANIMATIONMANAGER->addAnimation("피죤투_LEFT", "피죤투", 0, 2, 6, false, true);
	ANIMATIONMANAGER->addAnimation("피죤투_RIGHT", "피죤투", 3, 5, 6, false, true);
	ANIMATIONMANAGER->addAnimation("피죤투_UP", "피죤투", 9, 11, 6, false, true);
	ANIMATIONMANAGER->addAnimation("피죤투_DOWN", "피죤투", 6, 8, 6, false, true);

	// 초기설정 애니메이션
	paily.ANIM = ANIMATIONMANAGER->findAnimation("파일이_IDLE");

	warm.ANIM = ANIMATIONMANAGER->findAnimation("캐터피_IDLE");

	bird.ANIM = ANIMATIONMANAGER->findAnimation("피죤투_IDLE");
	// 초기설정 애니메이션

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
