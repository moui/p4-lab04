i#include "../lib/Jugador.h"

Jugador::Jugador(string nickname, string descripcion, map<float, Partida*> iniciadas, map<float, InfoPartidaJugador*> unen, set<Suscripcion> suscripto, set<Jugador*> sigue)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
  map<float, Partida*> iniciadas = iniciadas;
  map<float, InfoPartidaJugador*> unen = unen;
  set<Suscripcion> suscripto = suscripto;
  set<Jugador*> sigue = sigue;
  return;
}

// Getters
string Jugador::getNickname()
{
  return this->nickname;
}

string Jugador::getDescripcion()
{
  return this->descripcion;
}


set<Partida*> Jugador::getPartidasIniciadas()
{
  return this->iniciada;
}

set<InfoPartidaJugador*> Jugador::getPartidasMultijugador()
{
  return this->unen;
}

// Setters
void Jugador::setNickname(string nickname)
{
  this->nickname = nickname;
}

void Jugador::setDescripcion(string Descripcion)
{
  this->descripcion = Descripcion;
}


void Jugador::setPartidasIniciadas(set<Partida*> iniciadas)
{
  this->iniciada = iniciadas;
}

void Jugador::setPartidasMultijugador(set<PartidaMultijugador*> partidasMultijugador)
{
  this->unen = partidasMultijugador;
}

void finPartida(float id){
  this->iniciadas[id]->filaizada = true;

}

void seguir(Jugador* j){
  sigue->insert(j);
}

set<DtPartidas*> partidasInSF(){
   map<float, Partida*>::iterator i = iniciadas->begin();
   set<DtPartida*> isf;
   while(i != iniciadas->end()){
      if(!estaFinalizada(**i)){
        
      }
      ++i;
   }
   return isf;
}

void iniciadaP(Partida p){

}

bool estaSuscritoA(std::string NombreVJ){

}

set<DtPartidasIndividuales*> partidasIndF(){

}

set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas(){

}

void AltaSuscripcion(){

}

void CancelarSuscripcion(std::string NombreVJ){

}

Jugador::~Jugador()
{
  delete[] this->iniciada;
  delete[] this->unen;
}
