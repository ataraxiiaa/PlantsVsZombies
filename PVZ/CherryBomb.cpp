#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	exists = true;
	texture.loadFromFile("../Images/Cherrybomb3.png");
	sprite.setTexture(texture);
	Type = "CherryBomb";
}
void CherryBomb::Action(RenderWindow& window) {
	if (this->exists) {
		if (clock.getElapsedTime().asSeconds() >= 3) {
			DrawExplosion(window, this->position);
			exists = false;
			clock.restart();
		}
		else {
			sprite.setPosition(this->position.GetX(), this->position.GetY());
			window.draw(sprite);
			//clock.restart();
		}
	}
}