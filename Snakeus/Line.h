#pragma once

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"

class Line
{
public:
	Line(int x,int y, sf::Color playerColor_, const SharedCollisionGridType& pCollisionGrid_ );

	void update();
	void draw( sf::RenderWindow* window );

	double getX() const;
	double getY() const;
	double getAngle() const;

	sf::Color getPlayerColor() const;

	bool isInHole();
	void kill();
private:
	void detectCollision();

	SharedCollisionGridType pCollisionGrid;
	CirclePtrType pNextPoint;

	int holeCounter;
	double angle;
	sf::Color playerColor;

	bool inHole;
	bool alive;
};
