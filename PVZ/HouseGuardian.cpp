#include "HouseGuardian.h"


HouseGuardian::HouseGuardian(string std_path) {
	this->texture.loadFromFile(std_path);
	this->sprite.setTexture(this->texture);
	this->lives = 1;
	exists = true;
}
void HouseGuardian::CheckCollision(Vector<Zombie*>& Zptr) {
	for (int i = 0; i < Zptr.GetSize(); ++i) {
		if (GetPosition().GetX() - Zptr[i]->GetPosition().GetX() >= -10 &&
			GetPosition().GetX() - Zptr[i]->GetPosition().GetX() <= 10 &&
			GetPosition().GetY() - Zptr[i]->GetPosition().GetY() >= -80 &&
			GetPosition().GetY() - Zptr[i]->GetPosition().GetY() <= 80 &&
			Zptr[i]->GetExistance() && this->exists)
		{
			cout << "Collided" << endl;
			this->exists = false;
			Zptr.Destroy(i);
			//return;
		}
	}
}