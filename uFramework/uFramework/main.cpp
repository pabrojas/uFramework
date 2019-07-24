/*Permite a trav�s de las teclas A S D W  mover la c�mara,  la vista (c�mara) se mueve seg�n la indicaci�n proporcionada para el centro de esta,
la cual corresponde a una proporci�n de la ventana.
La ventana gr�fica utiliza un sistema de coordenadas cartesiano, el punto (0, 0) se encuentra en la esquina superior izquierda y los valores m�ximos de x / y en la 
esquina inferior derecha, por lo tanto el centro de visi�n de la camara se define desde el punto medio del �rea de visualizaci�n. El punto (0,0) en la c�mara ser� 
presentado en el centro de esta. */
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
	float OriginalAnch = 450, OriginalLarg = 100, rotacion=0;
	bool zoom = false;
	sf::RenderWindow window(sf::VideoMode(900, 200), "Camera"); 
	sf::Texture texture;
	if (!texture.loadFromFile("fondo.jpg"))
	{
		std::cout << "error" << std::endl;
	}
	else {
		texture.loadFromFile("fondo.jpg");
		sf::Sprite map(texture);
		sf::View view1(sf::Vector2f(OriginalAnch, OriginalLarg), sf::Vector2f(900.f,OriginalLarg*2)); /*construir una vista definida por una proporci�n de la ventana,
																									  no en pixeles, con un centro en (OriginalAnch, OriginalLarg). 
																									  Centro y tama�o respectivamente (ancho por alto)*/ 
		
		view1.setCenter(OriginalAnch, OriginalLarg);  //Las vistas siempre son manipuladas por su centro

	

		
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
				//Rotar Izquierda
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					rotacion = rotacion + 5.f;
					view1.setRotation(rotacion);
				}
				//Rotar derecha
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					rotacion = rotacion - 5.f;
					view1.setRotation(rotacion);
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