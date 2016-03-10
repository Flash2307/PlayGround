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

Line::Line(int x, int y, sf::Color playerColor_, const SharedCollisionGridType& pCollisionGrid_ ) :
	pCollisionGrid( pCollisionGrid_ ),
	pNextPoint( std::make_unique< Circle >( x, y, CIRCLE_RAY ) ),
	holeCounter( 0 ),
	angle( 0 ),
	playerColor( playerColor_ ),
	inHole( false ),
	alive( true )
{

}

void Line::update()
{
	if( this->alive )
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			angle += TURN_SPEED;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
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

sf::Color Line::getPlayerColor() const
{
	return playerColor;
}

bool Line::isInHole()
{
	return inHole;
}

void Line::kill()
{
	alive = false;
}
