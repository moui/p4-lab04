#include "../../lib/datatypes/DtPartidaIndividual.h"
#include "../../lib/datatypes/DtFechaHora.h"

// Constructor y destructor
DtPartidaIndividual::DtPartidaIndividual(int identificador,float duracion, DtFechaHora* fecha, DtFechaHora* fecha_fin, string n, int* continuacion)
    : DtPartida::DtPartida(identificador, duracion, fecha, fecha_fin, n)
{
    this->continuacion = continuacion;
}

DtPartidaIndividual::DtPartidaIndividual(int identificador, DtFechaHora* fecha, string n, int* continuacion)
    : DtPartida::DtPartida(identificador, fecha, n)
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
int* DtPartidaIndividual::getContinuacion()
{
  return continuacion;
}

// Sobrecarga del operador de insercion <<
ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd)
{
  os << "Tipo partida: Individual" << endl;
  os << "ID partida: " << static_cast<int>(dtPartidaInd.identificador) << endl;
  os << "Fecha inicio partida: " << *(dtPartidaInd.fecha);
  os << "Fecha fin partida: " << *(dtPartidaInd.fecha_fin);
 // if ( dtPartidaInd.fecha_fin != NULL){
    os << "Duracion: " << dtPartidaInd.getDuracion() << endl;  
 // }
  if (dtPartidaInd.continuacion != NULL)
    os << "Es continuacion de partidas anteriores " << endl;
  else
    os << "No es continuacion de partidas anteriores" << endl;
  return os;
}
