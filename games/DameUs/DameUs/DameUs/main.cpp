#include "game_state.h"
#include "main_menu.h"
#include <thread>

game_state coreState; 
bool quitGame = false;

int main(int argc, char ** argv)
{
	GameControls::createInstance(argc, argv);
	sf::RenderWindow window(sf::VideoMode(800, 800), "DameUs");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(17));
	}

	return 0;
}
