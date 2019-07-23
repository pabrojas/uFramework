
#include "EngineWindow.h"
#include "Point.h"
#include "Logger.h"

#include <iostream>

#include <Windows.h>

#include <SFML/Graphics.hpp>

int main()
{
	
	uFramework::EngineWindow Window;

	Window.CreateSprite("Index1", 5);
	Window.AddFrameToSprite("Index1", "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_01.png");
	Window.AddFrameToSprite("Index1", "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_02.png");

	Window.AddObject("Objeto1", -50, -50, "Index1");

	Window.AddObject("Objeto2", -150, -50, "Index1");
	

	Window.launch();

	while (1)
	{
		if (Window.IsGamepadConnected(0))
		{
			uFramework::Point* Origin = Window.GetObjectOrigin("Objeto1");
			if (Origin != nullptr)
			{
				Window.SetObjectOrigin("Objeto1", 
					Origin->X - Window.GetGamepadAxisValue(0, 0) / 20, 
					Origin->Y - Window.GetGamepadAxisValue(0, 1) / 20 );
			}

		}

		Sleep(16);
	}


	/*
	
	
	uFramework::SpriteList List;
	
	List.CreateSprite("Index1", 10);
	List.AddFrame("Index1", "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_01.png");
	List.AddFrame("Index1", "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_02.png");







	//SpriteList slist;

	//slist.createSprite("id1", "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_01.png", { "C:\\Users\\Pablo Rojas\\Desktop\\sokoban\\PNG\\Default size\\Blocks\\block_01.png" });

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	*/

	return 0;
}

