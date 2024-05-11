#pragma once
#ifndef Level_H
#define Level_H

#include "Menu.h"
#include "Gameplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Level { // Abstract class
protected:
	Gameplay gamePlay;
	Texture levelTexture;
	Sprite levelSprite;
	bool start;
	int level;
public:
	Level(int level = 1);
	//void displayLevel(RenderWindow& window, int level);
	bool getStart() { return this->start; }
	void setStart(bool start) { this->start = start; }
	void setLevel(int level) { this->level = level; }
	int GetLevel() { return this->level; }
	void startGamePlay(RenderWindow& window);
	Gameplay& GetGamePlay() { return this->gamePlay; }

	//virtual void DrawLevels(RenderWindow& window); 
};


#endif