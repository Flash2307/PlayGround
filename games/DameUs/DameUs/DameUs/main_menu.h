#pragma once

#include <memory>

#include "game_state.h"
#include "GameControls.h"

class main_menu : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	std::unique_ptr< sf::Font > font;
	std::unique_ptr< sf::Text > title;
	std::unique_ptr< sf::Text > play;
	std::unique_ptr< sf::Text > quit;

	GameControls* gameControls;
	int selected;

	bool upKey, downKey;
};