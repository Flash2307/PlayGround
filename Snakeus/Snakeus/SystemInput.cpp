#include "SystemInput.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>

#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <GamepadMsg.h>

#include <thread>

#ifndef NDEBUG

static void printError( sf::Socket::Status error )
{
	switch (error)
	{
	case sf::Socket::Status::Error:
		std::cout << "Unexpected upd socket error\n";
		break;
	case sf::Socket::Status::Disconnected:
		std::cout << "Disconnected upd socket error\n";
		break;
	case sf::Socket::Status::NotReady:
		std::cout << "Disconnected upd socket error\n";
		break;
	default:
		std::cout << "upd socket error!?\n";
		break;
	}
}

static void sendTestData()
{
	GamePadMsgType command;
	sf::UdpSocket socket;

	while (1)
	{
		socket.send(&command, sizeof(command), sf::IpAddress::LocalHost, GameDestinationPort);
		sf::sleep(sf::milliseconds(10));
	}
}

//std::thread testData(sendTestData);

#endif

/*

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
*/

void SystemInput::updateInput(SystemInput* systemInput_)
{
	assert(systemInput_ != nullptr);

	GamePadMsgType command;
	size_t bufferFilledDataCount = 0;

	std::size_t receivedData;
	sf::IpAddress senderIp;
	unsigned short port;

	sf::UdpSocket socket;
	sf::Socket::Status error = socket.bind(GameDestinationPort);
	assert(error == sf::Socket::Done);

	socket.setBlocking(false);
	
	while( systemInput_->run )
	{
		error = socket.receive(&command, sizeof(GamePadMsgType) - bufferFilledDataCount, receivedData, senderIp, port);
		bufferFilledDataCount += receivedData;

		if (error != sf::Socket::Done)
		{
			sf::sleep(sf::milliseconds(10));
		}

		if (bufferFilledDataCount == sizeof(GamePadMsgType))
		{
			size_t index = getGamepadIndex(command);
			assert(index < PLAYER_COUNT);

			systemInput_->players[index].setAKeyPressed(isGamepadABtn(command));
			systemInput_->players[index].setBKeyPressed(isGamepadBBtn(command));
			systemInput_->players[index].setLeftKeyPressed(isGamepadLeftArrow(command));
			systemInput_->players[index].setRightKeyPressed(isGamepadRigthArrow(command));
			bufferFilledDataCount = 0;
		}
	}

	socket.unbind();
}

SystemInput::SystemInput( int argc_, char** argv_ ) :
	run( true )
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

	this->updateKeys = std::thread( updateInput, this );
}

SystemInput::~SystemInput()
{
	this->run = false;
	this->updateKeys.join();
}

PlayerArrayType SystemInput::getPlayers()
{
	return this->players;
}

