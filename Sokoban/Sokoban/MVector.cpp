#include"RepetirPartida.h"
#include<iostream>
using namespace std;

/*vector<string> VectorRepeticion::insertar(string jugada) {

	vector<string> repeticionJugada;
	repeticionJugada.push_back(jugada);
	//return repeticionJugada;
}


void VectorRepeticion::BorrarVector(vector<string>& vector) {
	if (!vector.empty())
		vector.clear();
}*/

ListaEnlazada mover;
VectorRepetir::VectorRepetir() {
	Repetir.clear();
}

VectorRepetir::~VectorRepetir() {

}
void VectorRepetir::llenarVector(string dato) {
	Repetir.push_back(dato);
}

void VectorRepetir::repetirSolucion(Nodo* n) {
	for (int x = 0; x < Repetir.size(); x++) {
		if (Repetir[x].compare( "Arriba")) {
			mover.MovArriba(n);
		}
		if (Repetir[x].compare("Abajo")) {
			mover.MovAbajo(n);
		}
		if (Repetir[x].compare("Izquierda")) {
			mover.MovIzquierda(n);
		}
		if (Repetir[x].compare("Derecha")) {
			mover.MovDerecha(n);
		}
	}
}