#pragma once

#include "Entity.h"
#include "Coordinates.h"

class Chip
{
public:
	virtual bool isSelected(){ return false; }
	virtual void load(){}
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
	}

	Coordinates* getCoordinates()
	{
		return coordinates;
	}
protected:
	Entity* texture;
	Coordinates* coordinates;
};
