i#include "../lib/Jugador.h"

// Constructor y destructor

Jugador::Jugador(string email, string contrasena, string nickname, string descripcion, map<int, Partida*> inicio)
  : Usuario(email, contrasena)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
  this->inicio = inicio;
  return;
}

Jugador::~Jugador()
{
  // Determinar como se va a destruir el map<int, Partida>
}

// Getters
string Jugador::getNickname()
{
  return this->nickname;
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


map<int, Partida*> Jugador::getInicioPartidas()
{
  return this->inicio;
}

// Setters
void Jugador::setNickname(string nickname)
{
  this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion)
{
  this->descripcion = Descripcion;
}

void Jugador::setInicioPartidas(map<int,Partida*> inicio)
{
  this->inicio = inicio;
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
