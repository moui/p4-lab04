#include "../../lib/datatypes/DtPartidaIndividual.h"
#include "../../lib/datatypes/DtFechaHora.h"

// Constructor y destructor
DtPartidaIndividual::DtPartidaIndividual(int identificador,float duracion, DtFechaHora* fecha, string n, bool continuacion)
    : DtPartida::DtPartida(identificador, duracion, fecha, n)
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
  os << "Fecha partida: " << dtPartidaInd.fecha << endl;
  os << "Duracion partida: " << static_cast<int>(dtPartidaInd.duracion) << " hs" << endl;
  if (dtPartidaInd.continuacion == true)
    os << "Continua partida ID " << static_cast<float>(dtPartidaInd.continuacion) << endl;
  else
    os << "No es continuacion de partidas anteriores" << endl;
  return os;
}
