#ifndef ListasEnlazadas_H
#define ListasEnlazadas_H

#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;

#define NIVEL1 30;
#define NIVEL2 30;
#define NIVEL3 30;
#define NIVEL4 30;
#define NIVEL5 30;



struct Nodo {
	char Caracter;
	char Aux;
	int valor;
	Nodo* Arriba;
	Nodo* Abajo;
	Nodo* Derecha;
	Nodo* Izquierda;
	Nodo* Siguiente;

};

class ListaEnlazada {
public:
	ListaEnlazada() {
		Inicio = nullptr;
	}
	~ListaEnlazada() {

	}
	//------------Metodos para el mapa--------------------------------
	void Insertar(Nodo*&, char, int);
	void MostrarLista(Nodo*& n);
	void CargarTexturasNivel(std::string matriz, int nivel);

	//-----------Metodos para los movimientos del jugador-------------
	void MovArriba(Nodo*&);
	void MovAbajo(Nodo*&);
	void MovDerecha(Nodo*&);
	void MovIzquierda(Nodo*&);

	Nodo* PosJugador(Nodo*&);

	std::vector<char> AreaJuego;

	string LeerMatriz(Nodo*&);
	

	int ColumnaMapa;
	int FilaMapa;
	int Posx;
	int Posy;

private:
	Nodo* Inicio;
	Nodo* Nuevo;

	bool ListaVacia(Nodo*& Inicio);
	void BorrarLista(Nodo*&);
	void VerificarNivel(int Nivel);


};
#endif

