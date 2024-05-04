#include "Shop.h"


Shop::Shop() // Initiallizes every sprite
{

	sprite = new Sprite[6]; // Adding sprites
	texture = new Texture[6]; // Adding textures
	// Sunflower
	texture[0].loadFromFile("../Images/SunFlowerShop2.png");
	sprite[0].setTexture(texture[0]);
	sprite[0].setTextureRect(sf::IntRect(0, 0, 114, 101));
	selectedSprite.push_back(sprite[0]);
	selectedSprite.back().setTextureRect(sf::IntRect(114, 0, 228, 101));
	selectedSprite.back().setPosition(20, 50);
	sprite[0].setPosition(-10, 50);
	// PeaShooter
	texture[1].loadFromFile("../Images/PeaShooterShop2.png"); // Peashooter sprite sheet
	sprite[1].setTexture(texture[1]);
	sprite[1].setTextureRect(sf::IntRect(0, 0, 85, 101));
	sprite[1].setPosition(13, 133);
	selectedSprite.push_back(sprite[1]);
	selectedSprite.back().setTextureRect(sf::IntRect(85, 0, 170, 101));

	// Setting up ID pointer to keep track of what item to set 
	ids = new string[6];
	ids[0] = "sunflower";
	ids[1] = "peashooter";
	ids[2] = "repeater";
	ids[3] = "wallnut";
	ids[4] = "cherrybomb";
	ids[5] = "snowpea";
}
void Shop::DrawShop(sf::RenderWindow& window)
{
	window.draw(sprite[0]); // SunFlower shop image
	window.draw(sprite[1]); // PeaShooter shop image
}