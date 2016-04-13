#include <iostream>
#include "main_menu.h"
#include "main_game.h"

void main_menu::Initialize(sf::RenderWindow* window)
{
	this->gameControls = GameControls::getInstance();
	this->selected = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("font/font.ttf");

	this->title = new sf::Text("DameUs", *this->font, 256U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

	this->play = new sf::Text("2 Joueurs", *this->font, 128U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->quit = new sf::Text("Quitter", *this->font, 128U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play->getGlobalBounds().height);
}
void main_menu::Update(sf::RenderWindow* window)
{
	if (this->gameControls->player1Controls->upKey())
	{
		this->selected -= 1;
	}
	if (this->gameControls->player1Controls->downKey())
	{
		this->selected += 1;
	}
	if (this->selected > 1)
	{
		this->selected = 0;
	}
	if (this->selected < 0)
	{
		this->selected = 1;
	}

	if (this->gameControls->player1Controls->aKey())
	{
		switch (this->selected)
		{
		case 0:
			coreState.SetState(new main_game());
			break;
		case 1:
			quitGame = true;
			break;
		}
	}
	this->upKey = this->gameControls->player1Controls->upKey();
	this->downKey = this->gameControls->player1Controls->downKey();
}
void main_menu::Render(sf::RenderWindow* window)
{
	this->play->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	switch (this->selected)
	{
	case 0:
		this->play->setColor(sf::Color::Green);
		break;
	case 1:
		this->quit->setColor(sf::Color::Green);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{/*
 	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
 */

}
