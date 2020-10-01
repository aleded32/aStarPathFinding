#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class grid;
//variables need for the nodes
class node
{
public:

	grid* GridofNodes;
	bool isWalkable;
	node* PrevNode;
	int x;
	int y;
	sf::RectangleShape shape;

	int gCost;
	int hCost;

	int fcost()
	{
		return gCost + hCost;
	}

	node();
	~node();


};