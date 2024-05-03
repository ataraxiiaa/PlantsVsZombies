#pragma once

#include "Plants.h" // Include necassary header file(s)
#include "Sun.h"
#include <iostream>
using namespace std;

class SunPlant : public Plants
{
protected:
	Sun sun;
	int* money;
	Clock clock;
	int time;
public:
	SunPlant();
	void SetMoneyptr(int& money);
	void ProduceSun(RenderWindow& window, int& money);
	virtual void Action(RenderWindow& window); // Declared virtual in plant class

};

