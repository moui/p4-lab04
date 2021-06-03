#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"



class PartidaIndividual : public Partida
{
  private:

    bool continuaPartidaAnterior;

  public:

    PartidaIndividual(DtFechaHora, float, bool, Jugador *, Videojuego *);
    //~PartidaIndividual();

    float darTotalHorasParticipantes();
    //getters

    bool getcontinuaPartidaAnterior();

    //setters
    void setcontinuaPartidaAnterior(bool);


};

#endif
