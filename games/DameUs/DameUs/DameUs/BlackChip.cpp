#include "BlackChip.h"
#include "Board.h"

BlackChip::BlackChip()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->selected = false;
	this->chipType = Normal;
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

void BlackChip::getPossibleDestinations(Move* positions[], Board* board)
{
	positions[0] = nullptr;
	positions[1] = nullptr;
	positions[2] = nullptr;
	positions[3] = nullptr;

	int x = this->coordinates->x;
	int y = this->coordinates->y;

	int newX = x - 1;
	int newY = y - 1;

	if (!board->coordinatesExist(newY, newX))
	{

	}
	else if (board->hasNothing(newY, newX))
	{
		auto position = new Coordinates();
		position->x = newX;
		position->y = newY;

		positions[0] = new Move(this->coordinates, position, nullptr);
	}

	else if (board->hasBlackChip(newY, newX))
	{

	}

	else if (board->hasRedChip(newY, newX))
	{
		auto defeatedLocation = new Coordinates();
		defeatedLocation->x = newX;
		defeatedLocation->y = newY;

		newX -= 1;
		newY -= 1;
		if (!board->coordinatesExist(newY, newX))
		{
		}

		else if (board->hasNothing(newY, newX))
		{
			auto position = new Coordinates();
			position->x = newX;
			position->y = newY;

			positions[0] = new Move(this->coordinates, position, board->getRedChip(defeatedLocation->y, defeatedLocation->x));
		}
	}

	newX = x + 1;
	newY = y - 1;

	if (!board->coordinatesExist(newY, newX))
	{

	}
	else if (board->hasNothing(newY, newX))
	{
		auto position = new Coordinates();
		position->x = newX;
		position->y = newY;

		positions[1] = new Move(this->coordinates, position, nullptr);
	}

	else if (board->hasBlackChip(newY, newX))
	{
	}

	else if (board->hasRedChip(newY, newX))
	{
		auto defeatedLocation = new Coordinates();
		defeatedLocation->x = newX;
		defeatedLocation->y = newY;

		newX += 1;
		newY -= 1;

		if (!board->coordinatesExist(newY, newX))
		{
		}

		else if (board->hasNothing(newY, newX))
		{
			auto position = new Coordinates();
			position->x = newX;
			position->y = newY;

			positions[1] = new Move(this->coordinates, position, board->getRedChip(defeatedLocation->y, defeatedLocation->x));
		}
	}

}