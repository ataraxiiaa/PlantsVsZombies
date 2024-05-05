#pragma once
#ifndef Animation_H
#define Animation_H

#include "Coordinates.h" // Include neceassary header file(s)
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
	float animationDelay;
	float timer;
	Sprite sprite;
	Texture spriteSheet;
	int frameWidth; // X pixels in sprite sheet
	int frameHeight; // Y pixels in sprite sheet
	int totalFrames; // Tracking total frames
	int currFrame; // Tracking current frame
	int imagesPerCol; // Total number of images in columns
	int imagesPerRow; // Total number of images in rows
	bool animationstart;

public:
	Animation(float animationDelay=10); // Default constructor

	void SetSheet(float Delay,int totalFrames,Texture& spriteSheet, int imagesPerRow,int imagesPerCol);
	void Update(bool end = false);
	void DrawAnimation(sf::RenderWindow& window, Coordinates positon);
	int GetCurrFrame()const { return currFrame; }

	Sprite getSprite()const { return sprite; }
};




#endif // Animation_H
