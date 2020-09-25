#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "node.h"
#include "user.h"
#include <list>
#include <limits>

class pathFinding
{
public:

	int HEUSTRIC_COST;
	int STRAIGHT_COST;
	grid* GridOfNodes;
	sf::RenderWindow* app;

	pathFinding(grid* GridOfNodes, sf::RenderWindow* app);

	~pathFinding();

	grid* GetGrid()
	{
		return GridOfNodes;
	}

	std::list<node>* path(user* User,int startX, int startY, int EndX, int EndY);
	std::list<node*>* getNeighbour(node* currentNode);
	std::list<node*>* caluclatedPath(node* endNode);

	int getDistance(node* a, node* b)
	{
		int DisX = abs(a->x - b->x);
		int DisY = abs(a->y - b->y);
		int remaining = abs(DisX - DisY);
		return HEUSTRIC_COST * std::min(DisX,DisY) + STRAIGHT_COST * remaining;
	}


private:

	std::list<node*>* openlist;
	std::list<node*>* closedList;

	node* GetLowestFcostInList(std::list<node*>* openlistNode);
};