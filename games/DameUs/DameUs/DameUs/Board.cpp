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

void Board::initializeBoard()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			int offset = (j + 1) % 2;
			if ((offset + i) % 2 == 1)
			{
				if (j < 3)
				{
					chips[j][i] = new RedChip();
				}
				if (j <= 6)
				{
					chips[j][i] = new BlackChip();
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