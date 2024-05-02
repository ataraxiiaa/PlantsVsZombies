#include "WallNut.h"


WallNut::WallNut()
{
	// Setting up Grapics for Wallnut
	texture.loadFromFile("../Images/Wallnut.png");
	animate = new Animation;
	animate->SetSheet(0.15, 3, texture, 5, 1);
	exists = true;
	Coordinates pos(400, 200);
	this->position = pos;
	this->lives = 4;
}
void Action(RenderWindow& window)
{
	// Pass
}