#pragma once
#include "gameNode.h"
#include "characterChoice.h"

class choiceScene : public gameNode
{
private:
	characterChoice* character_info;
	//float temptime;
	//float currenttime;
	//bool isClick;

public:
	HRESULT init();
	void release();
	void update();
	void render();
	
	
	/*void setData(CHARACTER character) 
	{ character_info->charact = character; }*/
	/*int getData() { return character_info->charact; }*/
};

