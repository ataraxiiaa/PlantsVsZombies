#include "Explosive.h"

Explosive::Explosive() {
	// Loading graphics for explosions
	ExplosionTexture.loadFromFile("../Images/boom.png");
	ExplosionSprite.setTexture(ExplosionTexture);
	exists = true;
}
void Explosive::DrawExplosion(RenderWindow& window, Coordinates position) // For drawing explosion and stuff
{
	if(explosionClock.getElapsedTime().asSeconds() <= 3) {
		ExplosionSprite.setPosition(position.GetX(), position.GetY());
		window.draw(ExplosionSprite);
	}
	else {
		exists = false;
	}
}