#include "NormalZombie.h"

NormalZombie::NormalZombie() {
	this->speed = 0.5;
	this->lives = 8;
	this->damage = 1;
	this->texture.loadFromFile("../Images/Zombie2.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.4, 5, texture, 7, 1);
	this->exists = true;
	this->type = "normal";
}
