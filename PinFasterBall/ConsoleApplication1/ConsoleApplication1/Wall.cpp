#include "Wall.h"


Wall::Wall(sf::Color color_, float movementSpeed_, spawnSide side_)

: side_(side),
movementSpeed_(movementSpeed)

{

	this->shape.setFillColor(color_);
	
}



void Wall::update(const float& dt)
{

	this->ballShape.move(direction.x * this->movementSpeed * dt, direction.y * this->movementSpeed * dt);

}

void Wall::move(const float& dt, const float dir_x, const float dir_y)
{

	this->ballShape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);

}

void Wall::render(sf::RenderTarget* target)
{

	target->draw(this->shape);
}

void Wall::initWall(spawnSide side)
{
	switch (side)
	{
	case left:
		this->shape.setPosition(20.0f, 10.0f);
		this->shape.setSize(20.0f, 580.0f);
		break;
	case right:
		this->shape.setPosition(770.0f, 10.0f);
		this->shape.setSize(20.0f, 580.0f);
		break;
	case top:
		this->shape.setPosition(20.0f,10.0f);
		this->shape.setSize(770.0f,20);
		break;
	case down:
		this->shape.setPosition(20.0f, 580.0f);
		this->shape.setSize(770.0f,20.0f);
		break;
	default:
		break;
	};
}
