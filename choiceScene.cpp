#include "stdafx.h"
#include "choiceScene.h"

HRESULT choiceScene::init()
{
	character_info = new characterChoice;
	character_info->init();

	IMAGEMANAGER->addImage("캐릭터선택창", "images/캐릭터선택창.bmp", 284 * 3, 227 * 3,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("캐릭터선택구문", "images/캐릭터를선택해주세요_문구.bmp", 454 , 113 , true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("파일이네임", "images/파일이이름창.bmp", 119, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐터피네임", "images/캐터피이름창.bmp", 119, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피죤투네임", "images/피죤투이름창.bmp", 119, 48, true, RGB(255, 0, 255));

	return S_OK;
}

void choiceScene::release()
{
	character_info->release();
}

void choiceScene::update()
{

	character_info->update();
	/*currenttime += TIMEMANAGER->getElapsedTime();*/


}

void choiceScene::render()
{
	IMAGEMANAGER->render("캐릭터선택창", getMemDC());
	IMAGEMANAGER->render("캐릭터선택구문", getMemDC(), WINSIZEX/4 -15, 200);
	IMAGEMANAGER->render("파일이네임", getMemDC(), WINSIZEX / 4 + 40 , 450);
	IMAGEMANAGER->render("캐터피네임", getMemDC(), WINSIZEX / 4 + 150, 450);
	IMAGEMANAGER->render("피죤투네임", getMemDC(), WINSIZEX/4 + 270, 450);
	character_info->render();
}

