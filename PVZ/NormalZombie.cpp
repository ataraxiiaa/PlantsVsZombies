#include "NormalZombie.h"

NormalZombie::NormalZombie() {
	srand((unsigned)time(0));
	this->speed = 0.5;
	this->lives = 2;
	this->damage = 0.5;
	this->texture.loadFromFile("../Images/Zombie2.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.4, 5, texture, 7, 1);
	this->exists = true;
	this->position.SetX(1150);
	this->position.SetY(yPositions[rand() % 5]);
}
