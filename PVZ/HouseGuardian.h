#pragma once
#ifndef HouseGuardian_H
#define HouseGuardian_H

#include "Entity.h" // Include necessary header file(s)
#include "Zombies.h"
#include <string>

using namespace std;

class HouseGuardian : public Entity
{

public:
	HouseGuardian() = default; // Default constructor 

	HouseGuardian(string std_path);
	void CheckCollision(Vector<Zombie*>& Zptr);


};



#endif