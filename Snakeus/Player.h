#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <memory>

struct KeyMap
{
	KeyMap() :
		leftPressed( false ),
		rightPressed( false )
	{

	}

	bool leftPressed;
	bool rightPressed;
};

struct Player
{
	Player();
	Player( const std::string& name_, size_t index_ );

	bool isValid() const;

	bool isLeftKeyPress() const;
	void setLeftKeyPressed( bool pressed_ );

	bool isRightKeyPress() const;
	void setRightKeyPressed( bool pressed_ );

	std::string name;
	size_t index;
	std::shared_ptr< KeyMap > pKeys;
};


#endif // PLAYER_H_INCLUDED
