#include "Cajas.h"

using namespace std;

stack<char> Pila::Insertar(char Caja) {
	stack<char> CajaPila;
	if (CajaPila.empty()) {
		CajaPila.push(Caja);
	}
	else {
		CajaPila.push(Caja);
	}
	return CajaPila;
}

void Pila::EliminarCaja(stack<char>& CajaPila) {
	char Aux;
	Aux = CajaPila.top();
	CajaPila.pop();
}

void Pila::EliminarPila(stack<char>& CajaPila) {
	while (!CajaPila.empty()) {
		CajaPila.pop();
	}
}