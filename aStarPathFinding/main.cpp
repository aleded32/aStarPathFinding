#include <iostream>
#include "game.h"
#include <SFML/Graphics.hpp>


int main()
{

	game* Game = new game();

	Game->update();
	delete Game;
	return 0;
}