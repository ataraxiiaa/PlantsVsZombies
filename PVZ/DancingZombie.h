#pragma once
#include "Zombies.h"
#include "NormalZombie.h"

class DancingZombie :public Zombie {
	bool spawningZombies;
	bool spawned;
	Clock clock;
public:
	DancingZombie(); //Default constructor
	string getType() { return this->type; } //returns type of zombie
	virtual void moveZombie(Vector<Plants*>& ptr, bool** set); //moves dancing zombie
	virtual void spawnBackupZombies(Vector<Zombie*>& ptr, int& end); //spawns backup zombies 
};