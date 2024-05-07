#include "DancingZombie.h"

DancingZombie::DancingZombie() {
	srand((unsigned)time(0));
	rand();
	rand();
	rand();
	this->speed = 0.5;
	this->damage = 5;
	this->texture.loadFromFile("../Images/dancingZombie2.png");
	animate = new Animation;
	animate->SetSheet(0.5, 4, texture, 6, 6);
	this->exists = true;
	this->position.SetX(700);
	this->position.SetY((550 - (rand() % 5) * 110));
	this->type = "dancing";
}