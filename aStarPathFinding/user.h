#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "node.h"




class user
{
public:

	grid* gridOfNodes;
	sf::RenderWindow* app;

	
	

	user(grid* _GridOfNodes, sf::RenderWindow* app);
	~user();

	node* GetNodePos(int x, int y);


	void setWalkable(node* GetNode, bool isWalkable);
	sf::Vector2i worldPos();
private: 

	

};