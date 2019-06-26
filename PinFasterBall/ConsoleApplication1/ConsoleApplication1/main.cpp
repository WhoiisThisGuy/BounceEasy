#include "pch.h"
#include "Game.h"
#include "State.h"

int main()
{
	
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Game game;

	game.run();

	return 0;
}