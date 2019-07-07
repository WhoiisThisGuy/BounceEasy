#pragma once
#include "pch.h"	

//switch case-ba fogjuk használni arra hogy melyik oldalra spawnol
//left = 1, right = 2, top = 3, down = 4
enum SpawnSide { left, right, top, down }; 
enum WallState {dead,alive};

class Wall {

public:
	//Konstruktor / destruktor
	Wall(sf::Color _color, float _movementSpeed, SpawnSide _side,int _hitPoints);
	~Wall() = default;

	void move(const float& dt, const float x, const float y); //mozgatja a kör alakot (float deltaido (kepkockak frissitese között eltelt ido), x irány, y irány)
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	void initWall(SpawnSide side); //ez a függvény arra szolgál hogy a megadott side-tól függõen beállítja a kezdõkoordinátákat
	                               //side left -> balról fog jobbra menni,top-> topról lefele stb.


	//Getter / Setter a direction vektor eléréséhez
	const sf::Vector2f getDirection() { return this->direction; };
	void setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

	//Getter / Setter a shape-hez
	sf::RectangleShape& getShape();

	//hitpoint minusz

	void minus();

	//Getter Setter a wallstate-hez

	const WallState& getWallState() const { return this->wstate; };
	void setWallState(WallState newstate) { this->wstate = newstate; };

private:

	int hitPoints;
	WallState wstate;
	SpawnSide side;
	sf::RectangleShape shape;
	sf::Vector2f direction; //a fal irányvektora
	float movementSpeed;


};