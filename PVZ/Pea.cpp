#include "Pea.h"

Pea::Pea() // Default constructor
{
	fire = false; // WHenever a peashooter is created it fires
	speed = 10.0f; // Speed set to default
	bulletTexture.loadFromFile("../Images/pea.png");
	bulletSprite.setTexture(bulletTexture);

}
void Pea::DrawPea(sf::RenderWindow& window) {
	if (fire) {
		bulletSprite.setPosition(this->position.GetX()+5, this->position.GetY()+10);
		window.draw(bulletSprite);
	}
}
