#pragma once


enum TurnStates
{
	ChangeTurn,
	ChooseChip,
	ChooseDestination
};


class TurnState
{
public:
	static TurnState* getInstance();
	TurnStates getState();
	void setState(TurnStates state);
	~TurnState();

private:
	static TurnState* instance;
	TurnStates currentState;
	TurnState();
};