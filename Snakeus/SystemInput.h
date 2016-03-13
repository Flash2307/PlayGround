#ifndef SYSTEMINPUT_H_INCLUDED
#define SYSTEMINPUT_H_INCLUDED

#include <string>
#include <array>

#include "Player.h"

enum {  PLAYER_COUNT = 4 };
typedef std::array< Player, PLAYER_COUNT > PlayerArrayType;

class SystemInput
{
public:
	SystemInput( int argc_, char** argv_ );
	PlayerArrayType getPlayers();
	void update();
private:
	PlayerArrayType players;
};

#endif // SYSTEMINPUT_H_INCLUDED
