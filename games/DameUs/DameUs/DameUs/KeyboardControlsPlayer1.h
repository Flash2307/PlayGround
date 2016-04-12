#pragma once
#include "Controls.h"
#include <SFML/Graphics.hpp>

class KeyboardControlsPlayer1 : public Controls
{
public:
	KeyboardControlsPlayer1();
	~KeyboardControlsPlayer1();

	bool upKey()
	{
		if (this->upKey_ && !this->upKeyLast)
		{
			return true;
		}
		return false;
	}
	bool leftKey()
	{
		if (this->leftKey_ && !this->leftKeyLast)
		{
			return true;
		}
		return false;
	}
	bool rightKey()
	{
		if (this->rightKey_ && !this->rightKeyLast)
		{
			return true;
		}
		return false;
	}
	bool downKey()
	{
		if (this->downKey_ && !this->downKeyLast)
		{
			return true;
		}
		return false;
	}
	bool aKey()
	{
		if (this->aKey_ && !this->aKeyLast)
		{
			return true;
		}
		return false;
	}
	bool bKey()
	{
		if (this->bKey_ && !this->bKeyLast)
		{
			return true;
		}
		return false;
	}
	bool escapeKey()
	{
		if (this->aKey_ && !this->aKeyLast && this->bKey_ && !this->bKeyLast)
		{
			return true;
		}
		return false;
	}

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

