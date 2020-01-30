#pragma once
#include "gameNode.h"
#include "stdafx.h"


enum CHARACTER
{
	EMPTY = 0, PAILY , WARM ,BIRD
};
enum ANIMATION
{
	IDLE =1 , LEFT , RIGHT , DOWN , UP
};

struct CHARACTER_INFO
{
	CHARACTER	NUM;
	string		NAME;
	image*		img;
	RECT		rc;
	ANIMATION	ani;
	animation*	ANIM;
	int			HP;
	int			MP;
	int			STR;
	int			INT;
	int			LEVEL;
	bool		isChoise;
};

class characterChoice : public gameNode
{
private:
	float temptime;
	float currenttime;
	bool isClick;


public:
	CHARACTER charact = EMPTY;

	CHARACTER_INFO paily;
	CHARACTER_INFO warm;
	CHARACTER_INFO bird;

	HRESULT init();
	void release();
	void update();
	void render();
	void chaChoice();
	void animation();
	void choice();

	void setCharactENUM(CHARACTER num) { charact = num; }
	CHARACTER getCharactENUM() { return charact; }
	CHARACTER_INFO* getPailyInfo() { return &paily; }
	CHARACTER_INFO* getWarmInfo() { return &warm; }
	CHARACTER_INFO* getBirdInfo() { return &bird; }
};

