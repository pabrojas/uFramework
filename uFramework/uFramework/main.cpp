

#include "EngineWindow.h"
#include "Point.h"

#include <iostream>
#include <Windows.h>
#include <memory>

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
	Window.addIndexedObject("oPlayer1", -150, -55, "sIdle");
	Window.addIndexedObject("oPlayer2", -150, -455, "sIdle");

	Window.addTaggedObject("wall", -160, -285, "sWall");

	//Window.addTaggedObject("wall", -50, -386, "sWall");
	//Window.addTaggedObject("wall", -600, -386, "sWall");
	//Window.addIndexedObject("oWall2", -100, -386, "sWall");
	//Window.addIndexedObject("oWall1",-600, -386, "sWall");


	float ySpeed = 0;
	float gravity = -1;



	
	for (int i = 0; i < 1000; i+=64)
	{
		for (int j = 0; j < 300; j+=64)
		{
			//Window.addTaggedObject("wall",-(float)i, -(float)450-j, "sWall");
		}
	}
	

	Window.launch();

	bool ToLeft = false;
	bool ToRight = false;

	while (!Window.isClosed())
	{
		ySpeed = gravity;


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

		//ToLeft = false;
		//ToRight = true;



		std::shared_ptr<uFramework::Point> Origin1 = Window.getObjectOrigin("oPlayer1");
		std::shared_ptr<uFramework::Point> Origin2 = Window.getObjectOrigin("oPlayer2");
		if (Origin1 != nullptr)
		{
			
			//Actualizar Eje Y
			//Window.setObjectOrigin("oPlayer", Origin->x, Origin->y - ySpeed);
			if (!Window.objectDeltaCollidesTag("oPlayer1", "wall", 0, ySpeed))
			{
				Window.setObjectOrigin("oPlayer1", Origin1->x, Origin1->y + ySpeed);
			}
			else
			{
				//ySpeed = 0;
				//gravity = 0;
				//Window.setObjectOrigin("oPlayer", Origin->x, Origin->y + 0.1);
			}

			if (!Window.objectDeltaCollidesTag("oPlayer2", "wall", 0, -ySpeed))
			{
				//Window.setObjectOrigin("oPlayer2", Origin2->x, Origin2->y - ySpeed);
			}
			else
			{
				//ySpeed = 0;
				//gravity = 0;
				//Window.setObjectOrigin("oPlayer", Origin->x, Origin->y + 0.1);
			}

			
			
			
			//Actualizar Eje X
			
			int step = 1;

			if (ToRight)
			{
				//if (Window.isFree(Origin->x - 5, Origin->y))
				//if( !Window.objectCollidesObject("oPlayer", "oWall1") )
				if (!Window.objectCollidesTag("oPlayer1", "wall"))
				{
					Window.setObjectOrigin("oPlayer1", Origin1->x - step, Origin1->y);
				}
				Window.setObjectSprite("oPlayer1", "sWalk");
				Window.setObjectHorizontalDirection("oPlayer1", uFramework::Enums::HorizontalDirection::LEFT);



			}
			else if (ToLeft)
			{
				//if (Window.isFree(Origin->x - step, Origin->y))
				if (!Window.objectCollidesTag("oPlayer1", "wall"))
				{
					Window.setObjectOrigin("oPlayer1", Origin1->x + step, Origin1->y);
				}
				Window.setObjectSprite("oPlayer1", "sWalk");
				Window.setObjectHorizontalDirection("oPlayer1", uFramework::Enums::HorizontalDirection::RIGHT);
			}
			else
			{
				Window.setObjectSprite("oPlayer1", "sIdle");
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

