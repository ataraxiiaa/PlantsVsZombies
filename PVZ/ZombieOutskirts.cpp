#include "ZombieOutskirts.h"


ZombieOutskirts::ZombieOutskirts() {
	levelTexture.loadFromFile("../Images/Night.png");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(-20, -80);
	levelSprite.setScale(1.22, 1.1);
	this->level = 2;
}