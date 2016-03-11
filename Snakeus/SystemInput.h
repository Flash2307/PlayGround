#ifndef SYSTEMINPUT_H_INCLUDED
#define SYSTEMINPUT_H_INCLUDED

#include <string>
#include <array>

struct Player
{
	Player() :
		name(),
		index( 0 )
	{

	}

	Player( const std::string& name_, size_t index_ ) :
		name( name_ ),
		index( index_ )
	{

	}

	bool isValid() const
	{
		return name.empty() == false;
	}

	std::string name;
	size_t index;
};

enum {  PLAYER_COUNT = 4 };
typedef std::array< Player, PLAYER_COUNT > PlayerArrayType;

class SystemInput
{
public:
	SystemInput();
	PlayerArrayType getPlayers();
private:
	PlayerArrayType players;
};

#endif // SYSTEMINPUT_H_INCLUDED
