#include "BlackChipKing.h"

BlackChipKing::BlackChipKing()
{
	this->texture = new Entity();
	this->load();
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