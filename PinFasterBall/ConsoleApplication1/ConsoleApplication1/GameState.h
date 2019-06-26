#pragma once
#include "State.h"
#include "Player.h"
#include "Ball.h"


class GameState:public State
{
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();
	void update(const float& dt);
	void render(sf::RenderWindow* target = nullptr);

	void endState();

	void updateKeybinds(const float& dt);


private:

	Player player;
	Ball ball;
};

