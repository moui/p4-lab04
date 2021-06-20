#include "../../lib/datatypes/DtPartida.h"

DtPartida::DtPartida(float id, float duracion, DtFechaHora fecha, string n)
{
  this->identificador = id;
  this->fecha = fecha;
  this->duracion = duracion;
  this->nomVJ=n;
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