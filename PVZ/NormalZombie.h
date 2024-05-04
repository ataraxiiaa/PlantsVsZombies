#pragma once
#include "Zombies.h"
#include "Animation.h"

class NormalZombie :public Zombie {

public:
	NormalZombie();
	void setY(int y) { this->position.SetY(y); }
	void setX(int x) { this->position.SetX(x); }
};