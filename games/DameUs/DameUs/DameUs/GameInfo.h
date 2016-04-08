#pragma once

#include <ctime>
#include "Coordinates.h"

enum Turn
{
	Red = 0,
	Black
};

class GameInfo
{
public:
	static GameInfo* getInstance();
	Turn getTurn();
	void changeTurn();
	int getRedChipsRemaining();
	int getBlackChipsRemaining();
	void resetCounters();
	void removeRedChip();
	void removeBlackChip();
	void setCurrentCoordinates(int j, int i);
	Coordinates* getCurrentCoodinates();
	bool hopping;
	~GameInfo();

private:
	GameInfo();
	static GameInfo* instance;
	Turn currentTurn;
	int redChipsRemaining;
	int blackChipsRemaining;
	Coordinates* currentPosition;
};
