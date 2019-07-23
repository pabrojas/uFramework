#include "EngineWindow.h"
#include "Logger.h"

using namespace uFramework;

EngineWindow::EngineWindow() : sf::Thread(&EngineWindow::PrivateShow, this)
{
}

void EngineWindow::PrivateShow()
{
	sf::Clock Clock;

	sf::RenderWindow Window(sf::VideoMode(1024, 768), "uFramework");

	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				Window.close();
		}

		Window.clear();

		this->ResourcesMutex.lock();
		
		ObjectIterator Iterator = this->Objects.Begin();
		ObjectIterator End = this->Objects.End();
		
		while (Iterator != End)
		{
			Object* Object = Iterator->second;
			Sprite* Sprite = this->Sprites.GetSprite(Object->SpriteIndex);
			
			Sprite->Tick( Clock.getElapsedTime() );
			sf::Sprite* sfSprite = Sprite->GetCurrent();
			if (sfSprite != nullptr)
			{
				sfSprite->setOrigin(Object->X, Object->Y);
				Window.draw(*(sfSprite));
			}

			Iterator++;
		}
		

		this->ResourcesMutex.unlock();

		Window.display();
	}
}

/*
void EngineWindow::Show()
{
	sf::Thread Thread(&EngineWindow::PrivateShow, this);
	Thread.launch();
	return;
}
*/

bool EngineWindow::CreateSprite(std::string SpriteIndex, int FPS)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Sprites.CreateSprite(SpriteIndex, FPS);
	this->ResourcesMutex.unlock();
	return ReturnValue;
}

bool EngineWindow::AddFrameToSprite(std::string SpriteIndex, std::string Pathname)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Sprites.AddFrame(SpriteIndex, Pathname);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}

bool EngineWindow::AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Objects.AddObject(ObjectIndex, X, Y, SpriteIndex);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}

Point* EngineWindow::GetObjectOrigin(std::string ObjectIndex)
{
	this->ResourcesMutex.lock();
	Point* ReturnValue = this->Objects.GetOrigin(ObjectIndex);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}

bool EngineWindow::SetObjectOrigin(std::string ObjectIndex, float X, float Y)
{
	this->ResourcesMutex.lock();
	bool ReturnValue = this->Objects.SetOrigin(ObjectIndex, X, Y);
	this->ResourcesMutex.unlock();

	return ReturnValue;
}


bool EngineWindow::IsGamepadConnected(int id)
{

	return (sf::Joystick::isConnected(id));
}

bool EngineWindow::IsGamepadbuttonPressed(int GamepadId, int ButtonId)
{
	return  (sf::Joystick::isButtonPressed(GamepadId, ButtonId));
}

float EngineWindow::GetGamepadAxisValue(int GamepadId, int AxisId)
{
	if (AxisId == 0)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::X);
	if (AxisId == 1)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::Y);

	return 0;
}
