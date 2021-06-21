#ifndef INFO_PARTIDA_MULTI
#define INFO_PARTIDA_MULTI

#include "datatypes/DtFechaHora.h"
#include "Jugador.h"

class Jugador;

class InfoPartidaMulti
{
    private:
        DtFechaHora* abandonaEn;
        Jugador* participa;

    public:
        // Constructor y destructor
        InfoPartidaMulti(DtFechaHora* fecha, Jugador* jugador);
        ~InfoPartidaMulti();

        // Getters
        DtFechaHora* getAbandonaEn();
        Jugador* getParticipa();

        // Setters
        void setAbandonaEn(DtFechaHora* fecha);
        void setParticipa(Jugador* jugador);
};


#endif