#include "ListasEnlazadas.h"
#include<string>
#include<iostream>

#define DIRECCION_NIVEL1 "../Niveles/nivel1.txt"
#define DIRECCION_NIVEL2 "../Niveles/nivel2.txt"
#define DIRECCION_NIVEL3 "../Niveles/nivel3.txt"
#define DIRECCION_NIVEL4 "../Niveles/nivel4.txt"
#define DIRECCION_NIVEL5 "../Niveles/nivel5.txt"
#define DIRECCION_PARTIDA_GUARDADA "../Niveles/partidaAnterior.txt"

using namespace std;

struct NivelArch {
	NivelArch();
	string NivelSeleccionado(int);
	void LeerNivel(string Nombre, ListaEnlazada Lista, Nodo*& Actual);
	void EscribirArchivo(string dato);
};

