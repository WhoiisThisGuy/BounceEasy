#include "pch.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{


}

GameState::~GameState()
{
}

void GameState::update(const float& dt)
{
	this->updateKeybinds(dt);
	
	this->player.update(dt);
	
	if(ball.getShape().getGlobalBounds().intersects(player.getRect()))
		this->ball.update(dt,0.f,1.0f);
	else
		this->ball.update(dt, 0.f, -1.0f);
	//std::cout << "left\t" << ball.getGlobalBounds().left;
	
	//std::cout << "top\t" << player.getShape().getGlobalBounds().;
	system("CLS");
}

void GameState::render(sf::RenderWindow* target)
{

	this->player.render(this->window);
	this->ball.render(this->window);
	
}

void GameState::updateKeybinds(const float& dt)
{
	this->checkForQuit();

}

void GameState::endState()
{

	std::cout << "Ending gamestate4"<<"\n";

}
