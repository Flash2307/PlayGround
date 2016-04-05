#include "main_game.h"
#include "main_menu.h"
#include <string>
#include <sstream>

void main_game::Initialize(sf::RenderWindow* window)
{
	this->gameControls = GameControls::getInstance();
	this->gameInfo = GameInfo::getInstance();
	this->board = new Board();
	this->board->initializeBoard(window);
	this->board->initializeHighlight(this->gameInfo->getTurn());

	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");

	this->turnText = new sf::Text("", *this->font, 64U);
	this->turnText->setOrigin(this->turnText->getGlobalBounds().width / 2, this->turnText->getGlobalBounds().height / 2);
	this->turnText->setPosition(250, 0);

	this->redChipsText = new sf::Text("", *this->font, 32U);
	this->redChipsText->setOrigin(this->redChipsText->getGlobalBounds().width / 2, this->redChipsText->getGlobalBounds().height / 2);
	this->redChipsText->setPosition(50, 720);

	this->blackChipsText = new sf::Text("", *this->font, 32U);
	this->blackChipsText->setOrigin(this->blackChipsText->getGlobalBounds().width / 2, this->blackChipsText->getGlobalBounds().height / 2);
	this->blackChipsText->setPosition(450, 720);
	
	
	this->board->getTexture()->setOrigin(this->board->getTexture()->getGlobalBounds().width / 2, this->board->getTexture()->getGlobalBounds().height / 2);
	this->board->getTexture()->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void main_game::Update(sf::RenderWindow* window)
{
	switch (this->gameInfo->getTurn())
	{
	case Black:
		this->turnText->setString("Player2's Turn");
		break;
	case Red:
		this->turnText->setString("Player1's Turn");
		break;
	default:
		this->turnText->setString("???????");
	}
	std::stringstream stream;
	stream << "Red Chips Remaining: " << this->gameInfo->getRedChipsRemaining();

	this->redChipsText->setString(stream.str());
	stream.str(std::string());
	stream << "Black Chips Remaining: " << this->gameInfo->getBlackChipsRemaining();
	this->blackChipsText->setString(stream.str());

	if (this->gameControls->player1Controls->escapeKey())
	{
		coreState.SetState(new main_menu());
	}

	if (this->gameControls->player1Controls->aKey())
	{
		this->gameInfo->removeRedChip();
	}
}
void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->board->getTexture());
	window->draw(*this->turnText);
	window->draw(*this->redChipsText);
	window->draw(*this->blackChipsText);
	this->board->renderBoard(window);
}
void main_game::Destroy(sf::RenderWindow* window)
{
	delete board;
}
