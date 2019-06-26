#include "pch.h"
#include "Ball.h"

Ball::Ball() {

	this->movementSpeed = 50.0f;
	this->ballShape.setRadius(20.0f);
	this->movementSpeed = 300.0f;
	this->ballShape.setOrigin(sf::Vector2f(111.0f / 2, 11.0f / 2));
	this->ballShape.setPosition(400.0f, 100.0f);
	this->ballShape.setFillColor(sf::Color::Cyan);
	
}

Ball::~Ball()
{
}



void Ball::update(const float& dt,const float x, const float y)
{
	
	this->move(dt,x,y);

}

void Ball::move(const float& dt, const float dir_x, const float dir_y)
{

	this->ballShape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);

}

void Ball::render(sf::RenderTarget* target)
{

	target->draw(this->ballShape);
}
