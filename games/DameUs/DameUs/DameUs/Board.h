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
	void initializeBoard();
	void load();
	Entity* getTexture();

private:
	Entity* texture;
	Chip* chips[8][8];
};

