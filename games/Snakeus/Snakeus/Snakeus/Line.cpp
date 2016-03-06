#include "Line.h"
#include <math.h>

#define SPEED 2.5f
#define TURN_SPEED 0.07f

#define HOLE_FREQUENCY 100
#define HOLE_LENGTH 10

Line::Line(int x, int y, sf::Color color) {
	posX = x;
	posY = y;
	angle = 0;
	playerColor = color;
	holeCounter = 0;
	inHole = false;
	alive = true;
}

void Line::update() {
	if (alive) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			angle += TURN_SPEED;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			angle -= TURN_SPEED;
		}
		posX += SPEED * cos(angle);
		posY += SPEED * sin(angle);

		if (holeCounter < HOLE_FREQUENCY) {
			inHole = false;
			positions.push_back(sf::Vector2i(posX, posY));
		}
		else if (holeCounter >= HOLE_FREQUENCY + HOLE_LENGTH) {
			holeCounter = 0;
		}
		else {
			inHole = true;
		}
		holeCounter++;
	}
}

double Line::getX() {
	return posX;
}
double Line::getY() {
	return posY;
}
double Line::getAngle() {
	return angle;
}
sf::Color Line::getPlayerColor() {
	return playerColor;
}
std::vector<sf::Vector2i> Line::getPositions() {
	return positions;
}
bool Line::isInHole() {
	return inHole;
}
void Line::kill(){
	alive = false;
}