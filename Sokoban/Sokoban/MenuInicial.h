#ifndef MENUINICIAL_H
#define MENUINICIAL_H
#include <SFML/Graphics.hpp> 

#define MAXIMO_OPCIONES 8
#define DIR_FUENTES "../Fuentes/OriginTech personal use.ttf"

class menuInicial
{
public:

	menuInicial(float width, float height);
	~menuInicial();

	void draw(sf::RenderWindow& window);
	void MoverArriba();
	void MoverAbajo();
	int ObtenerItem() {
		return SeleccionarItem;
	}

private:
	int SeleccionarItem;
	sf::Font font;
	sf::Text menu[MAXIMO_OPCIONES];
	void CargarOpciones(float x, float y);
	void CargarFuentes();

};

#endif
