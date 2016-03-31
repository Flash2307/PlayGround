#pragma once

#include "Entity.h"


class Chip
{
public:
	virtual bool isSelected(){ return false; }
	virtual void load(){}
protected:
	Entity* texture;
};
