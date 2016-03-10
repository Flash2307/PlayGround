#include "Game.h"

#include <iostream>
#include <memory>
#include <cmath>

Game::Game() :
	pCollisionGrid( std::make_shared< CollisionGrid >( SCREEN_WIDTH, SCREEN_HEIGHT, 100 ) )
{
	for (int i = 0; i < 4; i++)
	{
		lines[i] = std::make_unique< Line >( i * 100 + 10, i * 100 + 10, sf::Color::Red, pCollisionGrid );
	}
}

void Game::update()
{
	std::for_each( lines.begin(), lines.end(),
	[]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->update();
		}
	});
}

void Game::draw(sf::RenderWindow* window)
{
	std::for_each( lines.begin(), lines.end(),
	[ window ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->draw( window );
		}
	});
}
