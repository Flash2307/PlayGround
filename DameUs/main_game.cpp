#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	this->gameControls = GameControls::getInstance();
}
void main_game::Update(sf::RenderWindow* window)
{
	if (this->gameControls->player1Controls->escapeKey())
	{
		coreState.SetState(new main_menu());
	}
}
void main_game::Render(sf::RenderWindow* window)
{
}
void main_game::Destroy(sf::RenderWindow* window)
{
}
