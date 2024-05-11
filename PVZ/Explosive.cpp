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
			ExplosionPosition.SetX(position.GetX());
			ExplosionPosition.SetY(position.GetY());
			window.draw(ExplosionSprite);
		}
		else {
			explode = false;
			explosionClock.restart();
		}
		
	}
}
void Explosive::CheckExplosionCollision(Vector<Zombie*>& Zombie, int& killed) {
	if (explode) {
		for (int j = 0; j < Zombie.GetSize(); ++j) {
			if (ExplosionPosition.GetX() - Zombie[j]->GetPosition().GetX() >= -150 &&
				ExplosionPosition.GetX() - Zombie[j]->GetPosition().GetX() <= 150 &&
				ExplosionPosition.GetY() - Zombie[j]->GetPosition().GetY() >= -150 &&
				ExplosionPosition.GetY() - Zombie[j]->GetPosition().GetY() <= 150 &&
				Zombie[j]->GetExistance())
			{
				killed++;
				Zombie[j]->setExists(false);
				Zombie.Destroy(j);
				cout << "zombie destroyed" << endl;
			}
		}
	}
}