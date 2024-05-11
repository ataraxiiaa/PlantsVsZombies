#pragma once
#ifndef Level_H
#define Level_H

#include "Menu.h"
#include "Gameplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Level { // Abstract class
protected:
	Vector<Sprite> transition;
	Gameplay gamePlay;
	Texture levelTexture;
	Sprite levelSprite;
	Text text;
	Font font;
	bool start;
	int level;
	Clock clock;
	Texture texture;
	bool transitioning;
public:
	Level(int level = 1);
	//void displayLevel(RenderWindow& window, int level);
	bool getStart() { return this->start; }
	void setStart(bool start) { this->start = start; }
	void setLevel(int level) { this->level = level; }
	int GetLevel() { return this->level; }
	void startGamePlay(RenderWindow& window);
	Gameplay& GetGamePlay() { return this->gamePlay; }

	void CreateTransition(RenderWindow& window);
	//virtual void DrawLevels(RenderWindow& window); 
};


#endif