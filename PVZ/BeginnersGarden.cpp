#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() {
	//Drawing the background
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("../Images/Background3.jpg");
	Texture map;
	map.loadFromImage(map_image);
	levelSprite.setTexture(map);
	levelSprite.setPosition(0, 0);

}
