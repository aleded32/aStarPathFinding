#include "grid.h"

											      
grid::grid(int _width, int _height, int _cellsize, int _originPoint, sf::RenderWindow* app)
{
	this->width = _width;
	this->height = _height;
	this->cellsize = _cellsize;
	this->originPoint = _originPoint;

	gridArray = new node[width * height];

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			
			gridArray[i * j].x = i;
			gridArray[i * j].y = j;

			gridArray[i * j].shape.setPosition(*nodePos(gridArray, cellsize, originPoint, i ,j));
			gridArray[i * j].shape.setSize(sf::Vector2f(20, 20));
			app->draw(gridArray[i * j].shape);
			delete nodePos(gridArray, cellsize, originPoint, i,j);
		}
		
	}
	

}

grid::~grid()
{
	delete gridArray;
	
}