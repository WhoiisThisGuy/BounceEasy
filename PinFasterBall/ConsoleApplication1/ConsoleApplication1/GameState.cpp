#include "pch.h"
#include "GameState.h"

#define MAXNUMofWALLS 2

GameState::GameState(sf::RenderWindow* window)
	: State(window),
	GameOver(false) 

{

	State::InitBorders();
	
	gameOverText.setFont(font);
	gameOverText.setString("OH NO... Game Over");
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setCharacterSize(30.0f);
	gameOverText.setPosition(270.0f,300.0f);

	gameOverText2.setFont(font);
	gameOverText2.setString("Press 'R' for restart or 'Q' to Quit!");
	gameOverText2.setFillColor(sf::Color::White);
	gameOverText2.setCharacterSize(25.0f);
	gameOverText2.setPosition(250.0f, 350.0f);

	Destroyedwalls = 0;
	DestroyedWallsText.setString("Number of destroyed walls : "+std::to_string(Destroyedwalls));
	DestroyedWallsText.setPosition(20.0f,660.0f);
	DestroyedWallsText.setFont(font);
	gameOverText2.setFillColor(sf::Color::White);
}

GameState::~GameState()
{
		int i = 0;
		int length = walls.size();

		for (; i < length; i++)
		{
			delete walls.at(i);

		}

		walls.clear();
	
}

void GameState::update(const float& dt)
{
	if (!GameOver) {
		this->deleteWall();
		this->createWall();
		this->UpdateWalls(dt);
		this->ball.update(dt);
		this->player.update(dt);
		this->updateKeybinds();
		GameOver = this->collider.checkCollision(this->player, this->ball, this->borders, this->walls, dt);
	}
	else {
		
		this->updateKeybinds();
	
	}
}

void GameState::render()// sf::RenderWindow* target
{
	
	this->DrawWalls(this->window);
	this->player.render(this->window);
	this->ball.render(this->window);
	this->window->draw(this->UpperRect);
	this->window->draw(this->LeftRect);
	this->window->draw(this->DownRect);
	this->window->draw(this->RightRect);
	this->window->draw(this->DestroyedWallsText);

	if (GameOver) {
	
		this->window->draw(this->gameOverText);
		this->window->draw(this->gameOverText2);
	}
}

void GameState::updateKeybinds()//const float& dt
{
		this->checkForQuit();
		this->checkForPlay();
}

void GameState::UpdateWalls(const float& dt)
{

	for (int i = 0; i < this->walls.size(); i++)
	{
		if ((walls.at(i)->getWallState()) == alive)
		{

			walls.at(i)->update(dt);

		}
	}

}

void GameState::createWall()
{

	if (this->walls.size() < MAXNUMofWALLS) {

		SpawnSide side = static_cast<SpawnSide>(rand() % 4);;

		walls.push_back(new Wall(sf::Color::Red, 90.0f, side, 5));
		
	}
}

void GameState::deleteWall()
{

	for (int i = 0; i < this->walls.size(); i++)
	{
		if ((walls.at(i)->getWallState()) == dead) {
			delete walls.at(i);
			walls.erase(walls.begin() + i);
			Destroyedwalls += 1;
			DestroyedWallsText.setString("Number of destroyed walls : " + std::to_string(Destroyedwalls));
		}
	}

}

void GameState::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

		this->quit = true;
	}
	//Megállitom a gémet törlök mindent és menu state-be lépünk

}


void GameState::checkForPlay() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
	
		this->play = true;
	
	}

}
void GameState::DrawWalls(sf::RenderWindow* window)
{
	for (int i = 0; i < walls.size();i++) {
	
		window->draw(walls.at(i)->getShape());
	
	}

}
//std cout-al befagyott valamilyen oknál fogva az endstate---> kérõdjel miért

void GameState::endState()
{

	//valami esetleg kiírni még megcsinálni a befejezés elõtt
	//std::cout << "Ending gamestate4"<<"\n";

}
