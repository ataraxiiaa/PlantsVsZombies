#include "FootballZombie.h"

FootballZombie::FootballZombie() {
	srand((unsigned)time(0));
	rand();
	this->exists = true;
	this->speed = 3;
	this->damage = 0.5;
	this->lives = 4;
	this->texture.loadFromFile("../Images/FBZ.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.125, 6, texture, 8, 1);
	this->animate->ChangeScale(1.25, 1.25);
	//Coordinates pos(700, 350);
	//this->position = pos;
}
void FootballZombie::drawZombie(sf::RenderWindow& window) {
	if (exists) {
		this->animate->Update();
		this->animate->DrawAnimation(window,this->position);
	}

}