#include "game_state.h"
#include "main_menu.h"
#include "GameControls.h"

game_state coreState; 
bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "DameUs");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		GameControls* pKeyController = GameControls::getInstance();
		pKeyController->clear();

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Left:
					pKeyController->leftKeyPressed = true;
					break;
				case sf::Keyboard::Key::Right:
					pKeyController->rigthKeyPressed = true;
					break;
				case sf::Keyboard::Key::Up:
					pKeyController->upKeyPressed = true;
					break;
				case sf::Keyboard::Key::Down:
					pKeyController->downKeyPressed = true;
					break;
				case sf::Keyboard::Key::A:
					pKeyController->aKeyPressed = true;
					break;
				case sf::Keyboard::Key::B:
					pKeyController->bKeyPressed = true;
					break;
				}
				break;
			default:
				break;
			}				
		}

		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}
	}

	return 0;
}
