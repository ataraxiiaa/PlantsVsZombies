#include "SunPlant.h"

SunPlant::SunPlant() {
	this->time = 10;;
}
void SunPlant::SetMoneyptr(int& money) {
	this->money = &money;
}
void SunPlant::ProduceSun(RenderWindow& window, int& money)
{
	this->sun.setExists(true);
	Coordinates pos;
	pos.SetX(this->position.GetX() + 25);
	pos.SetY(this->position.GetY() - 25);
	sun.SetPosition(pos);

}
void SunPlant::Action(RenderWindow& window) {
	if (!sun.getExists())
	{
		//cout << "nigga" << endl;
		if (clock.getElapsedTime().asSeconds() >= this->time)
		{
			int m = 0;
			ProduceSun(window, m);
			//*this->money += m;
		}
	}
	else
	{
		int m = 0;
		sun.DrawSun(window);
		sun.CollectSun(window, m);
		*money += m;
		clock.restart();
	}
}