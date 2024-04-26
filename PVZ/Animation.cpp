#include "Animation.h"

Animation::Animation(float animationDelay)
{
	this->animationDelay = animationDelay;
	timer = 0.0;
	frameWidth = 0;
	frameHeight = 0;
	currFrame = 0;
	imagesPerCol = 0;
	this->imagesPerRow = 0;
	totalFrames = 0;
}
void Animation::SetSheet(float Delay, int totalFrames,Texture& spriteSheet, int imagesPerRow, int imagesPerCol)
{
	frameWidth = spriteSheet.getSize().x/imagesPerRow; // getting each images width
	frameHeight = spriteSheet.getSize().y/imagesPerCol; // Getting each images height
	currFrame = 0;
	this->imagesPerCol = imagesPerCol;
	this->imagesPerRow = imagesPerRow;
	this->totalFrames = totalFrames;
	this->animationDelay = Delay;
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}
void Animation::Update()
{
	timer += 0.2f;
	if (timer >= animationDelay)
	{
		if (currFrame < imagesPerRow)
		{
			sprite.setTextureRect(sf::IntRect(currFrame * frameWidth, 0, frameWidth, frameHeight));
			timer = 0.0f;
			currFrame++;
		}
		if (currFrame >= imagesPerRow)
		{
			int col = currFrame % imagesPerRow;
			int row = currFrame / imagesPerRow;
			sprite.setTextureRect(sf::IntRect(col * frameWidth, row*frameHeight, frameWidth, frameHeight));
			timer = 0.0f;
			currFrame++;
		}
	}
	if (currFrame == totalFrames)
		currFrame = 0;
}