#include "Plants.h"

void Plants::drawPlant(RenderWindow& window)
{
	if (exists)
	{
		animate->Update();
		animate->DrawAnimation(window, this->position);
		window.draw(this->sprite);
	}
}