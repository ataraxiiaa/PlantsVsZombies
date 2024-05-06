#pragma once

#ifndef Plants_H
#define Plants_H 

#include <SFML/Audio.hpp>
#include "Entity.h" // Include necessary header files
#include "Animation.h"

#include <iostream>
using namespace std;

class Plants : public Entity // Abstract Class
{
protected:
	float coolDown; // Cool down between plants being used after one is placed
	int cost; // Cost for buying plants
	Animation* animate;
	int i;
	int j;
	bool shooterType;
	string Type;


public:
	Plants() { shooterType = false; }
	// Getters
	float GetCoolDown()const { return coolDown; }
	int GetCost()const { return cost; }
	int GetX() { return this->position.GetX(); }
	int GetY() { return this->position.GetY(); }
	float GetLives() { return this->lives; }
	bool GetExistence() { return this->exists; }
	Sprite getSprite() { return this->sprite; }
	int getI() { return i; }
	int getJ() { return j; }
	bool getShooterType() { return this->shooterType; }
	// Setters
	void SetCoolDown(float coolDown) { this->coolDown = coolDown; }
	void SetCost(int cost) { this->cost = cost; }
	void SetLives(float lives) { this->lives = lives; }
	void SetExistence(bool exists) { this->exists = exists; }
	virtual void drawPlant(RenderWindow& window);
	void setX(int x) { this->position.SetX(x); }
	void setY(int y) { this->position.SetY(y); }
	void setI(int i) { this->i = i; }
	void setJ(int j) { this->j = j; }
	
	Animation* getAnimation() { return animate; }
	// Action each plant performs
	virtual string GetType()const { return Type; }
	virtual void Action(RenderWindow& window) = 0; // Abstract function

};


#endif // PLants_H