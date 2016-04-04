#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

struct KeyMap
{
	KeyMap() :
		leftPressed( false ),
		rightPressed( false ),
		aPressed( false ),
		bPressed( false )
	{

	}

	bool leftPressed;
	bool rightPressed;
	bool aPressed;
	bool bPressed;
};

class Player
{
public:
	Player();
	Player( const std::string& name_, size_t index_, const sf::Vector2i& spawnPos_ = sf::Vector2i() );

	bool isValid() const;

	bool isLeftKeyPress() const;
	void setLeftKeyPressed( bool pressed_ );

	bool isRightKeyPress() const;
	void setRightKeyPressed( bool pressed_ );

	bool isAKeyPressed() const;
	void setAKeyPressed( bool pressed_ );

	bool isBKeyPressed() const;
	void setBKeyPressed( bool pressed_ );

	void setSpawnPos( const sf::Vector2i& spawnPos_ );
	int spawnX() const;
	int spawnY() const;

	const std::string& getName() const;
	size_t getIndex() const;

	size_t getScore() const;
	void setScore( size_t score_ );
private:
	std::shared_ptr< KeyMap > pKeys;
	std::string name;
	size_t index;
	size_t score;
	sf::Vector2i spawnPos;

};


#endif // PLAYER_H_INCLUDED
