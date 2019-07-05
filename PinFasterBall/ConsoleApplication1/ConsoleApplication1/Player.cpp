#include "pch.h"
#include "Player.h"

Player::Player() {

	this->shape.setSize(sf::Vector2f(120.0f, 11.0f));
	this->movementSpeed = 650.0f;
	//this->shape.setOrigin(sf::Vector2f(111.0f/2, 11.0f/2));
	this->shape.setPosition(380.0f, 550.0f);
	this->shape.setFillColor(sf::Color::Magenta);
	
	//Itt beállítok egy float rectanglet (floatrect) azért mert ezt adom át hogy Intersectre nézze

	
}

Player::~Player()
{
}

void Player::update(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		if (this->shape.getGlobalBounds().left>3)
			this->move(dt,-1.f,0.f);
	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		if (this->shape.getGlobalBounds().left+this->shape.getSize().x < 798)
		this->move(dt, 1.f, 0.f);
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		
			this->move(dt, 0.f, -1.f);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		
			this->move(dt, 0.f, 1.f);

	}

}

void Player::render(sf::RenderTarget* target)
{

	target->draw(this->shape);
}

void Player::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);

}