#include "Repeater.h"

Repeater::Repeater() : Shooter(2) // A repeater would shoot 2 bullets so set that
{
	// Loading up graphics and setting stuff for Repeater
	exists = true;
	this->texture.loadFromFile("../Images/Repeater.png");
	animate = new Animation;
	Coordinates pos(500, 500);
	this->position = pos;
	animate->SetSheet(0.15, 3, texture, 5, 1);
	Type = "Repeater";
	this->damage = 4;
	this->lives = 40;
	this->cost = 200;
}
void Repeater::Action(RenderWindow& window)
{
	Fire(window, this->position,0); // Finding bullets for both bullet index's
	//Fire(window, this->position, 1);
}
