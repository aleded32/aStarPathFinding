#include "pathFinding.h"


pathFinding::pathFinding(grid* _GridOfNodes, sf::RenderWindow* _app)
{
	this->GridOfNodes = _GridOfNodes;
	this->app = _app;
}

std::list<node>* pathFinding::path(user* User,int StartX, int startY, int endX, int endY)
{
	node* startNode = User->GetNodePos(GridOfNodes, app, StartX, startY);
	node* endNode = User->GetNodePos(GridOfNodes,app, endX, endY);

	openlist = new std::list<node*>;
	closedList = new std::list<node*>;

	openlist->push_back(startNode);

	for(int i = 0; i < GridOfNodes->getWidth; i++)
	{
		for(int j = 0; j < GridOfNodes->getWidth; j++)
		{
			node* pathNode = User->GetNodePos(GridOfNodes,app, i,j);
			pathNode->gCost = std::numeric_limits<float>::infinity();
			pathNode->fcost();

			pathNode->PrevNode = nullptr;


		}
	}

	startNode->gCost = 0;
	startNode->hCost = getDistance(startNode, endNode);
	startNode->fcost();
	//end of intialising pathfinding

	//pathfinding
	while (openlist->size > 0)
	{
		node* CurrentNodeInList = GetLowestFcostInList(openlist);

		if(CurrentNodeInList == endNode)
		{
			std::cout << "found node" << std::endl;
			return caluclatedPath(endNode);
		}

		openlist->remove(CurrentNodeInList);
		closedList->push_back(CurrentNodeInList);

		for (node* neighbourNode : getNeighbour(CurrentNodeInList))
		{

		}

	}
}


std::list<node*>*  pathFinding::getNeighbour(node* currentNode)
{
	
}