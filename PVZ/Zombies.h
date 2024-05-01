#pragma once
#include "Entity.h"
#include "Plants.h"

class Zombie : public Entity {
protected:
	float damage;
	float speed;
public:
	float getDamage() { return this->damage; }
	float getSpeed() { return this->speed; }
	void setDamage(float damage) { this->damage = damage; }
	void setSpeed(float speed) { this->speed = speed; }
	bool checkIfPlantAhead(Plants**& plant)
	{
		for (int i = 0; i < 45 && plant[i] != NULL; i++)
		{
			if (this->position.GetX() - 50 == plant[i]->GetX() && this->position.GetY() == plant[i]->GetY() && plant[i]->GetExistence())
				return true;
			else
				return false;
		}
	}
	void doDamage(Plants** ptr)
	{
		for (int i = 0; i < 45 && ptr[i] != NULL; i++)
		{
			if (ptr[i]->GetLives() > 0)
				ptr[i]->SetLives(ptr[i]->GetLives() - 0.1);
			else
				ptr[i]->SetExistence(false);
		}
	}
	virtual void moveZombie(Plants**& ptr)
	{
		if (!checkIfPlantAhead(ptr))
		{
			if (position.GetX() > 0)
			{
				this->position.SetX(position.GetX() - speed);
			}
		}
		else
			doDamage(ptr);
	}
	void drawZombie(sf::RenderWindow& window)
	{
		this->sprite.setPosition(this->position.GetX(), this->position.GetY());
		window.draw(this->sprite);
	}
	
	Coordinates GetPosition()const { return this->position; }
	
};