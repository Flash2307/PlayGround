#include "BlackChip.h"


BlackChip::BlackChip()
{
	this->texture = new Entity();
	this->load();
}


BlackChip::~BlackChip()
{
	delete this->texture;
}

void BlackChip::load()
{
	this->texture->Load("blackchip.png");
}

bool BlackChip::isSelected()
{
	return true;
}