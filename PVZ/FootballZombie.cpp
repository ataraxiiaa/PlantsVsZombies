#include "FootballZombie.h"

FootballZombie::FootballZombie() {
	srand((unsigned)time(0));
	rand();
	this->exists = true;
	this->speed = 10;
	this->damage = 5;
	this->texture.loadFromFile("../Images/FBZ.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.125, 6, texture, 8, 1);
	//Coordinates pos(700, 350);
	//this->position = pos;
}
void FootballZombie::drawZombie(sf::RenderWindow& window) {
	if (exists) {
		this->animate->Update();
		this->animate->DrawAnimation(window,this->position);
	}

}