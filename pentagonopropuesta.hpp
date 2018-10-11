#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

// Clase del Punto
class Punto{
	public:
		void asignarX( float x ) { suX = x; }
		void asignarY( float y ) { suY = y; }
		float obtenerX() const { return suX; }
		float obtenerY() const { return suY; }
	private:
		float suX;
		float suY;
};

// Clase del Pentágono
class Pentagono
{
	public:
		Pentagono(float radio = 0.85065080);
		~Pentagono() {}

		float obtenerRadio() const { return suRadio; }
		float obtenerLado() const { return suLado; }

		Punto obtenerVerticeUno() const { return suVerticeUno; }
		Punto obtenerVerticeDos() const  { return suVerticeDos; }
		Punto obtenerVerticeTres() const  { return suVerticeTres; }
		Punto obtenerVerticeCuatro() const  { return suVerticeCuatro; }
		Punto obtenerVerticeCinco() const  { return suVerticeCinco; }

		void asignarVerticeUno(Punto Ubicacion) { suVerticeUno = Ubicacion; }
		void asignarVerticeDos(Punto Ubicacion) { suVerticeDos = Ubicacion; }
		void asignarVerticeTres(Punto Ubicacion) { suVerticeTres = Ubicacion; }
		void asignarVerticeCuatro(Punto Ubicacion) { suVerticeCuatro = Ubicacion; }
		void asignarVerticeCinco(Punto Ubicacion) { suVerticeCinco = Ubicacion; }

		void asignarRadio(float radio) { suRadio = radio; }
		void asignarLado(float lado) { suLado = lado; }

		float obtenerPerimetro() const;
		float obtenerArea() const;

	private:
		Punto suVerticeUno;
		Punto suVerticeDos;
		Punto suVerticeTres;
		Punto suVerticeCuatro;
		Punto suVerticeCinco;
		float suRadio;
		float suLado;
};
