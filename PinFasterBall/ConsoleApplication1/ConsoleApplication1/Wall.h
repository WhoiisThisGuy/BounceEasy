#pragma once
#include "pch.h"	

//switch case-ba fogjuk haszn�lni arra hogy melyik oldalra spawnol
//left = 1, right = 2, top = 3, down = 4
enum spawnSide { left, right, top, down }; 

class Wall {

public:
	//Konstruktor / destruktor
	Wall(sf::Color _color, float _movementSpeed, spawnSide _side,int _hitPoints);
	~Wall() = default;

	void move(const float& dt, const float x, const float y); //mozgatja a k�r alakot (float deltaido (kepkockak frissitese k�z�tt eltelt ido), x ir�ny, y ir�ny)
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	void initWall(spawnSide side); //ez a f�ggv�ny arra szolg�l hogy a megadott side-t�l f�gg�en be�ll�tja a kezd�koordin�t�kat
	                               //side left -> balr�l fog jobbra menni,top-> topr�l lefele stb.


	//Getter / Setter a direction vektor el�r�s�hez
	const sf::Vector2f getDirection() { return this->direction; };
	void setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

	//Getter / Setter a shape-hez
	const sf::RectangleShape getShape() const;

	//Ir�nyv�ltoztat�s ha collision van!
	//void ChangeDirection(float NearestX, float NearestY, float BallX, float BallY, float dt);

private:

	int hitPoints;

	spawnSide side;
	sf::RectangleShape shape;
	sf::Vector2f direction; //a fal ir�nyvektora
	float movementSpeed;


};