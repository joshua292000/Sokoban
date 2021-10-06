#include "ListasEnlazadas.h"
#include <iostream>
#include <string>

using namespace std;

void ListaEnlazada::Insertar(Nodo*& Inicio, char caracter, int Linea) {
	int ContadorL = 0;
	Nuevo = new Nodo;
	Nuevo->Caracter = caracter;
	Nuevo->Aux = ' ';
	Nuevo->Arriba = nullptr;
	Nuevo->Abajo = nullptr;
	Nuevo->Derecha = nullptr;
	Nuevo->Izquierda = nullptr;

	if (Inicio == nullptr) {
		Inicio = Nuevo;
	}
	else {
		Nodo* Temporal1 = Inicio;
		Nodo* Temporal2 = Inicio;
		Nodo* Temporal3 = nullptr;
		if (Linea == 0) {
			while (Temporal1->Derecha != nullptr)
			{
				Temporal1 = Temporal1->Derecha;
			}
			Temporal1->Derecha = Nuevo;
			Nuevo->Izquierda = Temporal1;
		}
		else {
			while (ContadorL != Linea - 1 && Temporal1->Abajo != nullptr)
			{
				Temporal1 = Temporal1->Abajo;
				ContadorL++;

			}
			if (Temporal1->Abajo == nullptr) {
				Temporal1->Abajo = Nuevo;
			}
			else {
				Temporal2 = Temporal1;
				Temporal1 = Temporal1->Abajo;
				while (Temporal1->Derecha != nullptr) {
					Temporal1 = Temporal1->Derecha;
					Temporal2 = Temporal2->Derecha;
				}
				Temporal2 = Temporal2->Derecha;
				Temporal1->Derecha = Nuevo;
				Nuevo->Arriba = Temporal2;
				Temporal2->Abajo = Nuevo;
				Nuevo->Izquierda = Temporal1;
			}
		}
	}
}

void ListaEnlazada::BorrarLista(Nodo*& Inicio) {
	Nodo* Temporal1 = Inicio;
	Nodo* Temporal2;
	while (Temporal1->Abajo != nullptr)
	{
		Inicio = Inicio->Derecha;
		Nodo* Temporal3;
		while (Inicio != nullptr)
		{
			Temporal2 = Inicio;
			Inicio = Inicio->Derecha;
			delete Temporal2;
		}
		Temporal3 = Temporal1;
		Temporal1 = Temporal1->Abajo;
		Inicio = Temporal1;
		delete Temporal3;
	}
}

void ListaEnlazada::VerificarNivel(int Nivel) {
	if (Nivel == 1) {
		FilaMapa = NIVEL1;
		ColumnaMapa = NIVEL1;
	}
	else if (Nivel == 2) {
		FilaMapa = NIVEL2;
		ColumnaMapa = NIVEL2;
	}
	else if (Nivel == 3) {
		FilaMapa = NIVEL3;
		ColumnaMapa = NIVEL3;
	}
	else if (Nivel == 4) {
		FilaMapa = NIVEL4;
		ColumnaMapa = NIVEL4;
	}
	else if (Nivel == 5) {
		FilaMapa = NIVEL5;
		ColumnaMapa = NIVEL5;
	}
}

void ListaEnlazada::CargarTexturasNivel(string Matriz, int Nivel) {
	char Caracter = ' ';
	int Contador = Matriz.length();
	VerificarNivel(Nivel);
	for (int i = 0; i < Contador; i++) {
		AreaJuego.push_back(Matriz[i]);
		cout << AreaJuego[i];
	}

}

void ListaEnlazada::MostrarLista(Nodo*& n) {
	Nodo* Aux = n;
	if (ListaVacia(Aux)) {
		cout << endl << endl << "La lista no tiene elementos" << endl;
	}
	else {
		int p = 1;
		Nodo* Temporal;
		Temporal = n;
		while (Temporal != nullptr) {
			cout << "Elemento # " << p++ << " " << Temporal->Caracter << endl;
			Temporal = Temporal->Siguiente;
		}
	}
}

bool ListaEnlazada::ListaVacia(Nodo*& Vacio) {
	if (Vacio == nullptr) {
		return true;
	}
	return false;

}

Nodo* ListaEnlazada::PosJugador(Nodo*& Inicio) {
	Nodo* Personaje = Inicio;
	Nodo* Temporal = Inicio;
	Nodo* Temporal2 = nullptr;

	while (Temporal->Abajo != nullptr) {
		while (Personaje->Derecha != nullptr && Personaje->Caracter != '@')
		{
			Personaje = Personaje->Derecha;
		}
		if (Personaje->Caracter == '@') {
			Temporal2 = Personaje;
			break;
		}
		else {
			Personaje = Temporal->Abajo;
			Temporal = Temporal->Abajo;
		}
	}
	Temporal = nullptr;
	return Temporal2;
}

