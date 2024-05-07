#pragma once
#include "Zombies.h"
#include "NormalZombie.h"

class DancingZombie :public Zombie {
	bool spawningZombies;
	Clock clock;
public:
	DancingZombie();
	string getType() { return this->type; }
	void spawnZombies(Vector<Zombie*> ptr)
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
						y = this->position.GetY();
				cout << y << endl;
				ptr.push_back(new NormalZombie);
				ptr.back()->setY(57.5);
				ptr.back()->setX(1100);
				cout << ptr.back()->GetPosition().GetY() << endl;
				this->speed = 0.5;
				spawningZombies = false;
				clock.restart();
				cout << "luigi" << endl;
			}
		}
	}
};