#pragma once
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;

class PlantRemover {
	Texture texture;
	Sprite sprite;
	Coordinates position;
	bool selected;
public:
	PlantRemover()
	{
		texture.loadFromFile("../Images/shovel.gif");
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(67, 20, 61, 51));
		position.SetX(260);
		position.SetY(8);
		selected = false;
	}
	void drawRemover(RenderWindow& window) //draws remover sprite
	{
		sprite.setPosition(position.GetX(), position.GetY());
		window.draw(sprite);
	}
	//getters
	Sprite getSprite() { return this->sprite; }
	bool getSelect() { return this->selected; }
	//setter
	void setSelect(bool select) { this->selected = select; }
};
