#pragma once

#ifndef ZombieOutskirts_H
#define ZombieOutskirts_H

#include "Level.h" // Include necassary header file(s)

class ZombieOutskirts : public Level
{

public:
	ZombieOutskirts();
	void Action() {
		this->gamePlay.GetSun().setStopProduction(true);
	}
};



#endif // ZombieOutskirts_H