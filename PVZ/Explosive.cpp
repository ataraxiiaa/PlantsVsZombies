#include "Explosive.h"

Explosive::Explosive() {
	// Loading graphics for explosions
	ExplosionTexture.loadFromFile("../Images/boom.png");
	ExplosionSprite.setTexture(ExplosionTexture);
	explode = true;
}
void Explosive::DrawExplosion(RenderWindow& window, Coordinates position) // For drawing explosion and stuff
{
	if (explode) {
		if (explosionClock.getElapsedTime().asSeconds() <= 1.2) {
			ExplosionSprite.setPosition(position.GetX(), position.GetY());
			ExplosionSprite.setScale(1, 1);
			window.draw(ExplosionSprite);
		}
		else {
			explode = false;
			explosionClock.restart();
		}
		
	}
}
void Explosive::CheckExplosionCollision(Vector<Zombie*>& Zombie) {
	if (explode) {
		for (int j = 0; j < Zombie.GetSize(); ++j) {
			if (this->position.GetX() - Zombie[j]->GetPosition().GetX() >= -80 &&
				this->position.GetX() - Zombie[j]->GetPosition().GetX() <= 80 &&
				this->position.GetY() == Zombie[j]->GetPosition().GetY() + 100 &&
				Zombie[j]->GetExistance())
			{
				Zombie[j]->setExists(false);
			}
		}
	}
}