#ifndef DT_PARTIDAMULTIJUGADOR
#define DT_PARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include <string>
#include <iostream>
#include <set>

using namespace std;

class DtPartidaMultijugador : public DtPartida
{
    private:
        bool transmitidaEnVivo;
        set<string> nicknameJugadoresUnidos;
        int cantidadJugadoresUnidos;

    public:
        // Constructor
        DtPartidaMultijugador(int id, float duracion, DtFechaHora* fecha, string n,
            bool enVivo, set<string> jugadoresUnidos, int cantidadUnidos);
        // Destructor
        ~DtPartidaMultijugador();
        // Funcion pura de DtPartida
        void abstracta();

        // Getters
        bool getTransmitidaEnVivo();
        set<string> getNicknameJugadoresUnidos();
        int getCantidadJugadoresUnidos();

        // Sobrecarga del operador de insercion <<
        friend ostream& operator<<(ostream& os, const DtPartidaMultijugador& dtPartidaMulti);
};
#endif
