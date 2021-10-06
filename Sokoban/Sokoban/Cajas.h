#include<stack>
#include<iostream>
#include<string>

using namespace std;

struct Pila
{
	stack<char> Insertar(char Caja);
	void EliminarCaja(stack<char>& CajaPila);
	void EliminarPila(stack<char>& CajaPila);
};
