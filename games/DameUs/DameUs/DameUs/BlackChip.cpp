#include "BlackChip.h"


BlackChip::BlackChip()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->load();
	this->texture->setOrigin(this->texture->getGlobalBounds().width / 2, this->texture->getGlobalBounds().height / 2);
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