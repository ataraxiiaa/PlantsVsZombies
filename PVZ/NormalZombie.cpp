#include "NormalZombie.h"

NormalZombie::NormalZombie() {
	srand((unsigned)time(0));
	this->speed = 2;
	this->damage = 5;
	this->texture.loadFromFile("../Images/Zombie2.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.125, 5, texture, 7, 1);
	this->exists = true;
	this->position.SetX(1150);
	this->position.SetY((550 - (rand() % 5) * 110));

}