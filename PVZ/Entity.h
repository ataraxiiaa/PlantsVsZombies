#pragma once
#ifndef Entity_H
#define Entity_H 
#include <SFML/Graphics.hpp> // Include necessary resource files
#include <SFML/Audio.hpp>
#include "Coordinates.h" // Include necessary Header files
using namespace sf;

class Entity
{
protected:
	Coordinates position; // Position for objects
	float lives; // Tracking lives for any object in game
	bool exists; // Would make sure the object is removed/added whenever required
	Sprite sprite; // For adding images to objects
	Texture texture;
	//sf::Music music; // Whatever sound effects needed etc leaving it for now
public:
	bool CheckExistance()const { return exists; }
	Coordinates GetPosition()const { return position; }
	void SetCoordinates(Coordinates position) { this->position = position; }
	bool GetExistance()const { return exists; }
	
	void SetSprtePos(Coordinates pos) {
		sprite.setPosition(pos.GetX(), pos.GetY());
	}
	Sprite GetSprite()const { return sprite; }
	Texture GetTexture()const { return texture; }
};



#endif // Entity_H