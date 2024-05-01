#pragma once
#ifndef Gameplay_H
#define Gameplay_H

#include "Plants.h" // Include neceassary header file(s)
#include "Zombies.h"
#include "Shop.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include <iostream>

class Gameplay
{
	Shop shop;
	Zombie* Zptr; // Zombie plant
	const int gridCols, gridRows; // Making Grid
	bool** FIELD_GAME_STATUS; // Bool to track Grid movement
	bool selected;
	int index;
	bool firstClick;
public:
	Gameplay(); // Default Constructor
	~Gameplay(); // Destructor 
	// Creating functions for Gameplay
	void checkShopClick(RenderWindow& window);
	void dropToGrid(RenderWindow& window, Plants** ptr);
};



#endif // Gameplay_H

