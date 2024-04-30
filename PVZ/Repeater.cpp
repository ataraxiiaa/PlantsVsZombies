#include "Repeater.h"

Repeater::Repeater() : Shooter(2)
{
	exists = true;
	this->texture.loadFromFile("../Images/Repeater.png");
	animate = new Animation;
	Coordinates pos(500, 500);
	this->position = pos;
	animate->SetSheet(0.15, 3, texture, 5, 1);
}
void Repeater::action(RenderWindow& window)
{
	Fire(window, this->position,0);
	Fire(window, this->position, 1);
}
void Repeater::DrawRepeater(RenderWindow& window)
{
	if (exists) {
		this->action(window);
		animate->Update();
		animate->DrawAnimation(window, this->position);
	}
}