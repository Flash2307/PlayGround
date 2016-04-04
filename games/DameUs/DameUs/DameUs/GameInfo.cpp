#include "GameInfo.h"
#include <iostream>

GameInfo* GameInfo::instance = NULL;
GameInfo* GameInfo::getInstance()
{
	if (instance == NULL)
	{
		instance = new GameInfo();
	}
	return instance;
}

GameInfo::GameInfo()
{
	time_t temp = std::time(nullptr);

	this->currentTurn = static_cast<Turn>(temp % 2);

	this->redChipsRemaining = 12;
	this->blackChipsRemaining = 12;
}

GameInfo::~GameInfo()
{
}

void GameInfo::removeRedChip()
{
	this->redChipsRemaining--;
}

void GameInfo::removeBlackChip()
{
	this->blackChipsRemaining--;
}

int GameInfo::getBlackChipsRemaining()
{
	return blackChipsRemaining;
}

int GameInfo::getRedChipsRemaining()
{
	return redChipsRemaining;
}

Turn GameInfo::getTurn()
{
	return currentTurn;
}