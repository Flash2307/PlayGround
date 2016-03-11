#include "Game.h"

#include <iostream>
#include <memory>
#include <cmath>
#include <sstream>

namespace Color
{

static const sf::Color Yellow( 255, 255, 0 );

}

static void renderStatBoard( sf::RenderWindow* pWindow_ )
{
	sf::RectangleShape rectangle;
	rectangle.setPosition(sf::Vector2f(WORLD_WIDTH, 0));
	rectangle.setSize(sf::Vector2f(5, SCREEN_HEIGHT ));
	rectangle.setFillColor( Color::Yellow );
	pWindow_->draw( rectangle );
}

Game::Game() :
	pCollisionGrid( std::make_shared< CollisionGrid >( WORLD_WIDTH, SCREEN_HEIGHT, 100 ) ),
	hasPlayerAlive( false )
{
	if (!font.loadFromFile("Alef-Regular.ttf"))
	{
		std::cerr << "Impossible de chargé les polices de caractères...\n";
		abort();
	}

	PlayerArrayType players = this->systemCom.getPlayers();

	std::for_each( players.begin(), players.end(),
	[ this ]( const Player& player_ )
	{
		if( player_.isValid() )
			this->lines[ player_.index ] = std::make_unique< Line >( player_.index * 100 + 10, player_.index * 100 + 10, player_, this->pCollisionGrid );
	});
}

void Game::update()
{
	this->hasPlayerAlive = false;

	std::for_each( lines.begin(), lines.end(),
	[ this ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->update();
			this->hasPlayerAlive = hasPlayerAlive || pLine_->isAlive();
		}
	});
}

void Game::renderLineStat( sf::RenderWindow* pWindow_, Line& line_ )
{
	const Player& player = line_.getPlayer();
	std::stringstream strStream;

	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Red);

	strStream.str( std::string() );
	strStream << "Player " << player.index << ( line_.isAlive() ? " alive" : " dead" );
	text.setPosition(sf::Vector2f(WORLD_WIDTH + 15,  150 * player.index ));
	text.setString( strStream.str() );
	pWindow_->draw(text);

	text.setPosition(sf::Vector2f(WORLD_WIDTH + 15,  150 * player.index + 40 ));
	text.setString( player.name );
	pWindow_->draw(text);

	strStream.str( std::string() );
	strStream << "Score: " << line_.getPointCount();
	text.setPosition(sf::Vector2f(WORLD_WIDTH + 15,  150 * player.index + 2 * 40 ));
	text.setString( strStream.str() );
	pWindow_->draw(text);
}

void Game::draw(sf::RenderWindow* pWindow_)
{
	renderStatBoard( pWindow_ );

	std::for_each( lines.begin(), lines.end(),
	[ this, pWindow_ ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->draw( pWindow_ );
			this->renderLineStat( pWindow_, *pLine_ );
		}
	});
}
