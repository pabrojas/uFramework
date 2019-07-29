
#include <SFML/Graphics.hpp>

#include <iostream>

#include <Windows.h>


int main()
{
	std::cout << "Hello world!" << std::endl;
	return 0;
}



/*

std::string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}


void load_sprites(uFramework::EngineWindow * window)
{
	std::string path = ExePath();


	window->createSprite("sIdle", 1);
	window->addFrameToSprite("sIdle", path + "\\PNG\\Characters\\platformChar_idle.png");

	window->createSprite("sWalk", 10);
	window->addFrameToSprite("sWalk", path + "\\PNG\\Characters\\platformChar_walk1.png");
	window->addFrameToSprite("sWalk", path + "\\PNG\\Characters\\platformChar_walk2.png");

	window->createSprite("sWall", 1);
	window->addFrameToSprite("sWall", path + "\\PNG\\Tiles\\platformPack_tile040.png");
}

int main()
{
	uFramework::EngineWindow Window;
	load_sprites(&Window);
	Window.addIndexedObject("oPlayer", -150, -355, "sIdle");
	Window.addObject(-100, -386, "sWall");
	Window.addObject(-600, -386, "sWall");

	/*
	for (int i = 0; i < 1000; i+=64)
	{
		for (int j = 0; j < 300; j+=64)
		{
			Window.addObject(-(float)i, -(float)450-j, "sWall");
		}
	}
	* /

	Window.launch();

	bool ToLeft = false;
	bool ToRight = false;

	while (1)
	{
		ToLeft = false;
		ToRight = false;

		if (Window.isGamepadConnected(0))
		{
			float AxisValue = Window.getGamepadAxisValue(0, 0);

			if (AxisValue > 20 )
			{
				ToLeft = true;
			}
			else if (AxisValue < -20 )
			{
				ToRight = true;
			}
		}

		if (Window.isKeyPressed("LEFT"))
		{
			ToLeft = true;
		}
		if (Window.isKeyPressed("Right"))
		{
			ToRight = true;
		}


		uFramework::Point* Origin = Window.getObjectOrigin("oPlayer");
		if (Origin != nullptr)
		{


			if (ToRight)
			{
				if (Window.isFree(Origin->x - 5, Origin->y))
				{
					Window.setObjectOrigin("oPlayer", Origin->x - 5, Origin->y);
				}

				Window.setObjectSprite("oPlayer", "sWalk");
				Window.setObjectHorizontalDirection("oPlayer", uFramework::Object::HorizontalDirection::LEFT);

			}
			else if (ToLeft)
			{
				Window.setObjectOrigin("oPlayer", Origin->x + 5, Origin->y);
				Window.setObjectSprite("oPlayer", "sWalk");
				Window.setObjectHorizontalDirection("oPlayer", uFramework::Object::HorizontalDirection::RIGHT);
			}
			else
			{
				Window.setObjectSprite("oPlayer", "sIdle");
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
	* /

	return 0;
}
*/
