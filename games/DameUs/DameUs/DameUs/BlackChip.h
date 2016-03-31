#pragma once

#include "Chip.h"

class BlackChip : public Chip
{
public:
	BlackChip();
	~BlackChip();
	virtual void load();
	virtual bool isSelected();
};
