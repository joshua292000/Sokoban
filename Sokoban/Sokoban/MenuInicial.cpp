#include "MenuInicial.h"
#include "Ventanas.h"

using namespace std;


menuInicial::menuInicial(float width, float height)
{
	CargarFuentes();
	CargarOpciones(width, height);

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
	menu[0].setFillColor(sf::Color::Magenta);
	menu[0].setString("Iniciar un nuevo juego");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Green);
	menu[1].setString("Cargar partida");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Green);
	menu[2].setString("Reiniciar juego");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Green);
	menu[3].setString("Nivel 2");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::Green);
	menu[4].setString("Nivel 3");
	menu[4].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 5));

	menu[5].setFont(font);
	menu[5].setFillColor(sf::Color::Green);
	menu[5].setString("Nivel 4");
	menu[5].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 6));

	menu[6].setFont(font);
	menu[6].setFillColor(sf::Color::Green);
	menu[6].setString("Nivel 5");
	menu[6].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 7));

	menu[7].setFont(font);
	menu[7].setFillColor(sf::Color::Green);
	menu[7].setString("Salir del juego");
	menu[7].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 8));

	SeleccionarItem = 0;

}

void menuInicial::draw(sf::RenderWindow& window) {
	window.clear();

	for (int i = 0; i < MAXIMO_OPCIONES; i++) {
		window.draw(menu[i]);
	}
	window.display();
}

void menuInicial::MoverArriba() {
	if (SeleccionarItem - 1 >= 0) {
		menu[SeleccionarItem].setFillColor(sf::Color::Green);
		SeleccionarItem--;
		menu[SeleccionarItem].setFillColor(sf::Color::Magenta);
	}
}

void menuInicial::MoverAbajo() {
	if (SeleccionarItem + 1 < MAXIMO_OPCIONES) {
		menu[SeleccionarItem].setFillColor(sf::Color::Green);
		SeleccionarItem++;
		menu[SeleccionarItem].setFillColor(sf::Color::Magenta);
	}
}