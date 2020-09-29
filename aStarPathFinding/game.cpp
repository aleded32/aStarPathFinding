#include "game.h"

game::game()
{
	app = new sf::RenderWindow(sf::VideoMode(800,800), "a* pathFinding");
	Grid = new grid(8,8,10,0);
	User = new user(Grid, app);
	aStar = new pathFinding(Grid, app, User);
	
};

game::~game()
{
	delete app;
	delete User;
	delete Grid;
	
}



void game::update()
{


	

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

		
			
	
			std::list<node*>* pathAstar =  aStar->path(User, Grid->gridArray[2][1].x,  Grid->gridArray[2][1].y,  Grid->gridArray[4][3].x, Grid->gridArray[4][3].y);
		
			if(pathAstar != nullptr)
			{
				std::list<node*>::iterator it;

				for(it = pathAstar->begin(); it != pathAstar->end(); it++)
				{
					(*it)->shape.setFillColor(sf::Color::Green);
				}
			}
	
		
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			User->setWalkable(User->GetNodePos(User->worldPos().x, User->worldPos().y), true);
				
		}
		
		
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