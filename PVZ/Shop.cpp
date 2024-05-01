#include "Shop.h"


Shop::Shop() // Initiallizes every sprite
{
	sprite = new Sprite[6];
	texture = new Texture[6];
	texture[0].loadFromFile("../Images/PeaShooterShop2.png");
	sprite[1].setTexture(texture[0]);
	sprite[1].setTextureRect(sf::IntRect(0, 0, 85, 101));
	sprite[1].setPosition(13, 133);
	texture[1].loadFromFile("../Images/SunFlowerShop2.png");
	sprite[0].setTexture(texture[1]);
	sprite[0].setTextureRect(sf::IntRect(0, 0, 125, 101));
	sprite[0].setPosition(-10, 50);

}
void Shop::DrawShop(sf::RenderWindow& window)
{
	window.draw(sprite[0]); // SunFlower shop image
	window.draw(sprite[1]); // PeaShooter shop image
}