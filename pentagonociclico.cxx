#include "pentagonociclico.hpp"

Pentagono::Pentagono(float radio, float anguloUno, float anguloDos, float anguloTres,
			float anguloCuatro, float anguloCinco)
{
	suRadio = radio;
	suAnguloUno = anguloUno;
	suAnguloDos = anguloDos;
	suAnguloTres = anguloTres;
	suAnguloCuatro = anguloCuatro;
	suAnguloCinco = anguloCinco;

	suVerticeUno.asignarX(radio * cos(anguloUno * PI / 180));
	suVerticeUno.asignarY(radio * sin(anguloUno * PI / 180));

	suVerticeDos.asignarX(radio * cos(anguloDos * PI / 180));
	suVerticeDos.asignarY(radio * sin(anguloDos * PI / 180));

	suVerticeTres.asignarX(radio * cos(anguloTres * PI / 180));
	suVerticeTres.asignarY(radio * sin(anguloTres * PI / 180));

	suVerticeCuatro.asignarX(radio * cos(anguloCuatro * PI / 180));
	suVerticeCuatro.asignarY(radio * sin(anguloCuatro * PI / 180));

	suVerticeCinco.asignarX(radio * cos(anguloCinco * PI / 180));
	suVerticeCinco.asignarY(radio * sin(anguloCinco * PI / 180));
}

float Pentagono::obtenerPerimetro() const
{
	float distanciaX;
	float distanciaY;
	float lado;

	distanciaX = pow(suVerticeUno.obtenerX() - suVerticeDos.obtenerX(), 2);
	distanciaY = pow(suVerticeUno.obtenerY() - suVerticeDos.obtenerY(), 2);
	lado = sqrt(distanciaX + distanciaY);

	distanciaX = pow(suVerticeDos.obtenerX() - suVerticeTres.obtenerX(), 2);
	distanciaY = pow(suVerticeDos.obtenerY() - suVerticeTres.obtenerY(), 2);
	lado += sqrt(distanciaX + distanciaY);

	distanciaX = pow(suVerticeTres.obtenerX() - suVerticeCuatro.obtenerX(), 2);
	distanciaY = pow(suVerticeTres.obtenerY() - suVerticeCuatro.obtenerY(), 2);
	lado += sqrt(distanciaX + distanciaY);

	distanciaX = pow(suVerticeCuatro.obtenerX() - suVerticeCinco.obtenerX(), 2);
	distanciaY = pow(suVerticeCuatro.obtenerY() - suVerticeCinco.obtenerY(), 2);
	lado += sqrt(distanciaX + distanciaY);

	distanciaX = pow(suVerticeCinco.obtenerX() - suVerticeUno.obtenerX(), 2);
	distanciaY = pow(suVerticeCinco.obtenerY() - suVerticeUno.obtenerY(), 2);
	lado += sqrt(distanciaX + distanciaY);

	return lado;
}

float Pentagono::obtenerArea() const
{
	float area;
	area = abs(suVerticeUno.obtenerX() * suVerticeDos.obtenerY()
		- suVerticeUno.obtenerY() * suVerticeDos.obtenerX());

	area += abs(suVerticeDos.obtenerX() * suVerticeTres.obtenerY()
		- suVerticeDos.obtenerY() * suVerticeTres.obtenerX());

	area += abs(suVerticeTres.obtenerX() * suVerticeCuatro.obtenerY()
		- suVerticeTres.obtenerY() * suVerticeCuatro.obtenerX());

	area += abs(suVerticeCuatro.obtenerX() * suVerticeCinco.obtenerY()
		- suVerticeCuatro.obtenerY() * suVerticeCinco.obtenerX());

	area += abs(suVerticeCinco.obtenerX() * suVerticeUno.obtenerY()
		- suVerticeCinco.obtenerY() * suVerticeUno.obtenerX());

	return area / 2;
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

	cout << "\tLa distancia de lo vértices al centro del pentágono es ";
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
