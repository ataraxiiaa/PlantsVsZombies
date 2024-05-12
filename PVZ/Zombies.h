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
	int yPositions[5];
	bool fly;
	string type;
	Clock clock;
	bool slowed;
public:
	Zombie() 
	{
		yPositions[0] = 97.5 - 40;
		yPositions[1] = 203 - 40;
		yPositions[2] = 309 - 40;
		yPositions[3] = 415 - 30;
		yPositions[4] = 521 - 20;
		fly = false;
		type = "no";
	}
	float getDamage() { return this->damage; }
	float getSpeed() { return this->speed; }
	float getLives() { return this->lives; }
	bool getFly() { return this->fly; }
	virtual string getType() { return this->type; }
	void setDamage(float damage) { this->damage = damage; }
	void setSpeed(float speed) { this->speed = speed; }
	void setLives(float lives) { this->lives = lives; }
	void setExists(bool exists) { this->exists = exists; }
	bool checkIfPlantAhead(Vector<Plants*>& plant);
	int findIndex(Vector<Plants*> plant);
	void doDamage(Vector<Plants*>& ptr, bool** set);
	virtual void moveZombie(Vector<Plants*>& ptr, bool** set);
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void action(sf::RenderWindow& window, Vector<Plants*>& ptr, bool** set);
	int* getYPositions() { return this->yPositions; }
	virtual void setY(int y) { this->position.SetY(y); }
	virtual void setX(int x) { this->position.SetX(x); }
	Coordinates GetPosition()const { return this->position; }
	virtual void spawnBackupZombies(Vector<Zombie*>& ptr, int& end) {}
	void slowDown();
};