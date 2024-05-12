#pragma once
#include "Zombies.h"

class FlyingZombie :public Zombie {
public:
	FlyingZombie();
	void moveZombie(); //moves flying zombie
	void drawZombie(sf::RenderWindow& window); //draws flying zombie
	void action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set); 
};