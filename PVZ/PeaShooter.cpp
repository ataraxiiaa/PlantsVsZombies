#include "PeaShooter.h"

PeaShooter::PeaShooter()
{
	exists = true;
	cost = 100; // 100 Sun
	coolDown = 10.0f; // 10s Cool down
	texture.loadFromFile("../Images/PeaShooter3.png");
	animate = new Animation;
	animate->SetSheet(0.125, 6, texture, 8, 1);
	this->lives = 10;
	Type = "PeaShooter";
	this->damage = 0.4;
}
void PeaShooter::Action(RenderWindow& window)
{
	Fire(window, this->position);
}