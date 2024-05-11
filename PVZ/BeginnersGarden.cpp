#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() : Level(1) {
	//Drawing the background
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("../Images/Background3.jpg");
	Texture map;
	map.loadFromImage(map_image);
	levelSprite.setTexture(map);
	levelSprite.setPosition(0, 0);

}
