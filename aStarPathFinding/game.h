#pragma once
#include <iostream>
#include <vector>
#include "grid.h"
#include "node.h"
#include <SFML/Graphics.hpp>
#include "user.h"
#include "pathFinding.h"

class game
{
public:

	node* nodes;
	sf::RenderWindow* app;
	grid* Grid;
	user* User;
	pathFinding* aStar;



	game();
	~game();

	void update();
	void render();

};