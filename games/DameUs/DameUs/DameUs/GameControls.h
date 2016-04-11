#pragma once
#include "Controls.h"

class GameControls
{

public:
	static GameControls* getInstance();

	GameControls();
	~GameControls();

	bool upKey();
	bool leftKey();
	bool rightKey();
	bool downKey();
	bool aKey();
	bool bKey();

	void clear();

	bool upKeyPressed;
	bool downKeyPressed;
	bool leftKeyPressed;
	bool rigthKeyPressed;
	bool aKeyPressed;
	bool bKeyPressed;

};


