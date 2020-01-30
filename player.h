#pragma once
#include "characterChoice.h"


struct Player
{
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

};

class player : public characterChoice
{
private:
	characterChoice* chChoice;
	Player p1;
	

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void chaChoice();
	void animation();



};

