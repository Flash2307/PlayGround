#ifndef SYSTEMINPUT_H_INCLUDED
#define SYSTEMINPUT_H_INCLUDED

#include <string>
#include <array>
#include <thread>
#include "GameControls.h"

enum {  PLAYER_COUNT = 2 };

class SystemInput
{
public:
	SystemInput(int argc_, char** argv_);
	~SystemInput();

private:
	static void updateInput(SystemInput* systemInput_);
	bool run;
	std::thread updateKeys;
	GameControls* controls;
};

#endif // SYSTEMINPUT_H_INCLUDED
