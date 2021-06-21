#include "../../lib/datatypes/DtPartida.h"

DtPartida::DtPartida(int id, float duracion, DtFechaHora* fecha, DtFechaHora* fecha_fin,  string n)
{
  this->identificador = id;
  this->fecha = fecha;
  this->fecha_fin = fecha_fin;
  this->duracion = duracion;
  this->nomVJ=n;
  return;
}

DtPartida::DtPartida(int id, DtFechaHora* fecha, string n)
{
  this->identificador = id;
  this->fecha = fecha;
  this->nomVJ=n;
  fecha_fin = NULL;
  duracion = 0;
  return;
}

DtPartida::~DtPartida()
{
  if (fecha != NULL)
    delete fecha;

  if (fecha_fin != NULL)
    delete fecha_fin;
}

// Getters

string DtPartida::getNombreVJ()
{
  return this->nomVJ;
}

int DtPartida::getId()
{
  return identificador;
}

float DtPartida::getDuracion() const
{
  return duracion;
}

DtFechaHora* DtPartida::getFecha()
{
  return fecha;
}

DtFechaHora* DtPartida::getFechaFin()
{
  return fecha_fin;
}

ostream& operator<<(ostream& os, const DtPartida& dtPartida)
//falta agregar un casteo dinamico para ver que tipo de dt partida es y imprimir segun corresponda
{
  os << "Tipo partida: Individual" << endl;
  os << "ID partida: " << static_cast<int>(dtPartida.identificador) << endl;
  os << "Fecha inicio partida: " << *(dtPartida.fecha) << endl;
  os << "Videojuego: " << dtPartida.nomVJ << endl;
  return os;
  //
}