#include "Game.h" // Including neccessary header files
#include <SFML/Audio.hpp>

int main()
{
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("C:/Users/Ali Abdullah/Downloads/music1.mp3"))
		return -1;

	Game g; // Creating Game object
	g.Start_Game(); // Game starts
	return 0;
}