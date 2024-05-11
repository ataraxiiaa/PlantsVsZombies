#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() {

	levelTexture.loadFromFile("../Images/Background3.jpg");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(0, 0);

}
