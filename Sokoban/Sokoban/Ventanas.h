#ifndef VENTANAS_H
#define VENTANAS_H

#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include "MenuInicial.h"
#include "ListasEnlazadas.h"
#include "Niveles.h"
#include "Tablero.h"
//#include "RepetirPartida.h"

using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::string;


class Ventanas {

public:
	Ventanas();
	~Ventanas();

	void MenuInicial();


private:

	// Declaracion de variables necesarias de la clase
	bool Jugando = false;
	bool MenuActivo = true;
	bool Movimiento = false;
	int	TamAncho = 0;
	int	TamAlto = 0;
	bool IniciarJuego = false;
	Nodo* Temporal = nullptr;
	sf::Time tiempo = sf::seconds(0.5f);
	void MnejoEventosTeclado(sf::RenderWindow& window);
	void InicializarJuego(int nivel);
	void MovimientoPersonaje(int dir);
	void Teclado(sf::RenderWindow& window, Nodo*& n);
	int NivelSeleccionado = 1;
	void MedidasPantalla(sf::RenderWindow& window);
	void SiguienteNivel(int Nivel, bool sig);

};
#endif
