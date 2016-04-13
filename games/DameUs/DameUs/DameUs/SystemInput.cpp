#include "SystemInput.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>

#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <GamepadMsg.h>

#include <thread>
#include "GameControls.h"

/*#ifndef NDEBUG

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

#endif*/

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
			assert(index < 4);

			Controls* controls = systemInput_->controls->player1Controls;

			/*if (index == 0)
			{
				controls = systemInput_->controls->player1Controls;
			}
			else if (index == 1)
			{
				controls = systemInput_->controls->player2Controls;
			}

			else
			{
				continue;
			}*/

			controls->setAKey(isGamepadABtn(command));
			controls->setBKey(isGamepadBBtn(command));
			controls->setUpKey(isGamepadUpArrow(command));
			controls->setDownKey(isGamepadDownArrow(command));
			controls->setLeftKey(isGamepadLeftArrow(command));
			controls->setRightKey(isGamepadRigthArrow(command));

			controls = systemInput_->controls->player2Controls;

			controls->setAKey(isGamepadABtn(command));
			controls->setBKey(isGamepadBBtn(command));
			controls->setUpKey(isGamepadUpArrow(command));
			controls->setDownKey(isGamepadDownArrow(command));
			controls->setLeftKey(isGamepadLeftArrow(command));
			controls->setRightKey(isGamepadRigthArrow(command));

			bufferFilledDataCount = 0;
		}
	}

	socket.unbind();
}



SystemInput::SystemInput( int argc_, char** argv_ ) :
	run( true )
{
	this->controls = GameControls::getInstance();
	std::stringstream inputStream;
	std::string username;
	size_t userIndex = 0;

	/*for( int index = 1; index < argc_; ++index )
	{
		inputStream.clear();
		inputStream.str( std::string( argv_[ index ] ) );
		inputStream >> username;
		inputStream >> userIndex;

		assert( userIndex < PLAYER_COUNT );
		players[ userIndex ] = Player( username, userIndex );
	}
	*/
	if( argc_ == 1 )
	{
		this->controls->setPlayer1Name("Kevin");
		this->controls->setPlayer2Name("Antoine");
	}

	this->updateKeys = std::thread( updateInput, this );
}

SystemInput::~SystemInput()
{
	this->run = false;
	this->updateKeys.join();
}


