#include"RepetirPartida.h"
using namespace std;

vector<string> VectorRepeticion::insertar(string jugada) {

	vector<string> repeticionJugada;
	repeticionJugada.push_back(jugada);
	return repeticionJugada;
}


void VectorRepeticion::BorrarVector(vector<string>& vector) {
	if (!vector.empty())
		vector.clear();
}