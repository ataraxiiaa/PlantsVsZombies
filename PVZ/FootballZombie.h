#pragma once
#include "Zombies.h"

class FootballZombie :public Zombie {
public:
	FootballZombie();
	virtual void drawZombie(sf::RenderWindow& window);
};