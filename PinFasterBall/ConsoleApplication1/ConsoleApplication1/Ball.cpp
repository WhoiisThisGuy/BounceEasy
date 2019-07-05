#include "pch.h"
#include "Ball.h"

Ball::Ball() {

	this->movementSpeed = 500.0f;
	this->ballShape.setRadius(20.0f);
	this->ballShape.setOrigin(sf::Vector2f(20.0f, 20.0f));
	this->ballShape.setPosition(100.0f, 100.0f);
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

void Ball::ChangeDirection(float NearestX, float NearestY,float BallX,float BallY,float dt)
{

	//Fent ütközött rövidebb

	//Ha az X-ek egyenlõk akkor az ütközés vízszintesen lévõ oldallal történt
	if (NearestX == BallX) {

		//Fent ütközött ___________
		//                   O

		if (NearestY <= BallY)
		{

			this->direction.x == 0 ? this->move(dt, 0, 3) : this->direction.x > 0 ? this->move(dt,3,3) : this->move(dt,-3,3);

			this->direction.y *= -1;
		}

		//Lent ütközött      
        //              _____O_____     
		else if (NearestY >= BallY) {

			this->direction.x == 0 ? this->move(dt, 0, -3) : this->direction.x > 0 ? this->move(dt, 3, -3) : this->move(dt, -3, -3);

			this->direction.y *= -1;
		}
	}
	//ha az Y-ok egyenlõek akkor Függõleges oldalnak ütközött

	else if ( NearestY == BallY) {

		//Bal oldalán ütközött |
		//                     |O
		//                     |

		if (NearestX <= BallX) {

			this->direction.y > 0 ? this->move(dt, 3, 3) : this->move(dt, 3, -3); //

			this->direction.x *= -1;
		}
		//Jobb oldalán ütközött   |
		//                       O| 
		//                        |
		else if (NearestX >= BallX) {
		
			this->direction.y > 0 ? this->move(dt, -3, 3) : this->move(dt, -3, -3);

			this->direction.x *= -1;

		}

	}
	//ez a rész arra vonatkozik ha sarkot üti meg , ekkor a BallX,BallY mindekettõ vagy nagyobb vagy kisebb de semmiképp sem egyenlõ

	//     O __   __ O
	//      |       |        |_     _|
	//                      O         O

	else if (BallX != NearestX && BallY != NearestY) {

		this->move(dt, this->getDirection().x * -1, this->getDirection().y * -1);

		this->direction.x *= -1;
		this->direction.y *= -1;

	}

}

void Ball::ChangeDirectionByPlayer(float NearestX, float NearestY, float BallX, float BallY,float dt,Player& player)
{


	//Fent ütközött rövidebb

	//Ha az X-ek egyenlõk akkor az ütközés vízszintesen lévõ oldallal történt
	if (NearestX == BallX) {

		//Fent ütközött ___________
		//                   O

		if (NearestY <= BallY)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				this->direction.x = -1;
				this->direction.y = 2;
				this->move(dt, -1, 3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->direction.x = 0;
				this->direction.y = 2;
				this->move(dt, 0, 2);
				//this->direction.y = -2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				this->direction.x = 1;
				this->direction.y = 2;
				this->move(dt, 1, 3);
			}
			else {

				this->direction.y *= -1;

			}
		}

		//Lent ütközött      
		//              _____O_____     
		else if (NearestY >= BallY) {

			//Ha éppen balra mozgunk balra vált irány a labda
			//Föl - le mozgás esetében vertikálisan fog mozogni
			//Ha éppen jobbra akkor jobbra

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				this->direction.x = -1;
				this->direction.y = -2;
				this->move(dt, -1, -3);
				

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				this->direction.x = 0;
				this->direction.y = -2;
				this->move(dt, 0, -2);
				//this->direction.y = -2;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				this->direction.x = 1;
				this->direction.y = -2;
				this->move(dt, 1, -3);


			}
			else {

				this->direction.y *= -1;

			}
				//this->direction.x > 0 ? this->move(dt, 2, -2) : this->move(dt, -2, -2);

			
		}
	}
	//ha az Y-ok egyenlõek akkor Függõleges oldalnak ütközött

	else if (NearestY == BallY) {

		//Bal oldalán ütközött |
		//                     |O
		//                     |

		if (NearestX <= BallX) {

			this->direction.y > 0 ? this->move(dt, 2, 2) : this->move(dt, 2, -2); //

			this->direction.x *= -1;
		}
		//Jobb oldalán ütközött   |
		//                       O| 
		//                        |
		else if (NearestX >= BallX) {

			this->direction.y > 0 ? this->move(dt, -2, 2) : this->move(dt, -2, -2);

			this->direction.x *= -1;

		}

	}
	//ez a rész arra vonatkozik ha sarkot üti meg , ekkor a BallX,BallY mindekettõ vagy nagyobb vagy kisebb de semmiképp sem egyenlõ

	//     O __   __ O
	//      |       |        |_     _|
	//                      O         O

	else if (BallX != NearestX && BallY != NearestY) {

		this->move(dt, this->getDirection().x * -1, this->getDirection().y * -1);

		this->direction.x *= -1;
		this->direction.y *= -1;

	}


}
