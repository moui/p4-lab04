#include "../lib/PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(DtFechaHora fecha, float duracion, bool continuaP, Jugador *inicia, Videojuego *videojuego)
    :Partida(fecha, duracion, inicia, videojuego)
{
    this->continuaPartidaAnterior=continuaP;

}
// PartidaIndividual::~PartidaIndividual(){} 


////usar el datatype correspondiente
float PartidaIndividual::darTotalHorasParticipantes()
{
  return getDuracion();
}

bool PartidaIndividual::getcontinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;}



void PartidaIndividual::setcontinuaPartidaAnterior(bool continua){
    this->continuaPartidaAnterior=continua;
}
