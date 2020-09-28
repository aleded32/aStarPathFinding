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
	
	if(worldPos(gridOfNodes, app).x >= 0 && worldPos(gridOfNodes,app).y >= 0 &&  worldPos(gridOfNodes,app).x < gridOfNodes->width &&  worldPos(gridOfNodes,app).y < gridOfNodes->height )
	{
		gridOfNodes->gridArray[worldPos(gridOfNodes, app).x][worldPos(gridOfNodes, app).y].x = worldPos(gridOfNodes, app).x;
		gridOfNodes->gridArray[worldPos(gridOfNodes, app).x][worldPos(gridOfNodes, app).y].y = worldPos(gridOfNodes, app).y;

		return &gridOfNodes->gridArray[worldPos(gridOfNodes, app).x][worldPos(gridOfNodes, app).y];
		
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