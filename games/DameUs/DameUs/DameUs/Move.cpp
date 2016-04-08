#include "Move.h"
#include "Chip.h"

Move::Move(Coordinates* old, Coordinates* newC, Chip* chip)
{
	this->oldCoordinates = old;
	this->newCoordinates = newC;
	this->chipDefeated = chip;
}

Move::~Move()
{
}