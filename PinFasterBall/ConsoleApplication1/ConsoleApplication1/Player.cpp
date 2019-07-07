#include "pch.h"
#include "Player.h"

Player::Player()
	:movementSpeed(650.0f)


{

	//Alapméretek inicializálása a Playernek:
	this->shape.setSize(sf::Vector2f(100.0f, 12.0f)); //120.0f
	this->shape.setPosition(400.0f, 350.0f);
	this->shape.setFillColor(sf::Color::Magenta);

	this->shape.setOrigin(60.0f, 6.0f); //Az origin miatt tudom "egyhelybe" elforgatni.
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

		if (this->shape.getPosition().x+this->getShape().getGlobalBounds().width < 798)
		this->move(dt, 1.f, 0.f);
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		if (this->shape.getPosition().y > 10.0f)
			this->move(dt, 0.f, -1.f);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		if (this->shape.getPosition().y < 580.0f)
			this->move(dt, 0.f, 1.f);

	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && RotateTime.getElapsedTime().asMilliseconds() > 500.0f) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			
			this->shape.rotate(-90.0f);
			
			RotateTime.restart();
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

				
				this->shape.rotate(90.0f);
			
				RotateTime.restart().asSeconds();
				
		}
		
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