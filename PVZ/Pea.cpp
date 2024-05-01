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
bool Pea::CheckForCollision(Zombie*& Zptr) {
	if (this->position.GetX() - 50 == Zptr->GetPosition().GetX() && this->position.GetY() == Zptr->GetPosition().GetY() && Zptr->CheckExistance())
		return true;
	else
		return false;
}