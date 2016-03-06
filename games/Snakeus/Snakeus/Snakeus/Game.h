#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"

#define HEIGHT 600
#define WIDTH 800
#define LINE_RADIUS 3
#define PI = 3.1416f

class Game {
	Line* lines[4];
	int nbPlayers;
	void testCollision(int player1, int player2, sf::Vector2i point);
public:
	Game(int players);
	void update();
	void draw(sf::RenderWindow* window);
};