#include <iostream>

using namespace std;

// Clase del Punto
class Punto{
	public:
		void AsignarX( int x ) { suX = x; }
		void AsignarY( int y ) { suY = y; }
		int ObtenerX() const { return suX; }
		int ObtenerY() const { return suY; }
	private:
		int suX;
		int suY;
};
