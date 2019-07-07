#pragma once
#include "pch.h"
#include "State.h"
#include "Player.h"
#include "Ball.h"
#include "Collider.h"
#include "Wall.h"


class GameState:public State
{

public:

	GameState(sf::RenderWindow* window);
	
	void update(const float& dt);
	void render();//sf::RenderWindow* target = nullptr

	void endState();

	void updateKeybinds();//const float& dt
	void createWall();


private:

	
	void checkForQuit();
	void checkForPlay();

private:


	bool GameOver;
	std::vector<Wall*> walls;

	int numberOfWalls; //hány mozgó fal van a pályán, maximum 2 lehessen

	Player player;
	Ball ball;
	Collider collider;

	sf::Text gameOverText;
	sf::Text gameOverText2;
};

