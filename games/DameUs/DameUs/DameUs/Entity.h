#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	Entity()
	{
		this->texture = new sf::Texture();
	}

	~Entity()
	{
		delete this->texture;
	}

	void Load(std::string filename)
	{
		this->texture->loadFromFile("img/" + filename);
		this->setTexture(*this->texture);
	}

private:
	sf::Texture* texture;
};