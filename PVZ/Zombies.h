#pragma once
#include "Entity.h" // Include neceassary header file(s)
#include "Plants.h"
#include "Animation.h"
#include "Vector.h"

class Zombie : public Entity {
protected:
	float damage;
	float speed;
	Animation* animate;
public:
	float getDamage() { return this->damage; }
	float getSpeed() { return this->speed; }
	void setDamage(float damage) { this->damage = damage; }
	void setSpeed(float speed) { this->speed = speed; }
	bool checkIfPlantAhead(Vector<Plants*>& plant)
	{
		for (int i = 0; i < plant.GetSize(); i++)
		{
			if (this->position.GetX() - 50 == plant[i]->GetX() && this->position.GetY() == plant[i]->GetY() && plant[i]->GetExistence())
				return true;
		}
			return false;
	}
	void doDamage(Vector<Plants*>& ptr)
	{
		for (int i = 0; i < ptr.GetSize(); i++)
		{
			if (ptr[i]->GetLives() > 0)
				ptr[i]->SetLives(ptr[i]->GetLives() - 0.1);
			else
				ptr[i]->SetExistence(false);
		}
	}
	virtual void moveZombie(Vector<Plants*>& ptr)
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
	virtual void drawZombie(sf::RenderWindow& window)
	{
		this->sprite.setPosition(this->position.GetX(), this->position.GetY());
		window.draw(this->sprite);
	}
	
	Coordinates GetPosition()const { return this->position; }
	
};