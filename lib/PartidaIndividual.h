#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"



class PartidaIndividual : public Partida
{
  private:
    PartidaIndividual* continuacion;

  public:
    PartidaIndividual(float id, float duracion, bool finalizada, DtFechaHora fecha, Videojuego* videojuego, PartidaIndividual* continuacion);
    ~PartidaIndividual();

    float darTotalHorasParticipantes();
    
    // Getters
    bool getContinuacion();

    // Setters
    void setContinuacion(PartidaIndividual* partida);


};

#endif
