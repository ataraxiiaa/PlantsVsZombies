#include "FumeShroom.h"


FumeShroom::FumeShroom() :RangedShooter(6) {
	this->texture.loadFromFile("../Images/fumeshroom.png");
	this->animate = new Animation;
	animate->SetSheet(0.125, 2, texture, 4, 1);
	animate->ChangeScale(2.8, 2.8);
	this->Type = "FumeShroom";
	this->exists = true;
	this->damage = 0.01f;

}
void FumeShroom::Action(sf::RenderWindow& window) {
	Texture bullettexture;
	bullettexture.loadFromFile("../Images/shroombullet.png");
	Sprite sprite;
	sprite.setTexture(bullettexture);
	sprite.setScale(0.4, 0.4);
	bullet[0].SetSprite(sprite);
	bullet->setSpeed(3);
	for (int i = 0; i < totalBullets; ++i) {
		if (!CheckBulletRange()) {
			bullet[0].SetFire(false);
		}
		if (clock.getElapsedTime().asSeconds() >= 1) {
			clock.restart();
		}
		Shooter::Fire(window, this->position);
	}
}