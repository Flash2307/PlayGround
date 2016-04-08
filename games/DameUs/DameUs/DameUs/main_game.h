#pragma once

#include "game_state.h"
#include "GameControls.h"
#include "Board.h"
#include "Highlight.h"
#include "GameInfo.h"
#include "TurnState.h"
#include "Move.h"

class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void turnManager(sf::RenderWindow* window);
	void setTurnText();
	void setChipsRemainingText();
	void manageExit();
	void manageChangeTurnState();
	void manageChooseChipState();
	void manageChooseDestinationState();
	void manageDestinationHighlight(Move* [], Chip*);

private:
	GameControls* gameControls;
	TurnState* turnState;
	GameInfo* gameInfo;
	Board* board;
	sf::Font* font;
	sf::Text* turnText;
	sf::Text* blackChipsText;
	sf::Text* redChipsText;
	int destinationIndex;

};