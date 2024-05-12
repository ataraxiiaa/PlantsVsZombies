#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() {
	//setting background sprite for level
	levelTexture.loadFromFile("../Images/Background3.jpg");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(0, 0);
}
