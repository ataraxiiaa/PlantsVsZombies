#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	exists = true;
	cost = 100; // 100 Sun
	coolDown = 10.0f; // 10s Cool down
	texture.loadFromFile("../Images/PeaShooter3.png");
	animate = new Animation;
	animate->SetSheet(0.125, 6, texture, 8, 1);
	this->position.SetX(700);
	this->position.SetY(500);
	this->lives = 10;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 70, 100));
	//Animation::SetSheet(Texture& spriteSheet, int imagesPerRow, int imagesPerCol,int totalFrames)
	//SetSheet(float Delay, int totalFrames,Texture& spriteSheet, int imagesPerRow, int imagesPerCol)

}
void PeaShooter::drawPlant(sf::RenderWindow& window)
{
	if (exists)
	{
		Fire(window,this->position);
		//sprite.setPosition(this->position.GetX(), this->position.GetY());
		animate->Update();
		animate->DrawAnimation(window, this->position);
	}
}
