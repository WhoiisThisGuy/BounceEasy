#pragma once

class Player
{

	public:

		Player();
		virtual ~Player();
		
		void update(const float& dt);
		void render(sf::RenderTarget* target);

		sf::RectangleShape& getShape() { return this->shape; };
		

	private:
		sf::RectangleShape shape;
		void move(const float& dt, const float dir_x, const float dir_y);
		sf::Clock RotateTime;
		float movementSpeed;
};

