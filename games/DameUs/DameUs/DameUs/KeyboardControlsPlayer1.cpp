#include "KeyboardControlsPlayer1.h"

KeyboardControlsPlayer1::KeyboardControlsPlayer1()
{
	this->upKey_ = false;
	this->leftKey_ = false;
	this->rightKey_ = false;
	this->downKey_ = false;
	this->aKey_ = false;
	this->bKey_ = false;
	this->upKeyLast = false;
	this->leftKeyLast = false;
	this->rightKeyLast = false;
	this->downKeyLast = false;
	this->aKeyLast = false;
	this->bKeyLast = false;
}

KeyboardControlsPlayer1::~KeyboardControlsPlayer1()
{
}

void KeyboardControlsPlayer1::setUpKey(bool state)
{
	this->upKeyLast = this->upKey_;
	this->upKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
}

void KeyboardControlsPlayer1::setDownKey(bool state)
{
	this->downKeyLast = this->downKey_;
	this->downKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void KeyboardControlsPlayer1::setLeftKey(bool state)
{
	this->leftKeyLast = this->leftKey_;
	this->leftKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}

void KeyboardControlsPlayer1::setRightKey(bool state)
{
	this->rightKeyLast = this->rightKey_;
	this->rightKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void KeyboardControlsPlayer1::setAKey(bool state)
{
	this->aKeyLast = this->aKey_;
	this->aKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
}

void KeyboardControlsPlayer1::setBKey(bool state)
{
	this->bKeyLast = this->bKey_;
	this->bKey_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B);
}

void KeyboardControlsPlayer1::assignNewStates()
{
	while (true)
	{
		this->setAKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
		this->setBKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B));
		this->setUpKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
		this->setDownKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
		this->setLeftKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));
		this->setRightKey(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right));
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	
}

void KeyboardControlsPlayer1::startMonitor()
{
	this->controlsMonitor = std::thread(&KeyboardControlsPlayer1::assignNewStates, this);
}