#include "SystemInput.h"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <sstream>

#include <SFML/Window.hpp>

#include <GamepadMsg.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>

static bool inputAvailable()
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);

  return (FD_ISSET(0, &fds));
}

SystemInput::SystemInput( int argc_, char** argv_ )
{
	std::stringstream inputStream;
	std::string username;
	size_t userIndex = 0;

	for( int index = 1; index < argc_; ++index )
	{
		inputStream.clear();
		inputStream.str( std::string( argv_[ index ] ) );
		inputStream >> username;
		inputStream >> userIndex;

		assert( userIndex < PLAYER_COUNT );
		players[ userIndex ] = Player( username, userIndex );
	}

	if( argc_ == 1 )
	{
		players[ 0 ] = Player( "Kevin", 0 );
		players[ 1 ] = Player( "Gabriel", 1 );
		players[ 2 ] = Player( "Antoine", 2 );
		players[ 3 ] = Player( "Joel", 3 );
	}
}

PlayerArrayType SystemInput::getPlayers()
{
	return this->players;
}

void SystemInput::update()
{
	std::for_each( players.begin(), players.end(),
	[]( Player& player_ )
	{
		if( player_.isValid() )
		{
			player_.setLeftKeyPressed( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) );
			player_.setRightKeyPressed( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) );
			player_.setAKeyPressed( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) );
			player_.setBKeyPressed( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::B ) );
		}
	});

	uint16_t command = 0;
	size_t index = 0;

	while( inputAvailable() )
	{
		std::cin >> command;

		index = getGamepadIndex( command );
		assert( index < PLAYER_COUNT );

		players[ index ].setAKeyPressed( isGamepadABtn( command ) );
		players[ index ].setBKeyPressed( isGamepadBBtn( command ) );
		players[ index ].setLeftKeyPressed( isGamepadLeftArrow( command ) );
		players[ index ].setRightKeyPressed( isGamepadRigthArrow( command ) );
	}
}
