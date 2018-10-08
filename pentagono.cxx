#include "pentagono.hpp"

Pentagono::Pentagono(float radio)
{
	suRadio = radio;

	suVerticeUno.asignarX(radio * cos(0));
	suVerticeUno.asignarY(radio * sin(0));

	suVerticeDos.asignarX(radio * cos(2 * PI / 5));
	suVerticeDos.asignarY(radio * sin(2 * PI / 5));

	suVerticeTres.asignarX(radio * cos(4 * PI / 5));
	suVerticeTres.asignarY(radio * sin(4 * PI / 5));

	suVerticeCuatro.asignarX(radio * cos(6 * PI / 5));
	suVerticeCuatro.asignarY(radio * sin(6 * PI / 5));

	suVerticeCinco.asignarX(radio * cos(8 * PI / 5));
	suVerticeCinco.asignarY(radio * sin(8 * PI / 5));
}

float Pentagono::obtenerPerimetro() const
{
	float distanciaX;
	float distanciaY;
	float lado;
	distanciaX = pow(suVerticeUno.obtenerX() - suVerticeDos.obtenerX(), 2);
	distanciaY = pow(suVerticeUno.obtenerY() - suVerticeDos.obtenerY(), 2);
	lado = sqrt(distanciaX + distanciaY);
	return 5 * lado;
}

float Pentagono::obtenerArea() const
{
	float perimetro;
	perimetro = obtenerPerimetro();
	Punto PuntoMedio;
	PuntoMedio.asignarX((suVerticeUno.obtenerX() + suVerticeDos.obtenerX()) / 2);
	PuntoMedio.asignarY((suVerticeUno.obtenerY() + suVerticeDos.obtenerY()) / 2);
	float apotema;
	apotema = sqrt(pow(PuntoMedio.obtenerX(), 2) + pow(PuntoMedio.obtenerY(), 2));
	return apotema * perimetro / 2;
}

int main()
{
	Pentagono MiPentagono(PI);

	cout << "Coordenada en X del punto 1 es ";
	cout << MiPentagono.obtenerVerticeUno().obtenerX() << endl;

	cout << "Coordenada en Y del punto 3 es ";
	cout << MiPentagono.obtenerVerticeTres().obtenerY() << endl;

	cout << "El perímetro es ";
	cout << MiPentagono.obtenerPerimetro() << endl;

	cout << "El área es ";
	cout << MiPentagono.obtenerArea() << endl;

	return 0;
}
