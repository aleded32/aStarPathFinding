#include "user.h"


user::user(grid* _GridOfNodes, sf::RenderWindow* _app)
{
	this->app = _app;
	this->gridOfNodes = _GridOfNodes;
}

user::~user()
{

}


node* user::GetNodePos(int x, int y)
{
	
	if(x >= 0 &&y >= 0 &&  x < gridOfNodes->width &&  y < gridOfNodes->height )
	{

		return &gridOfNodes->gridArray[x][y];
		
	}
	else
	{
		return nullptr;
	}
	
}

void user::setWalkable(node* GetNode, bool isWalkable)
{
	
	if(GetNode != nullptr)
	{
		GetNode->isWalkable = isWalkable;
		GetNode->shape.setFillColor(sf::Color(255,120,120,255));

	}
	
	
	

	
}

sf::Vector2i user::worldPos()
{
		

		int gridX = (sf::Mouse::getPosition(*app).x/(gridOfNodes->cellsize * gridOfNodes->getWidth()));
		int gridY = (sf::Mouse::getPosition(*app).y/(gridOfNodes->cellsize * gridOfNodes->getHeight()));

		return sf::Vector2i(gridX,gridY);
}