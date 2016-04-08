#include "Highlight.h"

Highlight::Highlight()
{
	this->texture = new Entity();
	this->coordinates = new Coordinates();
	this->load();
	this->texture->setOrigin(this->texture->getGlobalBounds().width / 2, this->texture->getGlobalBounds().height / 2);
}

Highlight::~Highlight()
{
	if (this->texture != nullptr)
	{
		delete this->texture;
	}
	if (this->coordinates != nullptr)
	{
		delete this->coordinates;
	}
	
}

void Highlight::load()
{
	this->texture->Load("highlight.png");
}

void Highlight::setCoordinates(int i, int j, sf::RenderWindow* window)
{
	if (this->coordinates == nullptr || this == nullptr)
	{
		return;
	}
	int height = window->getSize().y;
	int width = window->getSize().x;

	int preambuleWidth = ((width - 600) / 2) + 37.5;
	int preambuleHeight = ((height - 600) / 2) + 37.5;
	this->coordinates->x = preambuleWidth + i * 75;
	this->coordinates->y = preambuleHeight + j * 75;

	this->texture->setPosition(this->coordinates->x, this->coordinates->y);
}