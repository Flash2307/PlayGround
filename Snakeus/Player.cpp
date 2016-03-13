#include "Player.h"

Player::Player() :
	name(),
	index( 0 )
{

}

Player::Player( const std::string& name_, size_t index_ ) :
	name( name_ ),
	index( index_ ),
	pKeys( std::make_shared< KeyMap >() )
{

}

bool Player::isValid() const
{
	return name.empty() == false && pKeys != nullptr;
}

bool Player::isLeftKeyPress() const
{
	return this->pKeys->leftPressed;
}

void Player::setLeftKeyPressed( bool pressed_ )
{
	this->pKeys->leftPressed = pressed_;
}

bool Player::isRightKeyPress() const
{
	return this->pKeys->rightPressed;
}

void Player::setRightKeyPressed( bool pressed_ )
{
	this->pKeys->rightPressed = pressed_;
}
