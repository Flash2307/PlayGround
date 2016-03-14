#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"
#include "SystemInput.h"
#include "Line.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 1000

#define WORLD_WIDTH 800
#define WORLD_HEIGHT SCREEN_HEIGHT

#define LINE_RADIUS 3
#define PI = 3.1416f

class Game
{
public:
	typedef std::unique_ptr< Line > LinePtrType;

	Game( int argc_, char** argv_ );

	void update();
	void draw( sf::RenderWindow* window );
	void reset();
private:
	void initRessources();
	void initPlayers();

	void updateLinesPosition();
	void checkEndgameAction();
	void resetAllLines();

	void renderLineStat( sf::RenderWindow* pWindow_, Line& line_ );
	void renderEndGameMessages( sf::RenderWindow* pWindow_ );
	void renderLines( sf::RenderWindow* pWindow_ );

	void sendStatictics();

	SystemInput systemCom;
	std::array< LinePtrType, PLAYER_COUNT > lines;
	SharedCollisionGridType pCollisionGrid;
	sf::Font font;
	bool hasPlayerAlive;
	bool quit;
	bool scoreSended;
};
