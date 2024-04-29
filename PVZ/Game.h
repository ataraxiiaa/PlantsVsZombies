#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "PeaShooter.h"
#include "NormalZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"
#include "Sun.h"
#include "Shop.h"
#include <string>
using namespace sf;
using namespace std;

class Game
{
	MainMenu menu;
	PeaShooter peaShooter;
	NormalZombie normal;
	FootballZombie football;
	FlyingZombie flying;
	DancingZombie dancing;
	Shop shop;
	DolphinRiderZombie dolphin;
	Plants* ptr = &peaShooter;
	Sun sun;
	int money = 0;
	Font font;
	Text text;
public:
	Game() = default; // (Default for now will change later on)
	// Function prototypes that are defined in Game.cpp
	void createBack(RenderWindow& window); // Creating Backgrund
	void createMap(RenderWindow& window); // Creating window
	void createGrid(RenderWindow& window); // Creating a grid
	void Start_Game(); // Starts the Game window when called
};

