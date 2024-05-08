#include "FumeShroom.h"


FumeShroom::FumeShroom() :RangedShooter(6) {
	this->texture.loadFromFile("../Images/fumeshroom.png");
	this->animate = new Animation;
	animate->SetSheet(0.125, 2, texture, 4, 1);
	animate->ChangeScale(2.8, 2.8);
	this->Type = "FumeShroom";
	this->exists = true;

}
void FumeShroom::Action(sf::RenderWindow& window) {
	for (int i = 0; i < totalBullets; ++i) {
		if (!CheckBulletRange()) {
			bullet[0].SetFire(false);
		}
		Shooter::Fire(window, this->position);
	}
}