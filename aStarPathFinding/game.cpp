#include "game.h"

game::game()
{
	app = new sf::RenderWindow(sf::VideoMode(800,800), "a* pathFinding");
	Grid = new grid<int>(10,10,0,0,2);
};

game::~game()
{

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


	app->display();
}