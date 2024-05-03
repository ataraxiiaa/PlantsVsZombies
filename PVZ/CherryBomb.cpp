#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	exists = true;
	texture.loadFromFile("../Images/CherryBomb2.png");
	sprite.setTexture(texture);
	animate = new Animation;
	animate->SetSheet(0.2, 6, texture, 6, 1);
	Coordinates pos(500, 500);
	this->position = pos;
}
void CherryBomb::Action(RenderWindow& window, int& money) {
	// Pass
}