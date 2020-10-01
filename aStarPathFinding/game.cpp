#include "game.h"

game::game()
{
	//creates pointers
	app = new sf::RenderWindow(sf::VideoMode(800,800), "a* pathFinding");
	Grid = new grid(8,8,10,0);
	User = new user(Grid, app);
	aStar = new pathFinding(Grid, app, User);
	
};

game::~game()
{
	//removes pointers from heap memory
	delete app;
	delete User;
	delete Grid;
	//delete aStar;

}



void game::update()
{

	//game Loop
	while (app->isOpen())
	{
		sf::Event e;
		while(app->pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				app->close();
			}
		}

		//setting colours of start and end point;

		

		//calling to calculate the path
		std::list<node*>* pathAstar =  aStar->path(User, Grid->gridArray[1][1].x,  Grid->gridArray[1][1].y,  Grid->gridArray[7][3].x, Grid->gridArray[7][3].y);	
		std::list<node*>::iterator it;
		

		//show the path drawn
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{		
			if(pathAstar != nullptr)
			{
				aStar->showPath(pathAstar, it, sf::Color::Green);
			}
				
		}
		else
		{
			if(pathAstar != nullptr)
			{
				aStar->showPath(pathAstar, it, sf::Color::Red);
			}
		}

		Grid->gridArray[1][1].shape.setFillColor(sf::Color::White);
		Grid->gridArray[7][3].shape.setFillColor(sf::Color::Blue);
		
		//set walkable nodes unwalkable
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			User->setWalkable(User->GetNodePos(User->worldPos().x, User->worldPos().y), false);
		}
		
		//render images on screen
		render();
		
	}
}

void game::render()
{
	

	app->clear();

  
	
	 Grid->RenderNodes(app);
		

	//std::cout << User->GetNodePos(Grid, app).isWalkable << std::endl;
	

	app->display();
}