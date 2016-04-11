#pragma once

#include <SFML/Graphics.hpp>

struct tiny_state
{
	virtual ~tiny_state() = default;

	virtual void Initialize(sf::RenderWindow* window) = 0;
	virtual void Update(sf::RenderWindow* window) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Destroy(sf::RenderWindow* window) {}
};

class game_state
{
public:
	game_state() :
		state( nullptr ),
		window( nullptr )
	{

	}

	virtual ~game_state()
	{
		if (this->state != nullptr)
		{
			this->state->Destroy(this->window);
		}
	}

	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(tiny_state* state)
	{
		if (this->state != nullptr)
		{
			this->state->Destroy(this->window);
		}
		this->state = state;
		if (this->state != nullptr)
		{
			this->state->Initialize(this->window);
		}
	}

	void Update()
	{
		if (this->state != nullptr)
		{
			this->state->Update(this->window);
		}
	}
	void Render()
	{
		if (this->state != nullptr)
		{
			this->state->Render(this->window);
		}
	}
private:
	sf::RenderWindow* window;
	tiny_state* state;
};

extern game_state coreState;
extern bool quitGame;

