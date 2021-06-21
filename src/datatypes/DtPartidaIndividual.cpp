#include "../../lib/datatypes/DtPartidaIndividual.h"
#include "../../lib/datatypes/DtFechaHora.h"

// Constructor y destructor
DtPartidaIndividual::DtPartidaIndividual(int identificador,float duracion, DtFechaHora* fecha, DtFechaHora* fecha_fin, string n, bool continuacion)
    : DtPartida::DtPartida(identificador, duracion, fecha, fecha_fin, n)
{
    this->continuacion = continuacion;
}

DtPartidaIndividual::~DtPartidaIndividual()
{
}

// Funcion pura de DtPartida
void DtPartidaIndividual::abstracta() {}

// Getters
bool DtPartidaIndividual::getContinuacion()
{
  return continuacion;
}

// Sobrecarga del operador de insercion <<
ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd)
{
  os << "Tipo partida: Individual" << endl;
  os << "ID partida: " << static_cast<int>(dtPartidaInd.identificador) << endl;
  os << "Fecha inicio partida: " << dtPartidaInd.fecha << endl;
  if (dtPartidaInd.continuacion == true)
    os << "Es continuacion de partidas anteriores " << endl;
  else
    os << "No es continuacion de partidas anteriores" << endl;
  return os;
}
