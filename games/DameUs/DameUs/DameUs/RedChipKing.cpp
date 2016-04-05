#include "RedChipKing.h"

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