#pragma once
#include "pch.h"
#include "Wall.h"

Wall::Wall(sf::Color _color, float _movementSpeed, spawnSide _side,int _hitPoints)

: side(_side),
movementSpeed(_movementSpeed),
hitPoints(_hitPoints)

{

	this->shape.setFillColor(_color);
	initWall(this->side);
}

void Wall::update(const float& dt)
{

	this->shape.move(direction.x * this->movementSpeed * dt, direction.y * this->movementSpeed * dt);

}

void Wall::move(const float& dt, const float dir_x, const float dir_y)
{

	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);

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
		this->shape.setSize(sf::Vector2f(20.0f, 580.0f));
		this->direction.x = 1.0f;
		this->direction.y = 0.0f;
		break;
	case right:
		this->shape.setPosition(780.0f, 20.0f);
		this->shape.setSize(sf::Vector2f(20.0f, 580.0f));
		this->direction.x = -1.0f;
		this->direction.y = 0.0f;
		break;
	case top:
		this->shape.setPosition(20.0f,10.0f);
		this->shape.setSize(sf::Vector2f(780.0f, 20.0f));
		this->direction.x = 0.0f;
		this->direction.y = 1.0f;
		break;
	case down:
		this->shape.setPosition(10.0f, 570.0f);
		this->shape.setSize(sf::Vector2f(780.0f,20.0f));
		this->direction.x = 0.0f;
		this->direction.y = -1.0f;
		break;
	default:
		break;
	};
}

const sf::RectangleShape Wall::getShape() const
{
	return this->shape;
}
