#pragma once

#include "Entity.h"
#include "Chip.h"
#include "RedChip.h"
#include "BlackChip.h"

class Board
{
public:
	Board();
	~Board();
	void initializeBoard(sf::RenderWindow* window);
	void load();
	Entity* getTexture();
	void renderBoard(sf::RenderWindow* window);


private:
	Entity* texture;
	Chip* redChips[8][8];
	Chip* blackChips[8][8];
};

