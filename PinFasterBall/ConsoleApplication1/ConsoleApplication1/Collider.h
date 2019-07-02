#pragma once
#include "Ball.h"
#include "Player.h"

class Collider
{
public:
	Collider() = default;
	void checkCollision(Player& player,Ball& ball,const std::vector<sf::RectangleShape>& borders,float dt);

private:
	bool collide(float DeltaX, float DeltaY, float CircleRadius);

};

