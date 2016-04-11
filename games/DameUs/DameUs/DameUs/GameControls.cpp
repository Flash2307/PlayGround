#include "GameControls.h"




GameControls* GameControls::getInstance()
{
	static GameControls* instance = nullptr;

	if (instance == nullptr)
	{
		instance = new GameControls();
	}

	return instance;
}

GameControls::GameControls() :
	upKeyPressed(false),
	downKeyPressed(false),
	leftKeyPressed(false),
	rigthKeyPressed(false),
	aKeyPressed(false),
	bKeyPressed(false)
{

}

GameControls::~GameControls()
{
}

bool GameControls::upKey()
{
	return upKeyPressed;
}

bool GameControls::leftKey()
{
	return downKeyPressed;
}

bool GameControls::rightKey()
{
	return rigthKeyPressed;
}

bool GameControls::downKey()
{
	return downKeyPressed;
}

bool GameControls::aKey()
{
	return aKeyPressed;
}

bool GameControls::bKey()
{
	return bKeyPressed;
}

void GameControls::clear()
{
	upKeyPressed=(false);
	downKeyPressed=(false);
	leftKeyPressed=(false);
	rigthKeyPressed=(false);
	aKeyPressed=(false);
	bKeyPressed=(false);
}