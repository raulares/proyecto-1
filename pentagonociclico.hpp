#include <iostream>
#include <cmath>

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
		Pentagono(float radio = 1, float anguloUno = 0, float anguloDos = 72,
			float anguloTres = 144, float anguloCuatro = 216, float anguloCinco = 288);
		~Pentagono() {}

		float obtenerRadio() const { return suRadio; }
		float obtenerAnguloUno() const { return suAnguloUno; }
		float obtenerAnguloDos() const { return suAnguloDos; }
		float obtenerAnguloTres() const { return suAnguloTres; }
		float obtenerAnguloCuatro() const { return suAnguloCuatro; }
		float obtenerAnguloCinco() const { return suAnguloCinco; }

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
		void asignarAnguloUno(float anguloUno) { suAnguloUno = anguloUno; }
		void asignarAnguloDos(float anguloDos) { suAnguloDos = anguloDos; }
		void asignarAnguloTres(float anguloTres) { suAnguloTres = anguloTres; }
		void asignarAnguloCuatro(float anguloCuatro) { suAnguloCuatro = anguloCuatro; }
		void asignarAnguloCinco(float anguloCinco) { suAnguloCinco = anguloCinco; }

		float obtenerPerimetro() const;
		float obtenerArea() const;

	private:
		Punto suVerticeUno;
		Punto suVerticeDos;
		Punto suVerticeTres;
		Punto suVerticeCuatro;
		Punto suVerticeCinco;
		float suRadio;
		float suAnguloUno;
		float suAnguloDos;
		float suAnguloTres;
		float suAnguloCuatro;
		float suAnguloCinco;
};
