#include "Board.h"
#include "BlackChip.h"
#include "RedChip.h"
#include "TurnState.h"
#include <iostream>

Board::Board()
{
	this->texture = new Entity();
	this->load();
}

Board::~Board()
{
	delete this->texture;
}

void Board::initializeBoard(sf::RenderWindow* window)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			this->highlights[j][i] = nullptr;
			if ((j + i) % 2 == 1)
			{
				if (j < 3)
				{
					this->redChips[j][i] = new RedChip();
					this->blackChips[j][i] = nullptr;
				}

				else if (j >= 5)
				{
					this->blackChips[j][i] = new BlackChip();
					this->redChips[j][i] = nullptr;
				}
				else
				{
					this->blackChips[j][i] = nullptr;
					this->redChips[j][i] = nullptr;
				}
			}
		}
	}
}

Entity* Board::getTexture()
{
	return this->texture;
}

void Board::load()
{
	this->texture->Load("board.png");
}

void Board::renderBoard(sf::RenderWindow* window)
{

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			int offset = j % 2;
			if ((j + i + 1) % 2 == 0)
			{
				if (this->redChips[j][i] != nullptr)
				{
					this->redChips[j][i]->setCoordinates(i, j, window);
					window->draw(*this->redChips[j][i]->getTexture());
				}

				if (this->blackChips[j][i] != nullptr)
				{
					this->blackChips[j][i]->setCoordinates(i, j, window);
					window->draw(*this->blackChips[j][i]->getTexture());
				}

				if (this->highlights[j][i] != NULL
					)
				{
					this->highlights[j][i]->setCoordinates(i, j, window);
					window->draw(*this->highlights[j][i]->getTexture());
				}
			}
		}
	}
}

void Board::setStartOfTurnHighlight()
{
	bool breakFlag = false;
	auto gameInfo = GameInfo::getInstance();
	switch (gameInfo->getTurn())
	{
	case Red:
		for (int j = 0; j < 8 && !breakFlag; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (redChips[j][i] != nullptr)
				{
					highlights[j][i] = new Highlight();
					breakFlag = true;
					gameInfo->setCurrentCoordinates(j, i);
					break;
				}
			}
		}
		break;
	case Black:
		for (int j = 7; j >= 0 && !breakFlag; j--)
		{
			for (int i = 0; i < 8; i++)
			{
				if (blackChips[j][i] != nullptr)
				{
					highlights[j][i] = new Highlight();
					breakFlag = true;
					gameInfo->setCurrentCoordinates(j, i);
					break;
				}
			}
		}
		break;
	default:
		break;
	}

	this->removeAllHighlight();
}

void Board::removeHighlight(int j, int i)
{
	auto coordinates = GameInfo::getInstance()->getCurrentCoodinates();
	if (highlights[j][i] != nullptr && coordinates->x != i && coordinates->y != j)
	{
		delete highlights[j][i];
		highlights[j][i] = nullptr;
	}
}

void Board::removeChip(int j, int i)
{
	if (this->hasBlackChip(j, i))
	{
		delete this->blackChips[j][i];
		this->blackChips[j][i] = nullptr;
		return;
	}

	if (this->hasRedChip(j, i))
	{
		delete this->redChips[j][i];
		this->redChips[j][i] = nullptr;
		return;
	}

}

void Board::addRedChip(int j, int i, Chip* chip)
{
	if (this->redChips[j][i] == nullptr)
	{
		this->redChips[j][i] = chip;
		chip->setCoordinates(i, j);
	}
}

void Board::addBlackChip(int j, int i, Chip* chip)
{
	if (this->blackChips[j][i] == nullptr)
	{
		this->blackChips[j][i] = chip;
		chip->setCoordinates(i, j);
	}
}

void Board::removeAllHighlight()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			this->removeHighlight(j, i);
		}
	}
}

