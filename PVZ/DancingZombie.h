#pragma once
#include "Zombies.h"
#include "NormalZombie.h"

class DancingZombie :public Zombie {
	bool spawningZombies;
	Clock clock;
public:
	DancingZombie();
	string getType() { return this->type; }
	virtual void spawnBackupZombies(Vector<Zombie*>& ptr)
	{
		if (!spawningZombies)
		{
			if (clock.getElapsedTime().asSeconds() >= 5)
			{
				cout << "mario" << endl;
				spawningZombies = true;
				this->speed = 0;
				clock.restart();
			}
		}
		else if (spawningZombies)
		{
			if (clock.getElapsedTime().asSeconds() >= 2)
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
				clock.restart();
				cout << "luigi" << endl;
			}
		}
	}
};