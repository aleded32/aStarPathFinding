#include "user.h"


user::user()
{

}

user::~user()
{

}


node user::GetNodePos(grid* gridOfNodes, sf::RenderWindow* app)
{
	
	if(worldPos(gridOfNodes, app)->x >= 0 && worldPos(gridOfNodes,app)->y >= 0 &&  worldPos(gridOfNodes,app)->x < gridOfNodes->width &&  worldPos(gridOfNodes,app)->y < gridOfNodes->height )
	{
		gridOfNodes->gridArray[worldPos(gridOfNodes, app)->x][worldPos(gridOfNodes, app)->y].x = worldPos(gridOfNodes, app)->x;
		gridOfNodes->gridArray[worldPos(gridOfNodes, app)->x][worldPos(gridOfNodes, app)->y].y = worldPos(gridOfNodes, app)->y;

		return gridOfNodes->gridArray[worldPos(gridOfNodes, app)->x][worldPos(gridOfNodes, app)->y];
		
	}
	else
	{
		std::cout << "error" << std::endl;
		return gridOfNodes->gridArray[0][0];
	}
	
}

void user::setWalkable(node& GetNode, bool isWalkable)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		std::cout << GetNode.isWalkable << std::endl;
		GetNode.isWalkable = isWalkable;
		
	}
	std::cout << GetNode.isWalkable << std::endl;

	
}