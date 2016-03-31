#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	this->gameControls = GameControls::getInstance();
	this->board = new Board();
	this->board->getTexture()->setOrigin(this->board->getTexture()->getGlobalBounds().width / 2, this->board->getTexture()->getGlobalBounds().height / 2);
	this->board->getTexture()->setPosition(window->getSize().x / 2, window->getSize().y / 2);

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
	window->draw(*this->board->getTexture());
}
void main_game::Destroy(sf::RenderWindow* window)
{
	delete board;
}
