#include "BlackChipKing.h"

BlackChipKing::BlackChipKing()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->load();
	this->texture->setOrigin(this->texture->getGlobalBounds().width / 2, this->texture->getGlobalBounds().height / 2);
}

BlackChipKing::~BlackChipKing()
{
	delete this->texture;
}

void BlackChipKing::load()
{
	this->texture->Load("blackchipking.png");
}

bool BlackChipKing::isSelected()
{
	return false;
}