#include "grid.h"

											      
grid::grid(int _width, int _height, int _cellsize, int _originPoint)
{
	this->width = _width;
	this->height = _height;
	this->cellsize = _cellsize;
	this->originPoint = _originPoint;

	gridArray = new node* [width];

	for(int i = 0; i < width; i++)
	{

		gridArray[i] = new node[height];

		for(int j = 0; j < height; j++)
		{
			
			gridArray[i][j].x = i;
			gridArray[i][j].y = j;

			gridArray[i][j].shape.setPosition((i * width) * cellsize + originPoint, (j* height) * cellsize);
			gridArray[i][j].shape.setSize(sf::Vector2f(50, 50));
			

			
		}
		
	}
	

}

grid::~grid()
{
	//delete gridArray;
	
}

void grid::RenderNodes(sf::RenderWindow* app)
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			app->draw(gridArray[i][j].shape);
		}
	}
}

int grid::getWidth()
{
	return width;
}

int grid::getHeight()
{
	return height;
}