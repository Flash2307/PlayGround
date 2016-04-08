#pragma once

#include "BlackChip.h"

class BlackChipKing : public BlackChip
{
public:
	BlackChipKing();
	~BlackChipKing();
	void load();
	void getPossibleDestinations(Move*[], Board*);
};

