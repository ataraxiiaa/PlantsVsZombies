#include "Shop.h"


Shop::Shop() // Initiallizes every sprite
{
	elements = 1;
	sprite = new Sprite[7]; // Adding sprites
	texture = new Texture[7]; // Adding textures
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
	// Wall nut
	texture[2].loadFromFile("../Images/potshape.png");
	sprite[2].setTexture(texture[2]);
	sprite[2].setTextureRect(sf::IntRect(0, 0, 94, 95));
	sprite[2].setPosition(8, 210);
	selectedSprite.push_back(sprite[2]);
	selectedSprite.back().setTextureRect(sf::IntRect(94, 0, 187, 95));
	shopSprite.push_back(sprite[2]);
	// CherryBomb
	texture[3].loadFromFile("../Images/CherryBombShop.png");
	sprite[3].setTexture(texture[3]);
	sprite[3].setTextureRect(sf::IntRect(0, 0, 75, 100));
	sprite[3].setPosition(15, 280);
	sprite[3].setScale(1.1, 1.1);
	selectedSprite.push_back(sprite[3]);
	selectedSprite.back().setTextureRect(sf::IntRect(82, 0, 160, 100));
	selectedSprite.back().setPosition(15, 280);
	selectedSprite.back().setScale(1.1, 1.1);
	// Repeater
	texture[4].loadFromFile("../Images/RepeaterShop.png");
	sprite[4].setTexture(texture[4]);
	sprite[4].setTextureRect(sf::IntRect(0, 0, 100, 101));
	sprite[4].setPosition(5, 400);
	selectedSprite.push_back(sprite[4]);
	selectedSprite.back().setTextureRect(sf::IntRect(100, 0, 200, 84));
	selectedSprite.back().setPosition(13, 400);
	// Snowpea
	texture[5].loadFromFile("../Images/snowPeaShop.png");
	sprite[5].setTexture(texture[5]);
	sprite[5].setTextureRect(sf::IntRect(0, 0, 120, 101));
	sprite[5].setPosition(13, 480);
	sprite[5].setScale(0.8, 0.8);
	selectedSprite.push_back(sprite[5]);
	selectedSprite.back().setTextureRect(sf::IntRect(120, 0, 240, 101));
	selectedSprite.back().setPosition(13, 480);
	selectedSprite.back().setScale(0.8, 0.8);
	// Fumeshroom
	texture[6].loadFromFile("../Images/fumeshroomshop.png");
	sprite[6].setTexture(texture[6]);
	sprite[6].setTextureRect(sf::IntRect(0, 0, 110, 101));
	sprite[6].setPosition(18, 560);
	sprite[6].setScale(0.8, 0.8);
	selectedSprite.push_back(sprite[6]);
	selectedSprite.back().setTextureRect(sf::IntRect(110, 0, 220, 101));
	selectedSprite.back().setPosition(18, 560);
	selectedSprite.back().setScale(0.8, 0.8);
	// Setting up ID pointer to keep track of what item to set 
	ids = new string[7];
	ids[0] = "sunflower";
	ids[1] = "peashooter";
	ids[2] = "wallnut";
	ids[3] = "cherrybomb";
	ids[4] = "repeater";
	ids[5] = "snowpea";
	ids[6] = "fume";
	
}
void Shop::DrawShop(sf::RenderWindow& window)
{
	for (int i = 0; i < this->elements && i < 7; i++) {
		window.draw(sprite[i]); // SunFlower shop image
	}
}
void Shop::setShop(int level)
{
	this->elements = level+1; //displays new plants available in new round
}