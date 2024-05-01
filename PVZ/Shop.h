#pragma once
#ifndef Shop_H
#define Shop_H

#include <SFML/Graphics.hpp> // Include necessary header file(s)
using namespace std;
using namespace sf;

class Shop
{
protected:
	Sprite* sprite;
	Texture* texture;
	string* ids;
public:
	Shop(); // Default constructor 
	void DrawShop(sf::RenderWindow& window);
	Sprite* getSprite() { return sprite; }
	string* getIds() { return ids; }
};



#endif // Shop_H