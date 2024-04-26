#include "Pea.h"

Pea::Pea() // Default constructor
{
	fire = false; // WHenever a peashooter is created it fires
	speed = 0.1; // Speed set to default
	bulletTexture.loadFromFile("../Images/pea.png");
	bulletSprite.setTexture(bulletTexture);

}
void Pea::MovePea()
{

}