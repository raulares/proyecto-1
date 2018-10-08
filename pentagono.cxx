#include "pentagono.hpp"

Pentagono::Pentagono(float radio)
{
	suRadio = radio;

	suVerticeUno.asignarX(radio * cos(PI / 5));
	suVerticeUno.asignarY(radio * sin(PI / 5));

	suVerticeDos.asignarX(radio * cos(2 * PI / 5));
	suVerticeDos.asignarY(radio * sin(2 * PI / 5));

	suVerticeTres.asignarX(radio * cos(3 * PI / 5));
	suVerticeTres.asignarY(radio * sin(3 * PI / 5));

	suVerticeCuatro.asignarX(radio * cos(4 * PI / 5));
	suVerticeCuatro.asignarY(radio * sin(4 * PI / 5));

	suVerticeCinco.asignarX(radio * cos(5 * PI / 5));
	suVerticeCinco.asignarY(radio * sin(5 * PI / 5));
}

int main()
{
	Pentagono MiPentagono(PI);

	cout << "Coordenada en X del punto 1 es ";
	cout << MiPentagono.obtenerVerticeUno().obtenerX() << endl;

	cout << "Coordenada en Y del punto 3 es ";
	cout << MiPentagono.obtenerVerticeTres().obtenerY() << endl;

	return 0;
}
