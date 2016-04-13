#include "GamePadControls.h"
#include "SystemInput.h"

GamePadControls::GamePadControls()
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

GamePadControls::~GamePadControls()
{
}

void GamePadControls::setUpKey(bool state)
{
	this->upKeyLast = this->upKey_;
	this->upKey_ = state;
}

void GamePadControls::setDownKey(bool state)
{
	this->downKeyLast = this->downKey_;
	this->downKey_ = state;
}

void GamePadControls::setLeftKey(bool state)
{
	this->leftKeyLast = this->leftKey_;
	this->leftKey_ = state;
}

void GamePadControls::setRightKey(bool state)
{
	this->rightKeyLast = this->rightKey_;
	this->rightKey_ = state;
}

void GamePadControls::setAKey(bool state)
{
	this->aKeyLast = this->aKey_;
	this->aKey_ = state;
}

void GamePadControls::setBKey(bool state)
{
	this->bKeyLast = this->bKey_;
	this->bKey_ = state;
}

void GamePadControls::startMonitor()
{
	SystemInput sysInput(1, nullptr);
}