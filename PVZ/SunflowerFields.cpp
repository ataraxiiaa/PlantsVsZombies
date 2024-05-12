#include "SunflowerFields.h"


SunflowerFields::SunflowerFields() {
	levelTexture.loadFromFile("../Images/Background3.jpg");
	levelSprite.setTexture(levelTexture);
	levelSprite.setPosition(0, 0);
	this->level = 3;
	rectangle.setSize(sf::Vector2f(0, 600));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(580, 70);
	
}
void SunflowerFields::Action(RenderWindow& window) {
	window.draw(rectangle);
	GetGamePlay().setxRange(600);
}