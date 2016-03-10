#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "ZATAKA!");
	window.setFramerateLimit(30);

	Game game;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if( event.type == sf::Event::Closed )
				window.close();
		}

		window.clear();
		game.update();
		game.draw(&window);
		window.display();
	}

	return 0;
}
