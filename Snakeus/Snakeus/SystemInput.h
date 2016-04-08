#ifndef SYSTEMINPUT_H_INCLUDED
#define SYSTEMINPUT_H_INCLUDED

#include <string>
#include <array>
#include <thread>

#include "Player.h"

enum {  PLAYER_COUNT = 4 };
typedef std::array< Player, PLAYER_COUNT > PlayerArrayType;

class SystemInput
{
public:
	SystemInput(int argc_, char** argv_);
	~SystemInput();

	PlayerArrayType getPlayers();
private:
	static void updateInput(SystemInput* systemInput_);

	bool run;
	std::thread updateKeys;
	PlayerArrayType players;
};

#endif // SYSTEMINPUT_H_INCLUDED
