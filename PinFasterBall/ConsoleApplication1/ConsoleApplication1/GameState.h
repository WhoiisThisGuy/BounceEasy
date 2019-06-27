#pragma once
#include "State.h"
#include "Player.h"
#include "Ball.h"
#include "Collider.h"

class GameState:public State
{

public:

	GameState(sf::RenderWindow* window);
	
	void update(const float& dt);
	void render();//sf::RenderWindow* target = nullptr

	void endState();

	void updateKeybinds(const float& dt);


private:

	sf::RectangleShape UpperRect;
	sf::RectangleShape DownRect;
	sf::RectangleShape LeftRect;
	sf::RectangleShape RightRect;

	std::vector<sf::RectangleShape> borders;

	Player player;
	Ball ball;
	Collider collider;
};

