#include "Shop.h"


Shop::Shop() // Initiallizes every sprite
{
	elements = 1;
	sprite = new Sprite[6]; // Adding sprites
	texture = new Texture[6]; // Adding textures
	// Repeater
	//texture[2].loadFromFile("../Images/RepeaterShop.png");
	//sprite[2].setTexture(texture[2]);
	//sprite[2].setTextureRect(sf::IntRect(0, 0, 100, 101));
	//sprite[2].setPosition(5, 240);
	//selectedSprite.push_back(sprite[2]);
	//selectedSprite.back().setTextureRect(sf::IntRect(100, 0, 200, 84));
	//selectedSprite.back().setPosition(13, 240);
	// CherryBomb
	//texture[3].loadFromFile("../Images/CherryBombShop.png");
	//sprite[3].setTexture(texture[4]);
	//sprite[3].setTextureRect(sf::IntRect(0, 0, 75, 100));
	//sprite[3].setPosition(15, 300);
	//selectedSprite.push_back(sprite[3]);
	//selectedSprite.back().setTextureRect(sf::IntRect(82, 0, 160, 100));
	//selectedSprite.back().setPosition(20, 300);
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
	for (int i=0; i<shopSprite.getCurr(); i++)
		window.draw(shopSprite[i]); // SunFlower shop image
}

void Shop::setShop(int level)
{
	if (level == 1) {
		// Sunflower
		texture[0].loadFromFile("../Images/SunFlowerShop2.png");
		sprite[0].setTexture(texture[0]);
		sprite[0].setTextureRect(sf::IntRect(0, 0, 114, 101));
		selectedSprite.push_back(sprite[0]);
		selectedSprite.back().setTextureRect(sf::IntRect(114, 0, 228, 101));
		selectedSprite.back().setPosition(20, 50);
		sprite[0].setPosition(-10, 50);
		shopSprite.push_back(sprite[0]);
		// PeaShooter
		texture[1].loadFromFile("../Images/PeaShooterShop2.png"); // Peashooter sprite sheet
		sprite[1].setTexture(texture[1]);
		sprite[1].setTextureRect(sf::IntRect(0, 0, 85, 101));
		sprite[1].setPosition(13, 133);
		selectedSprite.push_back(sprite[1]);
		selectedSprite.back().setTextureRect(sf::IntRect(85, 0, 170, 101));
		shopSprite.push_back(sprite[1]);

		elements = 2;
	}
}