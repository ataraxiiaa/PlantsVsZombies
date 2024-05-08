#include "RangedShooter.h"

RangedShooter::RangedShooter(int totalBullets):totalBullets(totalBullets) {
	shoot = false;
}
bool RangedShooter::CheckRange(Vector<Zombie*>& Zptr) {
	// Checking if Zombie is within 4 box range
	for (int i = 0; i < Zptr.GetSize(); ++i) {
		if (Zptr[i]->GetPosition().GetX() - this->position.GetX() <= 300 && Zptr[i]->GetExistance() &&
			Zptr[i]->GetPosition().GetX()-this->position.GetX() >= 0 &&
			Zptr[i]->GetPosition().GetY() - this->position.GetY() >= -70 &&
			Zptr[i]->GetPosition().GetY() - this->position.GetY() <= 70
			) {
			shoot = true;
			return true;
		}
	}
	return false;
}
bool RangedShooter::CheckBulletRange() {
	if (this->bullet[0].GetPosition().GetX() >= this->position.GetX() + 300) {
		shoot = false;
		return false;
	}
	return true;
}