#include "game.h"

game::game()
{
	app = new sf::RenderWindow(sf::VideoMode(800,800), "a* pathFinding");
	User = new user(Grid, app);
	Grid = new grid(8,8,10,0);
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

		
		
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			User->setWalkable(User->GetNodePos(User->worldPos(Grid, app).x, User->worldPos(Grid, app).y), true);
				
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