#include "pch.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{

	UpperRect.setPosition(10.0f,0.0f);
	UpperRect.setFillColor(sf::Color::Blue);
	UpperRect.setSize(sf::Vector2f(780.0f,10.0f));

	LeftRect.setPosition(0.0f, 0.0f);
	LeftRect.setFillColor(sf::Color::Blue);
	LeftRect.setSize(sf::Vector2f(10.0f, 600.0f));

	DownRect.setPosition(10.0f, 590.0f);
	DownRect.setFillColor(sf::Color::Blue);
	DownRect.setSize(sf::Vector2f(780.0f, 10.0f));

	RightRect.setPosition(790.0f, 0.0f);
	RightRect.setFillColor(sf::Color::Blue);
	RightRect.setSize(sf::Vector2f(10.0f, 600.0f));

	borders.push_back(UpperRect);
	borders.push_back(DownRect);
	borders.push_back(LeftRect);
	borders.push_back(RightRect);

}

void GameState::update(const float& dt)
{
	
	this->ball.update(dt);
	this->player.update(dt);
	this->updateKeybinds(dt);
	this->collider.checkCollision(this->player, this->ball, this->borders,dt);
}

void GameState::render(sf::RenderWindow* target)// sf::RenderWindow* target
{
	
	this->player.render(this->window);
	this->ball.render(this->window);
	this->window->draw(this->UpperRect);
	this->window->draw(this->LeftRect);
	this->window->draw(this->DownRect);
	this->window->draw(this->RightRect);

}

void GameState::updateKeybinds(const float& dt)
{
	this->checkForQuit();

}

//std cout-al befagyott valamilyen oknál fogva az endstate---> kérõdjel miért

void GameState::endState()
{

	//valami esetleg kiírni még megcsinálni a befejezés elõtt
	//std::cout << "Ending gamestate4"<<"\n";

}
