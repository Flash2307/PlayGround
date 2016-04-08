#include "main_game.h"
#include "main_menu.h"
#include "Chip.h"
#include "RedChipKing.h"
#include "BlackChipKing.h"
#include <string>
#include <sstream>

void main_game::Initialize(sf::RenderWindow* window)
{
	this->gameControls = GameControls::getInstance();
	this->gameInfo = GameInfo::getInstance();
	this->turnState = TurnState::getInstance();

	this->destinationIndex = 0;

	this->board = new Board();
	this->board->initializeBoard(window);
	this->board->setStartOfTurnHighlight();

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
	this->turnManager(window);
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
	this->gameInfo->resetCounters();
	delete board;
}


void main_game::turnManager(sf::RenderWindow* window)
{
	this->setTurnText();
	this->setChipsRemainingText();
	this->manageExit();

	switch (this->turnState->getState())
	{
	case ChangeTurn:
		this->manageChangeTurnState();
		break;
	case ChooseChip:
		this->manageChooseChipState();
		break;
	case ChooseDestination:
		this->manageChooseDestinationState();
		break;
	default:
		break;
	}
	
}

void main_game::setTurnText()
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
}

void main_game::setChipsRemainingText()
{
	std::stringstream stream;
	stream << "Red Chips Remaining: " << this->gameInfo->getRedChipsRemaining();

	this->redChipsText->setString(stream.str());
	stream.str(std::string());
	stream << "Black Chips Remaining: " << this->gameInfo->getBlackChipsRemaining();
	this->blackChipsText->setString(stream.str());
}

void main_game::manageExit()
{
	if (this->gameControls->player1Controls->escapeKey())
	{
		coreState.SetState(new main_menu());
	}
}

void main_game::manageChangeTurnState()
{
	this->gameInfo->changeTurn();
	this->gameInfo->hopping = false;
	this->board->removeAllHighlight();
	this->board->setStartOfTurnHighlight();
	TurnState::getInstance()->setState(ChooseChip);
}

void main_game::manageChooseChipState()
{
	switch (this->gameInfo->getTurn())
	{
	case Red:
		this->board->navigateRedChips();
		break;
	case Black:
		this->board->navigateBlackChips();
		break;
	default:
		break;
	}
	this->board->chooseChip(nullptr);
}

void main_game::manageChooseDestinationState()
{
	if (!this->gameInfo->hopping)
	{
		this->board->unChooseChips(nullptr, false);
	}
	
	auto selectedChip = this->board->getSelectedChip();

	if (selectedChip == nullptr)
	{
		this->board->removeAllHighlight();
		TurnState::getInstance()->setState(ChooseChip);
		return;
	}
	Move* positions[4] = { nullptr, nullptr, nullptr, nullptr };
	selectedChip->getPossibleDestinations(positions, this->board);
	this->manageDestinationHighlight(positions, selectedChip);
}

