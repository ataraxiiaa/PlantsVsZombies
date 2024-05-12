#include "HouseGuardian.h"


HouseGuardian::HouseGuardian(string std_path) {
	this->texture.loadFromFile(std_path);
	this->sprite.setTexture(this->texture);
	this->lives = 1;
	exists = true;
	speed = 15.0f;
	destroyed = false;
}
void HouseGuardian::CheckCollision(Vector<Zombie*>& Zptr,int& zombiesKilled) { //checks collision of guardian with zombie
	for (int i = 0; i < Zptr.GetSize(); ++i) {
		if (position.GetX() - Zptr[i]->GetPosition().GetX() >= -50 &&
			position.GetX() - Zptr[i]->GetPosition().GetX() <= 50 &&
			position.GetY() - Zptr[i]->GetPosition().GetY() >= -30 &&
			position.GetY() - Zptr[i]->GetPosition().GetY() <= 30 &&
			Zptr[i]->GetExistance() && this->exists)
		{	
			//kills zombie if in path of guardian
			zombiesKilled++;
			Zptr[i]->setExists(false);
			Zptr.Destroy(i);	
			destroyed = true;
		}
	}
	if (destroyed)
		MoveGuardian(); //moves guardian to end of grid
}
void HouseGuardian::MoveGuardian() {
	if (this->exists) {
		position.SetX(GetPosition().GetX() + speed);
		sprite.setPosition(position.GetX(), spritePos.GetY());

		if(position.GetX() >= 1150)
			this->exists = false; //despawns guardian when it reaches end of grid
	}
}