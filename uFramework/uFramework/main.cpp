#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
	float OriginalAnch = 450, OriginalLarg = 100;
	sf::RenderWindow window(sf::VideoMode(900, 200), "Camera"); 
	sf::Texture texture;
	if (!texture.loadFromFile("fondo.jpg"))
	{
		std::cout << "error" << std::endl;
	}
	else {
		texture.loadFromFile("fondo.jpg");
		sf::Sprite map(texture);
		sf::View view1(sf::Vector2f(OriginalAnch, OriginalLarg), sf::Vector2f(900.f,OriginalLarg*2)); //construir una vista de 300 x 200(se define por una proporción de la ventana no en pixeles) con un centro en (350,300). 
		
		view1.setCenter(OriginalAnch, OriginalLarg); //Las vistas siempre son manipuladas por su centro

		// run the program as long as the window is open
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{

				// respuesta para cierre de la ventana
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				//mover a la derecha
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					OriginalAnch = OriginalAnch + 60.f;
				view1.setCenter(OriginalAnch, OriginalLarg); 
			}
				//mover a la izquierda
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					OriginalAnch = OriginalAnch - 60.f;
					view1.setCenter(OriginalAnch, OriginalLarg);
				}

				//mover abajo
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					OriginalLarg = OriginalLarg + 60.f;
					view1.setCenter(OriginalAnch, OriginalLarg);
				}
				//mover arriba
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					OriginalLarg = OriginalLarg - 60.f;
					view1.setCenter(OriginalAnch, OriginalLarg);
				}
			}
			window.clear();
			window.setView(view1);
			window.draw(map); //dibujar sprite en el buffer
			window.display();//mostrar en ventana
		}

	}

	return 0;
}