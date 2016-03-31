#include "RedChip.h"

RedChip::RedChip()
{
	this->texture = new Entity();
	this->load();
}

RedChip::~RedChip()
{
	delete this->texture;
}

void RedChip::load()
{
	this->texture->Load("redchip.png");
}

bool RedChip::isSelected()
{
	return true;
}