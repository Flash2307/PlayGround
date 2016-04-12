#include "GameControls.h"


GameControls* GameControls::instance = nullptr;
GameControls* GameControls::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameControls(new KeyboardControlsPlayer1(), new KeyboardControlsPlayer1());
		}
		return instance;
	}

GameControls::GameControls(Controls* p1, Controls* p2)
{
	this->player1Controls = p1;
	this->player2Controls = p2;
}

GameControls::~GameControls()
{
}