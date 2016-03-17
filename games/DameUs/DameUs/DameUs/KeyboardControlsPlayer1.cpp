#include "KeyboardControlsPlayer1.h"

KeyboardControlsPlayer1::KeyboardControlsPlayer1()
{
}

KeyboardControlsPlayer1::~KeyboardControlsPlayer1()
{
}

bool KeyboardControlsPlayer1::upKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
}

bool KeyboardControlsPlayer1::leftKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}

bool KeyboardControlsPlayer1::rightKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

bool KeyboardControlsPlayer1::downKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

bool KeyboardControlsPlayer1::aKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma);
}

bool KeyboardControlsPlayer1::bKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period);
}

bool KeyboardControlsPlayer1::enterKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

bool KeyboardControlsPlayer1::escapeKey()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
}