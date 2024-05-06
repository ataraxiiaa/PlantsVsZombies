#include "Explosive.h"

Explosive::Explosive() {
	// Loading graphics for explosions
	ExplosionTexture.loadFromFile("../Images/boom.png");
	ExplosionSprite.setTexture(ExplosionTexture);
	

	
}
void Explosive::DrawExplosion(RenderWindow& window, Coordinates position) // For drawing explosion and stuff
{
	ExplosionSprite.setPosition(this->position.GetX(), this->position.GetY());
	window.draw(ExplosionSprite);
}