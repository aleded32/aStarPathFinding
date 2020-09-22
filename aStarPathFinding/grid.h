#pragma once
#include <iostream>
#include <vector>
#include "node.h"



class grid
{
public:

	int width, height, cellsize, originPoint;
    node* gridArray;

	grid(int width, int height, int cellsize, int originPoint,sf::RenderWindow* app);
	~grid();

	sf::Vector2f* nodePos(node* gridArray, int cellsize, int originPoint, int i, int j)
	{
	     int x = gridArray[i * j].x * cellsize + originPoint;
		 int y = gridArray[i * j].y * cellsize;

		 return new sf::Vector2f(x,y);
	}

};