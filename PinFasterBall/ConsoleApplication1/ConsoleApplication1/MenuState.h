#pragma once
#include "pch.h"
#include "State.h"
#include "Player.h"
#include "Ball.h"

class MenuState : public State

{

public:

	MenuState(sf::RenderWindow* window);

	void update(const float& dt);
	void render();//sf::RenderWindow* target = nullptr

	void endState();

	void updateKeybinds();//const float& dt


	//privát függvények

private:
	void checkForQuit();
	void checkForPlay();
private:

	sf::Text text;

	sf::Text text2;

	Player player;
	Ball ball;
};

