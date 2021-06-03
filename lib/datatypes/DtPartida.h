#ifndef DT_PARTIDA
#define DT_PARTIDA

#include "DtFechaHora.h"
#include <iostream>

class DtPartida
{
  private:

    DtFechaHora fecha;
    float duracion;

  public:

    DtPartida();
    virtual ~DtPartida();
    DtPartida(DtFechaHora fecha, float duracion);

    // Getters

    DtFechaHora getFecha () const;
    virtual float getDuracion() const;



};

#endif
