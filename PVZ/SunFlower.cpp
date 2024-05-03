#include "SunFlower.h"


SunFlower::SunFlower()
{
	this->exists = true;
	this->coolDown = 10;
	this->cost = 50;
	this->texture.loadFromFile("../Images/SunFlower.png");
	animate = new Animation;
	this->position.SetX(310);
	this->position.SetY(127.5);
	//	animate->SetSheet(0.125, 6, texture, 8, 1);
	animate->SetSheet(0.125, 5, texture, 6, 1);
}
void SunFlower::drawPlant(sf::RenderWindow& window)
{
	if (exists) {
		Plants::drawPlant(window);
	}
}
void SunFlower::ProduceSun(RenderWindow& window,Sun sun) {
	sun.SetPosition(this->position);
	//sun.DrawSun();
}
void SunFlower::Action(RenderWindow& window)
{
	// Pass
}