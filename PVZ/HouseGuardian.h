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
	void CheckCollision(Vector<Zombie*>& Zptr,int &zombiesKilled); //checks collision with zombie
	void MoveGuardian(); //moves guardian towards end of the game grid
	void SetSpritePosGuard(Coordinates pos) {
		spritePos.SetX(pos.GetX());
		spritePos.SetY(pos.GetY());
	}
	void Action() {
		
	}
	void setDestroyed(bool des) { this->destroyed = des; }

};



#endif