void Board::navigateChips(Chip* chips[][8])
{
	GameControls* controls = GameControls::getInstance();
	auto gameInfo = GameInfo::getInstance();
	auto position = gameInfo->getCurrentCoodinates();

	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	int i = position->x;
	int j = position->y;

	if (controls->upKey())
	{
		for (int y = j - 1; y >= 0 && !upFlag; y--)
		{
			for (int x = j; x < 8; x++)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					upFlag = true;
					break;
				}
			}
			for (int x = j; x >= 0 ; x--)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					upFlag = true;
					break;
				}
			}
		}

		for (int y = 7; y > j && !upFlag; y--)
		{
			for (int x = j; x < 8; x++)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					upFlag = true;
					break;
				}
			}
			for (int x = j; x >= 0; x--)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					upFlag = true;
					break;
				}
			}
		}
	}

	if (controls->downKey())
	{
		for (int y = j + 1; y < 8 && !downFlag; y++)
		{
			for (int x = j; x < 8; x++)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					downFlag = true;
					break;
				}
			}
		}
		for (int y = 0; y < j && !downFlag; y++)
		{
			for (int x = j; x < 8; x++)
			{
				if (chips[y][x] != nullptr)
				{
					this->removePreviousHighlight();
					gameInfo->setCurrentCoordinates(y, x);
					highlights[y][x] = new Highlight();
					downFlag = true;
					break;
				}
			}
		}
	}

	if (controls->leftKey())
	{
		int x = i - 1;
		for (; x >= 0 && !leftFlag; x--)
		{
			if (chips[j][x] != nullptr)
			{
				this->removePreviousHighlight();
				gameInfo->setCurrentCoordinates(j, x);
				highlights[j][x] = new Highlight();
				leftFlag = true;
				break;
			}
		}
		for (x = 7; x > i && !leftFlag; x--)
		{
			if (chips[j][x] != nullptr)
			{
				this->removePreviousHighlight();
				gameInfo->setCurrentCoordinates(j, x);
				highlights[j][x] = new Highlight();
				leftFlag = true;
				break;
			}
		}
	}

	if (controls->rightKey())
	{
		int x = i + 1;
		for (; x < 8 && !rightFlag; x++)
		{
			if (chips[j][x] != nullptr)
			{
				this->removePreviousHighlight();
				gameInfo->setCurrentCoordinates(j, x);
				highlights[j][x] = new Highlight();
				rightFlag = true;
				break;
			}
		}
		x = 0;
		for (; x <= i && !rightFlag; x++)
		{
			if (chips[j][x] != nullptr)
			{
				this->removePreviousHighlight();
				gameInfo->setCurrentCoordinates(j, x);
				highlights[j][x] = new Highlight();
				rightFlag = true;
				break;
			}
		}
	}
}

void Board::navigateRedChips()
{
	this->navigateChips(this->redChips);
}

void Board::navigateBlackChips()
{
	this->navigateChips(this->blackChips);
}

void Board::removePreviousHighlight()
{
	auto gameInfo = GameInfo::getInstance();
	auto highlight = gameInfo->getCurrentCoodinates();
	int x = highlight->x;
	int y = highlight->y;
	if (highlights[y][x] != nullptr)
	{
		delete highlights[y][x];
		highlights[y][x] = nullptr;
	}
}

void Board::setHighlight(int j, int i)
{
	if (highlights[j][i] == nullptr)
	{
		highlights[j][i] = new Highlight();
	}
}

Chip* Board::getRedChip(int j, int i)
{
	return this->redChips[j][i];
}

Chip* Board::getBlackChip(int j, int i)
{
	return this->blackChips[j][i];
}

void Board::chooseChip(Chip* chips[][8])
{
	auto gameInfo = GameInfo::getInstance();
	auto currentPosition = gameInfo->getCurrentCoodinates();

	auto gameControls = GameControls::getInstance();

	if (!gameControls->aKey())
	{
		return;
	}
	

	int x = currentPosition->x;
	int y = currentPosition->y;
	
	if (chips != nullptr && chips[y][x] != nullptr)
	{
		chips[y][x]->select();
	}

	TurnState::getInstance()->setState(ChooseDestination);
}

void Board::unChooseChips(Chip* chips[][8], bool forceUnselection)
{
	auto gameInfo = GameInfo::getInstance();
	auto gameControls = GameControls::getInstance();

	GameControls* controls = GameControls::getInstance();

	if (!controls->bKey() && !forceUnselection)
	{
		return;
	}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (chips[j][i] != nullptr && chips[j][i]->isSelected() == true)
			{
				chips[j][i]->unSelect();
			}
		}
	}
	TurnState::getInstance()->setState(ChooseChip);
}

bool Board::hasNothing(int j, int i)
{
	if (this->hasBlackChip(j, i) || this->hasRedChip(j, i))
	{
		return false;
	}
	return true;
}

bool Board::hasRedChip(int j, int i)
{
	if (this->redChips[j][i] != nullptr)
	{
		return true;
	}
	return false;
}

bool Board::hasBlackChip(int j, int i)
{
	if (this->blackChips[j][i] != nullptr)
	{
		return true;
	}
	return false;
}

bool Board::coordinatesExist(int j, int i)
{
	bool leftCondition = i < 0;
	bool rightCondition = i >= 8;
	bool upCondition = j < 0;
	bool bottomCondition = j >= 8;

	if (leftCondition || rightCondition || upCondition || bottomCondition)
	{
		return false;
	}
	return true;

}

Chip* Board::getSelectedChip()
{
	Chip* chip;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			switch (GameInfo::getInstance()->getTurn())
			{
			case Red:
				chip = this->redChips[j][i];
				if (chip == nullptr)
				{
					break;
				}
				if (chip->isSelected())
				{
					return chip;
				}
				break;
			case Black:
				chip = this->blackChips[j][i];
				if (chip == nullptr)
				{
					break;
				}
				if (chip->isSelected())
				{
					return chip;
				}
				break;
			default:
				break;
			}
		}
	}
	return nullptr;
}


