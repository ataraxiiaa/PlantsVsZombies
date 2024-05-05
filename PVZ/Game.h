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
#include "Paused.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "WallNut.h"
#include "Gameplay.h"
#include "Vector.h"
#include <string>
using namespace sf;
using namespace std;

class Game
{
	MainMenu menu;
	Paused pause;
	PeaShooter peaShooter;
	//NormalZombie normal;
	//FootballZombie football;
	//FlyingZombie flying;
	//DancingZombie dancing;
	Shop shop;
	//DolphinRiderZombie dolphin;
	//Plants** ptr;
	Vector<Plants*> ptr;
	Vector<Zombie*> zptr;
	CherryBomb bomb;
	Repeater repeat;
	WallNut nutty;
	Sun sun;
	int money;
	Font font;
	Text text;
	Gameplay gamep;
	int level;
public:
	Game(); // (Default for now will change later on)
	// Function prototypes that are defined in Game.cpp
	void createBack(RenderWindow& window); // Creating Background
	void createMap(RenderWindow& window); // Creating window
	void createGrid(RenderWindow& window); // Creating a grid
	void Start_Game(); // Starts the Game window when called
};

