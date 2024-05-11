#pragma once
#ifndef Shop_H
#define Shop_H

#include <SFML/Graphics.hpp> // Include necessary header file(s)
#include "Vector.h"

using namespace std;
using namespace sf;

class Shop
{
	int elements;
protected:
	Vector<Sprite> selectedSprite;
	Vector<Sprite> shopSprite;
	Sprite* sprite;
	Texture* texture;
	string* ids;
public:
	Shop(); // Default constructor 
	void DrawShop(sf::RenderWindow& window);
	Sprite* getSprite() { return sprite; }
	string* getIds() { return ids; }
	void setShop(int level);
	int getElement() { return this->elements; }
	Vector<Sprite> getSelectedSprite()const { return selectedSprite; }
	Vector<Sprite> getShopSprite()const { return shopSprite; }
};



#endif // Shop_H