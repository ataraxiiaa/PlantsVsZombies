#pragma once

#ifndef Plants_H
#define Plants_H 

#include "Entity.h" // Include necessary header files
class Plants : public Entity
{
protected:
	float coolDown; // Cool down between plants being used after one is placed
	int cost; // Cost for buying plants
public:
	// Getters
	float GetCoolDown()const { return coolDown; }
	int GetCost()const { return cost; }
	int GetX() { return this->position.GetX(); }
	int GetY() { return this->position.GetY(); }
	float GetLives() { return this->lives; }
	bool GetExistence() { return this->exists; }
	// Setters
	void SetCoolDown(float coolDown) { this->coolDown = coolDown; }
	void SetCost(int cost) { this->cost = cost; }
	void SetLives(float lives) { this->lives = lives; }
	void SetExistence(bool exists) { this->exists = exists; }
};


#endif // PLants_H