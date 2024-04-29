#pragma once
#ifndef Shop_H
#define Shop_H

#include <SFML/Graphics.hpp> // Include necessary header file(s)
using namespace sf;

class Shop
{
protected:
	Sprite peaShooter_S, sunFlower_S, repeater_S, snowPea_S, cherryBomb_S;
	Sprite* sprite;
	Texture* texture;
	Texture peaShooter_T, sunFlower_T, repeater_T, snowPea_T, cherryBomb_T;
public:
	Shop(); // Default constructor 
	void DrawShop(sf::RenderWindow& window);
};



#endif // Shop_H