void ListaEnlazada::MovArriba(Nodo*& Personaje) {
	Nodo* PosMov;
	Nodo* Temporal;
	if (Personaje->Caracter == '@' && Personaje->Arriba != nullptr) {
		PosMov = Personaje->Arriba;
		if (PosMov->Caracter == '$') {
			Temporal = PosMov->Arriba;
			if (Temporal->Caracter == ' ') {
				Temporal->Caracter = PosMov->Caracter;
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
			else if (Temporal->Caracter == '#') {

			}
			else if (Temporal->Caracter == '.') {
				Temporal->Caracter = '!';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
		else if (PosMov->Caracter == ' ') {
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '#') {

		}
		else if (PosMov->Caracter == '.') {
			PosMov->Aux = PosMov->Caracter;
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '!') {
			Nodo* Temporal2 = PosMov->Arriba;
			if (Temporal2->Caracter == '.') {
				Temporal2->Caracter = '!';
				PosMov->Aux = '.';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
	}
}

void ListaEnlazada::MovAbajo(Nodo*& Personaje) {
	Nodo* PosMov;
	Nodo* Temporal;
	if (Personaje->Caracter == '@' && Personaje->Abajo != nullptr) {
		PosMov = Personaje->Abajo;
		if (PosMov->Caracter == '$') {
			Temporal = PosMov->Abajo;
			if (Temporal->Caracter == ' ') {
				Temporal->Caracter = PosMov->Caracter;
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
			else if (Temporal->Caracter == '#') {

			}
			else if (Temporal->Caracter == '.') {
				Temporal->Caracter = '!';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
		else if (PosMov->Caracter == ' ') {
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '#') {

		}
		else if (PosMov->Caracter == '.') {
			PosMov->Aux = PosMov->Caracter;
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '!') {
			Nodo* Temporal2 = PosMov->Abajo;
			if (Temporal2->Caracter == '.') {
				Temporal2->Caracter = '!';
				PosMov->Aux = '.';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
	}
}

void ListaEnlazada::MovDerecha(Nodo*& Personaje) {
	Nodo* PosMov;
	Nodo* Temporal;
	if (Personaje->Caracter == '@' && Personaje->Derecha != nullptr) {
		PosMov = Personaje->Derecha;
		if (PosMov->Caracter == '$') {
			Temporal = PosMov->Derecha;
			if (Temporal->Caracter == ' ') {
				Temporal->Caracter = PosMov->Caracter;
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
			else if (Temporal->Caracter == '#') {

			}
			else if (Temporal->Caracter == '.') {
				Temporal->Caracter = '!';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
		else if (PosMov->Caracter == ' ') {
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '#') {

		}
		else if (PosMov->Caracter == '.') {
			PosMov->Aux = PosMov->Caracter;
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '!') {
			Nodo* Temporal2 = PosMov->Derecha;
			if (Temporal2->Caracter == '.') {
				Temporal2->Caracter = '!';
				PosMov->Aux = '.';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
	}
}

void ListaEnlazada::MovIzquierda(Nodo*& Personaje) {
	Nodo* PosMov;
	Nodo* Temporal;
	if (Personaje->Caracter == '@' && Personaje->Izquierda != nullptr) {
		PosMov = Personaje->Izquierda;
		if (PosMov->Caracter == '$') {
			Temporal = PosMov->Izquierda;
			if (Temporal->Caracter == ' ') {
				Temporal->Caracter = PosMov->Caracter;
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
			else if (Temporal->Caracter == '#') {

			}
			else if (Temporal->Caracter == '.') {
				Temporal->Caracter = '!';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {
					Personaje->Caracter = ' ';
				}
			}
		}
		else if (PosMov->Caracter == ' ') {
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '#') {

		}
		else if (PosMov->Caracter == '.') {
			PosMov->Aux = PosMov->Caracter;
			PosMov->Caracter = Personaje->Caracter;
			if (Personaje->Aux == '.') {
				Personaje->Caracter = Personaje->Aux;
			}
			else {
				Personaje->Caracter = ' ';
			}
		}
		else if (PosMov->Caracter == '!') {
			Nodo* Temporal2 = PosMov->Izquierda;
			if (Temporal2->Caracter == '.') {
				Temporal2->Caracter = '!';
				PosMov->Aux = '.';
				PosMov->Caracter = Personaje->Caracter;
				if (Personaje->Aux == '.') {
					Personaje->Caracter = Personaje->Aux;
				}
				else {	
					Personaje->Caracter = ' ';
				}
			}
		}
	}
}

std::string ListaEnlazada::LeerMatriz(Nodo*& Inicio) {
	std::string Matriz = "";
	Nodo* Temporal = Inicio;
	Nodo* Temporal2;

	while (Temporal != nullptr) {
		Temporal2 = Temporal;
		while (Temporal2 != nullptr)
		{
			Matriz += Temporal2->Caracter;
			Temporal2 = Temporal2->Derecha;
		}
		Matriz += "\n";
		Temporal = Temporal->Abajo;
	}
	return Matriz;
}



