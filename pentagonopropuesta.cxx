#include "pentagonopropuesta.hpp"

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

	float distanciaX;
	float distanciaY;
	distanciaX = pow(suVerticeUno.obtenerX() - suVerticeDos.obtenerX(), 2);
	distanciaY = pow(suVerticeUno.obtenerY() - suVerticeDos.obtenerY(), 2);
	suLado = sqrt(distanciaX + distanciaY);
}

float Pentagono::obtenerPerimetro() const
{
	return 5 * suLado;
}

float Pentagono::obtenerArea() const
{
	float apotema;
	apotema = suRadio * cos(PI / 5);
	return 5 * suLado * apotema / 2;
}

int main()
{
	cout << "\nUsando el constructor predeterminado: " << endl;
	Pentagono PentagonoPredeterminado;

	cout << "\tLa longitud del lado del pentágono es ";
	cout << PentagonoPredeterminado.obtenerLado() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PentagonoPredeterminado.obtenerPerimetro();
	cout << " y el área es ";
	cout << PentagonoPredeterminado.obtenerArea() << ".\n\n";

	cout << "Usando el constructor con parámetros: " << endl;
	Pentagono PentagonoConParametros(4);

	cout << "\tLa longitud del lado del pentágono es ";
	cout << PentagonoConParametros.obtenerLado() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PentagonoConParametros.obtenerPerimetro();
	cout << " y el área es ";
	cout << PentagonoConParametros.obtenerArea() << ".\n\n";

	cout << "Ahora, usando punteros con el constructor predeterminado: " << endl;
	Pentagono *PPentagonoPredeterminado = new Pentagono;

	cout << "\tLa longitud del lado del pentágono es ";
	cout << PPentagonoPredeterminado->obtenerLado() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PPentagonoPredeterminado->obtenerPerimetro();
	cout << " y el área es ";
	cout << PPentagonoPredeterminado->obtenerArea() << ".\n\n";

	delete PPentagonoPredeterminado;

	cout << "Por último, usando punteros con parámetros específicos: " << endl;
	Pentagono *PPentagonoConParametros = new Pentagono(2.5);

	cout << "\tLa longitud del lado del pentágono es ";
	cout << PPentagonoConParametros->obtenerLado() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PPentagonoConParametros->obtenerPerimetro();
	cout << " y el área es ";
	cout << PPentagonoConParametros->obtenerArea() << ".\n\n";

	delete PPentagonoConParametros;

	return 0;
}
