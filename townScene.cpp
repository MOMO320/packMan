#include "stdafx.h"
#include "townScene.h"

HRESULT townScene::init()
{
	IMAGEMANAGER->addImage("Ÿ���", "images/�����Ǹ���.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	character_info = new characterChoice;
	character_info->init();
	

	return S_OK;
}

void townScene::release()
{
	character_info->release();
}

void townScene::update()
{
	character_info->update();
}

void townScene::render()
{
	IMAGEMANAGER->render("Ÿ���", getMemDC());
	character_info->render();
}

