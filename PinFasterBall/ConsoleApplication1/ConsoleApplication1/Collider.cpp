#include "pch.h"
#include "Collider.h"

bool Collider::checkCollision(Player& player, Ball& ball, const std::vector<sf::RectangleShape>& borders)
{	//Valami r�videbb megold�st kital�lni, tal�n k�l�n f�ggv�nyekbe ellen�rizni az entity-ket?!
	//K�r - t�glalap t�vols�g logika
	//T�glalaphoz mely pontja van legk�zelebb a k�rh�z
	//�s az benne van e a k�rben (k�r k�z�ppont -> sug�r)

	float CircleRadius = ball.getShape().getRadius(); //Ez lehetne const oszt�lyv�ltoz� de lehet k�s�bb j�t�k k�zbe n�velni akarom akkor �jra lekell k�rni.
	float RectX = player.getShape().getPosition().x;
	float RectY = player.getShape().getPosition().y;

	float RectWidth = player.getShape().getGlobalBounds().width;
	float RectHeight= player.getShape().getGlobalBounds().height;

	float CircleX = ball.getShape().getPosition().x;
	float CircleY = ball.getShape().getPosition().y;

	float NearestX;
	float NearestY;

	float DeltaX;
	float DeltaY;

	NearestX = std::max(RectX, std::min(CircleX, RectX + RectWidth));
	NearestY = std::max(RectY, std::min(CircleY, RectY + RectHeight));

	DeltaX = CircleX - NearestX;
	DeltaY = CircleY - NearestY;

	if (collide(DeltaX, DeltaY, CircleRadius)) {
		
		ball.getShape().setFillColor(sf::Color::Red); //kiszedni csak az�rt van itt hogy l�ssam collision van
		ball.ChangeDirection(NearestX, NearestY, CircleX, CircleY);
		return true;
	}
	

	for (int i = 0; i < borders.size(); i++)
	{
		
		RectX = borders.at(i).getPosition().x;
		RectY = borders.at(i).getPosition().y;

		RectWidth = borders.at(i).getGlobalBounds().width;
		RectHeight = borders.at(i).getGlobalBounds().height;

		NearestX = std::max(RectX, std::min(CircleX, RectX + RectWidth));
		NearestY = std::max(RectY, std::min(CircleY, RectY + RectHeight));

		DeltaX = CircleX - NearestX;
		DeltaY = CircleY - NearestY;

		if (collide(DeltaX, DeltaY, CircleRadius)) {

			ball.getShape().setFillColor(sf::Color::Red); //kiszedni csak az�rt van itt hogy l�ssam collision van
			ball.ChangeDirection(NearestX,NearestY,CircleX,CircleY);
			return true;
		}
	}


	ball.getShape().setFillColor(sf::Color::Cyan); //Csak a villog�s kedv��rt ki lehet szedni

	return false;
}

bool Collider::collide(float DeltaX, float DeltaY, float CircleRadius)
{

	if ((DeltaX * DeltaX + DeltaY * DeltaY) < (CircleRadius * CircleRadius)) {

		return true;
	}

	return false;
}
