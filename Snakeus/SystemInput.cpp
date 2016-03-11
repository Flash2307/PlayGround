#include "SystemInput.h"

SystemInput::SystemInput()
{
	players[ 0 ] = Player( "Kevin", 0 );
	players[ 1 ] = Player( "Gabriel", 1 );
	players[ 2 ] = Player( "Antoine", 2 );
	players[ 3 ] = Player( "Joel", 3 );
}

PlayerArrayType SystemInput::getPlayers()
{
	return this->players;
}
