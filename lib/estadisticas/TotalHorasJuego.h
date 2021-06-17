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

    public:

        TotalHorasJuego(string n, float v);
        ~TotalHorasJuego();

        string getNombre();
        float getValor();

        void setNombre(string n);
        void setValor(float v);
     //   DtEstadistica* calcular();
    
};


#endif