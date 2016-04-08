#include "TurnState.h"

TurnState* TurnState::instance = nullptr;
TurnState::TurnState()
{
	this->currentState = ChooseChip;
}

TurnState::~TurnState()
{
	delete this->instance;
}

TurnStates TurnState::getState()
{
	return this->currentState;
}

TurnState* TurnState::getInstance()
{
	if (TurnState::instance == nullptr)
	{
		instance = new TurnState();
	}
	return instance;
}

void TurnState::setState(TurnStates state)
{
	this->currentState = state;
}