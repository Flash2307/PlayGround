#pragma once

#include <thread>
class Controls
{
public:
	virtual bool upKey()
	{
		if (this->upKey_ && !this->upKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool leftKey()
	{
		if (this->leftKey_ && !this->leftKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool rightKey()
	{
		if (this->rightKey_ && !this->rightKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool downKey()
	{
		if (this->downKey_ && !this->downKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool aKey()
	{
		if (this->aKey_ && !this->aKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool bKey()
	{
		if (this->bKey_ && !this->bKeyLast)
		{
			return true;
		}
		return false;
	}
	virtual bool escapeKey()
	{
		if (this->aKey_ && !this->aKeyLast && this->bKey_ && !this->bKeyLast)
		{
			return true;
		}
		return false;
	}

	virtual void setUpKey(bool state) = 0;
	virtual void setDownKey(bool state) = 0;
	virtual void setLeftKey(bool state) = 0;
	virtual void setRightKey(bool state) = 0;
	virtual void setAKey(bool state) = 0;
	virtual void setBKey(bool state) = 0;
	
	virtual void startMonitor() = 0;

protected:
	bool upKey_;
	bool leftKey_;
	bool rightKey_;
	bool downKey_;
	bool aKey_;
	bool bKey_;
	bool upKeyLast;
	bool leftKeyLast;
	bool rightKeyLast;
	bool downKeyLast;
	bool aKeyLast;
	bool bKeyLast;
	std::thread controlsMonitor;
};