#include "MenuInicial.h"
#include "Ventanas.h"
#include <windows.h>
#define windows_h
using namespace std;
using namespace sf;

menuInicial::menuInicial(float width, float height)
{
	CargarFuentes();
	CargarOpciones(width, height);
	MessageBoxA(NULL, "Para moverse dentro del menú principal utilice las flechas de arriba y abajo. Para seleccionar digite enter", "Opciones", MB_OK | MB_ICONEXCLAMATION);

}

menuInicial::~menuInicial() {

}

void menuInicial::CargarFuentes() {
	if (!font.loadFromFile(DIR_FUENTES)) {
		cout << "Error cargando la fuente de letra" << endl;
	}
}

void menuInicial::CargarOpciones(float width, float height) {

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Magenta);
	menu[0].setString("Iniciar un nuevo juego");
	menu[0].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::Green);
	menu[1].setString("Cargar partida");
	menu[1].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::Green);
	menu[2].setString("Reiniciar juego");
	menu[2].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(Color::Green);
	menu[3].setString("Nivel 2");
	menu[3].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(Color::Green);
	menu[4].setString("Nivel 3");
	menu[4].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 5));

	menu[5].setFont(font);
	menu[5].setFillColor(Color::Green);
	menu[5].setString("Nivel 4");
	menu[5].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 6));

	menu[6].setFont(font);
	menu[6].setFillColor(Color::Green);
	menu[6].setString("Nivel 5");
	menu[6].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 7));

	menu[7].setFont(font);
	menu[7].setFillColor(Color::Green);
	menu[7].setString("Salir del juego");
	menu[7].setPosition(Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 8));

	SeleccionarItem = 0;

}

void menuInicial::draw(RenderWindow& window) {
	window.clear();

	for (int i = 0; i < MAXIMO_OPCIONES; i++) {
		window.draw(menu[i]);
	}
	window.display();
}

void menuInicial::MoverArriba() {
	if (SeleccionarItem - 1 >= 0) {
		menu[SeleccionarItem].setFillColor(Color::Green);
		SeleccionarItem--;
		menu[SeleccionarItem].setFillColor(Color::Magenta);
	}
}

void menuInicial::MoverAbajo() {
	if (SeleccionarItem + 1 < MAXIMO_OPCIONES) {
		menu[SeleccionarItem].setFillColor(Color::Green);
		SeleccionarItem++;
		menu[SeleccionarItem].setFillColor(Color::Magenta);
	}
}