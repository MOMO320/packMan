#pragma once
#include"gameNode.h"
#include"choiceScene.h"
#include"townScene.h"
#include "animationTest.h"
class mainGame :  public gameNode
{
private:
	
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};
