#include "SunFlower.h"


SunFlower::SunFlower()
{
	this->exists = true;
	this->coolDown = 10;
	this->cost = 50;
	this->texture.loadFromFile("../Images/SunFlower.png");
	animate = new Animation;
	//	animate->SetSheet(0.125, 6, texture, 8, 1);
	animate->SetSheet(0.125, 5, texture, 6, 1);
}
void SunFlower::drawPlant(sf::RenderWindow& window)
{
	if (exists) {
		animate->Update();
		animate->DrawAnimation(window, this->position);
	}
}