#include "FlyingZombie.h"

FlyingZombie::FlyingZombie() {
	srand((unsigned)time(0));
	rand();
	rand();
	this->speed = 0.5;
	this->damage = 5;
	this->lives = 4;
	this->texture.loadFromFile("../Images/bz.png");
	this->animate = new Animation;
	animate->SetSheet(0.5f, 5, texture, 8, 1);
	animate->ChangeScale(3, 3);
	this->exists = true;
	this->position.SetX(700);
	this->position.SetY((550 - (rand() % 5) * 110));
	this->fly = true;
}
void FlyingZombie::moveZombie() {
	if (position.GetX() > 0)
	{
		this->position.SetX(position.GetX() - speed);
	}
}
void FlyingZombie::drawZombie(sf::RenderWindow& window) {
	animate->Update();
	animate->DrawAnimation(window, this->position);
}
void FlyingZombie::action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set) {
	moveZombie();
	drawZombie(window);
}