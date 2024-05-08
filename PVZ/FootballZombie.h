#pragma once
#include "Zombies.h"

class FootballZombie :public Zombie {
public:
	FootballZombie();
	virtual void moveZombie(Vector<Plants*>& ptr, bool** set);
	virtual void drawZombie(sf::RenderWindow& window);
};