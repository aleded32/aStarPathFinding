#pragma once
#include <iostream>
#include <vector>
#include "node.h"



class grid
{
public:

	int width, height, cellsize, originPoint;
    node** gridArray;

	grid(int width, int height, int cellsize, int originPoint);
	~grid();

	void RenderNodes(sf::RenderWindow* app);

	int getWidth();

	int getHeight();

};