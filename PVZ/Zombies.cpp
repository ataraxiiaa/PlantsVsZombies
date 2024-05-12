#include "Zombies.h"

bool Zombie::checkIfPlantAhead(Vector<Plants*>& plant) //checks if plant is infront of zombie
{
	for (int i = 0; i < plant.GetSize(); i++)
	{
		if (plant[i] != nullptr)
		{
			if (this->position.GetX() - plant[i]->GetX() >= -50 &&
				this->position.GetX() - plant[i]->GetX() <= 50 &&
				this->position.GetY() - plant[i]->GetY() >= -40 &&
				this->position.GetY() - plant[i]->GetY() <= 40 &&
				plant[i]->GetExistence())
			{
				return true;
			}
		}
	}
	return false;
}
int Zombie::findIndex(Vector<Plants*> plant) //finds plant index which is to be damaged
{
	for (int i = 0; i < plant.GetSize(); i++)
	{
		if (this->position.GetX() - plant[i]->GetX() >= -50 &&
			this->position.GetX() - plant[i]->GetX() <= 50 &&
			this->position.GetY() - plant[i]->GetY() >= -40 &&
			this->position.GetY() - plant[i]->GetY() <= 40 &&
			plant[i]->GetExistence())
		{
			return i;
		}
	}
	return -1;

}
void Zombie::doDamage(Vector<Plants*>& ptr, bool** set)
{
	int index = findIndex(ptr); //finds which plant to damage

	if (ptr[index]->GetLives() > 0) {
		ptr[index]->SetLives(ptr[index]->GetLives() - damage); //hits plant according to damage
	}
	else if (ptr[index]->GetLives() == 0) //kills plant if lives finished
	{
		if (ptr[index]->GetType() != "CherryBomb") {
			ptr[index]->SetExistence(false);
			set[ptr[index]->getI()][ptr[index]->getJ()] = false;
			ptr.Destroy(index);
		}
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
	if (this->exists) {
		this->animate->Update();
		this->animate->DrawAnimation(window, this->position);
	}
}

void Zombie::action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set)
{
	if (slowed && clock.getElapsedTime().asSeconds() >= 4) { //checks time to reset zombie speed 
		this->speed += 0.2;
		slowed = false;
	}
	this->moveZombie(ptr, set);
	this->drawZombie(window);
}

void Zombie::slowDown() //slows down zombie if hit by snowpea
{
	clock.restart();
	this->speed = this->speed - 0.2;
	slowed = true;
}