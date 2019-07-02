#pragma once

class Ball
{
public:

	//Konstruktor / destruktor
	Ball();
	~Ball() = default;

	void move(const float& dt, const float x, const float y); //mozgatja a kör alakot (float deltaido (kepkockak frissitese között eltelt ido), x irány, y irány)
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	sf::CircleShape& getShape() { return this->ballShape; }; //Konstanst vissza rakni

	//Getter / Setter a direction vektor eléréséhez
	const sf::Vector2f getDirection() { return this->direction; };
	void setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

	//Irányváltoztatás ha collision van!
	void ChangeDirection(float NearestX,float NearestY, float BallX, float BallY,float dt);
	void ChangeDirectionByPlayer(float NearestX, float NearestY, float BallX, float BallY);
	void ChangeDriectionV2(float NearestX, float NearestY, float RectTop, float RectLeft,float dt);
private:

	sf::CircleShape ballShape; //maga a köralakzat
	sf::Vector2f direction; //a labda irányvektora
	float movementSpeed;
};

