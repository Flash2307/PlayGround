#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"
#include "SystemInput.h"
#include "Line.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 1000
#define WORLD_WIDTH 800
#define LINE_RADIUS 3
#define PI = 3.1416f

class Game
{
public:
	typedef std::unique_ptr< Line > LinePtrType;

	Game();

	void update();
	void draw( sf::RenderWindow* window );
private:
	void renderLineStat( sf::RenderWindow* pWindow_, Line& line_ );

	SystemInput systemCom;
	std::array< LinePtrType, PLAYER_COUNT > lines;
	SharedCollisionGridType pCollisionGrid;
	sf::Font font;
	bool hasPlayerAlive;
};
