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
	~GameState();
	void update(const float& dt);
	void render();//sf::RenderWindow* target = nullptr

	void endState();

	void updateKeybinds();//const float& dt



private:

	void UpdateWalls(const float& dt);
	void createWall();
	void deleteWall();
	void checkForQuit();
	void checkForPlay();
	void DrawWalls(sf::RenderWindow* window);

private:

	int Destroyedwalls;
	bool GameOver;
	std::vector<Wall*> walls;
	Player player;
	Ball ball;
	Collider collider;

	sf::Text DestroyedWallsText;
	sf::Text gameOverText;
	sf::Text gameOverText2;
};

