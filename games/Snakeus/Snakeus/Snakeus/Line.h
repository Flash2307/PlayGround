#pragma once
#include <SFML/Graphics.hpp>

class Line {
	
	int holeCounter;
	double posX;
	double posY;
	double angle;
	sf::Color playerColor;
	std::vector<sf::Vector2i> positions;
	bool inHole;
	bool alive;

public:
	Line(int x,int y, sf::Color);
	void update();
	double getX();
	double getY();
	double getAngle();
	sf::Color getPlayerColor();
	std::vector<sf::Vector2i> getPositions();
	bool isInHole();
	void kill();

};
