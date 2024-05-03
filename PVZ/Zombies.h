#pragma once
#include "Entity.h" // Include neceassary header file(s)
#include "Plants.h"
#include "Animation.h"
#include "Vector.h"

class Zombie : public Entity {
protected:
	float damage;
	float speed;
	Animation* animate;
public:
	float getDamage() { return this->damage; }
	float getSpeed() { return this->speed; }
	void setDamage(float damage) { this->damage = damage; }
	void setSpeed(float speed) { this->speed = speed; }
	bool checkIfPlantAhead(Vector<Plants*>& plant);
	int findIndex(Vector<Plants*> plant);
	void doDamage(Vector<Plants*>& ptr);
	virtual void moveZombie(Vector<Plants*>& ptr);
	virtual void drawZombie(sf::RenderWindow& window);

	Coordinates GetPosition()const { return this->position; }
	
};