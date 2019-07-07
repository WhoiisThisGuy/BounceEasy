#include "pch.h"
#include "Collider.h"

//k�t f�le collision check van: a labda �s t�glalap k�z�tti collision detekt�l�sa (k�r alak t�glalap alak),
//valamint t�glalap - t�glalap alak (a wall �s player) detekt�l�sa
//ut�bbi esetben GameOver true-ra lesz �ll�tva.
//A t�bbi esetben a labda ir�nyt v�ltoztat.
//K�l�n direction change vonatkozik a player - labda k�z�tti �tk�z�s detekt�l�sakor.
//A labd�t a player el�theti v�zszintesen vagy f�gg�legesen, a falr�l csak sim�n visszapattan a labda.

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
	checkPlayerWallCollision(player,walls,dt); //player �s a mozg� falak, ez �ll�thatja a GameOvert amit visszadobunk a v�g�n.

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

//Az SFML k�nyvt�r saj�t "Collision detection"-j�t haszn�lom, igaz�b�l csak k�t n�gysz�gre megmondja, hogy �rintkeznek e.
//Ha �rintkeznek g�m �ver.

void Collider::checkPlayerWallCollision(Player& player, std::vector<Wall*>& walls, const float& dt) /////COLLISION 2 T�GLALAPRA MEGCSINALNI
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
			walls.at(i)->minus(); //kivonni a hitpointb�l
			
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
