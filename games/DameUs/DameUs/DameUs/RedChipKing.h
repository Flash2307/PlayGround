#pragma once

#include "RedChip.h"

class RedChipKing : public RedChip
{
public:
	RedChipKing();
	~RedChipKing();
	void load();
	bool isSelected();
};

RedChipKing::RedChipKing()
{
	this->texture = new Entity();
	this->load();
}

