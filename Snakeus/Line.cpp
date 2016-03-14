#include "Line.h"

#include <iostream>
#include <cmath>
#include <cassert>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define SPEED 2.5f
#define TURN_SPEED 0.07f

#define HOLE_FREQUENCY 100
#define HOLE_LENGTH 10
#define CIRCLE_RAY 3

static sf::Color getUserColor( size_t index_ )
{
	switch( index_ )
	{
	case 0:
		return sf::Color::Red;
		break;
	case 1:
		return sf::Color::Blue;
		break;
	case 2:
		return sf::Color::Green;
		break;
	case 3:
		return sf::Color::Cyan;
		break;
	}

	return sf::Color::Red;
}

Line::Line( const Player& player_, const SharedCollisionGridType& pCollisionGrid_ ) :
	pCollisionGrid( pCollisionGrid_ ),
	pNextPoint( std::make_unique< Circle >( player_.spawnX(), player_.spawnY(), CIRCLE_RAY ) ),
	player( player_ ),
	holeCounter( 0 ),
	angle( 0 ),
	playerColor( getUserColor( player_.index ) ),
	inHole( false ),
	alive( true )
{

}

void Line::reset()
{
	this->pNextPoint = std::make_unique< Circle >( player.spawnX(), player.spawnY(), CIRCLE_RAY );
	this->holeCounter = 0;
	this->angle = 0;
	this->inHole = false;
	this->alive = true;
}

void Line::update()
{
	if( this->alive )
	{
		if( this->player.isRightKeyPress() )
		{
			angle += TURN_SPEED;
		}
		else if( this->player.isLeftKeyPress() )
		{
			angle -= TURN_SPEED;
		}

		pNextPoint->posX += SPEED * cos(angle);
		pNextPoint->posY += SPEED * sin(angle);

		if( holeCounter < HOLE_FREQUENCY )
		{
			assert( pCollisionGrid != nullptr );

			if( pCollisionGrid->isOutOfGrid( *pNextPoint ) )
			{
				this->kill();
			}
			else
			{
				detectCollision();
				pNextPoint = pCollisionGrid->append( std::move( pNextPoint ) );
			}

			inHole = false;
		}
		else if( holeCounter >= HOLE_FREQUENCY + HOLE_LENGTH )
		{
			holeCounter = 0;
		}
		else
		{
			inHole = true;
		}

		holeCounter++;
	}
}

void Line::detectCollision()
{
	CirclePtrArrayType collisions;
	pCollisionGrid->collide( *pNextPoint, collisions );

	std::for_each( collisions.begin(), collisions.end(),
	[ this ]( const Circle* pCircle_ )
	{
		assert( pCircle_ != nullptr );

		if( pCircle_ != this->pNextPoint->pNext )
		{
			Circle* pNext = pNextPoint->pNext;

			while( pNext != nullptr &&
				   pNext != pCircle_ &&
				   distance( *pNext, *pCircle_ ) <= squareRadius( *pNext, *pCircle_ )
			)
			{
				pNext = pNext->pNext;
			}

			if( pNext != pCircle_ )
				this->kill();
		}
	});
}

void Line::draw( sf::RenderWindow* window )
{
	sf::CircleShape shape(3.f);
	shape.setFillColor( playerColor );

	assert( pNextPoint != nullptr );
	Circle* pNext = pNextPoint->pNext;

	while( pNext != nullptr )
	{
		shape.setPosition( pNext->posX, pNext->posY );
		window->draw( shape );
		pNext = pNext->pNext;
	}

	if( inHole )
	{
		shape.setPosition( pNextPoint->posX, pNextPoint->posY );
		window->draw( shape );
	}
}

double Line::getX() const
{
	return pNextPoint->posX;
}

double Line::getY() const
{
	return pNextPoint->posY;
}

double Line::getAngle() const
{
	return angle;
}

size_t Line::getPointCount() const
{
	Circle* pNext = pNextPoint->pNext;
	size_t pointCount = 1;

	while( pNext != nullptr )
	{
		++pointCount;
		pNext = pNext->pNext;
	}

	return pointCount;
}

sf::Color Line::getPlayerColor() const
{
	return playerColor;
}

const Player& Line::getPlayer() const
{
	return this->player;
}

bool Line::isAlive() const
{
	return this->alive;
}

bool Line::isInHole()
{
	return inHole;
}

void Line::kill()
{
	alive = false;
}
