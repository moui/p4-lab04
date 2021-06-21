#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"
#include "Videojuego.h"
#include <set>
#include "datatypes/DtPartidaIndividual.h"

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

    DtPartidaIndividual* getDatos();



};

#endif
