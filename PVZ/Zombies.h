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
			if (plant[i] != nullptr)
			{
				if (this->position.GetX() - 50 == plant[i]->GetX() && this->position.GetY() == plant[i]->GetY() && plant[i]->GetExistence())
				{
					cout << "plant ahead" << endl;
					return true;
				}
			}
		}
		return false;
	}
	int findIndex(Vector<Plants*> plant)
	{
		for (int i = 0; i < plant.GetSize(); i++)
		{
			if (plant[i] != nullptr)
			{
				if (this->position.GetX() - 50 == plant[i]->GetX() && this->position.GetY() == plant[i]->GetY() && plant[i]->GetExistence())
				{
					cout << "plant ahead" << endl;
					return i;
				}
			}
		}

	}
	void doDamage(Vector<Plants*>& ptr)
	{
		int index = findIndex(ptr);

		if (ptr[index]->GetLives() > 0)
			ptr[index]->SetLives(ptr[index]->GetLives() - damage);
		else if (ptr[index]->GetLives()==0)
		{
			ptr[index]->SetExistence(false);
			ptr[index] = nullptr;
			//bool** set = game.getFieldStatus();
			//set[i][j]=false;

		}
	}
	virtual void moveZombie(Vector<Plants*>& ptr)
	{
		if (!checkIfPlantAhead(ptr))
		{
			if (position.GetX() > 0)
				this->position.SetX(position.GetX() - speed);
		}
		else
		{
			doDamage(ptr);
		}
	}
	virtual void drawZombie(sf::RenderWindow& window)
	{
		this->animate->Update();
		this->animate->DrawAnimation(window, this->position);
	}

	Coordinates GetPosition()const { return this->position; }
	
};