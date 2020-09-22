#include "game.h"

game::game()
{
	app = new sf::RenderWindow(sf::VideoMode(800,800), "a* pathFinding");
	nodes = new node;
	
};

game::~game()
{
	delete app;
	
	
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
		render();
	}
}

void game::render()
{
	

	app->clear();

  
	Grid = new grid(16,10,50,10,app);
	
	

	app->display();
}