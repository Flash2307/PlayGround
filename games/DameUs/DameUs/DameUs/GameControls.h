#pragma once
#include "Controls.h"
#include "KeyboardControlsPlayer1.h"
#include <string>

class GameControls
{

public:
	static GameControls* getInstance();
	~GameControls();
	Controls* player1Controls;
	Controls* player2Controls;
	void setPlayer1Name(std::string name);
	void setPlayer2Name(std::string name);
	std::string getPlayer1Name();
	std::string getPlayer2Name();
	int getPlayer1Index();
	int getPlayer2Index();

private:
	GameControls(Controls*, Controls*);
	static GameControls* instance;
	std::string player1Name;
	std::string player2Name;
	int player1Index;
	int player2Index;


};


