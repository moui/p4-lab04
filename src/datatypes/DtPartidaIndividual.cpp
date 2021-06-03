#include "../../lib/datatypes/DtPartidaIndividual.h"
#include "../../lib/datatypes/DtFechaHora.h"

DtPartidaIndividual::DtPartidaIndividual(DtFechaHora fecha, float duracion, bool continua):
    DtPartida(fecha, duracion)
{

  this->continuaPartidaAnterior = continua;

}

// Getters
bool DtPartidaIndividual::getContinuaPartidaAnterior()
{
  return this->continuaPartidaAnterior;
}
std::ostream& operator<<(std::ostream& out, const DtPartidaIndividual& dt){

    out<<"Tipo de partida: Individual.\n";
    out << "Fecha partida:" << dt.getFecha().getd()<< "/" << dt.getFecha().getmes()<<"/"<< dt.getFecha().geta()<<"\n";
    out<< dt.getDuracion()<< "\n";
    out<< "Continua partida anterior:"<< ((dt.continuaPartidaAnterior) ? "Si.\n" : "No.\n");

    return out;
    }
