#include "Plants.h"

void Plants::drawPlant(RenderWindow& window)
{
	this->sprite.setPosition(this->position.GetX(), this->position.GetY());
	window.draw(this->sprite);
}