#pragma once
#ifndef Gameplay_H
#define Gameplay_H

#include "Plants.h" // Include neceassary header file(s)
#include "Zombies.h"
#include "Shop.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include "WallNut.h"
#include "Repeater.h"
#include "CherryBomb.h"
#include "SnowPea.h"
#include "NormalZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "Vector.h"
#include "HouseGuardian.h"
#include "FumeShroom.h"
#include <iostream>

class Gameplay
{
	Shop shop;
	Vector<Plants*> ptr;
	Vector<Zombie*> zptr;
	Vector<HouseGuardian*> Guardians;
	Sun sun;
	Font font;
	Text text;
	const int gridCols, gridRows; // Making Grid
	bool** FIELD_GAME_STATUS; // Bool to track Grid movement
	bool selected;
	int index;
	bool firstClick;
	bool hover, dragging;
	sf::RectangleShape rectangle;
	float initialTime;
	float timeInterval;
	int money;
	int zombiesSpawned;
	int zombiesKilled;
	Clock clock;
	Clock* cooldown;
	Texture* texture;
	bool restart;
public:
	Gameplay(); // Default Constructor
	~Gameplay(); // Destructor 
	// Creating functions for Gameplay
	void checkShopClick(RenderWindow& window);
	Sun& GetSun() { return this->sun; }
	void dropToGrid(RenderWindow& window);

	bool** getFieldStatus() { return FIELD_GAME_STATUS; }

	void checkGrid(int& row, int& col, float& xPos, float& yPos, RenderWindow& window, sf::Vector2f& mouse);
	void CheckCollision();
	void spawnZombies(int level); // , Clock& clock);
	void StartGamePlay(RenderWindow& window, int level);
	int getKilled() { return this->zombiesKilled; }
	void setKilled(int killed) { this->zombiesSpawned = killed; }
	int getSpawned() { return this->zombiesKilled; }
	void setSpawned(int spawned) { this->zombiesSpawned = spawned; }
	bool CheckTransitionCondition(int levels);
	void resetGame();
};



#endif // Gameplay_H

