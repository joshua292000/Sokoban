#define VECTOREPETIR_H
#include<string>
#include<vector>
#include<iostream>
#include "Ventanas.h"
#include "ListasEnlazadas.h"
// Declaracion de struct vector repeticion
/*struct VectorRepeticion
{
	std::vector<std::string> insertar(std::string Jugada);
	void BorrarVector(std::vector<std::string>& Vector);
};*/

using namespace std;
class VectorRepetir {
public:
	VectorRepetir();
	~VectorRepetir();
	void llenarVector(string dato);
	void repetirSolucion(Nodo* n);
private:
	vector<string> Repetir;
};