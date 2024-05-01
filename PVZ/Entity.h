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
};



#endif // Entity_H