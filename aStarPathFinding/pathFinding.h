#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "node.h"
#include "user.h"
#include <list>
#include <limits>
#include <algorithm>

class pathFinding
{
public:

	int HEUSTRIC_COST;
	int STRAIGHT_COST;
	

	pathFinding(grid* GridOfNodes, sf::RenderWindow* app, user* _User);

	~pathFinding();

	node* GetLowestFcostInList(std::list<node*>* openlistNode);


	grid* GetGrid()
	{
		return GridOfNodes;
	}

	std::list<node*>* path(user* User,int startX, int startY, int EndX, int EndY);
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

	grid* GridOfNodes;
	sf::RenderWindow* app;
	user* User;

	std::list<node*>* openlist;
	std::list<node*>* closedList;

	
};