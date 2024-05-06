#include "HouseGuardian.h"


HouseGuardian::HouseGuardian(string std_path) {
	this->texture.loadFromFile(std_path);
	this->sprite.setTexture(this->texture);
	this->lives = 1;
	exists = true;
	speed = 5.0f;
	destroyed = false;
}
void HouseGuardian::CheckCollision(Vector<Zombie*>& Zptr) {
	for (int i = 0; i < Zptr.GetSize(); ++i) {
		if (position.GetX() - Zptr[i]->GetPosition().GetX() >= -10 &&
			position.GetX() - Zptr[i]->GetPosition().GetX() <= 10 &&
			position.GetY() - Zptr[i]->GetPosition().GetY() >= -30 &&
			position.GetY() - Zptr[i]->GetPosition().GetY() <= 30 &&
			Zptr[i]->GetExistance() && this->exists)
		{	
			Zptr[i]->setExists(false);
			Zptr.Destroy(i);	
			cout << "Collided" << endl;
			//this->exists = false;
			destroyed = true;
		}
	}
	if (destroyed)
		MoveGuardian();
}
void HouseGuardian::MoveGuardian() {
	if (this->exists) {
		position.SetX(GetPosition().GetX() + speed);
		sprite.setPosition(position.GetX(), spritePos.GetY());

		if(position.GetX() >= 1150)
			this->exists = false;
	}
}