#pragma once

class Ball
{
public:
	Ball();

	virtual ~Ball();

	void move(const float& dt, const float x, const float y);

	void update(const float& dt, const float x, const float y);
	void render(sf::RenderTarget* target);
	const sf::CircleShape& getShape() { return this->ballShape; };

private:
	sf::CircleShape ballShape;
	float movementSpeed;
};

