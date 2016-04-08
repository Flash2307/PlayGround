#pragma once

#include "RedChip.h"

class RedChipKing : public RedChip
{
public:
	RedChipKing();
	~RedChipKing();
	void load();
	void getPossibleDestinations(Move*[], Board*);
};

RedChipKing::RedChipKing()
{
	this->texture = new Entity();
	this->load();
}

