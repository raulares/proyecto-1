/*
 * Proyecto 1.
*
 * Crear una clase que represente un pentágono. La clase debe reunir los siguientes criterios:
 * Un constructor predeterminado, un método para calcular el área, un método para calcular el
 * perímetro y una clase Punto para almacenar la información de los vértices.
 * Luego, instanciar dos objetos de la clase que representa el pentágono
 * (uno para cada constructor) y probar sus constructores y métodos y usar asignación dinámica
 * en el heap para crear dos punteros a un objeto de la clase que represente el pentágono
 * (uno para cada constructor) y probar sus constructores y métodos.
 *
 * Raúl Valentín Cortez Ares CA16007.
 * José Wilfredo Iraheta Martínez IM16003.
 * Esmeralda Guadalupe Morales Alfaro MA16009.
 */

#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

/*
 * Clase del Punto. Esta clase crea un punto en R^2.
 */
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

/*
 * Clase del Pentágono. Esta clase crea un pentágono regular centrado en el origen del plano R^2
 * con un radio dado, que por defecto es 0.85065080, el cual nos crea un pentágono con lado 1.
 * La clase tiene 7 variables, cinco son para los vértices del pentágono y las otras dos son para
 * la distancia del origen al vértice (suRadio) y la longitud del lado del pentágono (suLado),
 * además, la clase consta de 2 métodos, obtenerPerimetro() y obtenerArea los cuales nos permiten
 * obtener el perímetro y  el área del pentágono creado.
 */
class Pentagono
{
    public:
        Pentagono(float radio);
        Pentagono() : Pentagono(0.85065080) {};
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

/*
 * Constructor de la clase Pentagono. A este constructor se le pasa el parámetro radio el
 * que representa la distancia del origen a los vértices del pentágono. El pentágono está
 * construido de forma que uno de los vértices esté sobre el semieje positivo X. Además
 * calcula la longitud de un lado del pentágono para tener facil acceso a este dato.
 */
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

/*
 * El método obtenerPerimetro() nos regresa el perímetro del pentágono el cual se calcula
 * facilmente usando la variable suLado.
 */

float Pentagono::obtenerPerimetro() const
{
    return 5 * suLado;
}

/*
 * El método obtenerArea() nos devuelve el área del pentágono el cual se calcula obteniendo
 * su apotema y usando la variable suLado.
 */

float Pentagono::obtenerArea() const
{
    float apotema;
    apotema = suRadio * cos(PI / 5);
    return 5 * suLado * apotema / 2;
}

int main()
{
    //Primero usaremos el constructor predeterminado para crear el pentágono y probar sus métodos.
    cout << "\nUsando el constructor predeterminado: " << endl;
    Pentagono PentagonoPredeterminado;

    cout << "\tLa longitud del lado del pentágono es ";
    cout << PentagonoPredeterminado.obtenerLado() << ".\n";

    cout << "\tEl perímetro es ";
    cout << PentagonoPredeterminado.obtenerPerimetro();
    cout << " y el área es ";
    cout << PentagonoPredeterminado.obtenerArea() << ".\n\n";

    //Luego usaremos el constructor con parámetros para crear un pentágono y probar sus métodos.
    cout << "Usando el constructor con parámetros: " << endl;
    Pentagono PentagonoConParametros(4);

    cout << "\tLa longitud del lado del pentágono es ";
    cout << PentagonoConParametros.obtenerLado() << ".\n";

    cout << "\tEl perímetro es ";
    cout << PentagonoConParametros.obtenerPerimetro();
    cout << " y el área es ";
    cout << PentagonoConParametros.obtenerArea() << ".\n\n";

    /* Ahora haremos uso de punteros para crear el pentágono con el constructor predeterminado
       y usar sus métodos */
    cout << "Ahora, usando punteros con el constructor predeterminado: " << endl;
    Pentagono *aPPentagonoPredeterminado = new Pentagono;

    cout << "\tLa longitud del lado del pentágono es ";
    cout << aPPentagonoPredeterminado->obtenerLado() << ".\n";

    cout << "\tEl perímetro es ";
    cout << aPPentagonoPredeterminado->obtenerPerimetro();
    cout << " y el área es ";
    cout << aPPentagonoPredeterminado->obtenerArea() << ".\n\n";

    delete aPPentagonoPredeterminado;

    /* Para finalizar, probaremos los métodos de el pentágono usando punteros
       y el constructor con parámetros. */
    cout << "Por último, usando punteros con parámetros específicos: " << endl;
    Pentagono *aPPentagonoConParametros = new Pentagono(2.5);

    cout << "\tLa longitud del lado del pentágono es ";
    cout << aPPentagonoConParametros->obtenerLado() << ".\n";

    cout << "\tEl perímetro es ";
    cout << aPPentagonoConParametros->obtenerPerimetro();
    cout << " y el área es ";
    cout << aPPentagonoConParametros->obtenerArea() << ".\n\n";

    delete aPPentagonoConParametros;

    return 0;
}
