#pragma once
#ifndef Shop_H
#define Shop_H

#include <SFML/Graphics.hpp> // Include necessary header file(s)
using namespace sf;

class Shop
{
protected:
	Sprite* sprite;
	Texture* texture;
public:
	Shop(); // Default constructor 
	void DrawShop(sf::RenderWindow& window);

};



#endif // Shop_H