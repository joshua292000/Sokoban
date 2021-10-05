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
	else if (NumNivel == 6) {
		NombreNivel = DIRECCION_PARTIDA_GUARDADA;

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

void NivelArch::EscribirArchivo(Nodo*& Inicio) {
	ofstream Archivo;
	Archivo.open(DIRECCION_PARTIDA_GUARDADA, std::ofstream::out | std::ofstream::trunc);
	Archivo.close();
	Nodo* Temporal = nullptr;
	Temporal = Inicio;
	if (!AreaJuegoG.empty()) {
		AreaJuegoG.clear();
	}
	Matriz2 = Listita2.LeerMatriz(Temporal);
	cout << endl;
	for (unsigned int i = 0; i < Matriz2.length(); i++) {
		Caracter2 = Matriz2[i];
		AreaJuegoG.push_back(Matriz2[i]);
	}
	Archivo.open(DIRECCION_PARTIDA_GUARDADA, ios::app);
	if (Archivo.is_open()) {
		for (unsigned int j = 0; j < Matriz2.length(); j++) {
			Archivo << AreaJuegoG[j];
		}
		cout << "Partida guardada exitosamente" << endl;
		Archivo.close();
	}
}