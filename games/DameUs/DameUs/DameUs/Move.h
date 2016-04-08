#pragma once
#include "Coordinates.h"

class Chip;
class Move
{
public:
	Move(Coordinates* old, Coordinates* newC, Chip* chip);
	Coordinates* newCoordinates;
	Coordinates* oldCoordinates;
	Chip* chipDefeated;
	~Move();

private:
	
};
