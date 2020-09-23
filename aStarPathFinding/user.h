#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"




class user
{
public:

	

	sf::Vector2i* worldPos(grid* gridOfNodes, sf::RenderWindow* app)
	{
		int gridX = (sf::Mouse::getPosition(*app).x/(gridOfNodes->cellsize *gridOfNodes->width));
		int gridY = (sf::Mouse::getPosition(*app).y/(gridOfNodes->cellsize *gridOfNodes->height));

		return new sf::Vector2i(gridX,gridY);
	}

	user();
	~user();

	node GetNodePos(grid* gridOfNodes, sf::RenderWindow* app);

	void setWalkable(node& GetNode, bool isWalkable);
	

};