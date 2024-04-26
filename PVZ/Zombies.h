#pragma once
#include "Entity.h"

class Zombie : public Entity {
protected:
	float damage;
	float speed;
public:
	float getDamage() { return this->damage; }
	float getSpeed() { return this->speed; }
	void setDamage(float damage) { this->damage = damage; }
	void setSpeed(float speed) { this->speed = speed; }
	void moveZombie()
	{
		if (position.GetX() > 0)
		{
			this->position.SetX(position.GetX() - 5);
		}
	}
};