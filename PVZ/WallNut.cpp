#include "WallNut.h"


WallNut::WallNut()
{
	// Setting up Grapics for Wallnut
	texture.loadFromFile("../Images/pot.png");
	animate = new Animation;
	animate->SetSheet(0.3, 6, texture, 8, 1);
	exists = true;
	Coordinates pos(400, 200);
	this->position = pos;
	this->lives = 4;
}
void WallNut:: Action(RenderWindow& window)
{
	MovingPlant();
}