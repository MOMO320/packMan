#include "stdafx.h"
#include "player.h"


HRESULT player::init()
{
	chChoice = new characterChoice;
	//chChoice->init();

	if (chChoice->paily.isChoise == true)
	{
		p1.NAME = chChoice->getPailyInfo()->NAME;
		
		
		
		
		/*paily.img 
		paily.rc =
		paily.ani 
		paily.HP =
		paily.MP =
		paily.STR 
		paily.INT 
		paily.LEVEL =*/
	}

	return S_OK;
}

void player::release()
{

}

void player::update()
{

}

void player::render()
{
}

void player::chaChoice()
{
	
}

void player::animation()
{
}
