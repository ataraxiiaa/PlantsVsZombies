#include "MovePlant.h"

MovePlant::MovePlant() {
	this->movingSpeed = 5.0f; // Set accordingly
}
void MovePlant::MovingPlant() { //moves plant if it exists
	if (exists) {
		this->position.SetX(this->position.GetX() + this->movingSpeed);
		if (this->position.GetX() >= 1150)
			exists = false;
	}
}
void MovePlant::CheckCollision(Vector<Zombie*>& Zombie, int& killed) { //checks if any zombie is in path. if yes, then kills zombie 
	for (int i = 0; i < Zombie.GetSize() - 1; i++) {
		if (GetPosition().GetX() - Zombie[i]->GetPosition().GetX() >= -50 &&
			GetPosition().GetX() - Zombie[i]->GetPosition().GetX() <= 50 &&
			GetPosition().GetY() - Zombie[i]->GetPosition().GetY() >= -40 &&
			GetPosition().GetY() - Zombie[i]->GetPosition().GetY() <= 40 &&
			this->GetExistence() && Zombie[i]->GetExistance())
		{
			Zombie[i]->setExistence(false);
			Zombie[i]->setLives(0);
			killed++;
			return;
		}
	}
}