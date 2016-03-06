#include "Game.h"
#include <iostream>



Game::Game(int players) {
	nbPlayers = players;

	for (int i = 0; i < nbPlayers; i++) {
		lines[i] = new Line(i * 100 + 10, i * 100 + 10, sf::Color::Red);
	}
}

void Game::update() {
	for (int i = 0; i < nbPlayers; i++) {
		lines[i]->update();
	}
	for (int i = 0; i < nbPlayers; i++) {
		std::vector<sf::Vector2i> positions = lines[i]->getPositions();
		for (int k = 0; k < positions.size(); k++) {
			for (int j = 0; j < nbPlayers; j++) {
				testCollision(i, j, positions.at(k));
			}
		}
	}

}

void Game::testCollision(int p1, int p2, sf::Vector2i point) {
	if (abs(lines[p2]->getX() + 3 * cos(lines[p2]->getAngle()) - point.x) <= 1 && abs(lines[p2]->getY() + 3 * sin(lines[p2]->getAngle()) - point.y) <= 1){
		lines[p2]->kill();
	}
	else if (abs(lines[p2]->getX() + 4 * cos(lines[p2]->getAngle() + 3.1416f / 2) - point.x) <= 1 && abs(lines[p2]->getY() + 4 * sin(lines[p2]->getAngle() + 3.1416f / 2) - point.y) <= 1) {
		lines[p2]->kill();
	}
	else if (abs(lines[p2]->getX() + 4 * cos(lines[p2]->getAngle() - 3.1416f / 2) - point.x) <= 1 && abs(lines[p2]->getY() + 4 * sin(lines[p2]->getAngle() - 3.1416f / 2) - point.y) <= 1) {
		lines[p2]->kill();
	}
}

void Game::draw(sf::RenderWindow* window) {
	sf::CircleShape shape(3.f);

	for (int i = 0; i < nbPlayers; i++) {
		std::vector<sf::Vector2i> positions = lines[i]->getPositions();
		shape.setFillColor(lines[i]->getPlayerColor());
		for (int j = 0; j < positions.size(); j++) {
			shape.setPosition(positions.at(j).x, positions.at(j).y);
			window->draw(shape);
		}

		if (lines[i]->isInHole()) {
			shape.setPosition(lines[i]->getX(), lines[i]->getY());
			window->draw(shape);
		}
	}
}
