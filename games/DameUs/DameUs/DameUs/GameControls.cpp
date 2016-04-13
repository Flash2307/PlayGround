#include "GameControls.h"
#include "GamePadControls.h"
#include "SystemInput.h"

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

	this->player1Controls->startMonitor();
	this->player2Controls->startMonitor();

	this->player1Name = "";
	this->player2Name = "";

	this->player1Index = 0;
	this->player2Index = 1;
}

GameControls::~GameControls()
{
}

void GameControls::setPlayer1Name(std::string name)
{
	this->player1Name = name;
}

void GameControls::setPlayer2Name(std::string name)
{
	this->player2Name = name;
}

std::string GameControls::getPlayer1Name()
{
	return this->player1Name;
}

std::string GameControls::getPlayer2Name()
{
	return this->player2Name;
}

int GameControls::getPlayer1Index()
{
	return this->player1Index;
}

int GameControls::getPlayer2Index()
{
	return this->player2Index;
}

void GameControls::createInstance(int argc, char** argv)
{
	/*if (argc == 1)
	{
		GameControls::instance = new GameControls(new KeyboardControlsPlayer1(), new KeyboardControlsPlayer1());
	}
	else
	{*/
		GameControls::instance = new GameControls(new GamePadControls(), new GamePadControls());
		GameControls::instance->systemInput = new SystemInput(argc, argv);
	//}
}