#include "../../lib/datatypes/DtPartidaIndividual.h"
#include "../../lib/datatypes/DtFechaHora.h"

// Constructor y destructor
DtPartidaIndividual::DtPartidaIndividual(float identificador,float duracion, DtFechaHora fecha, PartidaIndividual* continuacion)
    : DtPartida::DtPartida(identificador, duracion, fecha)
{
    this->continuacion = continuacion;
}

DtPartidaIndividual::~DtPartidaIndividual()
{
    if (continuacion != NULL)
        delete continuacion;
}

// Funcion pura de DtPartida
void DtPartidaIndividual::abstracta() {}

// Getters
float* DtPartidaIndividual::getContinuacion()
{
  return continuacion;
}

// Sobrecarga del operador de insercion <<
ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd)
{
  os << "Tipo partida: Individual" << endl;
  os << "ID partida: " << static_cast<float>(dtPartidaInd.identificador) << endl;
  os << "Fecha partida: " << dtPartidaInd.fecha << endl;
  os << "Duracion partida: " << static_cast<int>(dtPartidaInd.duracion) << " hs" << endl;
  if (dtPartidaInd.continuacion != NULL)
    os << "Continua partida ID " << *static_cast<float*>(dtPartidaInd.continuacion) << endl;
  else
    os << "No es continuacion de partidas anteriores" << endl;
  return os;
}
