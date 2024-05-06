#pragma once
#ifndef HouseGuardian_H
#define HouseGuardian_H

#include "Entity.h" // Include necessary header file(s)
#include "Zombies.h"
#include <string>

using namespace std;

class HouseGuardian : public Entity
{
	float speed;
	bool destroyed;
	Coordinates spritePos;
public:
	HouseGuardian() = default; // Default constructor 

	HouseGuardian(string std_path);
	void CheckCollision(Vector<Zombie*>& Zptr);
	void MoveGuardian();
	void SetSpritePosGuard(Coordinates pos) {
		spritePos.SetX(pos.GetX());
		spritePos.SetY(pos.GetY());
	}

};



#endif