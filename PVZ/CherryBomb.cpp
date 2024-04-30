#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	exists = true;
	texture.loadFromFile("../Images/CherryBomb.png");
	sprite.setTexture(texture);
	animate = new Animation;
	animate->SetSheet(0.2, 4, texture, 4, 1);
	Coordinates pos(500, 500);
	this->position = pos;
}
void CherryBomb::DrawCherryBomb(RenderWindow& window) {
	if (exists) {
		if (animate->GetCurrFrame() <= 6) { 
			animate->Update(true);
			animate->DrawAnimation(window, position);
		}
	}
	if (animate->GetCurrFrame() >= 6) {
		DrawExplosion(window, this->position);
		exists = false;
	}

}