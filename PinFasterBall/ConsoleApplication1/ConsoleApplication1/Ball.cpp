#include "pch.h"
#include "Ball.h"

Ball::Ball() {

	this->movementSpeed = 50.0f;
	this->ballShape.setRadius(20.0f);
	this->movementSpeed = 600.0f;
	this->ballShape.setOrigin(sf::Vector2f(20.0f, 20.0f));
	this->ballShape.setPosition(400.0f, 100.0f);
	this->ballShape.setFillColor(sf::Color::Cyan);

	this->direction.x = 0.0f;
	this->direction.y = 1.0f;
	
}


void Ball::update(const float& dt)
{
	
	this->ballShape.move(direction.x * this->movementSpeed * dt, direction.y * this->movementSpeed * dt);

}

void Ball::move(const float& dt, const float dir_x, const float dir_y)
{

	this->ballShape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);

}

void Ball::render(sf::RenderTarget* target)
{

	target->draw(this->ballShape);
}

void Ball::ChangeDirection(float NearestX, float NearestY,float BallX,float BallY)
{

	if (NearestX == BallX && NearestY < BallY) {
		
		this->direction.x = this->direction.x;
		this->direction.y = this->direction.y*-1;
	
	}
	else if (NearestX == BallX && NearestY > BallY) {

		this->direction.x = this->direction.x;
		this->direction.y = this->direction.y * -1;

	}
	else if (NearestX < BallX && NearestY == BallY) {

		this->direction.x = this->direction.x*-1;
		this->direction.y = this->direction.y;

	}
	else if (NearestX > BallX && NearestY == BallY) {

		this->direction.x = this->direction.x * -1;
		this->direction.y = this->direction.y;

	}

}

void Ball::ChangeDirectionByPlayer(float NearestX, float NearestY, float BallX, float BallY)
{


	if (NearestX == BallX && NearestY < BallY) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			this->direction.x = this->direction.x;
			this->direction.y = this->direction.y * -1;
		}
		else
		{
			this->direction.x = this->direction.x;
			this->direction.y = this->direction.y * -1;

		}

	}
	else if (NearestX == BallX && NearestY > BallY) {

		this->direction.x = this->direction.x;
		this->direction.y = this->direction.y * -1;

	}
	else if (NearestX < BallX && NearestY == BallY) {

		this->direction.x = this->direction.x * -1;
		this->direction.y = this->direction.y;

	}
	else if (NearestX > BallX && NearestY == BallY) {

		this->direction.x = this->direction.x * -1;
		this->direction.y = this->direction.y;

	}


}
