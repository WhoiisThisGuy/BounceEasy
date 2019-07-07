#pragma once
#include "Ball.h"
#include "Player.h"
#include "Wall.h"

class Collider
{
public:

	Collider(); //Csak a bool GameOver-t állitom be falsera kezdésbõl
	
	bool checkCollision(Player& player,Ball& ball,const std::vector<sf::RectangleShape>& borders, std::vector<Wall*>& walls,const float& dt);
	float CircleX;
	float CircleY;
	float CircleRadius;


private:

	bool GameOver; //Csak akkor változik ha a wall - player collision van a checkCollision függvény returnolja ezzel nézem majd van e GameOver

	void checkPlayerBallCollision(Ball& ball, Player& player,const float& dt);

	void checkPlayerWallCollision(Player& player, std::vector<Wall*>& walls, const float& dt);

	void checkBallWallCollision(Ball& ball,std::vector<Wall*>& walls,const float& dt);

	void checkBallBorderCollision(Ball& ball, const std::vector<sf::RectangleShape>& borders, const float& dt);

	bool collide(float DeltaX, float DeltaY);

};

