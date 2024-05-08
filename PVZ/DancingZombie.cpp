#include "DancingZombie.h"

DancingZombie::DancingZombie() {
	srand((unsigned)time(0));
	rand();
	rand();
	rand();
	this->speed = 0.5;
	this->damage = 5;
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

void DancingZombie::spawnBackupZombies(Vector<Zombie*>& ptr)

{
	if (!spawningZombies && !spawned)
	{
		if (clock.getElapsedTime().asSeconds() >= 10)
		{
			cout << "mario" << endl;
			spawningZombies = true;
			this->speed = 0;
			clock.restart();
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
			cout << "y: " << y << endl;
			if (y > 0)
			{
				ptr.push_back(new NormalZombie);
				ptr.back()->setX(this->position.GetX());
				ptr.back()->setY(this->getYPositions()[y - 1]);
			}
			if (y < 4)
			{
				ptr.push_back(new NormalZombie);
				ptr.back()->setX(this->position.GetX());
				ptr.back()->setY(this->getYPositions()[y + 1]);
			}
			ptr.push_back(new NormalZombie);
			ptr.back()->setX(this->position.GetX() + 92);
			ptr.back()->setY(this->position.GetY());
			ptr.push_back(new NormalZombie);
			ptr.back()->setX(this->position.GetX());
			ptr.back()->setX(this->position.GetX() - 92);
			ptr.back()->setY(this->position.GetY());
			this->speed = 0.5;
			spawningZombies = false;
			spawned = true;
			//clock.restart();
			cout << "luigi" << endl;
		}
	}
}

void DancingZombie::moveZombie(Vector<Plants*>& ptr, bool** set)
{
	static Clock clock;
	srand((unsigned)time(0));
	int random = rand() % 5;
	if (clock.getElapsedTime().asSeconds() >= 5)
	{
		if (random == 0 && this->position.GetY() > 57.5)
		{
			cout << "up" << endl;
			this->position.SetY(this->position.GetY() - 106);
			clock.restart();
		}
		else if (random == 1 && this->position.GetY() < 501)
		{
			cout << "down" << endl;
			this->position.SetY(this->position.GetY() + 106);
			clock.restart();
		}
	}
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