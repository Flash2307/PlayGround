#include "GameInfo.h"
#include <iostream>

GameInfo* GameInfo::instance = nullptr;
GameInfo* GameInfo::getInstance()
{
	if (instance == nullptr)
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

	this->currentPosition = new Coordinates();
	hopping = false;
}

void GameInfo::resetCounters()
{
	this->blackChipsRemaining = 12;
	this->redChipsRemaining = 12;
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

void GameInfo::setCurrentCoordinates(int j, int i)
{
	this->currentPosition->x = i;
	this->currentPosition->y = j;
}

Coordinates* GameInfo::getCurrentCoodinates()
{
	return this->currentPosition;
}

void GameInfo::changeTurn()
{
	switch (this->currentTurn)
	{
	case Red:
		this->currentTurn = Black;
		break;
	case Black:
		this->currentTurn = Red;
		break;
	default:
		break;
	}
}