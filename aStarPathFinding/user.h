#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"




class user
{
public:

	

	sf::Vector2i worldPos(grid* gridOfNodes, sf::RenderWindow* app)
	{
		int gridX = (sf::Mouse::getPosition(*app).x/(gridOfNodes->cellsize *gridOfNodes->width));
		int gridY = (sf::Mouse::getPosition(*app).y/(gridOfNodes->cellsize *gridOfNodes->height));

		return sf::Vector2i(gridX,gridY);
	}

	user(grid* _GridOfNodes, sf::RenderWindow* app);
	~user();

	node* GetNodePos(int x, int y);

	void setWalkable(node* GetNode, bool isWalkable);
	
private: 

	grid* gridOfNodes;
	sf::RenderWindow* app;

};