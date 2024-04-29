#include "Sun.h"
#include <iostream>
Sun::Sun()
{
	// Setting Graphics For Sun
	sunTexture.loadFromFile("../Images/Sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(sf::IntRect(0, 0, 75, 77));
	exist = false;
	fallSpeed = 5.0f; // Speed by which sun falls down the screen
}
void Sun::DrawSun(sf::RenderWindow& window, int& money)
{
	srand(time(0));
	int randomTime = rand() % 5 + 1; // Set accordingly 
	if (clock.getElapsedTime().asSeconds() >= randomTime) {
		this->exist = true;
		// Handling random movement of position
		this->position.SetY(0);
		int RandomNum = rand() % 700 + 200; // Random number to decide where on the screen sun drops
		this->position.SetX(RandomNum);
		clock.restart();
	}

	if (exist) {
		CollectSun(window, money);
		sunSprite.setPosition(this->position.GetX(), this->position.GetY());
		if (this->exist)
			window.draw(sunSprite); // Drawing Sun
		DropSun();
	}
}
void Sun::DropSun()
{
	if (exist) {
		this->position.SetY(this->position.GetY() + fallSpeed);
		if (this->position.GetY() > 1100)
				exist = false;
	}
}
void Sun::CollectSun(sf::RenderWindow& window, int& money)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::FloatRect sunBounds(position.GetX(), position.GetY(),75,77);
		// IDk what to do with this 
		// will need a discussion on this leaving it just like this for now
		if (sunBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			exist = false;
			money += 25;
		}
	}
}
