#pragma once

class Ball
{
public:

	//Konstruktor
	Ball();
	~Ball() = default;


	void move(const float& dt, const float x, const float y);
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	sf::CircleShape& getShape() { return this->ballShape; }; //Konstanst vissza rakni


	//Getter / Setter a direction vektor eléréséhez
	const sf::Vector2f getDirection() { return this->direction; };
	void setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

	//Irányváltoztatás ha collision van!
	void ChangeDirection(float NearestX,float NearestY, float BallX, float BallY);
	void ChangeDirectionByPlayer(float NearestX, float NearestY, float BallX, float BallY);
private:

	sf::CircleShape ballShape;
	sf::Vector2f direction;
	float movementSpeed;
};

