#include "FlyingZombie.h"

FlyingZombie::FlyingZombie() {
	this->speed = 0.6;
	this->damage = 1;
	this->lives = 8;
	this->texture.loadFromFile("../Images/bz.png");
	this->animate = new Animation;
	animate->SetSheet(0.5f, 5, texture, 8, 1);
	animate->ChangeScale(3, 3);
	this->exists = true;
	this->fly = true;
	this->type = "flying";
}
void FlyingZombie::moveZombie() {
	if (position.GetX() > 0)
	{
		this->position.SetX(position.GetX() - speed); //moves zombie irrespective of if any plant is infront of it
	}
}
void FlyingZombie::drawZombie(sf::RenderWindow& window) {
	animate->Update();
	animate->DrawAnimation(window, this->position);
}
void FlyingZombie::action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set) {
	if (exists) {
		moveZombie();
		drawZombie(window);
	}
}