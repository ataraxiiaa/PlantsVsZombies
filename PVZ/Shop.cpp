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
	// Repeater
	texture[2].loadFromFile("../Images/RepeaterShop.png");
	sprite[2].setTexture(texture[2]);
	sprite[2].setTextureRect(sf::IntRect(0, 0, 100, 101));
	sprite[2].setPosition(5, 240);
	selectedSprite.push_back(sprite[2]);
	selectedSprite.back().setTextureRect(sf::IntRect(100, 0, 200, 84));
	selectedSprite.back().setPosition(13, 240);
	// CherryBomb
	texture[4].loadFromFile("../Images/CherryBombShop.png");
	sprite[4].setTexture(texture[4]);
	sprite[4].setTextureRect(sf::IntRect(0, 0, 75, 100));
	sprite[4].setPosition(15, 300);
	selectedSprite.push_back(sprite[4]);
	selectedSprite.back().setTextureRect(sf::IntRect(82, 0, 160, 100));
	selectedSprite.back().setPosition(20, 300);
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
	window.draw(sprite[2]); // Repeater
	window.draw(sprite[4]);
}