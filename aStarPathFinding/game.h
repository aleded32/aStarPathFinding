#include <iostream>
#include <vector>
#include "grid.h"
#include <SFML/Graphics.hpp>

class game
{
public:

	sf::RenderWindow* app;
	grid<int>* Grid;

	game();
	~game();

	void update();
	void render();

};