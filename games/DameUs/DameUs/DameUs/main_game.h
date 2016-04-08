#pragma once

#include "game_state.h"
#include "GameControls.h"
#include "Board.h"
#include "Highlight.h"
#include "GameInfo.h"

class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	GameControls* gameControls;
	GameInfo* gameInfo;
	Board* board;
	sf::Font* font;
	sf::Text* turnText;
	sf::Text* blackChipsText;
	sf::Text* redChipsText;

};