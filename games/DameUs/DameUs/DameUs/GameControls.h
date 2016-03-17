#pragma once
#include "Controls.h"
#include "KeyboardControlsPlayer1.h"

class GameControls
{

public:
	static GameControls* getInstance();
	~GameControls();
	Controls* player1Controls;
	Controls* player2Controls;

private:
	GameControls(Controls*, Controls*);
	static GameControls* instance;

};


