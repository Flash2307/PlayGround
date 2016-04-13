#pragma once
#include "Controls.h"
#include <SFML/Graphics.hpp>

class GamePadControls : public Controls
{
public:
	GamePadControls();
	~GamePadControls();

	void setUpKey(bool state);
	void setDownKey(bool state);
	void setLeftKey(bool state);
	void setRightKey(bool state);
	void setAKey(bool state);
	void setBKey(bool state);

	void startMonitor();
};

