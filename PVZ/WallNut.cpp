#include "WallNut.h"


WallNut::WallNut()
{
	// Setting up Grapics for Wallnut
	texture.loadFromFile("../Images/pot.png");
	animate = new Animation;
	animate->SetSheet(0.3, 6, texture, 8, 1);
	exists = true;
	this->lives = 10000;
	this->damage = 1000;
	Type = "Wallnut";
}
void WallNut::Action(RenderWindow& window)
{
	MovingPlant();
}