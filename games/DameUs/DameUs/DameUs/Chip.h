#pragma once

#include "Entity.h"
#include "Coordinates.h"
#include "Move.h"
#include <iostream>
class Board;

enum ChipType
{
	Normal,
	King
};

class Chip
{
public:
	bool isSelected(){ return this->selected; }
	void select(){ 
		std::cout << this->coordinates->y << this->coordinates->x << " selected\n";
		this->selected = true; }
	void unSelect() { 
		std::cout << this->coordinates->y << this->coordinates->x << " unSelected\n";
		this->selected = false; }
	virtual void getPossibleDestinations(Move*[], Board*){}

	virtual void load(){}

	ChipType getChipType()
	{
		return this->chipType;
	}
	
	void setChipType(ChipType chipType)
	{
		this->chipType = chipType;
	}

	Entity* getTexture()
	{
		return this->texture;
	}
	void setCoordinates(int i, int j, sf::RenderWindow* window)
	{
		int height = window->getSize().y;
		int width = window->getSize().x;

		int preambuleWidth = ((width - 600) / 2) + 37.5;
		int preambuleHeight = ((height - 600) / 2) + 37.5;
		this->coordinates->x = preambuleWidth + i * 75;
		this->coordinates->y = preambuleHeight + j * 75;

		this->texture->setPosition(this->coordinates->x, this->coordinates->y);
		this->coordinates->x = i;
		this->coordinates->y = j;
	}

	void setCoordinates(int i, int j)
	{
		this->coordinates->x = i;
		this->coordinates->y = j;
	}
	Coordinates* getCoordinates()
	{
		return coordinates;
	}
protected:
	Entity* texture;
	Coordinates* coordinates;
	bool selected;
	ChipType chipType;
};
