#include "KeyboardControlsPlayer1.h"

KeyboardControlsPlayer1::KeyboardControlsPlayer1()
{
	lastUpKey = false;
	lastLeftKey = false;
	lastRightKey = false;
	lastDownKey = false;
	lastAKey = false;
	lastBKey = false;
	lastEnterKey = false;
	lastEscapeKey = false;
}

KeyboardControlsPlayer1::~KeyboardControlsPlayer1()
{
}

bool KeyboardControlsPlayer1::upKey()
{
	bool result = !this->lastUpKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->lastUpKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	return result;
}

bool KeyboardControlsPlayer1::leftKey()
{
	bool result = !this->lastLeftKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->lastLeftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	return result;
}

bool KeyboardControlsPlayer1::rightKey()
{
	bool result = !this->lastRightKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	this->lastRightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	return result;
}

bool KeyboardControlsPlayer1::downKey()
{
	bool result = !this->lastDownKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	this->lastDownKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	return result;
}

bool KeyboardControlsPlayer1::aKey()
{
	bool result = !this->lastAKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma);
	this->lastAKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma);
	return result;
}

bool KeyboardControlsPlayer1::bKey()
{
	bool result = !this->lastBKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period);
	this->lastBKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period);
	return result;
}

bool KeyboardControlsPlayer1::enterKey()
{
	bool result = !this->lastEnterKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
	this->lastEnterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
	return result;
}

bool KeyboardControlsPlayer1::escapeKey()
{
	bool result = !this->lastEscapeKey && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	this->lastEscapeKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	return result;
}