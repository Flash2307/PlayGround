#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"
#include "Line.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
#define LINE_RADIUS 3
#define PI = 3.1416f

class Game
{
public:
	typedef std::unique_ptr< Line > LinePtrType;

	enum {  PLAYER_COUNT = 4 };

	Game();

	void update();
	void draw( sf::RenderWindow* window );
private:
	std::array< LinePtrType, PLAYER_COUNT > lines;
	SharedCollisionGridType pCollisionGrid;
};
