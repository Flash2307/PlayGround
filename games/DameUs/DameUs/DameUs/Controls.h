#pragma once

class Controls
{
public:
	virtual bool upKey() = 0;
	virtual bool leftKey() = 0;
	virtual bool rightKey() = 0;
	virtual bool downKey() = 0;
	virtual bool aKey() = 0;
	virtual bool bKey() = 0;
	virtual bool enterKey() = 0;
	virtual bool escapeKey() = 0;
};