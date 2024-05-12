#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	exists = true;
	texture.loadFromFile("../Images/Cherrybomb3.png");
	sprite.setTexture(texture);
	this->scale = 0.0;
	sprite.setScale(scale, scale);
	Type = "CherryBomb";
	this->cost = 150;
}
void CherryBomb::Action(RenderWindow& window) {
	if (this->exists) {
		if (clock.getElapsedTime().asSeconds() >= 0.5) {
			exists = false;
			clock.restart();
		}
		else {
			sprite.setScale(this->scale+=0.03, this->scale+=0.03);
			sprite.setPosition(this->position.GetX(), this->position.GetY());
			window.draw(sprite);
		}
	}
	if(!exists)
		DrawExplosion(window, this->position);
}