void main_game::manageDestinationHighlight(Move* positions[], Chip* selectedChip)
{
	bool allNull = true;
	for (int i = 0; i < 4; i++)
	{
		if (positions[i] != nullptr)
		{
			allNull = false;
		}
	}
	if (allNull)
	{
		this->board->unChooseChips(nullptr, true);
		TurnState::getInstance()->setState(ChooseChip);
		return;
	}
	int i = this->destinationIndex + 1;
	if (i >= 4)
	{
		i = 0;
	}
	auto coordinates = selectedChip->getCoordinates();
	this->board->setHighlight(coordinates->y, coordinates->x);

	if (positions[this->destinationIndex] == nullptr)
	{
		int k = 0;
		for (;  k < 4; i = (i + 1) % 4)
		{
			k++;
			if (positions[i] != nullptr)
			{
				this->destinationIndex = i;
				break;
			}
		}
	}
	

	this->board->setHighlight(positions[destinationIndex]->newCoordinates->y, positions[destinationIndex]->newCoordinates->x );

	Controls* controls;
	switch (this->gameInfo->getTurn())
	{
	case Red:
		controls = this->gameControls->player1Controls;
		break;
	case Black:
		controls = this->gameControls->player2Controls;
		break;
	default:
		controls = this->gameControls->player1Controls;
		break;
	}

	if (controls->rightKey())
	{
		int i = this->destinationIndex + 1;
		if (i >= 4)
		{
			i = 0;
		}
		int k = 0;
		for (; k < 4; i = (i + 1) % 4)
		{
			k++;
			if (positions[i] != nullptr)
			{
				this->board->removeHighlight(positions[this->destinationIndex]->newCoordinates->y, positions[this->destinationIndex]->newCoordinates->x);
				this->destinationIndex = i;
				break;
			}
		}
	}


	else if (controls->leftKey())
	{
		int i = this->destinationIndex - 1;
		if (i < 0)
		{
			i = 3;
		}
		int k = 0;
		for (; k < 4; )
		{
			k++;
			if (positions[i] != nullptr)
			{
				this->board->removeHighlight(positions[this->destinationIndex]->newCoordinates->y, positions[this->destinationIndex]->newCoordinates->x);
				this->destinationIndex = i;
				break;
			}
			i = i - 1;
			if (i == -1)
			{
				i = 3;
			}
		}
	}
	else if (controls->aKey())
	{
		auto coordinates = selectedChip->getCoordinates();
		auto chipType = selectedChip->getChipType();
		selectedChip->unSelect();
		this->board->removeChip(coordinates->y, coordinates->x);
		Chip* chip;
		Move* chosenMove = positions[this->destinationIndex];
		switch (gameInfo->getTurn())
		{
		case Red:
			if (chosenMove->newCoordinates->y == 7 || chipType == King)
			{
				chip = new RedChipKing();
			}
			else
			{
				chip = new RedChip();
			}

			this->board->addRedChip(chosenMove->newCoordinates->y, chosenMove->newCoordinates->x, chip);
			if (chosenMove->chipDefeated != nullptr)
			{
				this->gameInfo->removeBlackChip();
				this->board->removeChip(chosenMove->chipDefeated->getCoordinates()->y, chosenMove->chipDefeated->getCoordinates()->x);

				if (this->gameInfo->getBlackChipsRemaining() == 0)
				{
					coreState.SetState(new main_menu());
				}

				Move* newPositions[4] = { nullptr, nullptr, nullptr, nullptr };
				chip->getPossibleDestinations(newPositions, this->board);
				for (int i = 0; i < 4; i++)
				{
					if (newPositions[i] != nullptr && newPositions[i]->chipDefeated != nullptr)
					{
						chip->select();
						this->gameInfo->setCurrentCoordinates(chip->getCoordinates()->y, chip->getCoordinates()->x);
						this->gameInfo->hopping = true;
						return;
					}
				}
			}
			break;
		case Black:
			if (chosenMove->newCoordinates->y == 0 || chipType == King)
			{
				chip = new BlackChipKing();
			}
			else
			{
				chip = new BlackChip();
			}
			
			this->board->addBlackChip(chosenMove->newCoordinates->y, chosenMove->newCoordinates->x, chip);

			if (chosenMove->chipDefeated != nullptr)
			{
				this->gameInfo->removeRedChip();
				this->board->removeChip(chosenMove->chipDefeated->getCoordinates()->y, chosenMove->chipDefeated->getCoordinates()->x);
				if (this->gameInfo->getRedChipsRemaining() == 0)
				{
					coreState.SetState(new main_menu());
				}
				Move* newPositions[4] = { nullptr, nullptr, nullptr, nullptr };
				chip->getPossibleDestinations(newPositions, this->board);
				for (int i = 0; i < 4; i++)
				{
					if (newPositions[i] != nullptr && newPositions[i]->chipDefeated != nullptr)
					{
						chip->select();
						this->gameInfo->setCurrentCoordinates(chip->getCoordinates()->y, chip->getCoordinates()->x);
						this->gameInfo->hopping = true;
						return;
					}
				}
			}
			break;
		default:
			break;
		}



		

		TurnState::getInstance()->setState(ChangeTurn);

	}

}



