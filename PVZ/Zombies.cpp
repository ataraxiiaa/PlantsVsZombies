#include "Zombies.h"

bool Zombie::checkIfPlantAhead(Vector<Plants*>& plant)
{
	for (int i = 0; i < plant.GetSize(); i++)
	{
		if (plant[i] != nullptr)
		{
			if (this->position.GetX() - plant[i]->GetX() >= -50 &&
				this->position.GetX() - plant[i]->GetX() <= 50 &&
				this->position.GetY() + 40 == plant[i]->GetY() &&
				plant[i]->GetExistence())
			{
				return true;
			}
		}
	}
	return false;
}
int Zombie::findIndex(Vector<Plants*> plant)
{
	for (int i = 0; i < plant.GetSize(); i++)
	{
		if (this->position.GetX() - plant[i]->GetX() >= -50 &&
			this->position.GetX() - plant[i]->GetX() <= 50 &&
			this->position.GetY() + 40 == plant[i]->GetY() &&
			plant[i]->GetExistence())
		{
			return i;
		}
	}

}
void Zombie::doDamage(Vector<Plants*>& ptr, bool** set)
{
	int index = findIndex(ptr);

	if (ptr[index]->GetLives() > 0)
		ptr[index]->SetLives(ptr[index]->GetLives() - damage);
	else if (ptr[index]->GetLives() == 0)
	{
		ptr[index]->SetExistence(false);
		set[ptr.back()->getI()][ptr.back()->getJ()] = false;
		ptr.Destroy(index);
		cout << "destroyed" << endl;
	}
}
void Zombie::moveZombie(Vector<Plants*>& ptr, bool** set)
{
	if (!checkIfPlantAhead(ptr))
	{
		if (position.GetX() > 0)
			this->position.SetX(position.GetX() - speed);
	}
	else
	{
		doDamage(ptr, set);
	}
}
void Zombie::drawZombie(sf::RenderWindow& window)
{
	this->animate->Update();
	this->animate->DrawAnimation(window, this->position);
}

int Zombie::checkShooterType(Vector<Plants*> ptr)
{
	for (int i = 0; i < ptr.GetSize(); i++)
		if (ptr[i]->getShooterType())
			return i;
	return -1;
}

void Zombie::action(sf::RenderWindow& window, Vector<Plants*> ptr, bool** set)
{
	int i = checkShooterType(ptr);
	if (i != -1)
		ptr[i]->CheckExistance();
	this->moveZombie(ptr, set);
	this->drawZombie(window);
}