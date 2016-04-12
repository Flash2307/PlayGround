#pragma once
#include "Controls.h"
#include <SFML/Graphics.hpp>

class KeyboardControlsPlayer1 : public Controls
{
public:
	KeyboardControlsPlayer1();
	~KeyboardControlsPlayer1();

	bool upKey();
	bool leftKey();
	bool rightKey();
	bool downKey();
	bool aKey();
	bool bKey();
	bool enterKey();
	bool escapeKey();
	bool lastUpKey;
	bool lastLeftKey;
	bool lastRightKey;
	bool lastDownKey;
	bool lastAKey;
	bool lastBKey;
	bool lastEnterKey;
	bool lastEscapeKey;

private:

};

