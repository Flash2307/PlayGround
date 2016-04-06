#include <iostream>

#include <SFML/Graphics.hpp>
#include <direct.h>

#include "Game.h"

int main( int argc, char** argv )
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window( desktop, "ZATAKA!"/*, sf::Style::Fullscreen*/);

	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled( false );

	Game game(argc, argv, desktop );

	while( window.isOpen() )
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
