#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	exists = true;
	cost = 100; // 100 Sun
	coolDown = 10.0f; // 10s Cool down
	texture.loadFromFile("../Images/PeaShooter3.png");
	animate = new Animation;
	animate->SetSheet(0.5, 6, texture, 8, 1);
	//sprite.setTexture(texture);
	//Animation::SetSheet(Texture& spriteSheet, int imagesPerRow, int imagesPerCol,int totalFrames)
	//SetSheet(float Delay, int totalFrames,Texture& spriteSheet, int imagesPerRow, int imagesPerCol)

}
void PeaShooter::DrawPeaShooter(sf::RenderWindow& window)
{
	sprite.setPosition(500, 500);
	animate->Update();
	animate->DrawAnimation(window);
}