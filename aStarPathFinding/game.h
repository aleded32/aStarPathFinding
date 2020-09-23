#pragma once
#include <iostream>
#include <vector>
#include "grid.h"
#include "node.h"
#include <SFML/Graphics.hpp>
#include "user.h"

class game
{
public:

	node* nodes;
	sf::RenderWindow* app;
	grid* Grid;
	user* User;



	game();
	~game();

	void update();
	void render();

};