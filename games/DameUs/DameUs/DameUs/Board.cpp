#include "Board.h"

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
			this->highlights[j][i] = NULL;
			if ((j + i) % 2 == 1)
			{
				if (j < 3)
				{
					this->redChips[j][i] = new RedChip();
					this->blackChips[j][i] = NULL;
				}

				else if (j >= 5)
				{
					this->blackChips[j][i] = new BlackChip();
					this->redChips[j][i] = NULL;
				}
				else
				{
					this->blackChips[j][i] = NULL;
					this->redChips[j][i] = NULL;
				}
			}
		}
	}
}

void Board::initializeHighlight(Turn turn)
{
	switch (turn)
	{
	case Red:
		highlights[0][1] = new Highlight();
		break;
	case Black:
		highlights[7][0] = new Highlight();
		break;
	default:
		break;
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
				if (this->redChips[j][i] != NULL)
				{
					this->redChips[j][i]->setCoordinates(i, j, window);
					window->draw(*this->redChips[j][i]->getTexture());
				}

				if (this->blackChips[j][i] != NULL)
				{
					this->blackChips[j][i]->setCoordinates(i, j, window);
					window->draw(*this->blackChips[j][i]->getTexture());
				}

				if (this->highlights[j][i] != NULL)
				{
					this->highlights[j][i]->setCoordinates(i, j, window);
					window->draw(*this->highlights[j][i]->getTexture());
				}
			}
		}
	}
}