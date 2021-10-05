#include<stack>
#include<iostream>
#include<string>

//using namespace std;

struct Pila
{
	std::stack<char> Insertar(char Caja);
	void EliminarCaja(std::stack<char>& CajaPila);
	void EliminarPila(std::stack<char>& CajaPila);
};
