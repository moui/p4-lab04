#ifndef TOTALJUGADORESSUSCRITOS
#define TOTALJUGADORESSUSCRITOS

#include "../interfaces/IEstadistica.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../datatypes/DtEstadistica.h"


#include <string>
#include <algorithm>
#include <set>

using namespace std;


class TotalJugadoresSuscritos : public IEstadistica
{
    private:

    string nomEstadistica;
    float valor;

    public:

        TotalJugadoresSuscritos(string n, float v);
        ~TotalJugadoresSuscritos();

        string getNombre();
        float getValor();

        void setNombre(string n);
        void setValor(float v);
        //DtEstadistica* calcular();
    
};


#endif