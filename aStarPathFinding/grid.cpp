#include "grid.h"

											       //change to vector // change to node type
grid<int>::grid(int _width, int _height, int _cellsize, int _originPoint, int value)
{
	this->width = _width;
	this->height = _height;
	this->cellsize = _cellsize;
	this->originPoint = _originPoint;
	
	gridArray = new int[width * height];

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			gridArray[i * j] = value;

			std::cout << gridArray[i * j]  << " "; 

		}

		std::cout << std::endl;
	}
	

}