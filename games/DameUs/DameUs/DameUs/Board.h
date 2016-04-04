#pragma once

#include "Entity.h"
#include "Chip.h"
#include "RedChip.h"
#include "BlackChip.h"
#include "Highlight.h"
#include "GameInfo.h"

class Board
{
public:
	Board();
	~Board();
	void initializeBoard(sf::RenderWindow* window);
	void initializeHighlight(Turn turn);
	void load();
	Entity* getTexture();
	void renderBoard(sf::RenderWindow* window);


private:
	Entity* texture;
	Chip* redChips[8][8];
	Chip* blackChips[8][8];
	Highlight* highlights[8][8];
};

