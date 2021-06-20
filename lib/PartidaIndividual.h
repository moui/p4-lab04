#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"
#include <set>

class PartidaIndividual : public Partida
{
  private:

    PartidaIndividual* continuacion;

  public:
    PartidaIndividual(int id, float duracion, bool finalizada, DtFechaHora* fecha, DtFechaHora* fecha_fin, Videojuego* videojuego, PartidaIndividual* continuacion);
    ~PartidaIndividual();

    float darTotalHorasParticipantes();
    
    // Getters
    bool getContinuacion();
    PartidaIndividual* getContinuada();

    // Setters
    void setContinuacion(PartidaIndividual* partida);



};

#endif
