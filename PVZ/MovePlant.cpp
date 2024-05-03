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