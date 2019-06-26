#include "pch.h"
#include "Game.h"

Game::Game() {

	this->initWindow();
	this->initStates();
	this->ScreenHeight = window->getSize().y;
	this->ScreenWidth = window->getSize().x;
}

//Initializer
void Game::initWindow()
{
	
	//sf::VideoMode::getFullscreenModes().at(5)

	this->window = new sf::RenderWindow(sf::VideoMode(800,600),"PinFasterBall");
	
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
	
}

Game::~Game() {

	delete this->window;
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::endApplication()
{

	std::cout << "ending application"<<"\n";

}

void Game::updateDt()
{
	//Update: mennyi id� alatt friss�t egy k�pkock�t �gy m�s teljesitm�ny� pc-n is ugyanannyi id�vel mozog a unit pl.
	this->dt = this->deltaClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{

		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::update()
{
	this->updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit()) {
			
			this->states.top()->endState();
			//Ezt az�rt itt delete �s nem a destruktorban mert ha m�g le akarok j�tszani valami end animationt akkor itt meglehet tenni.
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endApplication();
		this->window->close();

	}
}

void Game::render()
{

	this->window->clear();

	//Render Items

	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();

}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
		
	}

}
