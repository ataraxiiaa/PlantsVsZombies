#include "Sun.h"
#include <iostream>
Sun::Sun()
{
	// Setting Graphics For Sun
	sunTexture.loadFromFile("../Images/Sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(sf::IntRect(0, 0, 75, 77));
	// Handling Movement of Sun
	this->position.SetY(0); // Start from the top of the screen
	srand(time(0));
	int RandomNum = rand() % 700 + 200;
	this->position.SetX(RandomNum);
	exist = true;
	fallSpeed = 5.0f;
}
void Sun::DrawSun(sf::RenderWindow& window)
{
	if (exist) {
		CollectSun(window);
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
void Sun::CollectSun(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::FloatRect sunBounds(position.GetX(), position.GetY(),75,77);
		// IDk what to do with this 
		// will need a discussion on this leaving it just like this for now
		if (sunBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			exist = false;
		}
	}
}
