#include "../../lib/datatypes/DtPartida.h"

DtPartida::DtPartida(float id, float duracion, DtFechaHora fecha)
{
  this->identificador = id;
  this->fecha = fecha;
  this->duracion = duracion;
  return;
}

DtPartida::~DtPartida()
{
}

// Getters

string DtPartida::getNombreVJ()
{
  return this->nomVJ;
}

float DtPartida::getId()
{
  return identificador;
}

float DtPartida::getDuracion()
{
  return duracion;
}

DtFechaHora DtPartida::getFecha()
{
  return fecha;
}