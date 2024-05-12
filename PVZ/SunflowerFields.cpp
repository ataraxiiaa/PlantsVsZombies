#include "SunflowerFields.h"


SunflowerFields::SunflowerFields() {
	levelTexture.loadFromFile("../Images/level3.jpg");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(0, -10);
	levelSprite.setScale(1.22, 1.3);
	this->level = 3;
}
