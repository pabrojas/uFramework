/*#include <SFML/Graphics.hpp>

//comentario

int main()
{
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
	}*/
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

	int main()
	{
		sf::RenderWindow window(sf::VideoMode(1024, 756), "Using sf::View", sf::Style::Close | sf::Style::Titlebar); // Create window
		window.setFramerateLimit(60); // Set a framrate limit to reduce the CPU load
		window.setMouseCursorVisible(false); // Hide the cursor
		sf::Texture texOverlay; // Create the overlay texture and sprite
		texOverlay.loadFromFile("overlay.png");
		sf::Sprite overlay(texOverlay);
		overlay.setPosition(100.f, 100.f);
		sf::View fixed = window.getView(); // The 'fixed' view will never change
		/*sf::Texture texMap; // Create the world texture and sprite
		texMap.loadFromFile("world.png");
		sf::Sprite map(texMap);

		sf::Texture texLink; // Create the link texture and sprite which will be out cursor
		texLink.loadFromFile("link.png");
		sf::Sprite link(texLink);
		link.setOrigin(8.f, 8.f); // The cursors point should be in the middle

		sf::View fixed = window.getView(); // The 'fixed' view will never change

		sf::View standard = fixed; // The 'standard' view will be the one that gets always displayed

		unsigned int size = 200; // The 'minimap' view will show a smaller picture of the map
		sf::View minimap(sf::FloatRect(standard.getCenter().x, standard.getCenter().y, static_cast<float>(size), static_cast<float>(window.getSize().y * size / window.getSize().x)));
		minimap.setViewport(sf::FloatRect(1.f - static_cast<float>(minimap.getSize().x) / window.getSize().x - 0.02f, 1.f - static_cast<float>(minimap.getSize().y) / window.getSize().y - 0.02f, static_cast<float>(minimap.getSize().x) / window.getSize().x, static_cast<float>(minimap.getSize().y) / window.getSize().y));
		minimap.zoom(4.f);

		// The 'left' and the 'right' view will be used for splitscreen displays
		sf::View left(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y)));
		left.setViewport(sf::FloatRect(0.f, 0.f, 0.5, 1.f));
		sf::View right(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y)));
		right.setViewport(sf::FloatRect(0.5, 0.f, 0.5, 1.f));
		right.move(100.f, 100.f); // The 'right' view should be set a bit diffrent to notice the difference

		sf::RectangleShape miniback; // We want to draw a rectangle behind the minimap
		miniback.setPosition(minimap.getViewport().left * window.getSize().x - 5, minimap.getViewport().top * window.getSize().y - 5);
		miniback.setSize(sf::Vector2f(minimap.getViewport().width * window.getSize().x + 10, minimap.getViewport().height * window.getSize().y + 10));
		miniback.setFillColor(sf::Color(160, 8, 8));

		/*sf::Text position("<0, 0> - <0, 0>"); // The text will contain the position of the cursor
		position.setPosition(10.f, 10.f);
		position.setColor(sf::Color::White);

		sf::Vector2i pos = sf::Mouse::getPosition(); // We will keep track of the old mouse position

		bool overlayClosed = false; // Is the overlay closed?
		bool toggleSplit = false; // Should the screen be split?
		bool moved = true; // Did the views move?
		std::stringstream ss; // Used to convert integers and floats to strings

		while (window.isOpen()) // As long as the window is open
		{
			sf::Event event; // Normal event handling

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (overlayClosed && event.type == sf::Event::MouseWheelMoved) // Zomm in or out if the mouse wheel moves
				{
					standard.zoom(1.f + event.mouseWheel.delta * 0.1f);
					left.zoom(1.f + event.mouseWheel.delta * 0.1f);
					right.zoom(1.f + event.mouseWheel.delta * 0.1f);
					moved = true;
				}
				else if (overlayClosed && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Q)
				{
					toggleSplit = !toggleSplit; // Split or unsplit the screen only on releasing the key Q
				}
			}

			if (overlayClosed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // Rotate counter clockwise
				{
					standard.rotate(0.25f);
					minimap.rotate(0.25f);
					left.rotate(0.25f);
					right.rotate(0.25f);
					moved = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) // Rotate clockwise
				{
					standard.rotate(-0.25f);
					minimap.rotate(-0.25f);
					left.rotate(-0.25f);
					right.rotate(-0.25f);
					moved = true;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					// Move left
					standard.move(-4.f, 0.f);
					minimap.move(-4.f, 0.f);
					left.move(-4.f, 0.f);
					right.move(-4.f, 0.f);
					moved = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					// Move right
					standard.move(4.f, 0.f);
					minimap.move(4.f, 0.f);
					left.move(4.f, 0.f);
					right.move(4.f, 0.f);
					moved = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					// Move up
					standard.move(0.f, -4.f);
					minimap.move(0.f, -4.f);
					left.move(0.f, -4.f);
					right.move(0.f, -4.f);
					moved = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					// Move down
					standard.move(0.f, 4.f);
					minimap.move(0.f, 4.f);
					left.move(0.f, 4.f);
					right.move(0.f, 4.f);
					moved = true;
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				overlayClosed = true; // Close overlay

			if (moved || pos != sf::Mouse::getPosition(window)) // Views got moved or the mouse got moved
			{
				pos = sf::Mouse::getPosition(window); // Get the new position
				link.setPosition(static_cast<sf::Vector2f>(pos)); // Set Link to the new position

				// Convert the position:
				//		left: relative position on the window
				//		right: relative position to the standard view
				ss.str("");
			//	ss << "<" << pos.x << ", " << pos.y << ">\t<" << window.convertCoords(pos, standard).x << ", " << window.convertCoords(pos, standard).y << ">";
			//	position.setString(ss.str());
			}

			window.clear(); // Remove old content

			if (!toggleSplit) // Draw one map for none split screen
			{
				window.setView(standard);
				window.draw(map);
			}
			else // Draw two maps for split screen
			{
				window.setView(left);
				window.draw(map);
				window.setView(right);
				window.draw(map);
			}

			window.setView(fixed); // Draw 'GUI' elements with fixed positions
			//window.draw(position);
			window.draw(miniback);

			window.setView(minimap); // Draw minimap
			window.draw(map);

			window.setView(fixed);
			if (!overlayClosed)
				window.draw(overlay);
			window.draw(link);

			window.display(); // Show everything
		}*/

		return 0;
	//}

}