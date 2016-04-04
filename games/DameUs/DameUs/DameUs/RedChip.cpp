#include "RedChip.h"

RedChip::RedChip()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->load();
	this->texture->setOrigin(this->texture->getGlobalBounds().width / 2, this->texture->getGlobalBounds().height / 2);
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