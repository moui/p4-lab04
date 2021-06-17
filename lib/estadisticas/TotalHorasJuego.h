#ifndef TOTALHORASJUEGO
#define TOTALHORASJUEGO

#include "../interfaces/IEstadistica.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../datatypes/DtEstadistica.h"


#include <string>
#include <algorithm>
#include <set>

using namespace std;


class TotalHorasJuego : public IEstadistica
{
    private:

    string nomEstadistica;
    float valor;
    string descripcion;

    public:

        TotalHorasJuego(string n, float v, string d);
        ~TotalHorasJuego();

        string getNombre();
        float getValor();

        void setNombre(string n);
        void setValor(float v);
        DtEstadistica* calcular();
    
};


#endif