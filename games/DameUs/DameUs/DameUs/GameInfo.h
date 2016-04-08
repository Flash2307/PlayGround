#pragma once

#include <ctime>

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
	int getRedChipsRemaining();
	int getBlackChipsRemaining();
	void removeRedChip();
	void removeBlackChip();
	~GameInfo();

private:
	GameInfo();
	static GameInfo* instance;
	Turn currentTurn;
	int redChipsRemaining;
	int blackChipsRemaining;
};
