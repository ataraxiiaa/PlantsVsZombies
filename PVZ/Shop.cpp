#include "Shop.h"


Shop::Shop() // Initiallizes every sprite
{
	sprite = new Sprite[6];
	texture = new Texture[6];
	texture[0].loadFromFile("../Images/PeaShooterShop2.png");
	peaShooter_S.setTexture(texture[0]);
	texture[1].loadFromFile("../Images/SunFlowerShop2.png");
	sunFlower_S.setTexture(texture[1]);
	sunFlower_S.setTextureRect(sf::IntRect(0, 0, 125, 101));
	sunFlower_S.setPosition(-10, 50);
	peaShooter_S.setTextureRect(sf::IntRect(85, 0, 166, 101));
	peaShooter_S.setPosition(13, 133);

}
void Shop::DrawShop(sf::RenderWindow& window)
{
	window.draw(sunFlower_S);
	window.draw(peaShooter_S);
}