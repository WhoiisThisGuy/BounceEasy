#include "pch.h"
#include "Collider.h"

void Collider::checkCollision(Player& player, Ball& ball, const std::vector<sf::RectangleShape>& borders,float dt)
{	//Valami rövidebb megoldást kitalálni a túl hosszú kódra, talán külön függvényekbe ellenõrizni az entity-ket?!
	//Kör - téglalap távolság logika
	//Téglalaphoz mely pontja van legközelebb a körhöz
	//és az benne van e a körben (kör középpont -> sugár)

	float CircleRadius = ball.getShape().getRadius(); //Ez lehetne const osztályváltozó de lehet késõbb játék közbe növelni akarom akkor újra lekell kérni.
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

		ball.getShape().setFillColor(sf::Color::Red);//kiszedni csak azért van itt hogy lássam collision van
		
		ball.ChangeDirection(NearestX, NearestY, CircleX, CircleY,dt);

		//return true;
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
			
			ball.getShape().setFillColor(sf::Color::Red); //kiszedni csak azért van itt hogy lássam collision van
			ball.ChangeDirection(NearestX,NearestY,CircleX,CircleY,dt);
		}
	}

	ball.getShape().setFillColor(sf::Color::Cyan); //kiszedni csak azért van itt hogy lássam nincs collision

}

bool Collider::collide(float DeltaX, float DeltaY, float CircleRadius)
{

	if ((DeltaX * DeltaX + DeltaY * DeltaY) < (CircleRadius * CircleRadius)) {

		return true;
	}

	return false;
}
