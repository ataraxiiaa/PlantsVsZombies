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
}
void WallNut::DrawWallNut(RenderWindow& window)
{
	if (exists)
	{
		animate->Update();
		animate->DrawAnimation(window, this->position);
	}
}