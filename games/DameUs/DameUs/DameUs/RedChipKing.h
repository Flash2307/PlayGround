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



