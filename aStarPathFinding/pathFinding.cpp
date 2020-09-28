#include "pathFinding.h"


pathFinding::pathFinding(grid* _GridOfNodes, sf::RenderWindow* _app, user* _User)
{
	this->GridOfNodes = _GridOfNodes;
	this->app = _app;
	this->User = _User;
}

std::list<node*>* pathFinding::path(user* User,int StartX, int startY, int endX, int endY)
{
	node* startNode = User->GetNodePos(StartX, startY);
	node* endNode = User->GetNodePos(endX, endY);

	openlist = new std::list<node*>;
	closedList = new std::list<node*>;

	openlist->push_back(startNode);

	for(int i = 0; i < GridOfNodes->getWidth(); i++)
	{
		for(int j = 0; j < GridOfNodes->getWidth(); j++)
		{
			node* pathNode = User->GetNodePos(i,j);
			pathNode->gCost = (int)std::numeric_limits<float>::infinity();
			pathNode->fcost();

			pathNode->PrevNode = nullptr;


		}
	}

	startNode->gCost = 0;
	startNode->hCost = getDistance(startNode, endNode);
	startNode->fcost();
	//end of intialising pathfinding

	//pathfinding
	while (openlist->size() > 0)
	{
		node* CurrentNodeInList = GetLowestFcostInList(openlist);

		if(CurrentNodeInList == endNode)
		{
			std::cout << "found node" << std::endl;
			return caluclatedPath(endNode);
		}

		openlist->remove(CurrentNodeInList);
		closedList->push_back(CurrentNodeInList);

		

		for (node* neighbour : *getNeighbour(CurrentNodeInList))
		{

			for(int i = 0; i < closedList->size(); i++)
			{

				bool nodeInClosed = std::find(closedList->begin, closedList->end, neighbour);

				if(std::find(closedList->begin, closedList->end, neighbour) != true)
				{
					continue;
				}
				if(neighbour->isWalkable != true)
				{
					closedList->push_back(neighbour);
				}
			}

			int tentativeGCost = CurrentNodeInList->gCost + getDistance(CurrentNodeInList, neighbour);

			if(tentativeGCost < neighbour->gCost)
			{
				neighbour->PrevNode = CurrentNodeInList;
				neighbour->gCost = tentativeGCost;
				neighbour->hCost = getDistance(neighbour, endNode);
				neighbour->fcost();

				if(bool nodeInOpenList = std::find(getNeighbour(CurrentNodeInList)->begin, getNeighbour(CurrentNodeInList)->end, neighbour) == true)
				{
					openlist->push_back(neighbour);
				}
			}
		}
		

	}
	return nullptr;
}


std::list<node*>*  pathFinding::getNeighbour(node* currentNode)
{
	std::list<node*>* neighbours = new std::list<node*>;

	//left neighbours
	if(currentNode->x -1 >= 0)
	{
		neighbours->push_back(User->GetNodePos(currentNode->x -1, currentNode->y));

		//leftDown
		if(currentNode->y + 1 >= 0)
		{
			neighbours->push_back(User->GetNodePos(currentNode->x -1, currentNode->y +1));
		}

		//leftUp
		if(currentNode->y - 1 >= 0)
		{
			neighbours->push_back(User->GetNodePos(currentNode->x -1, currentNode->y -1));
		}
	
	}
	//right neighbours
	if(currentNode->x +1 >= 0)
	{
		neighbours->push_back(User->GetNodePos(currentNode->x +1, currentNode->y));

		//rightDown
		if(currentNode->y + 1 >= 0)
		{
			neighbours->push_back(User->GetNodePos(currentNode->x +1, currentNode->y +1));
		}

		//leftUp
		if(currentNode->y - 1 >= 0)
		{
			neighbours->push_back(User->GetNodePos(currentNode->x +1, currentNode->y -1));
		}
	
	}

	//up neighbours
	if(currentNode->y -1 >= 0)
	{
		neighbours->push_back(User->GetNodePos(currentNode->x, currentNode->y - 1));
	}
	
	//down Neighbour
	if(currentNode->y + 1 >=0)
	{
		neighbours->push_back(User->GetNodePos(currentNode->x, currentNode->y + 1));	
	}

	return neighbours;
}

node* pathFinding::GetLowestFcostInList(std::list<node*>* openlistNode)
{

	node* LowestCost = openlist->front;
	

}