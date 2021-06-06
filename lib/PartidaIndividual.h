#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"



class PartidaIndividual : public Partida
{
  private:

    bool continuaPartidaAnterior;
    PartidaIndividual* continuada;

  public:

    PartidaIndividual(DtFechaHora, float, bool, Jugador *, Videojuego *);
    //~PartidaIndividual();

    float darTotalHorasParticipantes();
    //getters

    bool getcontinuaPartidaAnterior();
    DtPartidaIndividual getPartidaCont();

    //setters
    void setcontinuaPartidaAnterior(bool);


};

#endif
