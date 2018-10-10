#include "pentagonolado.hpp"

Pentagono::Pentagono(float lado)
{
	float radio;
	radio = lado / sqrt(2);
	radio = radio / sqrt(1 - cos(2 * PI / 5));
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
	float apotema;
	apotema = suRadio * cos(PI / 5);
	return apotema * perimetro / 2;
}

int main()
{
	cout << "\nUsando el constructor predeterminado: " << endl;
	Pentagono PentagonoPredeterminado;

	cout << "\tLa distancia de los vértices al centro del pentágono es ";
	cout << PentagonoPredeterminado.obtenerRadio() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PentagonoPredeterminado.obtenerPerimetro();
	cout << " y el área es ";
	cout << PentagonoPredeterminado.obtenerArea() << ".\n\n";

	cout << "Usando el constructor con parámetros: " << endl;
	Pentagono PentagonoConParametros(4);

	cout << "\tLa distancia de los vértices al centro del pentágono es ";
	cout << PentagonoConParametros.obtenerRadio() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PentagonoConParametros.obtenerPerimetro();
	cout << " y el área es ";
	cout << PentagonoConParametros.obtenerArea() << ".\n\n";

	cout << "Ahora, usando punteros con el constructor predeterminado: " << endl;
	Pentagono *PPentagonoPredeterminado = new Pentagono;

	cout << "\tLa distancia de los vértices al centro del pentágono es ";
	cout << PPentagonoPredeterminado->obtenerRadio() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PPentagonoPredeterminado->obtenerPerimetro();
	cout << " y el área es ";
	cout << PPentagonoPredeterminado->obtenerArea() << ".\n\n";

	delete PPentagonoPredeterminado;

	cout << "Por último, usando punteros con parámetros específicos: " << endl;
	Pentagono *PPentagonoConParametros = new Pentagono(2.5);

	cout << "\tLa distancia de los vértices al centro del pentágono es ";
	cout << PPentagonoConParametros->obtenerRadio() << ".\n";

	cout << "\tEl perímetro es ";
	cout << PPentagonoConParametros->obtenerPerimetro();
	cout << " y el área es ";
	cout << PPentagonoConParametros->obtenerArea() << ".\n\n";

	delete PPentagonoConParametros;

	return 0;
}
