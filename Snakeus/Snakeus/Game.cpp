#include "Game.h"

#include <iostream>
#include <memory>
#include <cmath>
#include <sstream>

namespace Color
{

static const sf::Color Yellow( 255, 255, 0 );

}

static const size_t FONT_SIZE = 30;
static const size_t PADDING_SIZE = 10;

Game::Game( int argc_, char** argv_, const sf::VideoMode& desktop_ ) :
	desktop(desktop_ ),
	systemCom( argc_, argv_ ),
	pCollisionGrid( std::make_shared< CollisionGrid >( worldWidth(), screenHeight(), GRID_SCALE ) ),
	hasPlayerAlive( true ),
	quit( false ),
	scoreSended( false ),
	clearScreen( true )
{

	this->initRessources();
	this->initPlayers();
}

void Game::initRessources()
{
	if( !font.loadFromFile( "font/Alef-Regular.ttf" ) )
	{
		std::cerr << "Impossible de chargé les polices de caractères...\n";
		abort();
	}
}

void Game::initPlayers()
{
	PlayerArrayType players = this->systemCom.getPlayers();

	std::for_each( players.begin(), players.end(),
	[ this ]( Player& player_ )
	{
		if( player_.isValid() )
		{
			size_t index = player_.getIndex();
			player_.setSpawnPos( sf::Vector2i( index * 100 + 10, index * 100 + 10 ) );
			this->lines[ index ] = std::make_unique< Line >( player_, this->pCollisionGrid );
		}
	});
}

void Game::update()
{
	if( this->hasPlayerAlive )
	{
		this->updateLinesPosition();
	}
	else
	{
		this->checkEndgameAction();
	}
}

void Game::updateLinesPosition()
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

void Game::checkEndgameAction()
{
	std::for_each( lines.begin(), lines.end(),
	[ this ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			if( pLine_->getPlayer().isAKeyPressed() )
			{
				sendStatictics();
				this->reset();
			}
			else if( pLine_->getPlayer().isBKeyPressed() )
			{
				this->quit = true;
				sendStatictics();
			}
		}
	});
}

void Game::resetAllLines()
{
	std::for_each( this->lines.begin(), this->lines.end(),
	[ this ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->reset();
		}
	});
}

void Game::reset()
{
	this->scoreSended = false;
	this->hasPlayerAlive = true;
	this->pCollisionGrid->clear();
	this->resetAllLines();
	this->clearScreen = true;
}

void Game::sendStatictics()
{
	if( !this->scoreSended )
	{
		this->scoreSended = true;

		std::for_each( lines.begin(), lines.end(),
		[]( LinePtrType& pLine_ )
		{
			if( pLine_ != nullptr )
			{
				const Player& player = pLine_->getPlayer();
				std::cout << "Score " << player.getIndex() << " " << player.getScore() << ' ';
			}
		});
	}
}

void Game::draw(sf::RenderWindow* pWindow_)
{
	if(clearScreen)
	{
		pWindow_->clear();
		pWindow_->display();
		pWindow_->clear();
		this->renderStatBoard(pWindow_);

		std::for_each(lines.begin(), lines.end(),
			[this, pWindow_](LinePtrType& pLine_)
		{
			if (pLine_ != nullptr)
			{
				this->renderLineStat(pWindow_, *pLine_);
			}
		});

		clearScreen = false;
	}
	if( this->hasPlayerAlive )
	{
		this->renderLines( pWindow_ );
	}
	else if( !this->quit )
	{
		this->renderEndGameMessages( pWindow_ );
	}
	else
	{
		pWindow_->close();
	}
}

void Game::renderStatBoard(sf::RenderWindow* pWindow_)
{
	sf::RectangleShape rectangle;
	rectangle.setPosition(sf::Vector2f(worldWidth(), 0));
	rectangle.setSize(sf::Vector2f(5, screenHeight()));
	rectangle.setFillColor(Color::Yellow);
	pWindow_->draw(rectangle);
}

void Game::renderLines( sf::RenderWindow* pWindow_ )
{
	std::for_each( lines.begin(), lines.end(),
	[ this, pWindow_ ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			pLine_->draw( pWindow_ );
			if (!pLine_->isScoreUpdated())
			{
				this->renderLineStat(pWindow_, *pLine_);
			}
		}
	});
}

void Game::renderEndGameMessages( sf::RenderWindow* pWindow_ )
{
	renderStatBoard(pWindow_);
	std::for_each( this->lines.begin(), this->lines.end(),
	[ this, pWindow_ ]( LinePtrType& pLine_ )
	{
		if( pLine_ != nullptr )
		{
			this->renderLineStat( pWindow_, *pLine_ );
		}
	});

	sf::Text text;
	text.setCharacterSize( FONT_SIZE );
	text.setFont(font);
	text.setColor(sf::Color::Red);

	text.setString( "Appuyer sur 'a' pour refaire une partie." );
	text.setPosition( sf::Vector2f( worldWidth() / 2 - text.getLocalBounds().width / 2, screenHeight() / 2 ) );
	pWindow_->draw(text);

	text.setString( "Appuyer sur 'b' pour quitter." );
	text.setPosition( sf::Vector2f( worldWidth() / 2 - text.getLocalBounds().width / 2, screenHeight() / 2 + text.getLocalBounds().height + PADDING_SIZE ) );
	pWindow_->draw(text);
}

void Game::renderLineStat( sf::RenderWindow* pWindow_, Line& line_ )
{
	const Player& player = line_.getPlayer();
	size_t playerIndex = player.getIndex();
	std::stringstream strStream;

	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(worldWidth() + PADDING_SIZE, 200 * playerIndex);
	rectangle.setSize(sf::Vector2f(300, 200));
	pWindow_->draw(rectangle);

	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Red);

	strStream.str( std::string() );
	strStream << "Player " << playerIndex + 1;
	text.setPosition(sf::Vector2f(worldWidth() + PADDING_SIZE, 200 * playerIndex));
	text.setString( strStream.str() );
	pWindow_->draw(text);

	text.setPosition(sf::Vector2f(worldWidth() + PADDING_SIZE, 200 * playerIndex + PADDING_SIZE + text.getLocalBounds().height ) );
	text.setString( player.getName());
	pWindow_->draw(text);

	text.setPosition(sf::Vector2f(worldWidth() + PADDING_SIZE, 200 * playerIndex + 2*(PADDING_SIZE + text.getLocalBounds().height)));
	text.setString(line_.isAlive() ? "Alive" : "Dead");
	pWindow_->draw(text);

	strStream.str( std::string() );
	strStream << "Score: " << line_.getPlayer().getScore();
	text.setPosition(sf::Vector2f(worldWidth() + PADDING_SIZE, 200 * playerIndex + 3 * (PADDING_SIZE + text.getLocalBounds().height)));
	text.setString( strStream.str() );
	pWindow_->draw(text);
}

