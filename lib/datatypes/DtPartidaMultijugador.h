#ifndef DT_PARTIDAMULTIJUGADOR
#define DT_PARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

class DtPartidaMultijugador : public DtPartida
{
    private:
        bool transmitidaEnVivo;
        string* nicknameJugadoresUnidos;
        int cantidadJugadoresUnidos;

    public:
        // Constructor
        DtPartidaMultijugador(float id, float duracion, DtFechaHora fecha,
            bool enVivo, string* jugadoresUnidos, int cantidadUnidos);
        // Destructor
        ~DtPartidaMultijugador();
        // Funcion pura de DtPartida
        void abstracta();

        // Getters
        bool getTransmitidaEnVivo();
        string* getNicknameJugadoresUnidos();
        int getCantidadJugadoresUnidos();

        // Sobrecarga del operador de insercion <<
        friend ostream& operator<<(ostream& os, const DtPartidaMultijugador& dtPartidaMulti);
};
#endif
