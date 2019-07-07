#pragma once
#include "Player.h"
class Ball
{
public:

	//Konstruktor / destruktor
	Ball();
	~Ball() = default;

	void move(const float& dt, const float x, const float y); //mozgatja a k�r alakot (float deltaido (kepkockak frissitese k�z�tt eltelt ido), x ir�ny, y ir�ny)
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	const sf::CircleShape& getShape() { return this->ballShape; };

	//Getter / Setter a direction vektor el�r�s�hez
	const sf::Vector2f getDirection() { return this->direction; };
	void setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

	//Ir�nyv�ltoztat�s ha collision van!
	void ChangeDirection(float NearestX,float NearestY, float BallX, float BallY,float dt);
	void ChangeDirectionByPlayer(float NearestX, float NearestY, float BallX, float BallY,float dt ,Player& player);

private:

	sf::CircleShape ballShape; //maga a k�ralakzat
	sf::Vector2f direction; //a labda ir�nyvektora
	float movementSpeed;
};

