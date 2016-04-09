#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "CollisionGrid.h"
#include "SystemInput.h"
#include "Line.h"

#define GRID_SCALE 100
#define STAT_WIDTH  200

#define WORLD_HEIGHT SCREEN_HEIGHT

#define LINE_RADIUS 3
#define PI = 3.1416f

class Game
{
public:
	typedef std::unique_ptr< Line > LinePtrType;

	Game( int argc_, char** argv_, const sf::VideoMode& desktop_ );

	void update();
	void draw( sf::RenderWindow* window );
	void reset();

	inline size_t screenWidth() const
	{
		return this->desktop.width;
	}

	inline size_t screenHeight() const
	{
		return this->desktop.height;
	}

	inline size_t worldWidth() const
	{
		return ( screenWidth() - STAT_WIDTH );
	}
private:
	void initRessources();
	void initPlayers();

	void updateLinesPosition();
	void checkEndgameAction();
	void resetAllLines();

	void renderStatBoard(sf::RenderWindow* pWindow_);
	void renderLineStat( sf::RenderWindow* pWindow_, Line& line_ );
	void renderEndGameMessages( sf::RenderWindow* pWindow_ );
	void renderLines( sf::RenderWindow* pWindow_ );

	void sendStatictics();

	sf::VideoMode desktop;
	SystemInput systemCom;
	std::array< LinePtrType, PLAYER_COUNT > lines;
	SharedCollisionGridType pCollisionGrid;
	sf::Font font;
	bool hasPlayerAlive;
	bool quit;
	bool scoreSended;
	bool isStatBoardRendered;
};
