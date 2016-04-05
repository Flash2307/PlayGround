#pragma once

#include "Entity.h"
#include "Coordinates.h"

class Highlight
{
public:
	Highlight();
	~Highlight();
	void load();

	Entity* getTexture()
	{
		return this->texture;
	}
	void setCoordinates(int i, int j, sf::RenderWindow* window);

	Coordinates* getCoordinates()
	{
		return coordinates;
	}

private:
	Entity* texture;
	Coordinates* coordinates;
};
