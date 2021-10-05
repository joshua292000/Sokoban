#include "Niveles.h"
#include "ListasEnlazadas.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

NivelArch::NivelArch() {

}

string NivelArch::NivelSeleccionado(int Numero) {
	string NombreNivel = "";
	int NumNivel = Numero;
	if (NumNivel == 1) {
		NombreNivel = DIRECCION_NIVEL1;
	}
	else if (NumNivel == 2) {
		NombreNivel = DIRECCION_NIVEL2;
	}
	else if (NumNivel == 3) {
		NombreNivel = DIRECCION_NIVEL3;
	}
	else if (NumNivel == 4) {
		NombreNivel = DIRECCION_NIVEL4;
	}
	else if (NumNivel == 5) {
		NombreNivel = DIRECCION_NIVEL5;
	}
	return NombreNivel;
}

void NivelArch::LeerNivel(string Nombre, ListaEnlazada Lista, Nodo*& Actual) {
	ifstream Archivo;
	string Linea;
	int CantCaracteres;
	int Cont = 0;
	Archivo.open(Nombre);
	if (Archivo.is_open()) {
		while (getline(Archivo, Linea)) {
			CantCaracteres = Linea.length();
			for (int i = 0; i <= CantCaracteres; i++) {
				if (Linea[i] == ' ' || Linea[i] == '#' || Linea[i] == '$' || Linea[i] == '.' || Linea[i] == '@' || Linea[i] == '!') {
					Lista.Insertar(Actual, Linea[i], Cont);
				}
			}
			Cont++;
		}
		Archivo.close();
	}
}

void NivelArch::EscribirArchivo(string Partida) {
	ofstream Archivo;
	Archivo.open(DIRECCION_PARTIDA_GUARDADA, ios::app);
	if (Archivo.is_open()) {
		Archivo << Partida;
		cout << "Partida guardada exitosamente" << endl;
		Archivo.close();
	}
}