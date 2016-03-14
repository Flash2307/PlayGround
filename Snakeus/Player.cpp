#include "Player.h"

Player::Player() :
	name(),
	index( 0 )
{

}

Player::Player( const std::string& name_, size_t index_, const sf::Vector2i& spawnPos_ ) :
	pKeys( std::make_shared< KeyMap >() ),
	name( name_ ),
	index( index_ ),
	spawnPos( spawnPos_ )
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

bool Player::isAKeyPressed() const
{
	return this->pKeys->aPressed;
}

void Player::setAKeyPressed( bool pressed_ )
{
	this->pKeys->aPressed = pressed_;
}

bool Player::isBKeyPressed() const
{
	return this->pKeys->bPressed;
}

void Player::setBKeyPressed( bool pressed_ )
{
	this->pKeys->bPressed = pressed_;
}

void Player::setSpawnPos( const sf::Vector2i& spawnPos_ )
{
	this->spawnPos = spawnPos_;
}

int Player::spawnX() const
{
	return this->spawnPos.x;
}

int Player::spawnY() const
{
	return this->spawnPos.y;
}

