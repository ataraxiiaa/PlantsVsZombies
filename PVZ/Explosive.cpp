#include "Explosive.h"

Explosive::Explosive() {
	// Loading graphics for explosions
	ExplosionTexture.loadFromFile("../Images/Explosion.png");
	
	animate = new Animation;
	animate->SetSheet(0.1, 8, ExplosionTexture, 8, 1);
	
	explode = false;
}
void Explosive::DrawExplosion(RenderWindow& window, Coordinates position) // For drawing explosion and stuff
{
	explode = true;
	if (explode) { // Handling how explosionw would work
		this->position = position;
		if (animate->GetCurrFrame() <= 4) {
			animate->Update(true); // Handling animatiosn
			animate->DrawAnimation(window, position);
		}
		explode = false;
	}
}