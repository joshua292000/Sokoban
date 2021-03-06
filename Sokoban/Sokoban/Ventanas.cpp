#include "Ventanas.h"
#include <iostream>
#include <windows.h>
#include<vector>
#include<ctime>
#define windows_h

using namespace sf;

Tablero tablero;
ListaEnlazada lista;
NivelArch nivel;
Nodo* Inicio;
Nodo* j = nullptr;
int x = 0;
vector<string> Repetir;

sf::RenderWindow window(sf::VideoMode(1000, 600), "El mejor Sokoban");

menuInicial menu(window.getSize().x, window.getSize().y);

Ventanas::Ventanas() {

}


Ventanas::~Ventanas() {

}

void delay(int secs) {
	for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void Ventanas::MedidasPantalla(RenderWindow& window) {
	if (NivelSeleccionado == 1) {
		window.setSize(Vector2u((1300), 768));
	}
	else if (NivelSeleccionado == 2) {
		window.setSize(Vector2u((1300), 768));
	}
	else if (NivelSeleccionado == 3) {
		window.setSize(Vector2u((1300), 768));
	}
	else if (NivelSeleccionado == 4) {
		window.setSize(Vector2u((1300), 768));
	}
	else if (NivelSeleccionado == 5) {
		window.setSize(Vector2u((1300), 768));
	}
}



void Ventanas::MenuInicial() {
	Inicio = nullptr;
	nivel.LeerNivel(nivel.NivelSeleccionado(NivelSeleccionado), lista, Inicio);
	tablero.CargarMusica();
	tablero.ReproducirMusica(1);
	window.setFramerateLimit(30);
	MnejoEventosTeclado(window);
}

void Ventanas::Teclado(RenderWindow& window, Nodo*& n) {
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			tablero.PausarMusica();
			break;

		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
				system("cls");
				cout << "Arriba\n";

				if (MenuActivo) {
					menu.MoverArriba();
					tablero.ReproducirMusica(2);
				}
				else if (Jugando) {
					lista.MovArriba(n); 
					Movimiento = true;
					Repetir.push_back("Arriba");
				}
				break;

			case Keyboard::Down:
				system("cls");
				cout << "Abajo\n";
				if (MenuActivo) {
					menu.MoverAbajo();
					tablero.ReproducirMusica(2);
				}
				else if (Jugando) {
					lista.MovAbajo(n);
					Movimiento = true;
					Repetir.push_back("Abajo");
				}
				break;

			case Keyboard::Right:
				system("cls");
				cout << "Derecha\n";
				if (MenuActivo) {
					
				}
				else if (Jugando) {

					lista.MovDerecha(n);
					Movimiento = true;
					Repetir.push_back("Derecha");
				}
				break;

			case Keyboard::Left:
				system("cls");
				cout << "Izquierda\n";
				if (MenuActivo) {
					
				}
				else if (Jugando) {
					lista.MovIzquierda(n);
					Movimiento = true;
					Repetir.push_back("Izquierda");
				}
				break;

			case Keyboard::Escape:
				if (IniciarJuego != false) {
					if (Jugando == true) {
						tablero.PausarMusica();
						tablero.ReproducirMusica(2);
						tablero.ReproducirMusica(1);
						cout << "\n Juego en pausa! \n";
						Jugando = false;
						MenuActivo = true;
					}
					else if (Jugando == false) {
						cout << "\n despausar juego \n";
						Jugando = true;
						MenuActivo = false;
						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
				}
				break;

			case Keyboard::G:
				if (Jugando == true) {
					nivel.EscribirArchivo(Inicio);
				}
				break;

			case Keyboard::R:
				InicializarJuego(NivelSeleccionado);
				Jugando = true;
				MenuActivo = false;
				j = lista.PosJugador(Inicio);

				while (x < Repetir.size()) {
					if (Repetir[x] == "Arriba") {
						cout << "\n pos Repetir  " << x << " " << Repetir[x] << "\n";
						lista.MovArriba(j);
						j = lista.PosJugador(Inicio);
						tablero.DibujarCambios(window, Inicio);

					}
					if (Repetir[x] == "Abajo") {
						cout << "\n pos Repetir  " << x << " " << Repetir[x] << "\n";
						lista.MovAbajo(j);
						j = lista.PosJugador(Inicio);
						tablero.DibujarCambios(window, Inicio);

					}
					if (Repetir[x] == "Izquierda") {
						cout << "\n pos Repetir  " << x << " " << Repetir[x] << "\n";
						lista.MovIzquierda(j);
						j = lista.PosJugador(Inicio);
						tablero.DibujarCambios(window, Inicio);

					}
					if (Repetir[x] == "Derecha") {
						cout << "\n pos Repetir  " << x << " " << Repetir[x] << "\n";
						lista.MovDerecha(j);
						j = lista.PosJugador(Inicio);
						tablero.DibujarCambios(window, Inicio);

					}
					delay(1);
					x++;

				}
				break;

			case Keyboard::S:
				if (NivelSeleccionado == 1) {
					Repetir.clear();
					InicializarJuego(2);
				}
				else if (NivelSeleccionado == 2) {
					Repetir.clear();
					InicializarJuego(3);
				}
				else if (NivelSeleccionado == 3) {
					Repetir.clear();
					InicializarJuego(4);
				}
				else if (NivelSeleccionado == 4) {
					Repetir.clear();
					InicializarJuego(5);
				}
				else if (NivelSeleccionado == 5) {
					Repetir.clear();
					MessageBoxA(NULL, "Niveles completados", "Ganastes", MB_OK | MB_ICONEXCLAMATION);
				}

			break;

			case Keyboard::Return:

				switch (menu.ObtenerItem())
				{
				case 0:

					if (IniciarJuego == false) {
						cout << "\n Ha comenzado un nuevo juego! \n";
						NivelSeleccionado = 1;
						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						IniciarJuego = true;
						MenuActivo = false;
						MessageBoxA(NULL, "Para guardar digite G y esc para pausar y salir al men? principal", "Opciones", MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado == 1) {
							cout << "\n No se puede cargar el nivel porque ya se encuentra jugando el mismo! \n";
						}
						else if (IniciarJuego == true && NivelSeleccionado != 1) {
							cout << "\n Cambio al nivel 1 \n";
							NivelSeleccionado = 1;
							InicializarJuego(NivelSeleccionado);
						}
						Jugando = true;
						MenuActivo = false;

						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
					break;
				case 1:
					if (IniciarJuego == false) {
						cout << "\nPrimero debe guardar una partida\n";

						
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado != 6) {
							cout << "\nSe abri? la partida guardada\n";
							NivelSeleccionado = 6;
							InicializarJuego(NivelSeleccionado);
							Jugando = true;
							MenuActivo = false;
							tablero.PausarMusica();
							tablero.ReproducirMusica(3);

						}
					}
					break;


				case 2:

					if (IniciarJuego != false) {
						cout << "\n Se ha seleccionado reiniciar el nivel! \n";

						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						MenuActivo = false;
					}
					else {
						cout << "\n Ha fallado la opcion de reiniciar nivel , esto se debe a que no esta ha comenzado ninguna partida! \n";
					}
					break;

				case 3:


					if (IniciarJuego == false) {
						cout << "\nSe ha seleccionado el nivel 2! \n";
						NivelSeleccionado = 2;
						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						IniciarJuego = true;
						MenuActivo = false;
						MessageBoxA(NULL, "Para guardar digite G y esc para pausar y salir al men? principal", "Opciones", MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado == 2) {

							cout << "\n No se puede cargar el nivel porque ya se encuentra jugando el mismo! \n";
						}
						else if (IniciarJuego == true && NivelSeleccionado != 2) {
							cout << "\n Cambio al nivel 2 \n";
							NivelSeleccionado = 2;
							InicializarJuego(NivelSeleccionado);
						}
						Jugando = true;
						MenuActivo = false;
						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
					break;

				case 4:
					if (IniciarJuego == false) {
						cout << "\n Se ha seleccionado el nivel 3! \n";
						NivelSeleccionado = 3;
						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						IniciarJuego = true;
						MenuActivo = false;
						MessageBoxA(NULL, "Para guardar digite G y esc para pausar y salir al men? principal", "Opciones", MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado == 3) {
							cout << "Ya tiene una partida iniciada!" << endl;
						}
						else if (IniciarJuego == true && NivelSeleccionado != 3) {
							cout << "\n Cambio al nivel 3 \n";
							NivelSeleccionado = 3;
							InicializarJuego(NivelSeleccionado);
						}
						Jugando = true;
						MenuActivo = false;
						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
					break;


				case 5:

					if (IniciarJuego == false) {
						cout << "\nSe ha seleccionado el nivel 4! \n";
						NivelSeleccionado = 4;
						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						IniciarJuego = true;
						MenuActivo = false;
						MessageBoxA(NULL, "Para guardar digite G y esc para pausar y salir al men? principal", "Opciones", MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado == 4) {
							cout << "Ya tiene una partida iniciada!" << endl;

						}
						else if (IniciarJuego == true && NivelSeleccionado != 4) {
							cout << "\n Cambio al nivel 4 \n";
							NivelSeleccionado = 4;
							InicializarJuego(NivelSeleccionado);
						}
						Jugando = true;
						MenuActivo = false;
						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
					break;

				case 6:

					if (IniciarJuego == false) {
						cout << "\nSe ha seleccionado el nivel 5! \n";
						NivelSeleccionado = 5;
						InicializarJuego(NivelSeleccionado);
						Jugando = true;
						IniciarJuego = true;
						MenuActivo = false;
						MessageBoxA(NULL, "Para guardar digite G y esc para pausar y salir al men? principal", "Opciones", MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						if (IniciarJuego == true && NivelSeleccionado == 5) {
							cout << "Ya tiene una partida iniciada!" << endl;

						}
						else if (IniciarJuego == true && NivelSeleccionado != 5) {
							cout << "\n Cambio al nivel 5 \n";
							NivelSeleccionado = 5;
							InicializarJuego(NivelSeleccionado);
						}
						Jugando = true;
						MenuActivo = false;
						tablero.PausarMusica();
						tablero.ReproducirMusica(3);
					}
					break;


				case 7:
					cout << "Boton de cerrar ventana de juego!" <<endl;
					window.close();
					tablero.PausarMusica();
					break;
				}

			}
		}

	}

}

void Ventanas::MnejoEventosTeclado(RenderWindow& window) {
	Nodo* n = nullptr;
	while (window.isOpen())
	{
		n = lista.PosJugador(Inicio);
		Teclado(window, n);

		if (Jugando && Movimiento) {
			tablero.DibujarCambios(window, Inicio);
			Movimiento = false;
		}
		else if (Jugando) {
			tablero.DibujarMapa(window);
		}
		else if (MenuActivo) {
			menu.draw(window);
		}
	}
}

void Ventanas::InicializarJuego(int Nivel) {
	window.clear();
	tablero.PausarMusica();
	tablero.ReproducirMusica(3);
	Inicio = nullptr;
	MedidasPantalla(window);
	nivel.LeerNivel(nivel.NivelSeleccionado(Nivel), lista, Inicio);
	tablero.ActualizarMatriz(Inicio);
	tablero.CargarTexturas();
	
}
