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

void Jugador::finPartida(float id){
  /* this->iniciadas[id]->filaizada = true; */
}

void Jugador::seguir(Jugador* j){
  /* sigue->insert(j); */
}

set<DtPartida*> Jugador::partidasIniciadasSinFinalizar()
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
        } else {
	PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(i->second);
        map<string, InfoPartidaMulti> part = pm->getParticipan();
        map<string, InfoPartidaMulti>::iterator it = part.begin();
        set<string> s;
        while (it != part.end()){
          s.insert(it->second.getParticipa()->getNickname());
          ++it;
        }
        DtPartidaMultijugador* p = new DtPartidaMultijugador(pm->getId(), pm->getDuracion(), pm->getFecha(), pm->getTransmitidaEnVivo(), s, s.size());
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

bool Jugador::estaSuscritoA(std::string NombreVJ)
{
  bool b = false;
  set<Suscripcion*>::iterator it = suscripto.begin();
  Suscripcion* s = NULL;
  while (!b && (it != suscripto.end())) {
	s = *it;
	if (s->getnombreVJ() == NombreVJ){
		b = true;
	}
	++it;
  }
  s->~Suscripcion();
  return b;
}

Suscripcion* Jugador::getSuscripcion(string nomVJ){
  set<Suscripcion*>::iterator it = suscripto.begin();
  Suscripcion* res = NULL;
  while (it != suscripto.end()) {
    Suscripcion* s= *it;
	  if (s->getnombreVJ() == nomVJ){
		  res=s;
      break;
	}
	++it;
  }
  return res;
}

DtSuscripcion* getDatosSuscripcion(string nomVJ){
  DtSuscripcion* res=NULL;
  CtrlUsuario* ctrlusuario = CtrlUsuario::getInstancia();
  Usuario* user= ctrlusuario->getSesionActiva();
  Jugador * jugador={dynamic_cast<Jugador*>(user)};
  Suscripcion* s= jugador->getSuscripcion(nomVJ);

  s = jugador->getSuscripcion(nomVJ);
  if (s!=NULL){
    //datos
    string n = s->getnombreVJ();
    DtFechaHora f=s->getFecha();
    float c = s->getCosto();
    TipoPago tp = s->getTipoPago();
    TipoEstado te=s->getEstado();
    bool v = s->getVitalicia();
    //(n,f,c,tp,te,v) datos

    res = new DtSuscripcion(n,f,c,tp,te,v);
  }
  return res;
}

set<DtPartidaIndividual*> Jugador::partidasIndividualesFinalizadas()
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

//Suscribirse a videojuego

set<DtVideojuegoSuscripcion*> Jugador::listarVideojuegoSuscripcionesActivas(map<string, DtVideojuegoSuscripcion*> Dcatalogo)
{
  set<DtVideojuegoSuscripcion*> res;
  set<Suscripcion*>::iterator it;
  for(it=suscripto.begin(); it!=suscripto.end(); it++){
    Suscripcion *s;
    s=*it;
    string idVJ=s->getnombreVJ();
    if (s->getEstado()==TipoEstado::activa){

        map<string, DtVideojuegoSuscripcion*>::iterator itDcatalogo=Dcatalogo.find(idVJ);
        res.insert(itDcatalogo->second);
        Dcatalogo.erase(idVJ);

    }
  }
  return res;
}



void Jugador::AltaSuscripcion()
{
}

void Jugador::CancelarSuscripcion(string NombreVJ)
{
}

void Jugador::mostrarUsuario(){ cout << "jug"; }
