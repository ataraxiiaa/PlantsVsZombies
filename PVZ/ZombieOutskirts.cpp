#include "ZombieOutskirts.h"


ZombieOutskirts::ZombieOutskirts():Level(2) {
	levelTexture.loadFromFile("../Images/Night.png");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(-20, -80);
	levelSprite.setScale(1.22, 1.1);
}