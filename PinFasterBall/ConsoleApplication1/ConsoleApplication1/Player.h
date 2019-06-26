#pragma once

class Player
{

	public:

		Player();
		virtual ~Player();
		
		void update(const float& dt);
		void render(sf::RenderTarget* target);

		const sf::RectangleShape& getShape() { return this->shape; };
		sf::FloatRect getRect() { return this->floatrect; };

	private:
		sf::RectangleShape shape;
		void move(const float& dt, const float dir_x, const float dir_y);
		sf::FloatRect floatrect;
		float movementSpeed;
};

