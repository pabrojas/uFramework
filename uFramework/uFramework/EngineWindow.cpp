#include "EngineWindow.h"
#include "Logger.h"

using namespace uFramework;

uFramework::EngineWindow::EngineWindow() : sf::Thread(&EngineWindow::PrivateShow, this)
{
}

void uFramework::EngineWindow::PrivateShow()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "uFramework");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		this->ResourcesMutex.lock();
		
		ObjectIterator Iterator = this->Objects.Begin();
		ObjectIterator End = this->Objects.End();
		
		while (Iterator != End)
		{
			Object* Object = Iterator->second;
			Sprite* Sprite = this->Sprites.GetSprite(Object->SpriteIndex);
			
			sf::Sprite* sfSprite = Sprite->GetCurrent();
			if (sfSprite != nullptr)
			{
				sfSprite->setOrigin(Object->X, Object->Y);
				window.draw(*(sfSprite));
			}

			Iterator++;
		}
		

		this->ResourcesMutex.unlock();

		window.display();
	}
}

void uFramework::EngineWindow::Show()
{
	sf::Thread thread(&EngineWindow::PrivateShow, this);
	thread.launch();
	return;
}

bool uFramework::EngineWindow::CreateSprite(std::string SpriteIndex, int FPS)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Sprites.CreateSprite(SpriteIndex, FPS);
	this->ResourcesMutex.unlock();
	return ReturnValue;
}

bool uFramework::EngineWindow::AddFrameToSprite(std::string SpriteIndex, std::string Pathname)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Sprites.AddFrame(SpriteIndex, Pathname);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}

bool uFramework::EngineWindow::AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Objects.AddObject(ObjectIndex, X, Y, SpriteIndex);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}
