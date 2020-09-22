#pragma once
#include <iostream>
#include <vector>
#include "grid.h"
#include "node.h"
#include <SFML/Graphics.hpp>

class game
{
public:

	node* nodes;
	sf::RenderWindow* app;
	grid* Grid;



	game();
	~game();

	void update();
	void render();

};