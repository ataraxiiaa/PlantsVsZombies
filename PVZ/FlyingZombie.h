#pragma once
#include "Zombies.h"

class FlyingZombie :public Zombie {
public:
	FlyingZombie();
	void moveZombie();
	void drawZombie(sf::RenderWindow& window);
	void action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set);
};