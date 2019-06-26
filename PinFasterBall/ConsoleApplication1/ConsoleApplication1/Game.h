#pragma once
#include "GameState.h"
class Game
{
	//V�ltoz�k
	private:
		sf::Event sfEvent;
		sf::RenderWindow *window;
		int ScreenWidth;
		int ScreenHeight;

		sf::Clock deltaClock;
		float dt;

		std::stack<State*> states;
		
		//F�ggv�nyek
private:

	

	//Initialization
	void initWindow();
	void initStates();

public:

	//Constructor / Destructor

	Game();
	virtual ~Game();

	//End function
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//Game start
	void run();

};
