#include "MovePlant.h"

MovePlant::MovePlant() {
	this->movingSpeed = 5.0f; // Set accordingly
}
void MovePlant::MovingPlant() {
	if (exists) {
		this->position.SetX(this->position.GetX() + this->movingSpeed);
		if (this->position.GetX() >= 1150)
			exists = false;
	}
}
void MovePlant::CheckCollision(Vector<Zombie*>& Zombie, int& killed) {
	if (GetPosition().GetX() - Zombie[i]->GetPosition().GetX() >= -50 &&
		GetPosition().GetX() - Zombie[i]->GetPosition().GetX() <= 50 &&
		GetPosition().GetY() - Zombie[i]->GetPosition().GetY() >= -40 &&
		GetPosition().GetY() - Zombie[i]->GetPosition().GetY() <= 40 &&
		this->GetExistence())
	{
		cout << killed << endl;
		Zombie[i]->setExistence(false);
		Zombie[i]->setLives(0);
		killed++;
		cout << killed << endl;
	}
}