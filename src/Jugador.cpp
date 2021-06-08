#include "../lib/Jugador.h"

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
  sigue->insert(j);
}

set<DtPartidas*> partidasInSF(){
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
   return NULL;
}

void iniciadaP(Partida p){
  this->inicio[p->getId()] = p;
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
}
