#include "Tablero.h"

using namespace sf;

Tablero::Tablero() {
	Caracter = ' ';
	Posx = 0;
	Posy = 0;
}

Tablero::~Tablero() {
	EliminarContVector();
}

void Tablero::DibujarCambios(RenderWindow& window, Nodo*& Inicio) {
	ActualizarMatriz(Inicio);
	DibujarMapa(window);
}

bool Ganar(vector<char> m, char busqueda) {
	return find(m.begin(), m.end(), busqueda) != m.end();

}

void Tablero::ActualizarMatriz(Nodo*& Inicio) {
	Nodo* Temporal = nullptr;
	Temporal = Inicio;
	if (!AreaJuego.empty()) {
		AreaJuego.clear();
	}
	Matriz = Listita.LeerMatriz(Temporal);
	cout << endl;
	for (unsigned int i = 0; i < Matriz.length(); i++) {
		Caracter = Matriz[i];
		AreaJuego.push_back(Matriz[i]);
	}
	for (unsigned int j = 0; j < Matriz.length(); j++) {
		cout << AreaJuego[j];
		
	}
	if (Ganar(AreaJuego, '.')) {
		cout << "\nAun no ha ganado\n";
	}
	else {
		cout << "\nSi gano\n";
	}
	cout << endl;
	cout << endl;
}


void Tablero::DibujarMapa(RenderWindow& window) {
	window.clear();
	float posX = 0;
	float posY = 0;

	Sprite Objeto;

	int ax = 0;
	int Cont = 0;

	for (unsigned int i = 0; i < AreaJuego.size(); i++) {
		if (i == 0) {
			posX += 32;
		}
		if (AreaJuego[i] == '\n') {
			posY += 32;
			posX = 0;
			ax++;
		}
		if (AreaJuego[i] == '#') {
			Objeto.setTexture(Pared);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		else if (AreaJuego[i] == ' ') {
			Objeto.setTexture(Camino);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		else if (AreaJuego[i] == '$') {
			Objeto.setTexture(Caja);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		else if (AreaJuego[i] == '@') {
			Posx = i;
			Posy = ax;
			Objeto.setTexture(Personaje);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		else if (AreaJuego[i] == '!') {
			Objeto.setTexture(CajaPuesta);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		else if (AreaJuego[i] == '.') {
			Objeto.setTexture(CampoCaja);
			Objeto.setPosition(posX, posY);
			window.draw(Objeto);
		}
		posX += 32;
	}

	window.display();
}

void Tablero::EliminarContVector() {
	if (!AreaJuego.empty()) {
		AreaJuego.clear();
	}
	else {
		cout << "No existe datos en el vector" << endl;
	}

}

void Tablero::CargarTexturas() {
	if (!Pared.loadFromFile(DIRECCION_PARED)) {
		cout << "Error cargando la pared" << endl;
	}
	if (!Caja.loadFromFile(DIRECCION_CAJA)) {
		cout << "Error cargando la caja" << endl;
	}
	if (!CampoCaja.loadFromFile(DIRECCION_CAMPOCAJA)) {
		cout << "Error cargando el campo de la caja" << endl;
	}
	if (!Personaje.loadFromFile(DIRECCION_JUGADOR)) {
		cout << "Error cargando el jugador" << endl;
	}
	if (!CajaPuesta.loadFromFile(DIRECCION_CAJAPUESTA)) {
		cout << "Error cargando la caja puesta" << endl;
	}
	if (!Camino.loadFromFile(DIRECCION_CAMINO)) {
		cout << "Error cargando el camino" << endl;
	}

}

void Tablero::CargarMusica() {
	if (!Musica.openFromFile(DIRECCION_SONIDO_PAUSA)) {
		cout << "Error cargando sonido de pausa" << endl;
	}
	if (!Musica.openFromFile(DIRECCION_MUSICA_TECLAS)) {
		cout << "Error cargando sonido de teclas" << endl;
	}
	if (!Musica.openFromFile(DIRECCION_MUSICA_FONDO)) {
		cout << "Error cargando sonido de fondo" << endl;
	}
}

void Tablero::ReproducirMusica(int Sonidito) {
	if (Sonidito == 1) {
		Musica.play();
		cout << "Sonido pausa" << endl;
	}
	else if (Sonidito == 2) {
		Sonido.setBuffer(MusTecla);
		cout << "Sonido teclas" << endl;
	}
	else if (Sonidito == 3) {
		Sonido.setBuffer(MusFondo);
		Sonido.setLoop(true);
		cout << "Sonido fondo" << endl;
	}
	Sonido.play();
}

void Tablero::PausarMusica() {
	Sonido.setLoop(false);
	Sonido.stop();
	Musica.stop();
}

