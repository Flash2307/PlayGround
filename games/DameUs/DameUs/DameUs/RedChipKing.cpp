#include "RedChipKing.h"

RedChipKing::RedChipKing()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->load();
	this->texture->setOrigin(this->texture->getGlobalBounds().width / 2, this->texture->getGlobalBounds().height / 2);
}


RedChipKing::~RedChipKing()
{
	delete this->texture;
}

void RedChipKing::load()
{
	this->texture->Load("redchipking.png");
}

bool RedChipKing::isSelected()
{
	return false;
}