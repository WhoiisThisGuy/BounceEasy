#include "pch.h"
#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window)
	:State(window)

{


	InitBorders();
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString("Hi this is a pinball(ish) game, but instead of breaking small chunks of blocks\nyou have to break big walls,\n"
		"they are big and red and they move towards you.\n"
		"Controlling: with the cursors (you can move up and down aswell)\n"
		"The ball always goes in the direction of the cursor you pressed.\n"
		"You can break them but you have to hit them 10 times.\nIf they reach you it is Game Over.\n"
		"You can rotate by pressing R and one of the cursors (Left,Right).\nIf you use rotating in the exact time the ball hits you\n"
		"the ball will go into the direction you rotated to.\n"
		"TIP: you should move the ball as close as you can between you and the wall and you will hit a lot.\n"
		"GL & HF\nAuthor@Near.");
	
	text.setPosition(20.0f,20.0f);
	text2.setFont(font);
	text2.setCharacterSize(18);
	text2.setString("Press Space to Play or Esc to Quit.");
	text2.setPosition(270.0f, 450.0f);

}

void MenuState::update(const float& dt)
{

	updateKeybinds();

}

void MenuState::render()
{
	this->window->draw(this->text);
	this->window->draw(this->text2);
	this->player.render(this->window);
	this->ball.render(this->window);
	this->window->draw(this->UpperRect);
	this->window->draw(this->LeftRect);
	this->window->draw(this->DownRect);
	this->window->draw(this->RightRect);

}

void MenuState::endState()
{

	

}

void MenuState::checkForQuit()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

		this->quit = true;
	}

}

void MenuState::checkForPlay() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		this->play = true;
	}

}

void MenuState::updateKeybinds()//const float& dt
{

	this->checkForQuit();
	this->checkForPlay();

}

