#include "Plants.h"

void Plants::drawPlant(RenderWindow& window)
{
	if (exists)
	{
		this->sprite.setPosition(this->position.GetX(), this->position.GetY());
		window.draw(this->sprite);
	}
}