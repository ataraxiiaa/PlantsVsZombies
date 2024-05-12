#include "SnowPea.h"

SnowPea::SnowPea()
{
	// Loading up sprties and setting stuff
	exists = true;
	texture.loadFromFile("../Images/SnowPea.png");
	Texture BulletTexture;

	BulletTexture.loadFromFile("../Images/SnowBullet.png");
	bullet->SetTexture(BulletTexture);

	animate = new Animation;
	this->lives = 40;
	animate->SetSheet(0.125, 6, texture, 8, 1);
	Coordinates pos(400, 300);
	this->position = pos;
	Ice = true;
	Type = "Snowpea";
}
void SnowPea::Action(RenderWindow& window, int& money)
{
	if (exists)
	{
		Fire(window, this->position);
	}
}
