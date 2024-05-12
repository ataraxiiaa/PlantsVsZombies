#include "Plants.h"

void Plants::drawPlant(RenderWindow& window) //draws plant if it exists
{
	if (exists)
	{
		animate->Update();
		animate->DrawAnimation(window, this->position);
		window.draw(this->sprite);
	}
}