#pragma once
#include "Controls.h"
#include <SFML/Graphics.hpp>

class KeyboardControlsPlayer1 : public Controls
{
public:
	KeyboardControlsPlayer1();
	~KeyboardControlsPlayer1();

	void setUpKey(bool state);
	void setDownKey(bool state);
	void setLeftKey(bool state);
	void setRightKey(bool state);
	void setAKey(bool state);
	void setBKey(bool state);

	void startMonitor();
private:
	void assignNewStates();

};

