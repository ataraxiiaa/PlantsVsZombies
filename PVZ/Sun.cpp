#include "Sun.h"
#include <iostream>
Sun::Sun()
{
	// Setting up Sun graphics to represent amount
	sunTextureShop.loadFromFile("../Images/button2.png");
	sunSpriteShop.setTexture(sunTextureShop);
	sunSpriteShop.setPosition(80, 5);
	// Setting Graphics For Sun
	sunTexture.loadFromFile("../Images/Sun.png");
	sunTexture2.loadFromFile("../Images/Sun2.png");
	sunSprite2.setTexture(sunTexture2);
	sunSprite2.setPosition(90, 17);
	sunSprite2.setTextureRect(sf::IntRect(0, 0, 75, 77));
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(sf::IntRect(0, 0, 75, 77));
	exist = false;
	fallSpeed = 5.0f; // Speed by which sun falls down the screen
	stopProduction = false;
}
void Sun::DrawSun(sf::RenderWindow& window, int& money)
{
	if (!stopProduction) {
		srand(time(0));
		int randomTime = rand() % 30 + 10; // Set accordingly 
		if (clock.getElapsedTime().asSeconds() >= 10 && !exist) {
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
	// Drawing Sun at the shop
	window.draw(sunSprite2);
	window.draw(sunSpriteShop);
}

void Sun::DrawSun(RenderWindow& window)
{
	if (this->exist && !stopProduction) {
		this->sunSprite.setPosition(this->position.GetX(), this->position.GetY());
		window.draw(sunSprite);
	}
}
void Sun::DropSun()
{
	if (exist && !stopProduction) {
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
		if (sunBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) //checks if sun sprite is clicked
		{
			exist = false;
			money += 25;
		}
	}
	if (autoCollect) //autocollects sun
		if (position.GetY() > 200)
		{
			exist = false;
			money += 25;
		}
}
