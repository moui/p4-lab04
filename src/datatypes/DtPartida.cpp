#include "../../lib/datatypes/DtPartida.h"

DtPartida::DtPartida(DtFechaHora fecha, float duracion)
{
  this->fecha = fecha;
  this->duracion = duracion;
}

// Getters
DtFechaHora DtPartida::getFecha () const
{
  return this->fecha;
}

float DtPartida::getDuracion() const
{
  return this->duracion;
}


DtPartida::~DtPartida()
{
}