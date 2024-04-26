#pragma once
class Coordinates
{
protected:

	int x, y; // Coordinates x and y
public:
	Coordinates(int x=0,int y=0):x(x),y(y){} // Default and paramaterized constructor
	// Getters
	int GetX()const { return x; }
	int GetY()const { return y; }
	// Setters
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
};

