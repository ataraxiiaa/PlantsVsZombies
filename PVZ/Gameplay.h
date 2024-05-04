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
#include "Vector.h"
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
	bool hover, dragging;
	sf::RectangleShape rectangle;
public:
	Gameplay(); // Default Constructor
	~Gameplay(); // Destructor 
	// Creating functions for Gameplay
	void checkShopClick(RenderWindow& window, int& money);
	void dropToGrid(RenderWindow& window, Vector<Plants*> &ptr, int& money);
	bool** getFieldStatus() { return FIELD_GAME_STATUS; }
	void checkGrid(int& row, int& col, float& xPos, float& yPos, RenderWindow& window, sf::Vector2f& mouse);
};



#endif // Gameplay_H

