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

set<DtPartida*> Jugador::partidasInSF()
{
   map<int, Partida*>::iterator i = this->inicio.begin();
   set<DtPartida*> isf;
   while(i != this->inicio.end()){
      if(!i->second->getFinalizada()){	
        if(dynamic_cast<PartidaIndividual*>(i->second) != NULL){
	 PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(i->second);
	 float* f = new float (pi->getContinuada()->getId());
         DtPartidaIndividual* p = new DtPartidaIndividual(pi->getId(), pi->getDuracion(), pi->getFecha(), f);
         DtPartida* p2 = dynamic_cast<DtPartida*>(p);
         isf.insert(p2);
	 isf.insert(p);
        } else {
	PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(i->second);
        map<string, InfoPartidaMulti> part = pm->getParticipan();
        map<string, InfoPartidaMulti>::iterator it = part.begin();
        string* s = new string[100];
	int c = 0;
        while (it != part.end()){
          s[c] = it->second.getParticipa()->getNickname();
	  c++;
          ++it;
        }
        DtPartidaMultijugador* p = new DtPartidaMultijugador(pm->getId(), pm->getDuracion(), pm->getFecha(), pm->getTransmitidaEnVivo(), s, c);
	DtPartida* p2 = dynamic_cast<DtPartida*>(p);
        isf.insert(p2);
        }
      }
      ++i;
   }
   return isf; 
}

void Jugador::iniciadaP(Partida* p){
   this->inicio[p->getId()] = p; 
}

bool estaSuscritoA(std::string NombreVJ)
{
  return false;
}

set<DtPartidaIndividual*> partidasIndF()
{
   map<int, Partida*>::iterator i = this->inicio.begin();
   set<DtPartidaIndividual*> isf;
   while(i != this->inicio.end()){
      if(i->second->getFinalizada()){	
        if(dynamic_cast<PartidaIndividual*>(i->second) != NULL){
	 PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(i->second);
	 float* f = new float (pi->getContinuada()->getId());
         DtPartidaIndividual* p = new DtPartidaIndividual(pi->getId(), pi->getDuracion(), pi->getFecha(), f);
	 isf.insert(p);
	}
      }
    ++i;
    }
    return isf;
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
