#pragma once

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"
#include "SystemInput.h"

class Line
{
public:
	Line( const Player& player_, const SharedCollisionGridType& pCollisionGrid_ );

	void update();
	void draw( sf::RenderWindow* window );

	double getX() const;
	double getY() const;
	double getAngle() const;
	size_t getPointCount() const;

	sf::Color getPlayerColor() const;
	const Player& getPlayer() const;

	bool isAlive() const;
	bool isInHole();
	void kill();
	void reset();
private:
	void detectCollision();

	SharedCollisionGridType pCollisionGrid;
	CirclePtrType pNextPoint;
	Player player;

	int holeCounter;
	double angle;
	sf::Color playerColor;

	bool inHole;
	bool alive;
};
