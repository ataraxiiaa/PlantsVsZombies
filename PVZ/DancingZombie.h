#pragma once
#include "Zombies.h"
#include "NormalZombie.h"

class DancingZombie :public Zombie {
	bool spawningZombies;
	bool spawned;
	Clock clock;
public:
	DancingZombie();
	string getType() { return this->type; }
	virtual void moveZombie(Vector<Plants*>& ptr, bool** set);
	virtual void spawnBackupZombies(Vector<Zombie*>& ptr);
};