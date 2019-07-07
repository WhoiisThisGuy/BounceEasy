#include "pch.h"
#include "Collider.h"

//két féle collision check van: a labda és téglalap közötti collision detektálása (kör alak téglalap alak),
//valamint téglalap - téglalap alak (a wall és player) detektálása
//utóbbi esetben GameOver true-ra lesz állítva.
//A többi esetben a labda irányt változtat.
//Külön direction change vonatkozik a player - labda közötti ütközés detektálásakor.
//A labdát a player elütheti vízszintesen vagy függõlegesen, a falról csak simán visszapattan a labda.

Collider::Collider()

	:GameOver(false)
{

}

bool Collider::checkCollision(Player& player, Ball& ball, const std::vector<sf::RectangleShape>& borders, std::vector<Wall*>& walls,const float& dt)
{	//Valami rövidebb megoldást kitalálni a túl hosszú kódra, talán külön függvényekbe ellenõrizni az entity-ket?!
	//Kör - téglalap távolság logika
	//Téglalaphoz mely pontja van legközelebb a körhöz
	//és az benne van e a körben (kör középpont -> sugár)

	
	this->CircleX = ball.getShape().getPosition().x;
	this->CircleY = ball.getShape().getPosition().y;
	this->CircleRadius = ball.getShape().getRadius();

	checkPlayerBallCollision(ball, player, dt); //Player és labda ütközés check
	checkBallBorderCollision(ball, borders, dt); //Labda és border (pályaszélek)
	checkBallWallCollision(ball, walls, dt); //labda és a falak (amik mozognak falak)
	checkPlayerWallCollision(player,walls,dt); //player és a mozgó falak, ez állíthatja a GameOvert amit visszadobunk a végén.

	return GameOver;
}

void Collider::checkPlayerBallCollision(Ball& ball,Player& player,const float& dt)
{

	float RectX = player.getShape().getGlobalBounds().left; // player.getShape().getPosition()
	float RectY = player.getShape().getGlobalBounds().top; // player.getShape().getPosition()

	float RectWidth = player.getShape().getGlobalBounds().width;
	float RectHeight = player.getShape().getGlobalBounds().height;

	float NearestX;
	float NearestY;

	float DeltaX;
	float DeltaY;

	NearestX = std::max(RectX, std::min(this->CircleX, RectX + RectWidth));
	NearestY = std::max(RectY, std::min(this->CircleY, RectY + RectHeight));

	DeltaX = this->CircleX - NearestX;
	DeltaY = this->CircleY - NearestY;

	if (collide(DeltaX, DeltaY)) {

		ball.ChangeDirectionByPlayer(NearestX, NearestY, this->CircleX, this->CircleY, dt, player);

	}

}

//Az SFML könyvtár saját "Collision detection"-jét használom, igazából csak két négyszögre megmondja, hogy érintkeznek e.
//Ha érintkeznek gém óver.

void Collider::checkPlayerWallCollision(Player& player, std::vector<Wall*>& walls, const float& dt) /////COLLISION 2 TÉGLALAPRA MEGCSINALNI
{

	sf::Rect<float> PlayerRect;
	sf::Rect<float> WallRect;

	PlayerRect.top = player.getShape().getGlobalBounds().top;
	PlayerRect.height = player.getShape().getGlobalBounds().height;
	PlayerRect.left = player.getShape().getGlobalBounds().left;
	PlayerRect.width = player.getShape().getGlobalBounds().width;


	for (int i = 0; i < walls.size(); i++)
	{
		WallRect.top = walls.at(i)->getShape().getGlobalBounds().top;
		WallRect.height = walls.at(i)->getShape().getGlobalBounds().height;
		WallRect.left = walls.at(i)->getShape().getGlobalBounds().left;
		WallRect.width = walls.at(i)->getShape().getGlobalBounds().width;

		if (PlayerRect.intersects(WallRect)) {
			
			GameOver = true; //VISSZATENNI lul
		
		}
	}

}

void Collider::checkBallWallCollision(Ball& ball, std::vector<Wall*>& walls, const float& dt)
{

	float RectX;
	float RectY;

	float RectWidth;
	float RectHeight;

	float NearestX;
	float NearestY;

	float DeltaX;
	float DeltaY;

	for (int i = 0; i < walls.size(); i++)
	{
		walls.at(i)->getShape().setFillColor(sf::Color::Red);
		RectX = walls.at(i)->getShape().getPosition().x;
		RectY = walls.at(i)->getShape().getPosition().y;

		RectWidth = walls.at(i)->getShape().getGlobalBounds().width;
		RectHeight = walls.at(i)->getShape().getGlobalBounds().height;

		NearestX = std::max(RectX, std::min(this->CircleX, RectX + RectWidth));
		NearestY = std::max(RectY, std::min(this->CircleY, RectY + RectHeight));

		DeltaX = this->CircleX - NearestX;
		DeltaY = this->CircleY - NearestY;

		if (collide(DeltaX, DeltaY)) {
			walls.at(i)->getShape().setFillColor(sf::Color::White);
			ball.ChangeDirection(NearestX, NearestY, this->CircleX, this->CircleY, dt); //Sima direction change van
			walls.at(i)->minus(); //kivonni a hitpointból
			
		}
	}

}

void Collider::checkBallBorderCollision(Ball& ball, const std::vector<sf::RectangleShape>& borders, const float& dt)
{

	float RectX;
	float RectY;

	float RectWidth;
	float RectHeight;

	float NearestX;
	float NearestY;

	float DeltaX;
	float DeltaY;

	for (int i = 0; i < borders.size(); i++)
	{

		RectX = borders.at(i).getPosition().x;
		RectY = borders.at(i).getPosition().y;

		RectWidth = borders.at(i).getGlobalBounds().width;
		RectHeight = borders.at(i).getGlobalBounds().height;

		NearestX = std::max(RectX, std::min(this->CircleX, RectX + RectWidth));
		NearestY = std::max(RectY, std::min(this->CircleY, RectY + RectHeight));

		DeltaX = this->CircleX - NearestX;
		DeltaY = this->CircleY - NearestY;

		if (collide(DeltaX, DeltaY)) {

			ball.ChangeDirection(NearestX, NearestY, this->CircleX, this->CircleY, dt);
		}
	}

}

bool Collider::collide(float DeltaX, float DeltaY)
{

	if ((DeltaX * DeltaX + DeltaY * DeltaY) < (this->CircleRadius * this->CircleRadius)) {

		return true;
	}

	return false;
}
