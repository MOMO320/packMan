#pragma once
#include "gameNode.h"
#include "characterChoice.h"
#include "choiceScene.h"
#include "player.h"
#include "camera.h"

class townScene : public gameNode
{
private:
	characterChoice* character_info; 
	
	

public :
	HRESULT init();
	void release();
	void update();
	void render();
	

};

