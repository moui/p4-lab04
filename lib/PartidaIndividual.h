#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"
#include <set>



class PartidaIndividual : public Partida
{
  private:

    bool continuaPartidaAnterior;
    PartidaIndividual* continuada;

  public:

    PartidaIndividual(DtFechaHora, bool, Jugador *, Videojuego *, PartidaIndividual *, bool);
    //~PartidaIndividual();

    float darTotalHorasParticipantes();
    //getters

    bool getcontinuaPartidaAnterior();
    DtPartidaIndividual getPartidaCont();

    //setters
    void setcontinuaPartidaAnterior(bool);
    void setpartidaACont(Partida p);


};

#endif
