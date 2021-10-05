#ifndef TABLERO_H
#define TABLERO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ventanas.h"
//#include "ListasEnlazadas.h"


#define DIRECCION_PARED "../Recursos/paredcita.jpg"
#define DIRECCION_CAMINO "../Recursos/camino.png"
#define DIRECCION_JUGADOR "../Recursos/Sonic.gif"
#define DIRECCION_CAJA "../Recursos/icon.png"
#define DIRECCION_CAMPOCAJA "../Recursos/campitovacio.png"
#define DIRECCION_CAJAPUESTA "../Recursos/cajas.png"
#define DIRECCION_SONIDO_PAUSA "../Recursos/Endofline.wav"
#define DIRECCION_MUSICA_TECLAS "../Recursos/confirm.wav"
#define DIRECCION_MUSICA_FONDO "../Recursos/Endofline.wav"

using namespace sf;

class Tablero {
public:
	Tablero();
	~Tablero();

	void DibujarCambios(RenderWindow& window, Nodo*& Inicio);
	void DibujarMapa(RenderWindow& window);
	void ActualizarMatriz(Nodo*& Inicio);
	void CargarTexturas();
	void CargarMusica();
	void ReproducirMusica(int Sonido);
	void PausarMusica();

private:
	Texture Pared;
	Texture Camino;
	Texture Caja;
	Texture CampoCaja;
	Texture Personaje;
	Texture CajaPuesta;
	Event Evento;
	Sprite Bichito;

	SoundBuffer MusPausa;
	SoundBuffer MusTecla;
	SoundBuffer MusFondo;

	Sound Sonido;
	Music Musica;

	vector<char>AreaJuego;
	void EliminarContVector();

	string Matriz;
	string DirPared;
	string DirCaja;
	string DirCampoCaja;
	string DirCajapuesta;
	string DirPersonaje;
	string DirCamino;
	char Caracter;
	unsigned int Posx;
	unsigned int Posy;
	ListaEnlazada Listita;

};
#endif 
