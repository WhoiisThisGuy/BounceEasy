#include "pch.h"
#include "Collider.h"

Collider::Collider()

	:GameOver(false)
{

}

bool Collider::checkCollision(Player& player, Ball& ball, const std::vector<sf::RectangleShape>& borders, std::vector<Wall*>& walls,const float& dt)
{	//Valami r�videbb megold�st kital�lni a t�l hossz� k�dra, tal�n k�l�n f�ggv�nyekbe ellen�rizni az entity-ket?!
	//K�r - t�glalap t�vols�g logika
	//T�glalaphoz mely pontja van legk�zelebb a k�rh�z
	//�s az benne van e a k�rben (k�r k�z�ppont -> sug�r)

	
	this->CircleX = ball.getShape().getPosition().x;
	this->CircleY = ball.getShape().getPosition().y;
	this->CircleRadius = ball.getShape().getRadius();

	checkPlayerBallCollision(ball, player, dt); //Player �s labda �tk�z�s check
	checkBallBorderCollision(ball, borders, dt); //Labda �s border (p�lyasz�lek)
	checkBallWallCollision(ball, walls, dt); //labda �s a falak (amik mozognak falak)
	checkPlayerWallCollision(player,walls,dt);

	return GameOver;
}

void Collider::checkPlayerBallCollision(Ball& ball,Player& player,const float& dt)
{

	float RectX = player.getShape().getPosition().x;
	float RectY = player.getShape().getPosition().y;

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

void Collider::checkPlayerWallCollision(Player& player, std::vector<Wall*>& walls, const float& dt) /////COLLISION 2 T�GLALAPRA MEGCSINALNI
{
	sf::Vector2f PlayerPosition;
	sf::Vector2f PlayerHalfSize;
	sf::Vector2f wallPosition;
	sf::Vector2f wallHalfSize;

	float DeltaX;
	float DeltaY;

	float intersectX;
	float intersectY;

	for (int i = 0; i < walls.size(); i++)
	{
		
		PlayerPosition = player.getShape().getPosition();
		PlayerHalfSize = player.getShape().getSize()/2.0f;
		wallPosition = walls.at(i)->getShape().getPosition();
		wallHalfSize = walls.at(i)->getShape().getSize() / 2.0f;

		DeltaX = wallPosition.x - PlayerPosition.x;
		DeltaY = wallPosition.y - PlayerPosition.y;

		intersectX = abs(DeltaX) - (PlayerHalfSize.x + wallHalfSize.x);
		intersectY = abs(DeltaY) - (PlayerHalfSize.y + wallHalfSize.y);

		if (intersectX < -4.0f && intersectY < -4.0f) { //egym�sba van a k�t object , gg end

			GameOver = true;
			
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
		
		RectX = walls.at(i)->getShape().getPosition().x;
		RectY = walls.at(i)->getShape().getPosition().y;

		RectWidth = walls.at(i)->getShape().getGlobalBounds().width;
		RectHeight = walls.at(i)->getShape().getGlobalBounds().height;

		NearestX = std::max(RectX, std::min(this->CircleX, RectX + RectWidth));
		NearestY = std::max(RectY, std::min(this->CircleY, RectY + RectHeight));

		DeltaX = this->CircleX - NearestX;
		DeltaY = this->CircleY - NearestY;

		if (collide(DeltaX, DeltaY)) {

			ball.ChangeDirection(NearestX, NearestY, this->CircleX, this->CircleY, dt);
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
