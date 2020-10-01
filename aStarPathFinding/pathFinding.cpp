#include "pathFinding.h"


pathFinding::pathFinding(grid* _GridOfNodes, sf::RenderWindow* _app, user* _User)
{
	this->GridOfNodes = _GridOfNodes;
	this->app = _app;
	this->User = _User;
	HEUSTRIC_COST = 14;
	STRAIGHT_COST = 10;
}

std::list<node*>* pathFinding::path(user* User,int StartX, int startY, int endX, int endY)
{
	//start of intiallising pathfinding
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
			pathNode->gCost = std::numeric_limits<int>::max();
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

		
		//loop through neighbour list to find the lowest cost neighbour by, comparning it the tentative gCost
		for (node* neighbour : *getNeighbour(CurrentNodeInList))
		{
			
			bool contains = std::find(closedList->begin(), closedList->end(), neighbour) != closedList->end();

				if(contains == true)
				{
					continue;
				}
				if(neighbour->isWalkable == false)
				{
				
					closedList->push_back(neighbour);
					continue;
				}
			

			bool nodeInOpen = (std::find(openlist->begin(), openlist->end(), neighbour) != openlist->end());
			int tentativeGCost = CurrentNodeInList->gCost + getDistance(CurrentNodeInList, neighbour);
			
			
			
			if(tentativeGCost < neighbour->gCost)
			{
				
				neighbour->PrevNode = CurrentNodeInList;
				neighbour->gCost = tentativeGCost;
				neighbour->hCost = getDistance(neighbour, endNode);
				neighbour->fcost();
				
				if(nodeInOpen == false)
				{
					openlist->push_back(neighbour);
					
				}
			}
		}
		
		
	}
	return nullptr;
}

//generates a list of neighbours arround the current node
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

//find the lowestFcost in the open list
node* pathFinding::GetLowestFcostInList(std::list<node*>* openlistNode)
{

	node* LowestCost = openlist->front();
	std::list<node*>:: iterator it;


	for(it = openlist->begin(); it != openlist->end(); it++)
	{
		if( (*it)->fcost() < LowestCost->fcost())
		{
			 LowestCost = (*it);
		}
		
	}
	return LowestCost;
}


// add the path to a new list and reverse the list to find the path
std::list<node*>* pathFinding::caluclatedPath(node* endNode)
{
	std::list<node*>* pathToTarget = new std::list<node*>;

	pathToTarget->push_back(endNode);
	node* currentNode = endNode;

	while(currentNode->PrevNode != nullptr)
	{
		pathToTarget->push_back(currentNode->PrevNode);
		currentNode = currentNode->PrevNode;
	}

	pathToTarget->reverse();

	return pathToTarget;
}

void pathFinding::showPath(std::list<node*>* pathList, std::list<node*>::iterator it, sf::Color color)
{
	for(it = pathList->begin(); it != pathList->end(); it++)
	{
		(*it)->shape.setFillColor(color);
	}
}