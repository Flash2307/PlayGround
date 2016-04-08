#pragma once

#include "Chip.h"

class RedChip : public Chip
{
public:
	RedChip();
	~RedChip();
	virtual void load();
	virtual bool isSelected();
};

