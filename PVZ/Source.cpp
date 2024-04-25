#include "Game.h" // Including neccessary header files

struct Coordinates { // Coordinate class used for tracking sprites
	int x;
	int y;
}; 

int main()
{
	Game g; // Creating Game object
	g.Start_Game(); // Game starts

	return 0;
}