#include "stdafx.h"
#include "choiceScene.h"

HRESULT choiceScene::init()
{
	character_info = new characterChoice;
	character_info->init();

	IMAGEMANAGER->addImage("ĳ���ͼ���â", "images/ĳ���ͼ���â.bmp", 284 * 3, 227 * 3,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("ĳ���ͼ��ñ���", "images/ĳ���͸��������ּ���_����.bmp", 454 , 113 , true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����̳���", "images/�������̸�â.bmp", 119, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ĳ���ǳ���", "images/ĳ�����̸�â.bmp", 119, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����������", "images/�������̸�â.bmp", 119, 48, true, RGB(255, 0, 255));

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
	IMAGEMANAGER->render("ĳ���ͼ���â", getMemDC());
	IMAGEMANAGER->render("ĳ���ͼ��ñ���", getMemDC(), WINSIZEX/4 -15, 200);
	IMAGEMANAGER->render("�����̳���", getMemDC(), WINSIZEX / 4 + 40 , 450);
	IMAGEMANAGER->render("ĳ���ǳ���", getMemDC(), WINSIZEX / 4 + 150, 450);
	IMAGEMANAGER->render("����������", getMemDC(), WINSIZEX/4 + 270, 450);
	character_info->render();
}

