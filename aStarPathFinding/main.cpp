#include <iostream>
#include <vector>
#include "game.h"
#include <SFML/Graphics.hpp>


int main()
{

	game* Game = new game();

	Game->update();

	return 0;
}