#include "../lib/Jugador.h"

// Constructor y destructor

Jugador::Jugador(string email, string contrasena, string nickname, string descripcion): Usuario(email, contrasena)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
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
  this->descripcion = descripcion;
}

void Jugador::setInicioPartidas(map<int,Partida*> inicio)
{
  this->inicio = inicio;
}

void finPartida(float id){
  /* this->iniciadas[id]->filaizada = true; */
}

void seguir(Jugador* j){
  /* sigue->insert(j); */
}

set<DtPartida*> partidasInSF()
{
   set<DtPartida*> foo;
   /*map<float, Partida*>::iterator i = inicio->begin();
   set<DtPartida*> isf;
   while(i != inicio->end()){
      if(!estaFinalizada(**i)){
        if(dynamic_cast<PartidaIndividual*>(*i) != NULL){
         DtPartidaIndividual* p = dynamic_cast<DtPartidaIndividual*>(*i->getId(), *i->getDuracion, *i->getFecha(), *i->getContinuacion());
         isf->insert(p);
        } else {
        map<string, InfoPartidaMulti> part = *i->getParticipan();
        map<string, InfoPartidaMulti>::iterator it = part->begin();
        set<string> s;
        while (*it != part->end()){
          s->insert(*it->getNickname);
          ++it;
        }
        DtPartidaMultijugador* p = dynamic_cast<DtPartidaMultijugador*>(*i->getId(), *i->getDuracion, *i->getFecha(), *i->getTrasmitidaEnVivo(), s, s->size());
        isf->insert(p);
        }
      }
      ++i;
   }
   return isf; */
   return foo;
}

void iniciadaP(Partida* p){
  /* this->inicio[p->getId()] = p; */
}

bool estaSuscritoA(std::string NombreVJ)
{
  return false;
}

set<DtPartidaIndividual*> partidasIndF()
{
  set<DtPartidaIndividual*> foo;
  return foo;
}

set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas()
{
  set<DtVideojuegoSuscripcion*> foo;
  return foo;
}

void AltaSuscripcion()
{
}

void CancelarSuscripcion(string NombreVJ)
{
}

void Jugador::mostrarUsuario(){ cout << "jug"; }