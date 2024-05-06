#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	exists = true;
	texture.loadFromFile("../Images/Cherrybomb3.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->position.GetX(), this->position.GetY());
	Type = "CherryBomb";
}
void CherryBomb::Action(RenderWindow& window) {
	// Pass
	cout<<"C"<<endl;
	if (this->exists) {
		cout << "C" << endl;
		if (clock.getElapsedTime().asSeconds() >= 3) {
			DrawExplosion(window, this->position);
			exists = false;
			clock.restart();
		}
		else {
			for (int i = 0; i < 3; ++i)
				sprite.setScale(20*i,20*i);
			window.draw(sprite);
		}
	}
}