#include "DancingZombie.h"

DancingZombie::DancingZombie() {
	this->speed = 1;
	this->damage = 1;
	this->lives = 16;
	this->texture.loadFromFile("../Images/dancingZombie2.png");
	animate = new Animation;
	animate->SetSheet(0.5, 4, texture, 6, 6);
	this->exists = true;
	this->position.SetX(700);
	this->position.SetY((550 - (rand() % 5) * 110));
	this->type = "dancing";
	this->spawningZombies = false;
	this->spawned = false;
}

void DancingZombie::spawnBackupZombies(Vector<Zombie*>& ptr, int& end)
{
	if (exists) {
		if (!spawningZombies && !spawned)
		{
			if (clock.getElapsedTime().asSeconds() >= 15) //checks time for spawning backup zombies
			{
				spawningZombies = true;
				this->speed = 0; //stops zombie in place to spawn backup zombies
				clock.restart(); //resets clock to space out spawning of backup zombies
			}
		}
		else if (spawningZombies && !spawned)
		{
			if (clock.getElapsedTime().asSeconds() >= 4)
			{
				//find y pos
				int y;
				for (int j = 0; j < 5; j++)
					if (ptr[ptr.GetSize() - 1]->getYPositions()[j] == this->position.GetY())
						y = j;
				//checks if in top row
				if (y > 0)
				{
					ptr.push_back(new NormalZombie);
					ptr.back()->setX(this->position.GetX());
					ptr.back()->setY(this->getYPositions()[y - 1]);
					end++;
				}
				//checks if last row
				if (y < 4)
				{
					ptr.push_back(new NormalZombie);
					ptr.back()->setX(this->position.GetX());
					ptr.back()->setY(this->getYPositions()[y + 1]);
					end++;
				}
				ptr.push_back(new NormalZombie);
				ptr.back()->setX(this->position.GetX() + 92); //spawns zombie behind dancing zombie
				ptr.back()->setY(this->position.GetY());
				ptr.push_back(new NormalZombie);
				ptr.back()->setX(this->position.GetX());
				ptr.back()->setX(this->position.GetX() - 92); //spawns zombie infront of dancing zombie
				ptr.back()->setY(this->position.GetY());
				this->speed = 0.5;
				spawningZombies = false;
				end += 2;
				spawned = true; //sets bool to true to stop further spawning
			}
		}
	}
}

void DancingZombie::moveZombie(Vector<Plants*>& ptr, bool** set)
{
	if (exists) {
		static Clock clock;
		srand((unsigned)time(0));
		int random = rand() % 5;
		if (clock.getElapsedTime().asSeconds() >= 5)
		{
			//check y position
			int y = 0;
			for (int i = 0; i < 5; i++)
				if (this->yPositions[i] == this->position.GetY())
				{
					y = i;
					break;
				}
			if (random == 0 && y > 0) //moves zombie into above row
			{
				this->position.SetY(this->yPositions[y - 1]);
				clock.restart();
			}
			else if (random == 1 && y < 4) //moves zombie into below row
			{
				this->position.SetY(this->yPositions[y + 1]);
				clock.restart();
			}
		}
		if (!checkIfPlantAhead(ptr)) //checks if any plant is infront of zombie
		{
			if (position.GetX() > 0)
				this->position.SetX(position.GetX() - speed);
		}
		else
		{
			doDamage(ptr, set);
		}
	}
}